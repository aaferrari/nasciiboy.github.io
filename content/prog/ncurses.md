+++
tags = [ "ncurses", "howto" ]
title = "Ncurses"
date = "2016-12-19T21:45:05-06:00"
categories = [ "prog" ]
+++

## Que es Ncurses

Es una libreria (parte del proyecto GNU) que nos permite crear **TUIs** (Text
User Interface) escrita en lenguaje de programacion **C** con *envoltorios* para
algunos otros lenguajes. Se utiliza principalmente en el sistema GNU/linux y en
los derivados de BSD y probablemente tambien corra en el sistema de las ventanas
mediante minGW (Minimalist GNU for Windows).

Proporciona funciones para «dibujar» caracteres en la pantalla con hasta 256
colores disponibles (si la terminal lo permite). Despues de conocer `mvwprintw`
utilizar `printf` es igual a sufrir alguna incapacidad. Tambien nos da la
posibilidad de modificar varios atributos de la tipografia como pueden ser
**negrita**, *italica* o <u>subrayado</u>.

finalmente nos ofrece la posibilidad de tener acceso completo al teclado y
raton.

## Por que programar TUIs

Bueno, es una foma muy sencilla de crear una interfaz «visual» sin morir en el
intento y como fiel creyente de la iglesia de Emacs creo que *el texto es la
unica interfaz verdadera*. Si planeas aprender programacion de videojuegos
tambien encontraras que es mas sencillo interactuar con caracteres en lugar de
con pixeles (aunque en el fondo sean lo mismo)


## Como aprender a programar con Ncurses?

complicado lo tienes... solo existe un mini-manual (NCURSES Programming HOWTO) y
un libro (Programmer's Guide to NCurses) (ambos en ingles) para aprender lo
basico del tema.

Tampoco leer codigo ayuda mucho, sobre todo el codigo fuente de la propia
libreria (es muy raro).

Hace ya un tiempo dedique algunas tardes a traducir el minimanual, puedes encontrar
lo fundamental en este [zip](../ncurses-programming-howto.zip) y el resto en un
repositorio en [github](https://github.com/nasciiboy/NCURSES-Programming-HOWTO).
No ha sido revisado, y la traduccion  se realizo con el "traductor de
internet". En el repositorio encontraras los fuentes en formato org-mode de
emacs, en algun momento (o años) le dare alguna revicion y quizo se
actualice. Si te es de `interes && utilidad && y-lo-mejoras` no dudes en
enviarme el resultado

quiza en un post/tutorial futuro ponga algun codigo interesante del tipo "como
programar un tetris" o algo asi...

ps: tengo una traduccion (ilegal) de el libro casi terminada...

ps 2: actualmente no me gusta ncurses, principalmente por que no entiendo su
codigo fuente, y porque es un "todo en uno", preferiria que la interaccion con
el teclado, el mouse e incluso joystick fuesen librerias independientes
