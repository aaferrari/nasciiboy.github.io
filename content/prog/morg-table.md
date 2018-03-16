+++
title      = "TextTable2HtmlTable (Volume One)"
tags       = [ "morg" ]
categories = [ "prog" ]
date       = 2017-12-15T20:02:05-06:00
draft      = false
+++

<center>
![](/img/mikoto.jpg)
</center>

## o, como "parsear" una tabla en texto plano para convertirla en una tabla html (u otra cosa) (+ codigo de ejemplo en Golang)

convertir una tabla como

```
|---------------------------------------------------------------------|
| MiTabla Fila  1 | De Creacion           | Estructurales             |
|-----------------|-----------------------|---------------------------|
| MiTabla Fila  2 | De Creacion           | Estructurales             |
|-----------------|-----------------------|---------------------------|
| MiTabla Fila  3 | De Creacion           | Estructurales             |
|-----------------|-----------------------|---------------------------|
```

es decir, con un numero de "celdas" siempre constante, a pesar de tener su
complejidad, es relativamente sencillo el programar unas cuantas funciones sin
tener mucha idea y lograr convertirla en cualquier otro formato, por ejemplo (y
por conveniencia) HTML

sin embargo, como demonios *parsear* (*analizar*) algo como (de ahora en
adelante **estilo A**)


```
|                            Proposito                                |
|---------------------------------------------------------------------|
|                 | De Creacion           | Estructurales             |
|-----------------|-----------------------|---------------------------|
| Ambito | Clase  | @l(#Factory Method)   | @l(#Adapter) (de clases)  |
|        |        |-----------------------|---------------------------|
|        |        |     nenteot           | @l(#Builder)              |
|        |        |  @l(#Bonlder)         |                           |
|        |--------|-----------------------|---------------------------|
|        | Objeto | @l(#Abstract Factory) | @l(#Adapter) (de objetos) |
|        |        |-----------------------|---------------------------|
|        |        | @l(#Beuuuua)          | @l(#Bridge)               |
|        |        |-----------------------|---------------------------|
|        |        |                       | @l(#Flyweight)            |
|        |        |-----------------------|---------------------------|
|        |        |                       | @l(#Proxy)   | kas        |
|--------|--------|-----------------------|--------------|------------|
```

esta tabla, a simple vista mas compleja, delimita sus celdas mediante signos
"tuberia" al inicio y fin, y sus bordes por tuberias y "menos" (`|----|`), pero
manteniendo todas las filas con una longitud constante. Sin embargo cada celda,
puede abarcar una longitud (relativa a las columnas de al rededor) arbitraria
tanto en altura como en anchura

pero antes de continuar veamos un ejemplo de sintaxis de tablas alternativo, el
que utiliza reStructuredText (**estilo B**)

```
+---------------------------------------------------------------------+
|                            Proposito                                |
+-----------------+-----------------------+---------------------------+
|                 | De Creacion           | Estructurales             |
+-----------------+-----------------------+---------------------------+
| Ambito | Clase                          | @l(#Adapter) (de clases)  |
|        |                                +---------------------------+
|        |                                | @l(#Builder)              |
|        |                                |                           |
|        +--------+-----------------------+---------------------------+
|        | Objeto | @l(#Abstract Factory) | @l(#Adapter) (de objetos) |
|        |        +-----------------------+---------------------------+
|        |        | @l(#Beuuuua)          | @l(#Bridge)               |
|        |        +-----------------------+---------------------------+
|        |        |                       | @l(#Flyweight)            |
|        |        +-----------------------+--------------+------------+
|        |        |                       | @l(#Proxy)   | kas        |
+--------+--------+-----------------------+--------------+------------+
```

bastante distinto, he!?, la mayor diferencia, son las intercecciones de las
celdas, que facilitan un poco el analisis de la tabla, al hacer explicitos
dichos simbolos, ademas de dejar de forma explicita cuando un signo tuberia es
una division, pues en sus margenes va acompañada por los "mas" (`+`). Obviamente donde
este conjunto no este emparejado, las tuberias serian solo parte del texto plano

y pasemos a un ejemplo mas de sitaxis (**estilo C**), solo por que si y para
que dudes de tu existencia, si logras captar las obcuras sutilesas de su construccion

```
|                            Proposito                                |
|---------------------------------------------------------------------|
|                 | De Creacion           | Estructurales             |
|---------------------------------------------------------------------|
| Ambito | Clase                          | @l(#Adapter) (de clases)  |
|        |                                |---------------------------|
|        |                                | @l(#Builder)              |
|        |                                |                           |
|        |------------------------------------------------------------|
|        | Objeto | @l(#Abstract Factory) | @l(#Adapter) (de objetos) |
|        |        |---------------------------------------------------|
|        |        | @l(#Beuuuua)          | @l(#Bridge)               |
|        |        |---------------------------------------------------|
|        |        |                       | @l(#Flyweight)            |
|        |        |---------------------------------------------------|
|        |        |                       | @l(#Proxy)   | kas        |
```

bien? pues olvida todo lo que sabes y desconoces, por que aqui coloco mi solucion
(sin tener idea) para el estilo de tabla **A**

primero, consideremos que las tablas (HTML) son simplemente un metodo para
dibujar mosaicos rectangulares con texto (o algo), asi que deberiamos averiguar
las posiciones de inicio y fin de cada celda rectangular

la segunda consideracion y que es la que toma html, es averiguar cuantas
casillas abarca cada celda tanto de largo como de alto... ademas de su aparicion
secuencial (de derecha a izquierda) "por filas"

como ya sabemos que una tabla no dejan de ser dibujos de cuadrados, podriamos
enviar un emisario a la posicion 0,0 de la tabla en texto plano e identificar el
primer cuadrado, luego buscar un segundo cuadrado en la misma primer fila,
cerrarla, abrir una nueva fila y seguir asi hasta terminar, para finalmente establecer el
tamaño de la celda mas pequeña, y conforme a esta, establecer la dimencion de
todas las demas... o ir por un camino mas escabroso donde las celdas pueden
tener tablas internas, y estas a su ves tablas internas, ..., hasta el infinito

no podria ser mas sencillo, pero como de momento no tengo idea de como hacer un
*automata segidor de contornos rectangulares* (con "codigo elegante"), voy a
proceder de una forma menos sofisticada dividendo toda la tabla en filas y estas a
su vez en segmentos, averiguando donde estan las intercecciones de cada celda,
para con ello asignar las dimenciones de las celdas una ves identifique sus
valores, o, algo asi!

primero debemos dividir nuestra tabla por lineas y segmentos

aqui esta la funcion que divide un string por sus lineas en un slice de
strings. Si, esto puede hacerse directamente con la libreria estandar de Go, pero el
comportamiento su comportamiento no me termina de convencer

```
func GetLines( str string ) []string {
  result := make( []string, 0, 64 )
  last := 0;
  for i, c := range str {
    if c == '\n' {
      result = append( result, str[last:i] )
      last = i + 1
    }
  }

  if last < len( str ) { result = append( result, str[last:] ) }

  return result
}
```

aqui estan las estructuras base sobre las que gira el codigo

```
const (
  cText = 0
  cEdge = '-'
)

type Rect  struct { y, x, y2, x2 int }
type Sec   struct { a, b, t int }
type Mikoto []Sec
```

`Rect` sera el inicio y fin de nuestra celda rectangular... puedes cambiar el
nombre, je, je, je, estos son los detalles que se presentan cuando vas
descubriendo a base de prueba y error como hacer algo nuevo. `Sec` sera un
segmento de cada linea que representa el punto de inicio (`a`) y fin (`b`) de
cada uno, `t` es el tipo del segmento (o texto (`cText`) o un
divisor (`cEdge`)). Finalmente `Mikoto` es un arreglo de segmentos, que vedrian a
conformar la linea ya analizada, por que `Mikoto`? por una obscura referecia
hilarante a nivel personal, que nada tiene que ver con buenas metodologias de
programacion, aunque, como es mi maldito codigo, creo que imprimir el estilo "de la
casa" es cuando menos una forma de hacerlo divertido. Por cierto, lo de nombrar
los tipos con su primer letra en mayuscula, mas que por temas de exportacion
fuera del paquete, lo hago para poder crear tipos locales con el mismo nombre
pero en minuscula (asi: `var rect Rect`).

mmm, todo este rollo de codigo esta dentro de dos ficheros lo que trato de
explicar aqui esta en [table.go](/data/table.go) y aulgunas (insuficientes) pruebas en
[table_test.go](/data/table_test.go). Colocalas dentro de una carpeta sin otro
codigo, y ejecuta con `go test`

a partir de este momento, el codigo fuera de cualquier funcion, es parte de la
funcion principal `func TextTable2HtmlTable( data string ) string`, el demas
vendra correctamente dentro de su funcion correspondiente. Inicio >

```
lines := GetLines( data )
mikotos := make( []Mikoto, 0, 5 )
for _, l := range lines {
  mikotos = append( mikotos, scissors(l) )
}
```

ok, paso a dividir la cadena de entrada (la tabla) en lineas, para despues crear un slice
`mikotos` de `Mikoto`, recordemos que `Mikoto` es la representacion segmentada
de cada linea, y este slice, vendria a ser toda la tabla segmentada por filas y
en estas en segmentos. Asi pues, inicio un bucle enviando cada linea al
segmentador `scissors` (tijeras) y agrego esta linea segmentada en un indice del
slice `mikotos`

asi se ve `scissors`

```
func scissors( line string ) []Sec {
  secs, sec := make( []Sec, 0, 5 ), Sec{}

  for x := 1; x < len( line ); x++ {
    switch line[x] {
    case cEdge: x += skipSep ( line[x:] ); sec.t = cEdge
    default   : x += skipText( line[x:] ); sec.t = cText
    }

    sec.b = x
    secs = append( secs, sec )
    sec.a = x
  }

  return secs
}
```

se declara un slice (`secs`) que sera regresado con los segmentos de la linea de entrada,
y tambien un segmento (`sec`) que tendra el segmento actual (con los valores de inicio,
fin y tipo

se inicia el ciclo por la linea, el numero magico *1* es para esquivar el `|` al
inicio de la linea, por supuesto se asume que los datos de entrada son
correctos...

Luego se averigua con el `switch` si tenemos o un segmento de texto o de
separacion y se procede a averiguar su longitud y establecer su tipo. Despues
agregamos el segmento actual dentro del slice, y, repetimos el bucle una y otra
vez, hasta llegar al final de la linea. Pon atencion a como (no) se establece el
punto de inicio del primer bucle, ademas de prepararlo para el siguiente

las funciones para averiguar los limites del segmento son

```
func skipSep( data string ) int {
  for i, c := range data {
    switch c {
    case cEdge: continue
    case '|'  : return i
    }
  }

  return len(data)
}

func skipText( data string ) int {
  for i, c := range data {
    switch c {
    case '|': return i
    default: continue
    }
  }

  return len(data)
}
```

basicamente se limitan a encontrar el primer `|` que aparesca, pero, tienen su
propia funcion para (en un futuro) agregar distintos tipos de separadores, por
ejemplo encabezado y fondo de la tab!a, o, tambien para afinar la busqueda de
los limites

continuando con la funcion principal tenemos

```
ncol, nrow := mikotosToEdgeCells(mikotos)
```

te preguntaras, he? sin panico, brother, ya que tenemos la tabla completamente
segmentalizada, no es necesario iterar de nuevo directamente sobre el string de
texto, tenemos un primer grado de abstraccion y podemos ahorrar bastante
iterando con este, en lugar de volver a hacerlo sobre los datos en bruto. Lo que
hace la siguiente funcion es averiguar donde estan los margenes de inicio y fin
de cada celda y con ellos asignar mas adelante las dimenciones "en celdas" de
cada rectangulo

La idea es esta: nuestras celdas tienen una longitud variable, pero su longitud
se mide en base de las celdas que cruza, mas que por su longitud "en
caracteres"


```
 0  5    15 2022      45  50  55
 ^  ^    ^  ^ ^       ^   ^   ^
 ______________________________
 |1_|_2__|__3_|___4___|_5_|_3_|  A
 |1_|_2__|3_|4|___5___|_6_|_7_|  B
 |1_|____2____|___4___|___5___|  C

    a<--C2--->b  = 3
    |         |
    5         22
```

anotamos los bordes de las celdas de todas las filas, segun la posicion
donde aparecen, por ejemplo para este caso seria 0, 5, 15, 20, 22, 45, 50
y 55

Dados los puntos de inicio y fin de una celda particural, podemos averiguar su
longitud, considerando el resto de celdas, hemmm, por ejemplo, tomando de la
fila C la columna 2, esta abarca las intercepcionens que van desde 5 a 22, que
en este caso serian 3 celdas (las tres de las celdas 2, 3 y 4 de la fila B). Si
aplicamos esto a la fila A celda 3, abarcaria 2 celdas, las dos de la fila B (3
y 4). Para otras celdas que mantienen su alineacion con respecto a todas las
demas, su longitud (en celdas) seria 1.

Anotando todas las intercepciones y luego iterando sobre estas, podemos averiguar
cuantas celdas "toca" un rango arbitrario. Ya que la orientacion de estas
intercepciones solo esta en nuestra mente, se aplicara tanto para filas como
columnas indistintamente.

La funcion encargada de lograr tal proeza esta aqui

```
func mikotosToEdgeCells( mikotos []Mikoto ) (c, r []int){
  cols,    rows   := make( map[int]bool ), make( map[int]bool )
  cols[0], rows[0] = true, true

  for y, mikoto := range mikotos {
    for _, sec := range mikoto {
      if _, set := cols[sec.b]; !set { cols[sec.b] = true }
      if _, set := rows[y]; sec.t == cEdge && !set { rows[y] = true }
    }
  }

  return mapToSortIntArray(cols), mapToSortIntArray(rows)
}
```

consta de dos mapas *hash*, uno para las columnas y otro para las filas, como ya
sabemos que deben iniciar en el punto 0, lo asignamos directamente, para el
resto solo debemos iterar sobre las filas segmentalizadas anotando donde estan
los bordes de las celdas: para las columnas seria el fin del segmento y para las
filas la aparicion de un segmento de borde. La consulta de existencia en el mapa
es opcional, pero recomendable. Utilizamos un mapa para evitar una iteracion sin
sentido por un arreglo de n elementos y n consultas

una ves terminado el bucle, podemos ordenar los puntos de intercepcion en un
arreglo de enteros

```
func mapToSortIntArray( m map[int]bool ) []int {
  arry, i := make([]int, len( m )), 0
  for key := range m { arry[i] = key; i++ }
  sort.Ints( arry )
  return arry
}
```

ahora, para la funcion que se encarga de contabilizar cuantos segmentos toca un
rango dado, pasariamos el arreglo (de filas o columnas) y el segmento en si

```
func rangeCells( a, b int, cells []int ) int {
  min := 0
  for min < len( cells ) && a > cells[ min ] { min++ }
  max := min
  for max < len( cells ) && b > cells[ max ] { max++ }

  if min == max {
    return 1
  } else if a < cells[min] {
    return max - min + 1
  }

  return max - min
}
```

si, un bucle poco elgante, pero mis conocimientos no dan para mas, preguntar en
reddit tampco sirvio de mucho. Sospecho que es carne para matemagicos que no
andan por internet... y que el nivel de los programadores "en general" es penoso
(como el mio)

momento de pasar a donde se concentra toda la magia

```
alive := make( map[int]*Rect )
type Rows []*Rect
var rows []Rows
var cRow Rows
for y, mikoto := range mikotos {
  cRow = nil

  for _, sec := range mikoto {
    switch sec.t {
    case cEdge:
      alive[sec.a].y2 = y - 1
      delete( alive, sec.a )
    default:
      if _, live := alive[sec.a]; !live {
        p := &Rect{ y: y, x:sec.a, x2:sec.b }
        cRow = append( cRow, p )
        alive[sec.a] = p
      }
    }
  }

  if cRow != nil { rows = append( rows, cRow) }
}
```

esto es un bucle por nuestra tabla segmentalizada. En concepto revisamos fila a
fila anotando cada secmento que no teniamos previamente dentro de nuestra
fila actual (`cRow` (currentRow)) y abriendo una lista de rectangulos sin
cerrar (`alive`).

Si el segmento forma parte de un segmento "vivo" lo ignoramos, y si encontramos
un segmento de cierre que encaja con uno vivo, lo cerramos y matamos.

El correcto orden de apertura de cada nueva fila dentro de la lista global de
rectangulos por filas (`rows`) se logra con la variable `cRow`, que se reinicia
en cada iteracion por las filas y solo se incluye si aparecio un rectangulo
nuevo. El punto magico-mistico y misterioso, ademas de razon de la sincronia de
los cierres en la estructura de filas global (`rows`) viene dado por el uso de
puenteros, sip! magicos punteros. Seguramente no encuentres este codigo muy
claro, pero dale vueltas, para mi no estaba disponible algo
asi... bueno, si. algo en python (un lenguaje al que le tengo mania, en el peor
sentido de la palabra) y que tenia una muy, muy, muy rara implementacion de
algunos miles de lineas indecifrables en mi ignorancia

Para finalizar, ya con nuestros rectangulos organizados, solo resta imprimir la
tabla y averiguar su longitud con respecto a otros rectangulos, con la
anteriormente expuesta `rangeCells`

```
buf := new( bytes.Buffer )
fmt.Fprintf( buf,  "<table border=\"1\">\n" )

for _, rl := range rows {
  fmt.Fprintf( buf, "<tr>" )

  for _, rect := range rl {
    fmt.Fprintf( buf, "<td" )
    if colspan := rangeCells(rect.x, rect.x2, ncol); colspan != 1 {
      fmt.Fprintf( buf, " colspan=\"%d\"", colspan )
    }
    if rowspan := rangeCells(rect.y, rect.y2, nrow); rowspan != 1 {
      fmt.Fprintf( buf, " rowspan=\"%d\"", rowspan )
    }
    fmt.Fprintf( buf, ">%s</td>", rectToString(rect, lines) )
  }

  fmt.Fprintf( buf, "</tr>\n" )
}

fmt.Fprintf( buf, "</table>\n" )
return buf.String()
```

el texto de cada celda se optiene con

```
func rectToString( rect *Rect, lines []string ) string {
  s := "<p>"
  for y := rect.y; y <= rect.y2; y++ {
    s += lines[y][rect.x+1:rect.x2]
  }
  s += "</p>"
  return s
}
```

que se alimento de nuestro anteriormente usado slice con lineas

## Epilogo

El problema es por demas complejo (o lo es para este subnormal que escribe), sin
embargo, tengo la firme creencia de que si podemos enterder un concepto (aun sin
poder explicar el como), con mucho, mucho, mucho estudio e insintencia, podemos
ser capaces de codificarlo y quiza tras muchas iteraciones optener un codigo
elegante.

Si podemos decifrar su informacion, es porque la informacion esta hay,
simplemente ignoramos los mecanismos de nuestra mente

Este no deja de ser un primer acercamiento a este problema, por ello la solucion
dista bastante de algo util en la vida real. Aun queda por implementarlo para
tablas que no sean solo de caracteres de ancho fijo, como en codificacion
unicode, resolver el dilema de escapes de las tuberias que debieran ser solo
texto, tablas no alineadas, fijar la sistaxis en general, examinar la alineacion
del texto sin mas datos que el texto en si, y otros puntos mas que aun no
contemplo, pero eso sera para otras sesiones de buena musica, mientras veo
fijamente el montor con un semblante serio

ho, ho, ho, como tengo ganas de implementarlo en la siguiente iteracion de morg,
aunque en el transcurso de leer sobre patrones de diseño, seguro que nuevas
modificaciones se hacen presentes, ademas, adaptar esto y otras ideas sobre el
parseo a texto rectangular, llebaran una labor de revision fina, fina!

happy hacking!
