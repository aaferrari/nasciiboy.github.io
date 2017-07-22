+++
tags = [
  "morg",
]
title = "yorozuya"
draft = true
date = "2017-03-14T16:33:15-06:00"
categories = [
  "prog",
]

+++

*Yorozuya* en una tienda donde se toma cualquier tipo de trabajo por una
tarifa... bienvenidos los encargos!

![](../yorozuya.jpg)

bueno, bueno, matizando un poco y conectado con la saga de post
sobre [morg](https://nasciiboy.github.io/tags/morg), me encontraba aprendiendo
golang y para tener una referencia rapida del lenguaje, pase el libro oficial
(apartir de un pdf) a morg ([AQUI](../tgpl.zip) el material, fuente, resultado e
imagenes). Aun le falta una revision <q>fina</q> que ire realizando a medida que
avance su lectura, aunque la actualizacion quisa solo vea la luz cuando aparesca
el proyecto morg al 100%.

Por cierto, aunque solo he leido (medio entendiendo english) hasta el capitulo
2, el libro promete a lo grande, eso si como no se hagan los ejersicios dificil
sera dominar el asunto.

Claro que hay mas cosas de donde salio esta! como: *The Land of Lisp*, *Clean
Code*, *Programmer's Guide to NCurses*, *The C programming Languge*, *In the
Beginning was the Command Line*, *matematicas para programadores*, *elisp*,
*arduino projects for the evil genius*, *openGL game programming*, *rama*,
*dune*, *el fin de la eternidad*, *3012*, *Fahrenheit 451*, *El calculo de
dios*, y otros tantos a medio hacer. Las novelas las adapte para obligarme a
leerlas y los libros para averiguar si eran interesantes, ademas de prara
practicar mecanografia transcribiendo unos 5 de ellos (la dislexia y poca
habilidad literaria es un defecto incorregible). El asunto es que este es el
primero (o mejor dicho el ultimo) que cumple con la sintaxis actual

El proceso de adaptacion fue sencillo, pero fueron necesarios pequeños ajustes
al exportador. Lo mas complejo fue hacer una funcion que convirtiese las tablas
a html y agregar un comando para crear columnas. Siendo sincero no me complique
mucho y dichos comandos son en realidad muy basicos.

Ademas descubri que mes mejor exportar el comando `"` como `<q>` en lugar de
`<cite>` (internamente se ve mejor) y que no es buena idea colocar targets
dentro de los encabezados, por que al generar la tabla de contenidos hay una
coalicion de identificadores, a menos que se desactive la intepretacion de
contenido en la tabla de contenidos, peeeroo, si el exportador ya genera un
blaco automagicamente, por que habria que crear target adicional?

Como el documento no tiene formulas matematicas, no tuve que lidiar con latex,
ni buscar un generador de texto a imagen, por otro lado, el material esta lleno
de referencias (enlaces), y <em><q>citas</q></em> (commillas dobles), asunto que
dificulta (pero no imposibilita) la lectura del documento fuente en texto plano

El resaltado de codigo se realiza con pygments, asi que si quieres comprobar que
morg funciona tiene que tenerlo instalado (y esperar un rato, python es
<b>lento</b>), o en su defecto eliminar `pygments` del comando de configuracion
`..options >`

Por cierto, la imagenes las optuve con capturas en png. Para hacer ligero el
resultado converti a jpg, ho, y un par de imagenes (graficos) las hice con texto
plano, en el fuente se ven bien, pero en el html las exporto como codigo, asi
que desentonan...

En fin, si el resultado o el metodo es de tu agrado y deseas que adapte un
documento o cooperar con la causa, recivo pedidos. El precio por algo de similar
complejidad a la muestra, es de 500 euros/dolares (en nasciiboy inc. no hay
sobreprecio). El proceso de adaptacion toma entre 1 o 2 semanas de tiempo ocioso

pd: tambien son bienvenidas las criticas al estilo visual
