package main

import( "image"; "image/color"; "image/png"; "os" )

func main() {
  const width, height = 4096, 4096
  i, r, g, b := uint32(0), uint8(0), uint8(0), uint8(0)
  img := image.NewRGBA(image.Rect(0, 0, width, height))

  for   py := 0; py < height; py++ {
    for px := 0; px <  width; px++ {
      r, g, b = uint8(i), uint8(i >> 8), uint8(i >> 16)
      img.Set(px, py, color.RGBA{ r, g, b, 255 })
      i++
    }
  }

  png.Encode(os.Stdout, img);
}
