package katana

import (
  "fmt"
  "sort"
  "bytes"
)

const OUTSIDE = '\uFFFD' // unicode.RuneError = '\uFFFD'
const CORNER  = '+'  //  +----+
const VEDGE   = '|'  //  |    |
const HEDGE   = '-'  //  +----+

type cell struct {
  y, x, y2, x2 int
  data string
}

type grid struct {
  data [][]rune
  w, h int
}

func (g *grid) init( data string ) *grid {
  g.data = gridify( data )
  g.h = len( g.data )
  if g.h > 0 {
    g.w = len( g.data[0] )
  } else { g.w = 0 }

  return g
}

func (g *grid) visit( p point ) rune {
  if p.x < 0 || p.y < 0 || p.x >= g.w || p.y >= g.h ||
     g.h < 1 || g.w < 1 {
    return OUTSIDE
  }

  return g.data[p.y][p.x]
}

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

type square struct {
  topLeft, topRight, bottomLeft, bottomRight point
  *grid
}

func (g *grid) newSquare( p point ) *square {
  return &square{ grid: g, topLeft: p }
}

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

func TextTable2HtmlTable( data string ) string {
  g := new( grid ).init( data )
  xEdges, yEdges := map[int]bool{ 0: true }, map[int]bool{ 0: true }

  rows := make( [][]*cell, 0, 10 )
  row  := make(   []*cell, 0,  5 )

  hotPoints := make( map[point]bool )

  for next, y := new(point), 0; next != nil;  {
    s := g.newSquare(*next)
    s.tourist()

    xEdges[ s.topRight.x   ] = true
    yEdges[ s.bottomLeft.y ] = true

    if y != s.topLeft.y {
      rows = append( rows, row)
      row = make( []*cell, 0, 5 )
      y = s.topLeft.y
    }

    r := &cell{ y: s.topLeft.y, x: s.topLeft.x, y2: s.bottomRight.y, x2: s.bottomRight.x }
    r.data = cutRectangularText( g.data, r )
    row = append( row, r )

    if g.visit( s.bottomLeft.nmv( DOWN ) ) == VEDGE {
      hotPoints[ s.bottomLeft ] = true
    }

    if _, exist := hotPoints[ s.topRight ]; exist {
      delete( hotPoints, s.topRight )
      next = &s.topRight
    } else if g.visit( s.topRight.nmv( RIGHT ) ) == HEDGE {
      next = &s.topRight
    } else {
      next = pullNextPoint( hotPoints )

      if next == nil { rows = append( rows, row) }
    }
  }

  xS, yS :=  mapToSortIntArray(xEdges), mapToSortIntArray(yEdges)
  return tableToHtml( rows, xS, yS )
}

func tableToHtml( table [][]*cell, xS, yS []int ) string {
  buf := new( bytes.Buffer )

  fmt.Fprintf( buf,  "<table border=\"1\">\n" )
  for _, row := range table {
    fmt.Fprintf( buf, "<tr>" )

    for _, cell := range row {
      fmt.Fprintf( buf, "<td" )
      if colspan := rangeCells(cell.x, cell.x2, xS); colspan != 1 {
        fmt.Fprintf( buf, " colspan=\"%d\"", colspan )
      }
      if rowspan := rangeCells(cell.y, cell.y2, yS); rowspan != 1 {
        fmt.Fprintf( buf, " rowspan=\"%d\"", rowspan )
      }
      fmt.Fprintf( buf, "><p>%s</p></td>", SpaceSwap( cell.data, " " ) )
    }

    fmt.Fprintf( buf, "</tr>\n" )
  }
  fmt.Fprintf( buf, "</table>\n" )

  return buf.String()
}

func pullNextPoint( m map[point]bool ) *point {
  if len( m ) == 0 { return nil }

  n := point{}
  for key, _ := range m { // random first value
    n = key
    break
  }

  for key, _ := range m {
    if key.y < n.y {
      n = key
    } else if key.y == n.y && key.x < n.x  {
      n = key
    }
  }

  delete( m, n )
  return &n
}

// calderilla

func gridify( data string ) (grid [][]rune) {
  lines := GetLines( data )
  grid   = make( [][]rune, len( lines ) )

  for i, l := range lines { grid[ i ] = []rune( l ) }

  return
}

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

func cutRectangularText( grid [][]rune, r *cell ) string {
  buf := new( bytes.Buffer )

  if y := r.y + 1; y < r.y2 {
    buf.WriteString( string(grid[y][r.x+1:r.x2]) )
  }

  for y := r.y + 2; y < r.y2; y++ {
    buf.WriteByte( '\n' )
    buf.WriteString( string(grid[y][r.x+1:r.x2]) )
  }

  return buf.String()
}

func mapToSortIntArray( m map[int]bool ) []int {
  arry, i := make([]int, len( m )), 0
  for key := range m { arry[i] = key; i++ }
  sort.Ints( arry )
  return arry
}

func SpaceSwap( str, swap string ) string {
  i, j, k := 0, 0, make( []byte, len( str ) + len( swap ) * countSpacesRegions( str ) )

  for ; i < len( str );  {
    switch str[i] {
    case ' ', '\t', '\n', '\v', '\f', '\r' :
      i += CountInitSpaces( str[i:] )
      j += copy( k[j:], swap )
    default: k[j] = str[i]; j++; i++
    }
  }

  return string( k[:j] )
}

func countSpacesRegions( str string ) (n int) {
  for i := 0; i < len( str ); i++ {
    switch str[i] {
    case ' ', '\t', '\n', '\v', '\f', '\r' :
      i += CountInitSpaces( str[i:] )
      n++
    }
  }

  return
}

func CountInitSpaces( str string ) int {
  for i, c := range str {
    switch c {
    case ' ', '\t', '\n', '\v', '\f', '\r' :
    default: return i
    }
  }

  return len(str)
}
