+++
title      = "GDP"
tags       = [ "go" ]
categories = [ "prog" ]
date       = 2018-03-28T14:53:20-06:00
+++

**Go Design Patterns**, es un libro enfocado en los patrones de diseño
implementados en Go...

El material de esta ocacion, viene (o lo encontre) en presentacion de pdf, con
una extencion de aproximadamente 400 paginas en letra grande.

El primer 15% es un sobrevuelo de las caracteristicas del lenguaje de
programacion Go. Nada profundo, pero viene bien como recordatorio de como es
esto de Go

El siguiente 55% nos muestran la implementacion de los "clasicos" patrones
includidos en el GoF y el resto ilustra maneras de aprovechar las
caracteristicas concurrentes del lenguaje (gorutinas y canales) reimplementando
algunos patrones y mostrando un par especificos de esta tematica

La ideologia programacional-didactica que imparte el autor se llama
[TDD](https://es.wikipedia.org/wiki/Desarrollo_guiado_por_pruebas) (Test-driven
development). Aunque me parece algo aburrida y monotona (hacer la prueba,
fallar, refactorizar, hacer la prueba, acercarse al comportamiento,
refactorizar, etc, etc) conicido en que las pruebas son un buen punto de
referencia para afrontar un problema, pues:

1. Si es dificil realizar una prueba a tu codigo, seguramente este mal planteado,
   ya sea por realizar demaciadas cosas, recibir demaciados parametros, regresar
   variados resultados

2. Son una garantia de que las nuevas modificaciones no rompan con el comportamiento
   establecido

aun asi, el TDD como mantra sigue sin convencerme. Por lo demas, cada patron
se divide mas o menos en las secciones Descripcion, Objetivos, Criterios de
aceptacion, Pruebas de unidad, Implementacion y "resumen-reflexion-o-algo".

El acercamiento que tome, por resultarme tedioso y aburrido lo relacionado con
la TDD, fue leer todo ignorando criterios de aceptacion y pruebas de unidad para
ir directamente al codigo, descifrarlo y verlo funcionar, luego ante alguna duda
ya leer la seccion de implementacion y pasar al resumen-o-algo

Los primeros capitulos, dedicados a los patrones estructurales y de creacion,
son bastante desabridos. Basicamente se podrian resumir en simples
interfaces. Pero cuando se llega a los patrones de comportamiento, el codigo se
convierte en ludicos rompecabezas (no frustrantes) y con concurrencia mejoran
aun mas. La implemantacion del patron `Pipeline` es una gozada de sencilles y
genialidad que unicamente podria implementarse en Go con tanta genialidad
(aunque creo que en el TGPL lo muestran aun mejor implementando una pasteleria)

mencionar que el codigo fuente no incluye ni un puñetero comentario, yeee! este
sujeto es de mi escuela de pensamiento... No temais, entre los nombres, tipos,
funciones del paquete en conjuncion con las acciones dentro de las pruebas es
suficiente para entender lo que se esta intentando demostrar. Diria que en caso
de amnesias mentales, en lugar de revisitar el libro, es mas interesante ir
directo al codigo, y si tienes la suficiente determinacion, ni siquiera hace
falta leer el libro

por la demas, la lectura es amena y rapida, no se esfuersa en repetir lo que en
otros libros (como el mismo GoF) encontrarias mejor y mas detallado. En su lugar
se decanta por enseñar formas idiomaticas de aprovechar el lenguaje

## Notas

el codigo fuente, del libro esta disponible en
[github](https://github.com/PacktPublishing/Go-Design-Patterns) pero aunque la
mayoria esta listo para compilar/probar uno que otro tiene fallos, no se si
intencionales, como por ejemplo en el penultimo capitulo, para ejecutar el
codigo es necesario renombrarlo, reorganizarlo y ocacionalmente modificar y/o
agregar alguna funcion o libreria. Ya en el capitulo 10 ni se molestan
(literalmente) en terminar la escritura, el primer fichero trae una funcion a
medio hacer y poco mas... coloque una
[issue](https://github.com/PacktPublishing/Go-Design-Patterns/issues/1),
esperando que corrijan el asunto... pero no espero nada, es un libro "de
maquila", con mas de un año en el mercado, un mercado inundado de material
generico donde apenas alguien tiene interes en ellos y las unicas ventas,
ocurren casi por equivocacion, ja, ja, ja, la ruleta rusa de los libros!

el primer error que detecte en el codigo, esta en `Chapter02/prototype.go`:

```
func GetShirtsCloner() ShirtCloner {
    return nil
}
```

el asunto, es que la funcion regresa un `nil` para una interfaz que tiene como
contrato una funcion `GetClone(m int) (ItemInfoGetter, error)` que solo es
cumplida por la estructura `ShirtsCache` por su metodo `GetClone` aplicado en
un puntero a la funcion...

Al principio me jodio la mente pensando en que dicho codigo pudiera funsionar.
Comor? un nil convirtiendose en una interfaz para una estructura que no se
declara explicitamente? Go hace este tipo de magia (me pregunte) ... y nop,
para que la cosa funcione `GetShirtsCloner` debe regresar `new(ShirtsCache)`.

En el capitulo 8, fue necesario aislar un par de ficheros para ejecutar el patron
singleton (concurrente con canales)

En el capitulo 9, hubo que reorganizar todos los ficheros y modificarlos un poco

Y el 10 directamente no esta hecho. Me habia planteado terminarlos, sin embargo,
como la metodolagia que habia adoptado era ir directamente al codigo, esta vez
inexistente, y mi forma de aproximarme al libro fue con una traduccion no
humana, no fui capaz (ni me esforce) en enterder que demonios decia. Es una
lastima, por que dicho capitulo mostraba (creo) como limitar la cantidad de gorutinas
en ejecucion, como finalizar la ejecucion de una gorutina y un codigo final que
incluia de todo un poco

Como nota final en una parte del patron State, mencionan un FSM que al parecer
no solo se refiere al buen **monstruo de espagueti volador** o
[FSM](https://en.wikipedia.org/wiki/Flying_Spaghetti_Monster) si no tambien a
una maquina de estados finitos ([finite-state machine](https://es.wikipedia.org/wiki/Aut%C3%B3mata_finito))

## cobaya

Aunque cobayizar un material es un entretenimiento "mecanico", cada vez, me da
mas pereza tener que aplicarlo a tristes PDFs. Pero para optener una traduccion
"express" es lo mas sencillo que encuentro, y bueno `¯\_(ツ)_/¯` aunque sea poco, material a
material van refinando las ideas del lenguaje de documentacion
imaginario. Por ejemplo, esta vez hicieron evidente un fallo en el
reconocimiento de listas alfabeticas (y numericas) que se resolvio modificando
chapuseramente una regex (aunque no subire el cambio al repo hasta el siguiente refactorizado)

Hem, el material tenia pocos retos y apenas incluia imagenes. Lo mas complicado
fue dar formato al codigo, tambien inferir donde demonios terminabas los TIPs y
darle la jerarquia adecuada a los encabezados

Los bloques donde se mostraba la salida de las pruebas no la afine del todo, y
en la lectura del libro no me percate del hecho de su no correcta indentacion
hasta luego de la mitad

en el [repo cobayizado](https://github.com/nasciiboy/gdp) encontraran el fuente,
una exportacion a html sin interes ni esfuerzo, y la version (mal) traducida
automaticamente. Dicha traduccion, no tiene ni tabla de indice, ni los
encabezados tienen el orden correcto (mientras la leia, iba corrigiendo la
version en ingles), ademas seguramente el html este bastante
roto por toquetearlo bastante a mano y con regexes... y asi se quedara, esta
ocacion no hay una version "fuente" en español, es mucho curro y prefiero
ponerme a practicar los patrones

felices trazos!
