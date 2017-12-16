package katana

import (
  "fmt"
  "sort"
  "bytes"
)

const (
  cText = 0
  cEdge = '-'
)

type Rect  struct { y, x, y2, x2 int }
type Sec   struct { a, b, t int }
type Mikoto []Sec

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


func TextTable2HtmlTable( data string ) string {
  lines := GetLines( data )
  mikotos := make( []Mikoto, 0, 5 )
  for _, l := range lines {
    mikotos = append( mikotos, scissors(l) )
  }

  ncol, nrow := mikotosToEdgeCells(mikotos)

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
}

func rectToString( rect *Rect, lines []string ) string {
  s := "<p>"
  for y := rect.y; y <= rect.y2; y++ {
    s += lines[y][rect.x+1:rect.x2]
  }
  s += "</p>"
  return s
}

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

func mapToSortIntArray( m map[int]bool ) []int {
  arry, i := make([]int, len( m )), 0
  for key := range m { arry[i] = key; i++ }
  sort.Ints( arry )
  return arry
}

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
