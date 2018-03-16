+++
title      = "iScheme"
tags       = [ "apt", "sicp" ]
categories = [ "prog" ]
date       = 2017-08-20T15:59:03-05:00
+++

![](/img/lambda.png)

La traduccion del SICP se esta poniendo matemagicamente densa, casi hostil para
mi escaso saber, por su parte los conceptos programacionales con Scheme solo los
entiendo a nivel superficial, es decir, podria explicar de que van, pero no
ponerlo en nada practico, ademas han dejado de aparecer fraces esotericas.

Con el proposito de enmendar uno de estos dilemas (el de la programacion, por su
puesto), me plante comenzar un port del raptor (si, otro mas) al Scheme, mas,
pronto me di cuenta que habia olvidado siquiera como definir una variable, una
funcion y una l-a-a-m-m-b-d-a-a (que raro suena), oohh, que dilema –dijo
interiormente nasciiboy

Tres escenarios se plantaron hacia mi (luego de ver con detalle el temario
restante del SICP)

1. Mandar la traduccion a la mierda y desaparecer de intenné

2. Buscar otro libro de Scheme... que seguramente tambien requiera
   traduccion... (ya habia dado un primer paso antes de pasar a la suguiente opcion)

3. Crusarme por casualidad con el libro estraño de racket y ver de que iba y la
   razon de habero metido en "los recursos" de Scheme

De la opcion 2 tenia en reserva los "The Little Schemer", tras una revision
preliminar, quedaron descartados, por fortuna hace un par de meses aparecio una
compilacion de cosas de lisp (incluido scheme, prolog y haskell) que traia un
libro apto para su servidor *Teach Yourself Scheme in Fixnum Days*. Para aun
mas sorpresa es de "Codigo Visible" o algo asi, tiene [un repo](https://github.com/ds26gte/tyscheme) en github,
ademas de una version online (seccionizada por paginas), escrita en tex y por lo
que vi, de facil adaptacion a otros formatos

Pero la ganadora, amenos por ahora es la opcion 3: abrir el libro con el simbolo
lambda (no, no **↦**) **λ**, dedicado a
rocket [*Programando con Racket 5*](http://aliamondano-eo.wikidot.com/racket-5)
y distribuido bajo licencia Creative Commons Attribution-Noncommercial-Share
Alike 3.0.

Si tienen efectivo, comprarle un libro o darle dinero

... luego de haber pasado por la "Introduccion a emacs lisp", "Land Of Lisp"
(que mecanografie y traduje hasta el 20%) y un truncado intento por
mecanografiar "ANSI Common Lisp", la unica conclusion optenida es que la
trancripcion y traduccion no son metodos validos para aprender otro lenguaje, a
programar o a escribir ...

## interpretes

Dejando de lado la charla anterior, sobre libros que no he leido... pero que
cuando lees y esperas "dominarlos" debes poner en practica sus enseñansas, les dejo una
reducida lista de los interpretes de Scheme que he podido catar.

(para lisp razo, ir con clisp)

### guile

Pagina Oficial: http://www.gnu.org/software/guile

(Ver lo que le han hecho a la pagina de Guile y otras tantas del *proyecto GNU*,
si dan ganas de darles dinero o comprarles lo que sea que vendan)

Freidora 25, que es lo que estoy usando trae la version 2.0, de los tres
interpretes es el menos amigable, no viene con atajos de teclado, la entrada y
borrado se limitan a escribir y retroceso, sin historial ni naaaa, teniendo el
proyecto GNU una de las librerias mas utilizadas para estos menesteres, es aun
mas incomprensible

### kawa

Pagina Oficial: https://www.gnu.org/software/kawa/index.html

Chan, chan, chan, (insente aqui el rugido de godzilla). Joder, este interprete
aparecio en el repositorio, luego de un `search` y hasta el momento es el que
mas habia utilizado (que realmente es poco) y tambien miembro de proyecto GNU
y... corre sobre Java y... tiene todas las comodidades que se esperan de un
interprete de linea de comandos: historial y edicion

Si, si lo encuentran probar

### racket

Pagina Oficial: https://racket-lang.org/

La cleptomania de libros electronicos (ja, que raro suena
"e-l-e-c-t-r-o-n-i-c-o-s") me hiso (no) conocer este
interprete/lenguaje/dialecto de lisp/scheme, que segun el libro "programando con
Racket 5" (antes mencionado y enlazado) contiene en sus entrañas todo lo
necesario para correr scheme.

Este no lo encontre en los repos, asi que debe descargarse
desde
[su web](https://download.racket-lang.org/racket-6-10-x86_64-linux-sh.html).
**!!!Cuidado!!!**, con seguir alguno de los enlaces que hay aparecen
directamente pues en el momento de escribir esto (version 6.10) el contenido es
un script bash de 118M, al seguirlo con firefox, se colgo un rato, y al abrirlo
con el `less` crashearon todos los `tilix` en ejecucion (en masa), la causa? en
sus entrañas contiene un tar "enbebido" (probablemente lo mas raro que me he
topado, pues no esta en base64) asi que en lugar de seguir el enlace darle con el
boton derecho y "copiar la ruta de enlace", ir directamente a un terminal y
conseguirlo con un `wget`.

Luego darle permisos de ejecucion al `*.sh`, ejecutar y seguir las
intrucciones. Para istalarlo en el sistema, ejecutarlo como root, contestar
`"yes"`, luego enter, enter, ..., enter. En caso contrario ejecutar como usuario
de a pie y leer lo que pide. En caso de error, leer donde coloco el binario
`racket-uninstall` y ejecutarlo

Ademas del interprete, se instala un compilador, un IDE y otras cosas que aun
desconosco

El interprete en si, esta mas cerca de la experiencia de kawa, pero no incluye
todos los "atajos" de edicion.

happy l-a-m-m-m-m-m-b-d-a-s-s-s-s-s-s-s-s!
