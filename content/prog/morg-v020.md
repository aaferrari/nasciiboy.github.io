+++
title      = "morg v0.20"
tags       = [ "morg" ]
categories = [ "prog" ]
date       = 2017-10-06T17:33:57-05:00
+++

![](/img/morgv020.jpg)

## One More Kiss

**woooooo!!! wraaoggghhh!!! (&) wrooomgfff!!!**

aunque he dedicado aproximadamente los ultimos 2 meses en exclusiva y de forma
obsesa a la refactorizacion de morg, su codigo sigue siendo mediocre.
mentiria si dijera que comparativamente no ha avanzado un guevo con respecto a
la ultima vez que lo toque, pero como diria mick, "no me satisface" (aun)

muchas cosas he aprendido por el camino, sobre todo relacionado con Go, pues
ahora si me siento comodo y casi seguro con su huso, tambien aprendi ha hacer un
"Scanner" para identificar lineas... cadenas, numeros, constantes y otros cosas
dentro de una cadena "cruda" de texto, ademas ahora se, que las cadenas (como
las cucharas) no existen, y un monton de cosas mas que ya no recuerdo...

algunas anotaciones he dejado que darian para varios post (o un libro en el
futuro) pero no llegaran hasta tener un programa robusto y "señorial", con la
suficiente calidad como para atreverme a mandarlo a alguna distro, no obstante,
lo pongo a disposicion del mundo para resivir algun tipo de aportacion
intelectual, hackeril, ecomica o moral

Pero bueno, aunque no dejan de ser frajiles, pasemos a las caracteristicas y
cambios que incorpora la nueva version

(para quien no tenga idea de que mierda es *morg*, dedicare una guia exhaustiva
en el futuro, mientras pueden pasarse por el
[repo](https://github.com/nasciiboy/morg) y leer el  inactualizado readme, o si
quiere ver una muestra de sus actuales capacidades de exportacion y su sintaxis
en si, (y ademas aprender Go) vallan a [este](https://github.com/nasciiboy/tgpl) repo)

### resaltado (o marcas)

las marcas eran antes `@` + `caracter` + `(` + `contenido` + `)` y ahora sigue
siendo asi, peroooo por primera vez `caracter` puede ser una serie de varios
caracteres, es decir, el "resaltado" se puede concatenar, como en `@eibc(algo)`
que exportado a html seria asi: `<em><i><b><code>algo</code></b></i></em>`

### paramentros con sintaxis estilo "funcion"

en la mayoria de herramientas de linea de comandos un parametro tiene la
sintaxis

    --algo="cosa"

o

    -algo cosa

bien?, para morg esto tiene la forma

    algo

o

    algo()

o

    algo( cosa )

o

    algo( cosa-a, cosa-b, ... )

una forma de entenderlo, es como una funcion que tiene valores establecidos por
defecto, y segun el numero de parametros que se envien el resto se colocan de
forma automatica, y en caso de que un parametro (o su numero) sea erroneo,
se subtituyen los errores por el valor por defecto.

La diferencia radica en que no se trata de una funcion, sino del nombre de un
parametro y sus valores!

ahora, estos modificadores aparecen dentro de los bloques, que tienen la forma

```
..bloque >
  cosas
< bloque..
```

quedando asi

```
..bloque algo algo1() algoMas2( "cadena", 123, .21, `raw`, identificador )  >
  cosas
< bloque..
```

un uso de ejemplo es para especificar un tema especifico, o indicar que la
salida debe numerarse apartir de un numero dado

```
..code n(10) style( "blackHole" )  > c
  esto es codigo en lenguaje C «o no»
< code..
```

como es una cosa muy chula, tambien active el parseo de esta caracteristica
dentro de un comando especial (`options`) en la configuracion del documento

```
..options > fancyCode() toc
```

de momento solo con dos opciones, la primera para especificar que queremos
resaltado de sintaxis en la exportacion (dentro de este puede especificarse
algun tema de color, pero en su lugar recomiendo dejar el campo vacio y
establecer el tema con css en la exportacion html).

la otra opcion es `toc`, que sirve para indicar que queremos que la exportacion
incluya la tabla de contenidos

### ladrillos

je, bloques y ladrillos. Imagina que tienes un bloque de codigo fuente, y en
algun momento lo deseas "ejecutar" y colocar su salida dentro del documento,
pues hay es donde aparecen los ladrillos

```
..code > sh
  echo "hola, mundo"
<>
  hola, mundo
< code..
```

exacto, el `<>` separa el bloque de sus ladrillos... y en este podriamos indicar
algurna cosa como por ejemplo

```
..code > sh
  random
<> ejecucion 1
  1236
<> ejecucion 2
  47
< code..
```

y asi sucesivamente.

Aunque es una opcion disponible en cualquier bloque (exepto los de configuracion
del documento) de momento solo la he dejado activa en el bloque especial `cols`,
que sirve para dibujar columnas de cosas (en html)

```
..cols >

  este es el texto de la columna 1

<>

  este es el texto de la columna 2

<>

  contenido de la columna 3

...
```

al principio pense en que la division del ladrillo tuviera el formato

```
..cols >
  cosa
<-> otra cosa
  la otra cosa
<->
  la ultima cosa
< cols..
```

con `<->` por facilitar la identificacion visual de los "ladrillos", pero
abandone la idea, por que es mas complejo el agregar el guion en medio, lo unico
que tenia en claro era la utilisacion de los simbolos `<>` que de algun modo
complementan la idea de unidad en los bloques cerrando y abriendo las secciones.

como sea, aun es un prospecto de caracteristica

### srci

el otro comando de bloque que sufrio cambios es "sorci" (escrito `srci`) que es
un bloque donde se simula un prompt de algun lenguaje y su salida, sin hechar
mano de los ladrillos

en la anterior version la sistaxis era

```
..srci > lenguaje
  > (esto simularia ser (codigo)  \
      (en lisp (o algo)           \
               (por el estilo)))
  esta seria la supuesta salida
  que produce el codigo
```

las diagonales al final servia para indicar que la supuesta seccion de codigo
se expande por varias lineas, de forma identica a como se hace en bash

pues ahora sera

```
..srci > lenguaje
  > (esto simularia ser (codigo)
  ^   (en lisp (o algo)
  ^            (por el estilo)))
  esta seria la supuesta salida
  que produce el codigo
```

cada linea que se supone forma parte de la entrada, inicia con `^`.

Este cambio lo hice por ninguna razon en especifico, un mero capricho. El como
escapar unas entradas legitimas de los simbolos `>` (prompt) y `^` (cosas que
forman parte del promtpt en cuestion) es un asunto aun inexplorado, he, he, he

pero bueno, lo bonico de este bloque, es que con una sintaxis comun se puede
simular la supuesta estrada de casi cualquier lenguaje! Para casos donde el
lenguaje tenga mas de un promt, habria que utilizar un parametro adicional y
supongo que diversos bloques, por ejemplo para simular una secion como usuario
de a pie en bash y luego un logueo como root, seria

```
..srci prompt( "$ " ) > sh
  > rm -rf /boot
  permiso denegado
  > su
  password

aqui con algun texto se alerta de los peligros de ser root y ejecutar
comandos con poder ilimitado

..srci prompt( "# " ) > sh
  > whoami
  root
  > rm -rf /boot
  error: lo siento su princesa se encuentra en otro castillo
```

### mensajes de error

la version anterior era silenciosa como una tumba, solo lanzaba mensajes cuando
se rompia el parser. Para la nueva version, ademas de los mensajes en un
escenario catastrofico, se incluyen mensajes en errores dentro de los bloques,
tambien del resaltado y los relacionados con problemas de codificacion

no es todo lo presiso que deberia ser, aun asi cumple su funcion medianamente bien

### pinche python culero del infierno

en la version "antigua" de morg, utilizaba pygments para colorear (o mas bien
etiquetar) el codigo fuente, puede que hiera alguna sensivilidad, pero **el puto
python de los cojones** no esta hecho para hacer aplicaciones, si lo estas
utilizando de esa forma, colaboras con el calentamiento global, matas gatitos y
peor aun, no mereses mi respeto

ja, ja, no hay color! entre la vieja version que utilizaba python para el
coloreado y el actual hay una diferencia de 3 minutos:

```
$ time morg-old toHtml The-Go-Programming-Language.morg

real	3m6,947s
user	2m40,701s
sys	0m16,755s
$ time morg-new toHtml The-Go-Programming-Language.morg
morg:katana:The-Go-Programming-Language:4346:52: illegal UTF-8 encoding
katana:The-Go-Programming-Language:4346:52: illegal UTF-8 encoding

real	0m2,414s
user	0m2,456s
sys	0m0,030s
```

**si tres malditos minutos**, que hacian a morg inviable para por ejemplo una edicion "en
vivo" (en alguna futura version), no solo eso, si no que con la version en puro
y nativo codigo Go, en la practica, **el tiempo de espera no existe**, peor aun
ni siquiera estoy utilizando paralelismo (aun)

cuasi como un milagro santisimo del mismo RMS, aparecio un proyecto llamado
[chroma](https://github.com/alecthomas/chroma), que se esta encargando de portar
pygments a Go.

pero bueno, no todo es tan bonito como parece, la libreria chroma no esta
preparada para ser utilizada concurrentemente, asunto que descubri de mala manera
y con el *sentido aracnido*. Ademas es demasiado compleja de utilizar, tira de
una libreria de expresiones regulares de una tercera parte, no esta pensada para
utilizarse "en solitario" (segun yo) y hecha mano de paquetes "peligrosos".

Sea como fuere, **chroma** es una aportacion invaluable y de facil modificacion
para mis propositos (o modos, segun se vea). Ya que tiene que cumplir con
necesidades muy especificas dentro de morg que dificilmente serian aceptadas en
el proyecto original, he hecho un clonacion y lo he subido a mi repo... aunque
como el proyecto chroma aun es joven, va a ser tortuoso sincronisar las
actualizaciones que en el se hagan, en fin, el menor de los males

## EOF

aunque tiene un monton de horas y pruebas, el codigo al igual que la
"especificacion" siguen siendo fragiles, asi que no recomendare su uso, incluido
el mio, que recintemente tuve que hacer cambios en algunos documentos para poder
utilizarlos como ficheros de prueba

como de costumbre, me libre de algunos baches con chapuzas, y sigo encontrando
dificuldades para establecer un modelo solido. La seccion que se encarga del
despliegue en terminal solo la actualice para que fuera funcional, esta sigue
siendo lo mismo que hace (como) 5 meses, cuando aun era un forastero en Go. Lo
unico que no merma es la adrenalina mientras me pongo a pensar, ni la esperansa
de verlo completo con su

- interfaz (completa) para terminal,
- exportador para multiples formatos,
- con opciones para ser extensible y modificable
- verlo substituir a todos los otros formatos que existen,
- crear un super repositorio lleno de conociminto en formato morg y dotarlo de un buscador para este,
- incorporar traduccion automatica,
- reformateo,
- encontrar el lenguaje ideal para formulas matemagicas y diagramas,
- que cuente con tablas de datos complejas e interactivas en puro texto
- y un modo para emacs...
- etc.

En claro y dicho de otro modo, es un proyecto a muy largo plazo para este
ejercito de un solo hombre

### dependencias

odio las dependencias, incuso incluir a la libreria estandar. Por ello trato de
mantener el codigo lo mas "puro", el nucleo es realmente sencillo y
practicamente limitado solo a mi carpeta (ver en el siguiente arbol), pero para
cumplir la mision primero hubo que hechar mano de chroma (no puedo dejar de
agradecerles) y estos para mi desforturio hechan mano de una libreria de
expresiones regulares llamada regexp2 (dlclark/regexp2) que ralentiza la
compilacion de forma considerable (~20s)

la otra dependencia, es **termbox-go** (nsf/termbox-go), que sirve para la
interfaz de linea de comandos y por ultimo tambien esta *fnmatch*, la cual no se
que haga...

<pre>
── Dependencias
    ├── danwakefield
    │   └── fnmatch
    ├── dlclark
    │   └── regexp2
    ├── mattn
    │   └── go-runewidth
    ├── nasciiboy
    │   ├── chroma
    │   ├── morg
    │   │   ├── biskana
    │   │   ├── howto.md
    │   │   ├── katana
    │   │   ├── LICENSE.txt
    │   │   ├── morg.go
    │   │   ├── morg_test.go
    │   │   ├── nirvana
    │   │   ├── porg
    │   │   ├── readme.md
    │   │   └── testdata
    │   ├── regexp4
    │   └── txt
    └── nsf
        └── termbox-go
</pre>

el arbol esta bastante resumido, segun `find` son 292 ficheros de codigo (inclidas
las pruebas) haber si en un futuro logro restringir las dependencias exclusivamente
a mi codigo y a termbox

o, como curiosidad, la imagen del inicio la utilize para inscribir el proyecto morg
en un concurso mexxxicano de "ideas mexico", que exigia hacer un video ([aca](https://www.youtube.com/watch?v=F5QVI98TZNU)
(en yutu)) ja, ja, el video es mudo y no tiene sentido alguno, fue gracioso hacerlo.

El concurso se ganaba con votacion popular que exigia un registro en la pagina.
Habia muchos proyectos que daban para unas risas, morg, no resivio ningun voto,
y tampoco me hacia ilusion ganar dicho concurso, aunque si hubiera sido asi, me
habria quitado algunos estigmas "ambientales" de en cima, pero bueno, no hay
prisa, no tengo duda que en un futuro cercano o quiza lejano morg se impondra
como el formato supremo, he!

Happy hacking!
