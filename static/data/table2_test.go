package katana

import "testing"

func TestTextTable2HtmlTable( t *testing.T ){
  data := []struct {
    in, out string
  } {

    { `+-+-+--+
|      |
+      +
|      |
+--+---+`,
      `<table border="1">
<tr><td><p> </p></td></tr>
</table>
` },

    { `+---+---+---+
| 0 | 1 | 2 |
+---+---+---+
| 3 | 4 | 5 |
+---+---+---+
| 6 | 7 | 8 |
+---+---+---+`,
    `<table border="1">
<tr><td><p> 0 </p></td><td><p> 1 </p></td><td><p> 2 </p></td></tr>
<tr><td><p> 3 </p></td><td><p> 4 </p></td><td><p> 5 </p></td></tr>
<tr><td><p> 6 </p></td><td><p> 7 </p></td><td><p> 8 </p></td></tr>
</table>
` },

    { `+---+---+---+
| 0 | 1 | 2 |
+---+---+---+
|   3   | 4 |
+-------+---+
|   5   | 6 |
+-------+---+`,
    `<table border="1">
<tr><td><p> 0 </p></td><td><p> 1 </p></td><td><p> 2 </p></td></tr>
<tr><td colspan="2"><p> 3 </p></td><td><p> 4 </p></td></tr>
<tr><td colspan="2"><p> 5 </p></td><td><p> 6 </p></td></tr>
</table>
` },

    { `+---+---+---+
| 0 | 1 | 2 |
+---+---+---+
|   3   |   |
+-------+ 4 |
|   5   |   |
+-------+---+`,
      `<table border="1">
<tr><td><p> 0 </p></td><td><p> 1 </p></td><td><p> 2 </p></td></tr>
<tr><td colspan="2"><p> 3 </p></td><td rowspan="2"><p> 4 </p></td></tr>
<tr><td colspan="2"><p> 5 </p></td></tr>
</table>
` },

    { `+---+---+---+
| 0 | 1 | 2 |
+---+---+---+
|       |   |
|   3   | 4 |
|       |   |
+-------+---+`,
    `<table border="1">
<tr><td><p> 0 </p></td><td><p> 1 </p></td><td><p> 2 </p></td></tr>
<tr><td colspan="2"><p> 3 </p></td><td><p> 4 </p></td></tr>
</table>
` },

    { `+----------------------+
|   mi tabla compleja  |
+-------+----+---------+
|  a    | b  |    c    |
+---+---+----+----+----+
| d | e | f  |  g |  h |
|   |   +----+----+----+
|   |   | i  |    j    |
|   +---+----+---------+
|   | k | l  |         |
+---+   +----+    m    |
|   |   | o  |         |
| n |   +----+---------+
|   |   | p  |    q    |
+---+---+----+---------+`,
    `<table border="1">
<tr><td colspan="5"><p> mi tabla compleja </p></td></tr>
<tr><td colspan="2"><p> a </p></td><td><p> b </p></td><td colspan="2"><p> c </p></td></tr>
<tr><td rowspan="3"><p> d </p></td><td rowspan="2"><p> e </p></td><td><p> f </p></td><td><p> g </p></td><td><p> h </p></td></tr>
<tr><td><p> i </p></td><td colspan="2"><p> j </p></td></tr>
<tr><td rowspan="3"><p> k </p></td><td><p> l </p></td><td colspan="2" rowspan="2"><p> m </p></td></tr>
<tr><td rowspan="2"><p> n </p></td><td><p> o </p></td></tr>
<tr><td><p> p </p></td><td colspan="2"><p> q </p></td></tr>
</table>
` },

    { `+------------+---------+
|     a      |    b    |
+-------+----+----+----+
|   c   | d  |  e |    |
+---+---+----+----+ f  |
| g |      h      |    |
+---+-+---------+-+----+
|     |    j    |      |
|  i  +-----+---+   k  |
|     |  l  | m |      |
+-----+-----+---+------+`,
    `<table border="1">
<tr><td colspan="5"><p> a </p></td><td colspan="3"><p> b </p></td></tr>
<tr><td colspan="3"><p> c </p></td><td colspan="2"><p> d </p></td><td colspan="2"><p> e </p></td><td rowspan="2"><p> f </p></td></tr>
<tr><td><p> g </p></td><td colspan="6"><p> h </p></td></tr>
<tr><td colspan="2" rowspan="2"><p> i </p></td><td colspan="4"><p> j </p></td><td colspan="2" rowspan="2"><p> k </p></td></tr>
<tr><td colspan="2"><p> l </p></td><td colspan="2"><p> m </p></td></tr>
</table>
` },
  }

  for _, d := range data {
    out := TextTable2HtmlTable( d.in )
    if out != d.out {
      t.Errorf( "Test rangeCells()\n   in =\n%s\n   out =\n%s\n exp =\n%s\n", d.in, out, d.out )
    }
  }
}
