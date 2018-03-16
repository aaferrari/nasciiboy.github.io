+++
categories = ["prog"]
date = "2017-07-04T18:47:44-05:00"
tags = ["morg"]
title = "morg [dia 432]"
+++

![](/img/BOM.jpg)

sin un titulo interesante y sin esperar una secuencia tan armonica, confie a un
programa informatico de internet la tarea de calcular los dias desde el primer
commit del repo de morg, no por ningun hecho revelante y menos por un desarrollo
agil, que es mas bien paralitico

bueno, el programa exportador llevaba parado un rato con un bicho enorme, mientras continua el
aprendizage del lenguaje Go, a la espera de una refactorizacion, pruebas y demas
cosas necesarias, asi pues cuando me decidia a probar a exportar o visualizar
algun libro recien maquetado, optenia un log inverso de panicos y direcciones
de memoria exadecimales. Toque aqui y un poco alla, sin comprender el problema,
hasta que un momento de aburrimiento y terquedad irracional me guiaron por la ruta dificil...

en una revelacion mistica, pense que el problema era la codificacion del
documento, quiza no estaba en utf-8 puro (que es lo unico que acepta el exportador)
asi que con un `file`, el fichero en cuestion decia tener un *BOM*, "o, hay esta
el problema –me dije"... mas bien no, al parecer es algo que se descarta mientras se lee
el fichero, pero por cualquier duda, los pase a utf-8 sin el BOM (en emacs `C-x
Enter f`, se abre un prompt, e introduces la codificacion, `utf-8`, pero
tambien vale con `unix`)

luego, en una muestra de ingenio impresionante, tome un manual de muchas muchas
lineas y comence a quitar y guardar cosas hasta encontrar la linea que hacia
explotar el programa, el culpable era un *bloque de comando*, sin
definir.

Dentro del codigo el error se devia a exportar un bloque vacio... y no
considerar tal indudable posivilidad, provocada incluso por un error tipografico

he, he, ya mencione que generalmente programo sin considerar los casos de error
y que el programa no notifica nada para ningun fallo... fiel a mis costumbres
le hice unos pequeñøs ajustes, que tambien suponen datos de entrada
correctos...

entre los cambios, inclui el comando `srci` para "simular" un prompt de algun
lenguaje, es decir, colocas la supuesta entrada en un determinado lenguaje y
tambien su supuesta salida, sencillo, no?

un comando `tab` para separar un poco de la izquierda cualquier cosa

el comando `pret`, de "texto pre", es decir, es texto, cada linea es un
parrafo, pero se visualiza como pre

un comando `verse`, para versos y tambien un "separador" para los libros, que
ahora recuerdo olvide implementar, bueno no importa

todo fue implementado de forma fugaz, por mis ancias de exportar el [sicp en formato morg](https://github.com/nasciiboy/sicp),
tiene tanto cruft que se pega en la ropa! pero hey! solo es una prueba de
concepto, ya tengo una mejor idea de como implementar algunas cosas (algun dia)
y tambien he visto la necesidad de esconder la implementacion de los
exportadores del formato, haciendo que la estructura principial se "desenrrolle"
sola, el programador devera proporcionar solo las reglas para cada elemento, o
esa es la idea, veremos si puedo hacerlo o siquiera visualizarlo, pues hay es
donde radica la magia de la programacion, si eres capaz de imaginar una
estructura funcional, es problable que la puedas implementar (como en el kung-fu)

me tome la libertad, y ya que esta version sera la ultima con el anterior
enfoque (desechable) de segir utilizando pygments para el resaltado de codigo
(go-highlight es un timo), e incluir el javascript de *Mathjax* para hacerse
cargo de unas pocas formulas matemagicas de la version exportada del sicp. De
igual forma no le meti mano al visualizador de linea de comandos, pues considere
que seria un esfuerzo futil

no modifique mucho mi hoja de estilos generica, sera tarea para otro dia mientras preparo
un discusito para pedir financiacion para la traduccion del sicp, continuar el
desarrollo del morg, comprar un par de monitores, una estacion de trabajo y
aspirar cocaina sobre el cuerpo de unas japonesas en nagoya

tambien puse a prueba el morg con los 4 libros de Ender, pero ese material, ya
tendra su propio post
