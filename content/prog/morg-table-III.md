+++
title      = "TextTable2HtmlTable (Volume Three)"
tags       = [ "morg" ]
categories = [ "prog" ]
date       = 2018-01-15T14:31:33-06:00
+++

<center>
![](/img/jb130510.jpg)
</center>

## o, como "parsear" una tabla en texto plano para convertirla en una tabla html (u otra cosa) y escribir tres post sobre ello con explicaciones cripticas (+ codigo de ejemplo en Golang) – Tercera Parte "Conclucion"

finalizando con "la saga" de post mal escritos, en la [entrega
anterior](../morg-table-ii/) se mostro el metodo de analizar la tabla en texto
plano como un conjunto de cuadrilateros "con contorno" enviando un emisario al
punto 0,0 (y,x) de la cuadricula.

En esta ocacion se ha preparado el codigo como una especie de simulacion de lo
que seria un paquete "serio"... sin probar en un campo real y por ello
posiblemente cuente con carencias aberrantes, pero como antes mencione, cuando
lo incorpore al proyecto morg, dificil sera aplicarlo en otro proyecto sin
intercepcion de por medio, ademas colocarlo aqui servira de testigo si quiero
saber como era el concepto inicial

la interfaz al usuario se limita a ver unas cuantas constantes (que no puede
usar ni modificar), dos funciones y dos estructuras (todas sin documentacion alguna)
(`go doc`):

```
const RIGHT = iota ...
const CORNER = '+'
const HEDGE  = '-'
const HEDGEF = '~'
const HEDGEH = '='
const OUTSIDE = '\uFFFD'
const VEDGE = '|'
func TextTable2HtmlTable(data string) (string, error)
type Cell struct{ ... }
type Table struct{ ... }
    func Text2Table(txtTable string) (t Table, e error)
```

las funciones regresan errores (algo cripticos) y las tablas pueden dividirse con un
encabezado, cuerpo y "pie". Una funcion (`Tex2Table`) convierte el texto en una
tabla (`Table`)  procesada de celdas (`Cell`) y la otra (`TextTable2HtmlTable`)
entrega una tabla en formato html apartir de su entrada en texto plano.

Un ejemplo de tabla seria:

    +-------------------------------------------------+
    | una tabla realmente dificil de dibujar a mano   |
    +------+----+----+----+---------------------------+
    |  jo  | jo | jo | jo | y mas jos como encabezado |
    +======+====+====+====+====+======================+
    |             a            |          b           |
    +------------------+-------+------+---------------+
    |        c         |   d   |  e   |               |
    +--------+---------+-------+------+      f        |
    |   g    |      h                 |               |
    +--------+--+----------------+----+-+-------------+
    |           |        j       |      |             |
    |  i        +--------+-------+   k  |      l      |
    |           |    m   |   n   |      |             |
    +~~~~~~~~~~~+~~~~~~~~+~~~~~~~+~~+~~~+~~~~~~~~~~~~~+
    |      con un pie de pagina     |   o algo asi    |
    +-------------------------------+-----------------+



que produce:

```
<table border="1">
<thead>
  <tr><th colspan="13"><p> una tabla realmente dificil de dibujar a mano </p></th></tr>
  <tr><th><p> jo </p></th><th colspan="2"><p> jo </p></th><th><p> jo </p></th><th colspan="3"><p> jo </p></th><th colspan="6"><p> y mas jos como encabezado </p></th></tr>
</thead>
<tbody>
  <tr><td colspan="8"><p> a </p></td><td colspan="5"><p> b </p></td></tr>
  <tr><td colspan="5"><p> c </p></td><td colspan="3"><p> d </p></td><td colspan="3"><p> e </p></td><td colspan="2" rowspan="2"><p> f </p></td></tr>
  <tr><td colspan="2"><p> g </p></td><td colspan="9"><p> h </p></td></tr>
  <tr><td colspan="3" rowspan="2"><p> i </p></td><td colspan="6"><p> j </p></td><td colspan="3" rowspan="2"><p> k </p></td><td rowspan="2"><p> l </p></td></tr>
  <tr><td colspan="3"><p> m </p></td><td colspan="3"><p> n </p></td></tr>
</tbody>
<tfoot>
  <tr><td colspan="10"><p> con un pie de pagina </p></td><td colspan="3"><p> o algo asi </p></td></tr>
</tfoot>
</table>
```

y se ve (sin css por medio) asi:

<table border="1">
<thead>
  <tr><th colspan="13"><p> una tabla realmente dificil de dibujar a mano </p></th></tr>
  <tr><th><p> jo </p></th><th colspan="2"><p> jo </p></th><th><p> jo </p></th><th colspan="3"><p> jo </p></th><th colspan="6"><p> y mas jos como encabezado </p></th></tr>
</thead>
<tbody>
  <tr><td colspan="8"><p> a </p></td><td colspan="5"><p> b </p></td></tr>
  <tr><td colspan="5"><p> c </p></td><td colspan="3"><p> d </p></td><td colspan="3"><p> e </p></td><td colspan="2" rowspan="2"><p> f </p></td></tr>
  <tr><td colspan="2"><p> g </p></td><td colspan="9"><p> h </p></td></tr>
  <tr><td colspan="3" rowspan="2"><p> i </p></td><td colspan="6"><p> j </p></td><td colspan="3" rowspan="2"><p> k </p></td><td rowspan="2"><p> l </p></td></tr>
  <tr><td colspan="3"><p> m </p></td><td colspan="3"><p> n </p></td></tr>
</tbody>
<tfoot>
  <tr><td colspan="10"><p> con un pie de pagina </p></td><td colspan="3"><p> o algo asi </p></td></tr>
</tfoot>
</table>

pasemos a [el codigo](/data/table3.go) (guardar-como) (las pruebas
por [aca](/data/table3_test.go), un `go test -v` en una carpeta sin otro codigo go):

```
package katana


// importaciones estandar sin cosas raras
import (
  "fmt"
  "sort"
  "bytes"
  "errors"
)

// constantes que se pueden modificar sin mucho problema para
// alterar el aspecto de una tabla
const OUTSIDE = '\uFFFD' // unicode.RuneError = '\uFFFD'
const CORNER  = '+'      //  +----+     //  +--------+-----+--------+
const VEDGE   = '|'      //  |    |     //  | header       |  Yhee! |
const HEDGE   = '-'      //  +----+     //  +========+=====+========+
                                        //  | body-A | B   |   C    |
                                        //  +~~~~~~~~+~~~~~+~~~~~~~~+
const HEDGEH  = '='  // h == head       //  | Yhak!  |    footer    |
const HEDGEF  = '~'  // f == foot       //  +--------+-----+--------+


// convierte una tabla en texto plano (perfectamente entregada) en una estructura
// con los datos procesados, o entrega un error
func Text2Table( txtTable string ) (t Table, e error) {
  // se convierte la cadena de entrada en una cuadricula de runas
  runeTable := gridify( txtTable )
  // si no hay cuadricula, la cadena de entrada no tenia nada
  if runeTable == nil { return t, errors.New( "empty input" ) }

  // buscamos si existe un divisor de encabezado y pie en la tabla
  var yHead, yFoot int = 0, -1 // valores magicos de inicio
  for y, row := range runeTable {
    // si la fila es un encabezado
    if isHead( row ) {
      if yHead ==  0 {
        yHead = y
      // no puede haber mas de un encabezado
      } else { return t, fmt.Errorf( "there can only be one header, repetition in row %d", y ) }
    }
    // si la fila es un pie
    if isFoot( row ) {
      if yFoot == -1 {
        yFoot = y
      // no puede haber mas de un pie
      } else { return t, fmt.Errorf( "there can only be one footer, repetition in row %d", y ) }
    }
  }

  // se normalizan las columnas de encabezado y pie para simplificar el
  // analisis de contornos
  if yHead !=  0 { normalizeRuneTableRow( runeTable, yHead ) }
  if yFoot != -1 { normalizeRuneTableRow( runeTable, yFoot ) }

  // -----> basicamente lo mismo que en el post anterior con algun cambio poco interesante
  g         := new( grid ).init( runeTable )
  rows      := make( [][]*quad, 0, 10 )
  row       := make(   []*quad, 0,  5 )
  hotPoints := make( map[point]bool )
  xEdges, yEdges := map[int]bool{ 0: true }, map[int]bool{ 0: true }

  for next, y := new(point), 0; next != nil;  {
    s := g.newQuad(*next)

    if e = s.tourist(); e != nil {
      return t, fmt.Errorf( "square.tourist: %v", e )
    }

    xEdges[ s.cornerC.x ] = true
    yEdges[ s.cornerA.y ] = true

    if y != s.cornerD.y {
      rows = append( rows, row)
      row  = make( []*quad, 0, 5 )
      y    = s.cornerD.y
    }

    row = append( row, s )

    if g.visit( s.cornerA.nmv( DOWN ) ) == '|' {
      hotPoints[ s.cornerA ] = true
    }

    if _, exist := hotPoints[ s.cornerC ]; exist {
      delete( hotPoints, s.cornerC )
      next = &s.cornerC
    } else if g.visit( s.cornerC.nmv( RIGHT ) ) == '-' {
      next = &s.cornerC
    } else {
      next = pullNextPoint( hotPoints )

      if next == nil { rows = append( rows, row) }
    }
  }
  // <--------------


  xS, yS :=  mapToSortIntArray(xEdges), mapToSortIntArray(yEdges)
  // internamente se utiliza una estructura para las celdas con
  // paremetros irrelevantes para la interfaz final, asi que se
  // copian a la estructura final
  table := make( [][]Cell, len( rows ) )
  for y, row := range rows {
    table[y] = make([]Cell, len( row ) )
    for x, q := range row {
      table[y][x].rowspan = rangeCells( q.cornerD.y, q.cornerA.y, yS )
      table[y][x].colspan = rangeCells( q.cornerD.x, q.cornerB.x, xS )
      table[y][x].data    = cutCellTxt( g.data, q.cornerD, q.cornerB )
    }

    // estos dos ifs son para identificar cuales filas pertenecen al
    // encabezado o pie (si existen), ademas se asignan al mismo tiempo.
    // De lo contrario, la seccion de la tabla (encabezado, cuerpo o pie)
    // es un "nil"
    if yHead != 0 && (row[0].cornerA.y == yHead) {
      yHead  = y + 1
      t.Head = table[:yHead]
    }
    if yFoot != -1 && (row[0].cornerD.y == yFoot) {
      yFoot  = y
      t.Foot = table[yFoot:]
    }
  }
  // la asignacion del cuerpo
  if yFoot == -1 { yFoot = len( table ) }
  if yFoot - yHead > 0 { t.Body = table[yHead:yFoot] }

  return
}

// la tabla en si [fila][celda]
type Table struct {
  Head [][]Cell
  Body [][]Cell
  Foot [][]Cell
}

// la celda, con informacion de cuantas columnas y filas abarca
// y el texto "rectangular" que contiene
type Cell struct {
  colspan, rowspan int
  data string
}
```

jo, la funcion principal quedo bastante extensa, lo cual no es bueno para hacer
pruebas... pero creo que esto facilita entender el flujo del programa sin saltar
de un lado a otro del codigo. Es cierto que puede dividirse en fragmentos con un
nombre apropiado e incluso colocarlos con un orden descendente, ¡pero! pasar
parametros de un lado a otro no me entusiasma demaciado, tampoco hacer una
estructura mas que tenga dichos datos con metodos (para evitar la copia de parametros)

La funcion que optiene y genera el formato html creo me ha quedado bastante
estetica y compacta, considerando el numero de acciones que realiza


```
// en lugar de tener tres funciones distintas segun la seccion
// de la tabla a imprimir, utilizo un truco con estos dos arreglos
var zs = [3]string{ "thead", "tbody", "tfoot" }
var ys = [3]string{    "th",    "td",    "td" }

// la funcion que convierte directamente de texto a html
func TextTable2HtmlTable( data string ) (string, error) {
  t, e := Text2Table( data ) // se optiene la tabla procesada
  // si hubo un errror se informa
  if e != nil { return "", fmt.Errorf( "Text2Table: %v", e ) }

  buf := new( bytes.Buffer ) // un buffer por eficiencia
  fmt.Fprintf( buf,  "<table border=\"1\">\n" )

  // aqui se itera sobre las tres secciones de la tabla
  // el indice es para el truco antes mencionado
  for i, sec := range [3][][]Cell{ t.Head, t.Body, t.Foot } {
    if sec == nil { continue } // si esta vacia la seccion se pasa a la siguiente

    fmt.Fprintf( buf,  "<%s>\n", zs[i] )  // abre la seccion
      for _, row := range sec {           // bucle por la seccion, genera las filas
        buf.WriteString( "  <tr>" )       // imprime la etiqueta de fila
        for _, cell := range row {        // bucle por la fila, genera las celdas
          fmt.Fprintf( buf, "<%s", ys[ i ] )
          if cell.colspan != 1 { fmt.Fprintf( buf, " colspan=\"%d\"", cell.colspan ) }
          if cell.rowspan != 1 { fmt.Fprintf( buf, " rowspan=\"%d\"", cell.rowspan ) }
          fmt.Fprintf( buf, "><p>%s</p></%s>", SpaceSwap( cell.data, " " ), ys[ i ] )
        }
        buf.WriteString( "</tr>\n" )      // se cierra la fila
      }
    fmt.Fprintf( buf,  "</%s>\n", zs[i] ) // se cierra la seccion
  }

  fmt.Fprintf( buf, "</table>\n" )        // termina la tabla

  return buf.String(), nil
}
```

y listo, el resto es calderilla!

por implementar, en este punto seria un juego hacer el exportador a digamos,
algun hijo de TeX, lo que si sera duro, es hacer un conversor tabla a texto y
algo complejo tambien un analizador de la orientacion del texto para agregar
estos datos a la tabla (centrado, a la izquierda a la derecha)

por otro lado tambien sienta una buena base para generar tablas (o umls) como
imagenes o svgs, incluso un analizador de ascii a un dibujo o cosas por el
estilo... un buen proyecto para alguien sin ideas...

happy hacking!
