package main

func main() {
  var r, g, b uint8

  for i := uint32(0); r + g + b == 765; i++ {
    // nuevo valor
    r, g, b = uint8(i), uint8(i >> 8), uint8(i >> 16)

    for _, variaciones := range variar( r, g, b ) {
      for _, rotaciones := range rotar( r, g, b ) {
        // establecer variaciones o hacer algo
      }
    }
  }
}

func variar(r, g, b uint8) []rgbS {
  var variados = [] rgbS { { r, g, b },};
  // cosas
  return variados
}

func rotar(r, g, b uint8) []rgbS {
  var rotados = [] rgbS { { r, g, b },};
  // cosas
  return rotados
}
