 package katana

import "testing"

func TestRangeCells( t *testing.T ){
  data := [...]struct{
    a, b, out int
    cells []int
  } {
    {  0,  9, 1, []int{ 0, 9, 18, 27, 36, 45, 54, 63, 72, 81, 90 } },
    {  0,  5, 1, []int{ 0, 9, 18, 27, 36, 45, 54, 63, 72, 81, 90 } },
    {  2,  9, 1, []int{ 0, 9, 18, 27, 36, 45, 54, 63, 72, 81, 90 } },
    {  2,  8, 1, []int{ 0, 9, 18, 27, 36, 45, 54, 63, 72, 81, 90 } },
    {  0, 18, 2, []int{ 0, 9, 18, 27, 36, 45, 54, 63, 72, 81, 90 } },
    {  9, 18, 1, []int{ 0, 9, 18, 27, 36, 45, 54, 63, 72, 81, 90 } },
    {  7, 18, 2, []int{ 0, 9, 18, 27, 36, 45, 54, 63, 72, 81, 90 } },
    {  5, 45, 5, []int{ 0, 9, 18, 27, 36, 45, 54, 63, 72, 81, 90 } },
    {  5, 46, 6, []int{ 0, 9, 18, 27, 36, 45, 54, 63, 72, 81, 90 } },
    { 15, 90, 9, []int{ 0, 9, 18, 27, 36, 45, 54, 63, 72, 81, 90 } },
  }

  for _, d := range data {
    if r := rangeCells( d.a, d.b, d.cells ); r != d.out {
      t.Errorf( "Test rangeCells( %d, %d, %v )\nresult %d != %d expected", d.a, d.b, d.cells, r, d.out )
    }
  }
}

func TestTextTable2HtmlTable( t *testing.T ){
  data := []struct {
    in, out string
  } {

    { `| 0 | 1 | 2 |
|---|---|---|
| 3 | 4 | 5 |
|---|---|---|
| 6 | 7 | 8 |
|---|---|---|`,

      `<table border="1">
<tr><td><p> 0 </p></td><td><p> 1 </p></td><td><p> 2 </p></td></tr>
<tr><td><p> 3 </p></td><td><p> 4 </p></td><td><p> 5 </p></td></tr>
<tr><td><p> 6 </p></td><td><p> 7 </p></td><td><p> 8 </p></td></tr>
</table>
` },

    { `| 0 | 1 | 2 |
|---|---|---|
|   3   | 4 |
|-------|---|
|   5   | 6 |
|-------|---|`,

      `<table border="1">
<tr><td><p> 0 </p></td><td><p> 1 </p></td><td><p> 2 </p></td></tr>
<tr><td colspan="2"><p>   3   </p></td><td><p> 4 </p></td></tr>
<tr><td colspan="2"><p>   5   </p></td><td><p> 6 </p></td></tr>
</table>
` },


    { `| 0 | 1 | 2 |
|---|---|---|
|   3   |   |
|-------| 4 |
|   5   |   |
|-------|---|`,

      `<table border="1">
<tr><td><p> 0 </p></td><td><p> 1 </p></td><td><p> 2 </p></td></tr>
<tr><td colspan="2"><p>   3   </p></td><td rowspan="2"><p>    4    </p></td></tr>
<tr><td colspan="2"><p>   5   </p></td></tr>
</table>
` },


    { `| 0 | 1 | 2 |
|-------|---|
|       |   |
|   3   | 4 |
|       |   |
|-------|---|`,

      `<table border="1">
<tr><td><p> 0 </p></td><td><p> 1 </p></td><td><p> 2 </p></td></tr>
<tr><td colspan="2"><p>          3          </p></td><td><p>    4    </p></td></tr>
</table>
` },

    { `|   mi tabla compleja  |
|----------------------|
|  a    | b  |    c    |
|-------|----|---------|
| d | e | f  |  g |  i |
|   |   |----|----|----|
|   |   | i  |    j    |
|   |---|----|---------|
|   | k | l  |         |
|   |   |----|    m    |
|   |   | n  |         |
|   |   |----|---------|
|   |   | o  |    p    |
|---|---|----|---------|`,

      `<table border="1">
<tr><td colspan="5"><p>   mi tabla compleja  </p></td></tr>
<tr><td colspan="2"><p>  a    </p></td><td><p> b  </p></td><td colspan="2"><p>    c    </p></td></tr>
<tr><td rowspan="5"><p> d                         </p></td><td rowspan="2"><p> e       </p></td><td><p> f  </p></td><td><p>  g </p></td><td><p>  i </p></td></tr>
<tr><td><p> i  </p></td><td colspan="2"><p>    j    </p></td></tr>
<tr><td rowspan="3"><p> k             </p></td><td><p> l  </p></td><td colspan="2" rowspan="2"><p>             m             </p></td></tr>
<tr><td><p> n  </p></td></tr>
<tr><td><p> o  </p></td><td colspan="2"><p>    p    </p></td></tr>
</table>
` },
  }

  for _, d := range data {
    if r := TextTable2HtmlTable( d.in ); r != d.out {
      t.Errorf( "Test rangeCells()\n   in =\n%s\n   out =\n%s\n", d.in, r )
    }
  }
}
