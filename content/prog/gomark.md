+++
title      = "benchmarks dentro de un programa en go"
tags       = [ "go" ]
categories = [ "prog" ]
date       = 2017-10-06T21:03:55-05:00
+++

en Go podemos realizar benchmarks dentro de los ficheros `_test.go`, sin embargo
realizar comparativas dentro de en un programa "regular" no es (era) tan
sencillo hasta la llegada de la version 1.9

## cgo

la primer opcion es echar mano de la libreria `time` de C. Esta libreria
contiene la funcion `clock` que nos regresa una aproximacion a la cantidad de tiempo
del procesador que ha utilizado el programa desde su ejecucion.


```
package main

//#include <time.h>
import "C"

import "fmt"

const top = 1 << 12

func main(){
  init := CpuTime()

  // prueba >
  for x, str := 0, ""; x < top; x++ { str += "1234567890" }
  // < prueba

  fmt.Printf( "CpuTime %dms\n", DiffCpuTimeByMS( init, CpuTime() ) )
}

func CpuTime() uint64 {
  return uint64(C.clock())
}

func DiffCpuTimeByMS( begin, end uint64 ) uint64 {
  return (end - begin) *  1000 / uint64(C.CLOCKS_PER_SEC)
}
```

**resultado:** `CpuTime 55ms`

solo hay que cambiar el codigo dentro de las comentaarios "prueba", es
importante mantener la linea con `//#include <time.h>` tal cual, pues es una
(obscura) indicacion para decirle al compilador de Go que incluya dicha libreria
de C. Por supuesto tambien hay que mantener la importacion de `"C"`

Para la compilacion no hace falta pasar ningun parametro adicicional, basta con
un simple `go build main.go`

## testing

la segunda opcion para realizar un benchmark es invocar a `testing` desde codigo
regular con una funcion literal... lo se, no es intiuitivo, pero hay esta y
funciona


```
package main

import "fmt"
import "testing"
import "time"

const top = 1 << 12

func main(){

  result := testing.Benchmark(func(b *testing.B) {
    b.N = 1 // numero de repeticiones de la prueba
    for i := 0; i < b.N; i++ {
      // prueba >
      for x, str := 0, ""; x < top; x++ { str += "1234567890" }
      // < prueba
    }
  })

  fmt.Printf( "tiempo %s\n", result.T / time.Duration(result.N) )
}
```

**resultado:** `tiempo 67.861708ms`

esta prueba toma mucho mas tiempo que con la version anterior, la diferencia se
origina en el propio `testing.B`, ya que realiza metricas adicionales, como el numero de
asignaciones de memoria, bytes utilizados, gorutinas y otras cosas

## time

por ultimo la prueba del tiempo se puede realizar con la libreria estandar de
Go, aunque esto no es asi para verciones del compilador inferiores a 1.9 ya que
antes de estos no se media el timpo "monolitico" de ejecucion (lo que hace
`clock` de la libreria `time` de C)

```
package main

import "time"
import "fmt"

const top = 1 << 12

func main(){
  start   := time.Now()
  for x, str := 0, ""; x < top; x++ { str += "1234567890" }
  elapsed := time.Since( start )

  fmt.Printf( "tiempo %s\n", elapsed )
}
```

**resultado:** `tiempo 59.746755ms`

## conclusion

en pruebas personales, con `clock` (de C) los resultados son mas constantes y con
menor variacion que en las demas opciones, mas la version con `time` nativo no
dista demaciado de esta, ademas por ser la opcion con codigo nativo y sin
dependencias externas es la que recomiendo y utilizo. Reservaria como segunda
opcion y para pruebas mas exigentes la que utiliza `testing.B`, siempre asumiendo
una consumo superior de recursos

## referencias

https://www.reddit.com/r/golang/comments/6u4xhs/how_make_a_benchmark_in_a_regular_program_no/

https://golang.org/pkg/time/
