package main

import "fmt"

func main() {
  const width, height = 5, 1//4096, 4096
  i, r, g, b := uint32(0), uint8(0), uint8(0), uint8(0)

  for   py := 0; py < height; py++ {
    for px := 0; px <  width; px++ {
      // nuevo valor
      newValue(&r, &g, &b, i)
      // rotaciones
      rotar( r, g, b )
      // variaciones (+ rotaciones)
      variar( r, g, b )
      i++
    }
    //  png.Encode(os.Stdout, img);
  }

}

func newValue( r, g, b *uint8, i uint32 ) {
  *r, *g, *b = uint8(i), uint8(i >> 8), uint8(i >> 16)
  fmt.Printf( "\n[%3d %3d %3d] ", *r, *g, *b )
}

func rotar(r, g, b uint8){
  if r == g && g == b { return }

  if r != g && g != b {
    fmt.Printf( "[%3d %3d %3d] ", r, b, g )
    fmt.Printf( "[%3d %3d %3d] ", g, r, b )
    fmt.Printf( "[%3d %3d %3d] ", b, r, g )
    fmt.Printf( "[%3d %3d %3d] ", b, g, r )
    fmt.Printf( "[%3d %3d %3d] ", g, b, r )
    return
  }

  if g == b && r != g {
    fmt.Printf( "[%3d %3d %3d] ", b, r, g )
    fmt.Printf( "[%3d %3d %3d] ", b, g, r )
    return
  }

  if r == g || g != r {
    fmt.Printf( "[%3d %3d %3d] ", r, b, g )
    fmt.Printf( "[%3d %3d %3d] ", b, g, r )
    return
  }

  if r == b || g != r {
    fmt.Printf( "[%3d %3d %3d] ", g, r, b )
    fmt.Printf( "[%3d %3d %3d] ", r, b, g )
    return
  }
}


func variar(r, g, b uint8){


  rotar( r, g, b )
}
