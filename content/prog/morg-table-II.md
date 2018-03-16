+++
title      = "TextTable2HtmlTable (Volume Two)"
tags       = [ "morg" ]
categories = [ "prog" ]
date       = 2018-01-10T18:44:03-06:00
+++

<center>
![](/img/1ef7ys9dnksz.jpg)
</center>

## o, como "parsear" una tabla en texto plano para convertirla en una tabla html (u otra cosa) (+ codigo de ejemplo en Golang) – Segunda Parte

En el [post anterior](../morg-table/) expuse una manera para parsear tablas
relativamente complejas, con una tecnica relativamente sencilla, con un codigo
relativamente interesante... ahora la tecnica y la sintaxis ha cambiado, en
lugar de "concatenar" las columnas, se realiza un analisis de los contornos de
las celdas; ademas la sintaxis ha sido modificada para ser compatible con la que
utiliza (un estilo) de reStructuredText (es mas sencillo y supongo, (algun
dia...) el editor del formato, tendra un programa auxiliar que mitigue el
fastidio de dibujar lineas):

```
                                  +----------------------+
|   mi tabla compleja  |          |   mi tabla compleja  |
|-------|----|---------|          +-------+----+---------+
|  a    | b  |    c    |          |  a    | b  |    c    |
|---|---|----|----|----|          +---+---+----+----+----+
| d | e | f  |  g |  i |      \   | d | e | f  |  g |  i |
|   |   |----|----|----|  =====\  |   |   +----+----+----+
|   |   | i  |    j    |  =====/  |   |   | i  |    j    |
|   |---|----|---------|      /   |   +---+----+---------+
|   | k | l  |         |          |   | k | l  |         |
|   |   |----|    m    |          |   |   +----+    m    |
|   |   | n  |         |          |   |   | n  |         |
|   |   |----|---------|          |   |   +----+---------+
|   |   | o  |    p    |          |   |   | o  |    p    |
|---|---|----|---------|          +---+---+----+---------+
```

pero, por que el cambio? bueno esta nueva version (sutilmente expuesta anteriormente)
permite evitar ambiguedades entre los delimitadores de la tabla y el contenido
de cada "celda", ademas [el codigo](/data/table2.go) (guardar-como) no es demaciado complejo (pruebas
por [aca](/data/table2_test.go), un `go test -v` en una carpeta sin otro codigo go)

Basicamente solo se modifica la forma de analizar la tabla. La convenienca de
pasar los datos de entrada a una cuadricula de runas y conocer la
dimencion-posicion relativa de las celdas con respecto a las demas, permanece sin
cambios.

El codigo es severamente basico y asume datos de entrada correctos (en caso
contrario no seria extraño entrar en bucles infinitos). Aun no estoy conforme
con la estructura literarea del codigo, es poco intuitivo y casi nada
secuencial, tambien dudo un poco de los objetos que se utilizan, pero en fin las
bases estan aqui, el codigo de referencia estara dentro de
`github.com/nasciiboy/morg/katana/table.go` en el repo de morg (algun dia) y
lamentablemente sera poco reutilizable debido a la naturaleza (actual) de la
forma en como se recorre el texto de entrada... pero bueno, al ajo

```
// constantes para definir el contorno de la tabla
const CORNER  = '+'  //  +----+
const VEDGE   = '|'  //  |    |
const HEDGE   = '-'  //  +----+

// y una constante para indicar que la posicion se encuentra
// fuera de la cuadricula de la tabla
const OUTSIDE = '\uFFFD' // unicode.RuneError = '\uFFFD'
```

unas estructuras fundamentales

```
type cell  struct {
  y, x, y2, x2 int
  data string
}
```

en `cell`, iran los datos "listos para usar" de cada celda

```
// la cuadricula cuadricular
type grid struct {
  data [][]rune
  w, h int
}

// inicializar la cuadricula
func (g *grid) init( data string ) *grid {
  g.data = gridify( data )
  g.h = len( g.data )
  if g.h > 0 {
    g.w = len( g.data[0] )
  } else { g.w = 0 }

  return g
}

// visitar una posicion de la celda y conocer
// el caracter que en ella habita o saber si es una
// posicion mas alla de los bordes (OUTSIDE)
func (g *grid) visit( p point ) rune {
  if p.x < 0 || p.y < 0 || p.x >= g.w || p.y >= g.h ||
     g.h < 1 || g.w < 1 {
    return OUTSIDE
  }

  return g.data[p.y][p.x]
}
```

point es un objeto que representa una ubicacion, tiene dos metodos para avanzar
en una de cuatro direcciones. El primer metodo (`mv`) mueve el punto, el segundo
(`nmv`) regresa una simulacion del movimiento

```
const ( RIGHT = iota; UP; LEFT; DOWN )

type point struct { y, x int }

func (p *point) mv( dir byte ) point {
  switch dir {
  case RIGHT: p.x += 1
  case UP   : p.y -= 1
  case LEFT : p.x -= 1
  case DOWN : p.y += 1
  }

  return *p
}

func (p point) nmv( dir byte ) point {
  return p.mv( dir )
}
```

hay un otro objeto casi identico a las celdas, pero este cuenta con cuatro
puntos, uno para cada una de las esquinas de la celda, ummm, para dejar abierta
la posibilidad de mejorar la comprabacion del contorno de la celda, lanzar
mensajes de error y esas cosas... supongo

```
type square struct {
  topLeft, topRight, bottomLeft, bottomRight point
  *grid
}
```

tiene un puntero a `grid`, para saber sobre que cuadricula se realiza la
busqueda del contorno. Hay una funcion de conveniecia para crear squares:

```
func (g *grid) newSquare( p point ) *square {
  return &square{ grid: g, topLeft: p }
}
```

y a continuacion, la funcion para iniciar el recorrido por el perimetro de una celda desde
su posicion superior izquierda hacia la derecha (en sentido de las manecillas
del reloj).

Es poco elegante, pero las bases para su mejora se encuentran hay

```
func (s *square) tourist( ) bool {
  s.topRight    = s.findUpCorner( s.topLeft )
  s.bottomRight = s.findRightCorner( s.topRight )
  s.bottomLeft  = s.findDownCorner( s.bottomRight )

  return true
}

func (g *grid) findCorner( p point, dir byte ) (c point) {
  edge := rune(VEDGE)
  if dir == UP || dir == DOWN { edge = HEDGE }

  for {
    switch g.visit( p.mv( dir ) ) {
    case CORNER : return p
    case edge   : continue
    }
  }

  return p
}

func (g *grid) findUpCorner( p point ) point {
  for p = g.findCorner( p, RIGHT ); g.visit( p.nmv( DOWN ) ) != VEDGE; p = g.findCorner( p, RIGHT ) {}
  return p
}

func (g *grid) findDownCorner( p point) point {
  for p = g.findCorner( p, LEFT  ); g.visit( p.nmv( UP   ) ) != VEDGE; p = g.findCorner( p, LEFT  ) {}
  return p
}

func (g *grid) findRightCorner( p point) point {
  for p = g.findCorner( p, DOWN  ); g.visit( p.nmv( LEFT ) ) != HEDGE; p = g.findCorner( p, DOWN  ) {}
  return p
}
```

tengo muchas dudas, sobre la combinacion de cuadricula y squares, aun no termino
de verlo claro

ahora si el plato fuerte

```
// recibe una tabla como cadena y regresa la tabla en html (como cadena)
func TextTable2HtmlTable( data string ) string {
  // crea e inicializa la cuadricula
  g := new( grid ).init( data )
  // para conocer todos los bordes de las celdas (ver post anterior)
  xEdges, yEdges := map[int]bool{ 0: true }, map[int]bool{ 0: true }

  rows := make( [][]*cell, 0, 10 ) // almacena la tabla procesada [fila][columna]
  row  := make(   []*cell, 0,  5 ) // la fila actual
  // las celdas son punteros para evitar la copia de estructuras completas
  // de esta forma, si es necesaria la reaccignacion de memoria, unicamente
  // se copian los punteros.
  // la dimencion inicial, es la que considere razonable

  // aqui se almacena el inicio de futuras celdas
  //
  // en general, siempre se almacena la posicion que representa
  // la posicion inferior izquierda de las celdas, SOLO si hay un
  // caracter VEDGE debajo de esta, de otra forma no habria
  // una celda a explorar en esa posicion... ja, ja, ja, es algo un poco
  // anti-intuitivo, pero las unicas esquinas de las celdas que se necesitan
  // revisar para explorar todas en orden, son las esquinas superior derecha
  // de la celda actual, continuando hacia el final derecho de la fila, y luego
  // explorar las esquinas inferiores izquierdas de las celdas (almacenadas en
  // esta tabla hash, ve una tabla "cruda" y realiza simulaciones mentales
  hotPoints := make( map[point]bool )

  // se inicia el ciclo por las celdas, la primera se encuentra en la posicion
  // [0,0] (puntero a un nuevo punto... piensalo)
  // next es un puntero para no tener un centinela (adicional) dedicado, es
  // decir, si next == nil, ha terminado la exploracion
  for next, y := new(point), 0; next != nil;  {
    s := g.newSquare(*next) // un nuevo square en la posicion actual
    s.tourist()             // se averiguan los margenes del square

    // anotamos los limites derecho e inferior de la celda
    // el "true" no tiene importancia, se eligio por que es necesario asignar
    // un valor, y un booleano es lo mas simple que hay
    xEdges[ s.topRight.x   ] = true
    yEdges[ s.bottomLeft.y ] = true

    // ... si el indice de fila actual es distinto al anterior
    if y != s.topLeft.y {
      rows = append( rows, row)     // agregamos la fila anterior a la tabla
      row = make( []*cell, 0, 5 )   // una nueva fila actual
      y = s.topLeft.y               // actualizamos el indice
    }

    // creamos una celda con los datos definitivos
    r := &cell{ y: s.topLeft.y, x: s.topLeft.x, y2: s.bottomRight.y, x2: s.bottomRight.x }
    // se extrae el texto de la cuadricula
    r.data = cutRectangularText( g.data, r )
    // se agrega la celda a la fila actual
    row = append( row, r )

    // si la posicion del borde inferior izquierdo es el inicio
    // de otra celda, se agrega a los puntos calientes
    if g.visit( s.bottomLeft.nmv( DOWN ) ) == VEDGE {
      hotPoints[ s.bottomLeft ] = true
    }

    // terminamos con la celda actual, vamos con la siguiente
    //
    // si, hemos cambiado de fila y estamos viendo un punto caliente
    // (posicion inferior izquierda) de la fila anterior, necesitamos
    // retirarla de los puntos calientes
    if _, exist := hotPoints[ s.topRight ]; exist {
      delete( hotPoints, s.topRight ) // quitamos el elemento
      next = &s.topRight              // la siguiente celda a la derecha

      // si aun no hemos cambiado de fila, la siguiente celda deberia
      // estar (o no) a la derecha de la celda actual.
      // comprobamos si es asi
    } else if g.visit( s.topRight.nmv( RIGHT ) ) == HEDGE {
      next = &s.topRight

      // llegamos al final de la fila, veamos cual es la celda con la posicion
      // (fila y columna) mas arriba a la izquierda
    } else {
      // regresa dicha posicion y la quita del mapa de puntos calientes
      next = pullNextPoint( hotPoints )

      // si ya no hay puntos calientes, agregamos la ultima fila a la tabla
      if next == nil { rows = append( rows, row) }
    }
  }

  // se ordenan los mapas con las ubicaciones de todos los bordes en la tabla
  xS, yS :=  mapToSortIntArray(xEdges), mapToSortIntArray(yEdges)

  // ya analizada y ordenada la tabla, solo resta la exportacion
  return tableToHtml( rows, xS, yS )
}
```

```

func tableToHtml( table [][]*cell, xS, yS []int ) string {
  buf := new( bytes.Buffer )  // un buffer para hacerlo mas eficiente

  fmt.Fprintf( buf,  "<table border=\"1\">\n" )

  // ciclo por las filas
  for _, row := range table {
    fmt.Fprintf( buf, "<tr>" )

    // ciclo por las columnas
    for _, cell := range row {
      fmt.Fprintf( buf, "<td" )
      // ver el funcionamiento de rangeCells en el post anterior!
      if colspan := rangeCells(cell.x, cell.x2, xS); colspan != 1 {
        fmt.Fprintf( buf, " colspan=\"%d\"", colspan )
      }
      if rowspan := rangeCells(cell.y, cell.y2, yS); rowspan != 1 {
        fmt.Fprintf( buf, " rowspan=\"%d\"", rowspan )
      }
      // la celda en si, SpaceSwap es una conveniencia para hacer las pruebas
      // sin hacer demaciados escapes de \n, \" y espacios
      fmt.Fprintf( buf, "><p>%s</p></td>", SpaceSwap( cell.data, " " ) )
    }

    fmt.Fprintf( buf, "</tr>\n" )
  }
  fmt.Fprintf( buf, "</table>\n" )

  return buf.String()
}
```

por ultimo el misterioso codigo para conocer cual es la celda mas a la izquierda
y arriba en el mapa de puntos calientes

```
func pullNextPoint( m map[point]bool ) *point {
  if len( m ) == 0 { return nil }

  n := point{}
  // para establecer un valor inicial de comparacion util
  for key, _ := range m {
    n = key
    break
  }

  for key, _ := range m {
    // si la cerda esta mas arriba va primero
    if key.y < n.y {
      n = key

    // si estan en la misma fila, pero es una columna anterior
    // va primero
    } else if key.y == n.y && key.x < n.x  {
      n = key
    }
  }

  delete( m, n ) // saca el siguiente elemento
  return &n      // regresa el siguiente elemento
}
```

y listo, sin miles de lineas ni (demaciadas) complejidades inecesarias (cof, cof
puñetero ~~y apestoso, apestoso~~ codigo python de reStructuredText)

el codigo fuente completo tiene mucha calderilla auxiliar conveniente
(sobre todo del paquete `github.com/nasciiboy/txt`). Lo coloque directamente
para evitar dependencias inecesarias para el ejemplo, su comprension/mejora
queda a modo de reto personal...

happy hacking!
