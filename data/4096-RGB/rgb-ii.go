package main

import( "image";"image/color";"image/png";"os" )
import "fmt"

func main() {
  const width, height = 4096, 4096
  var colors [768][]color.RGBA
  r, g, b := uint8(0), uint8(0), uint8(0)
  img := image.NewRGBA(image.Rect(0, 0, width, height))

  for i := uint32(0); i < 16777216; i++ {
    r, g, b = uint8(i), uint8(i >> 8), uint8(i >> 16)
    sum := int(r)+int(g)+int(b)
    colors[sum] = append( colors[sum], color.RGBA{ r, g, b, 255 } )

    if i > 16777212 { fmt.Fprintf( os.Stderr, "rgb %d %d-%d-%d %v\n", i, r, g, b, colors[sum] ) }

  }


  i, y, x := 0, 0, 0
  xdir, ydir := -1, 1
  for o := 0; o < 768; o++ {
    for _, rgb := range colors[o] {
      img.Set(x, y, rgb )
//      fmt.Fprintf( os.Stderr, "%d %d-%d\n", i, x, y ) // 11111111 11111111 11111111

      // if x == width {
      //   x = 0
      //   y++
      // }

      // x += dir
      // if x == width {
      //   y++
      //   x = width -1
      //   dir = -1
      // }
      // if x == -1 {
      //   y++
      //   x = 0
      //   dir = 1
      // }

      y += ydir
      if y < 0 {
        y = 0
        ydir = 1
        xdir = -1
      }

      x += xdir
      if x < 0 {
        x = 0
        xdir = 1
        ydir = -1
      }

      i++
    }
    if o == 0 || o == 2 || o == 5 || o == 767 {
      fmt.Fprintf( os.Stderr, "%d %v\n", o, colors[o] )
    }

  }

  fmt.Fprintf( os.Stderr, "%d %d-%d %025b\n", i, x, y, 16777215 ) // 11111111 11111111 11111111
  png.Encode(os.Stdout, img);
}
