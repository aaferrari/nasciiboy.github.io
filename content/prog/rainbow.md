+++
categories = ["prog"]
date = "2017-06-17T12:39:43-05:00"
title = "Crear una paleta de color con solo un indice"
+++

![](/img/mandelbrot.png)

que tal, como lo indica el titulo vamos a generar una paleta de color apartir de
un unico indice, para, por ejemplo colorear una imagen en una escala de
colores RGB del negro absoluto (0,0,0) al blanco (255,255,255), con una
trancicion "suave" por estos

El asunto surgio resolviendo algunos de los ejercicios de libro de programacion
de go, especificamente el 3.5, donde proponian dar color a una imagen de
mandelbrot, que estaba en una escala de grises (de hay viene lo de generar los
colores apartir de un solo indice).

La primer y mas facil solucion es utilizar una paleta de colores prefabricada y
adaptar el indice a un valor que entre en la paleta, pero eso es muy cutre, lo mas molon
seria generar el color "al vuelo" de una paleta con un numero de colores
arbitrario, yeee!

entonces, como se hace? bueno... tenia una idea con un circulo de color,
una espiral, y longitudes, pero como las mates no son lo mio, le pregunte a la gente de [internet](https://www.reddit.com/r/programacion/comments/6g28j9/generar_paleta_de_colores_con_solo_un_indice/)
(mejor explicado [aca](https://www.reddit.com/r/Matematicas/comments/6g5f22/recorrido_atravez_de_un_circulo_de_color_rgb/))

y luego? pues, no llego la respuesta matematica que esperaba, peeeeeero una
respuesta me dio a conocer dos modelos de color, como los que utilzaban las
teles crt de la antiguedad

## Modelo de color HSL

https://es.wikipedia.org/wiki/Modelo_de_color_HSL

![](/img/HSL.png)

como podemos ver, tenemos tres valores, **luminosidad**, **saturacion** y
**matiz**, con la particularidad que el color inicia en negro absoluto y luego
converge en blanco, y los colores puros (del esquema RGB, cuando uno de ellos es
255 y los otros dos 0) se optienen con la luminosidad a la mitad de su valor y
la saturcion al maximo, ahora, si la luminosidad esta al maximo, terminaremos
con un color blanco, independientemente de saturacion y matiz, lo mismo en caso
contrario, es decir, si la luminocidad al minimo dara el color negro

estas particulares hacen a este modelo mucho mas intuitivo que el clasico modelo
RGB, ademas de practico para optener tranciciones suaves, especiarmente para el
caso de generar una paleta variada

supondre que su popularidad no esta lo suficientemente extendida en el campo
programacional por requerir un calculo considerablemente mayor

## Modelo de color HSV

https://es.wikipedia.org/wiki/Modelo_de_color_HSV

En este modelo, los colores alcanzan su maximo valor de iluminacion con el valor
maximo de luminocidad, sin embargo y adiferencia de HSL este se decanta por un
color u otro segun la
saturacion y matiz

![](/img/HSV.png)

## Codigo

De entre los dos Modelos de color, escogi HSL, pues se realiza la trancicion del
negro al blanco y con HSV la trancicion culminaria en un color especifico (si
desea seguir este ultimo esquema, lo ideal seria generar distintos matizes con
niveles de saturacion especificos, realizando un bucle por la luminocidad)

aqui esta el codigo para optener un color dentro de nuestra paleta de colores

    package color

    const colors = 255             // colores disponibles
    const secs   = 3               // seciones de color
    const sec    = colors / secs   // longitud de seccion

    func MagicColor( x, scale int ) (r, g, b uint8) {
      color := int(x * colors / scale)

      h := float64(color % sec) / sec
      s := 1.0
      l := float64(color) / colors

      return hsl2rgb( h, s, l )
    }

    func hsl2rgb( h, s, l float64 ) (red, green, blue uint8) {
      r, g, b := l, l, l

      var v float64

      if l <= 0.5 {
        v = l * (1.0 + s)
      } else {
        v = l + s - l * s
      }

      if v > 0 {
        m  := l + l - v
        sv := (v - m) / v
        h  *= 6.0
        sextant := int(h)
        fract := h - float64(sextant)
        vsf   := v * sv * fract
        mid1 := m + vsf
        mid2 := v - vsf

        switch sextant {
        case 0: r, g, b = v, mid1, m
        case 1: r, g, b = mid2, v, m
        case 2: r, g, b = m, v, mid1
        case 3: r, g, b = m, mid2, v
        case 4: r, g, b = mid1, m, v
        case 5: r, g, b = v, m, mid2
        }
      }

      red, green, blue = uint8(r * 255.0), uint8(g * 255.0), uint8(b * 255.0)
      return
    }

debo aclarar que pese a que funciona segun lo planeado, los algoritmos para
convertir de HSL (y HSV) a rgb los traduje de codigo de internete, desconosco si
pueda hacerse mejor, por que no entiendo "las formulas" que proporciona la wikipedia

vamos con la explicacion (de lo que entiendo), primero la funcion de cara al
publico, es `MagicColor` que recive el indice, y el valor maximo que este puede
alcanzar (suprimir este ultimo si se conoce de antemano o mejor aun, que la
paleta tenga tantos colores como el valor maximo, no hice esto por pereza y por
que las constantes en Go son "magicas" y no requieren de estupidos cast y se
pueden utilizar tanto para enteros, como flotantes, como **racionales**(?que es
esto?))

la constante `colors` establece el numero de colores que tendra la paleta,
`secs` es el numero de "tranciciones" atraves del matiz (`h`) es decir,
partiendo de color rojo, pasamos por el verde y luego azul para terminar de
nuevo en rojo. Si tenemos solo una transicion/seccion/ciclo digamos que nos
movemos en espiral (ver dibujo HSL) negro-rojo-verde-azul-rojo-blanco si tenemos mas
de un ciclo seria negro - **(rojo-verde-azul)** - blanco, donde la region
**(rojo-verde-azul)**  se repite una y otra vez, con variaciones de luminocidad

por ultimo establesco el nivel de saturacion al maximo (`1.0`, la variables de
hsl2rgb y hsv2rgb van de 0.0 a 1.0)

aqui esta la vercion hsv2rgb, pero como antes mencione, debemos tomar un enfoque
distinto en MagicColor, para que la paleta tenga una variedad logica, primero un
ciclo por la luminocidad, y dentro de este un ciclo por saturacion y matiz, no hice
eso, asi que vas por cuenta propia, aunque tampoco es muy complicado

(Nota: agregar `import "math"` luego de la declaracion `package color`)

    func hsv2rgb( h, s, v float64 ) (red, green, blue uint8) {
      var r, g, b float64

      i := int(math.Floor(h * 6))
      f := h * 6 - float64(i);
      p := v * (1 - s);
      q := v * (1 - f * s);
      t := v * (1 - (1 - f) * s);

      switch i % 6 {
      case 0: r, g, b = v, t, p
      case 1: r, g, b = q, v, p
      case 2: r, g, b = p, v, t
      case 3: r, g, b = p, q, v
      case 4: r, g, b = t, p, v
      case 5: r, g, b = v, p, q
      }

      red, green, blue = uint8(r * 255.0), uint8(g * 255.0), uint8(b * 255.0)
      return
    }

puedes copiar el codigo y ponerlo en un fichero (digamos en `~/color/color.go`), y
hacer pruebas con lo siguiente (poner en `~/main.go`)

    package main

    import (
      "fmt"
      "./color"
    )

    func main(){
      fmt.Printf( `<?xml version="1.0" encoding="utf-8"?>
    <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
    "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
    <html xmlns="http://www.w3.org/1999/xhtml" lang="" xml:lang="" >

      <body>
    ` )

      for i := 0; i < 255; i++ {
        r, g, b := color.MagicColor( i, 255 )
        var c int32
        c = int32(r) << 16 | int32(g) << 8 | int32(b)

        fmt.Printf( "<span style=\"color:#%06x;\" >a</span>", c )
      }
      fmt.Println( "</body></html>" )
    }

ir a nuestro `~` y ejecutar con `go run main.go > prueba.html`, abrimos
`prueba.html` con nuestro flamante navegador y veremos una fila de `a`s en
escala de colores!

para terminar, [aca](https://raw.githubusercontent.com/nasciiboy/TGPL-Exercises/master/03-05/nasciiboy/main.go) esta
la solucion al ejercicio que motivo este post

descargar y ejecutar con

``` sh
cd 'directorio-de-descarga'

# para imagen mandelbrot
go run main.go > mandelbrot.png

# o

go run main.go -t m > mandelbrot.png

# para imagen newton
go run main.go -t n > newton.png

# para imagen sqrt
go run main.go -t s > sqrt.png

# para imagen acos
go run main.go -t a > acos.png
```

la imagen generada con mandelbrot es muy triste, en cambio con el algoritmo
newton es distinto:

algoritmo newton con `secs` establecido en 1 (un ciclo)

![](/img/newton.png)

algoritmo newton con `secs` establecido en 2 (dos ciclos)

![](/img/newton2.png)

algoritmo newton con `secs` establecido en 50 y `colors` en 5000

![](/img/newton3.png)

para los algoritmos `acos` y `sqrt` no interviene nuestro `MagicColors`, aun asi
la salida es bastante chula

Happy Hacking!
