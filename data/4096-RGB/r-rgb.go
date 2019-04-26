package main

import( "image";"image/color";"image/png";"os" )

func main() {
  const width, height = 4096, 4096
  var colors [768][]color.RGBA
  var r, g, b uint8

  for i, sum := uint32(0), 0; i < 16777216; i++ {
    r, g, b = uint8(i), uint8(i >> 8), uint8(i >> 16)
    sum = int(r) + int(g) + int(b)
    colors[sum] = append( colors[sum], color.RGBA{ r, g, b, 255 } )
  }

  img := image.NewRGBA( image.Rect(0, 0, width, height) )
  for i, y, x := 0, 0, 0; i < 766; i++ {
    for _, rgb := range colors[i] {
      if x == width { x = 0; y++ }
      img.Set(x, y, rgb )
      x++
    }
  }

  png.Encode(os.Stdout, img);
}
