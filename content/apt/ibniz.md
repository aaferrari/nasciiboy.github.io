+++
title      = "ibniz"
tags       = [ "ibniz" ]
categories = [ "apt" ]
date       = 2017-10-30T15:45:27-06:00
+++

![](/img/ibniz.jpg)

<blockquote>
<p>IBNIZ es una máquina virtual diseñada para programas audiovisuales de bajo
nivel extremadamente compactos. El objetivo principal del diseño es la
utilidad como plataforma para producciones demoscene, arte de <a href="https://es.wikipedia.org/wiki/Glitch">glitch</a>(es) y
proyectos similares. Los aspectos de ingeniería de software del equipo
principal se consideran totalmente irrelevantes.</p>

<p>IBNIZ significa Ideally Bare Numeric Impression giZmo. El nombre también se
refiere a Gottfried Leibniz, el polimatemático del siglo XVII que, entre
otras cosas, inventó la aritmética binaria, construyó la primera máquina calculadora
de cuatro operaciones, y creía que el mundo estaba diseñado con el principio
de que un conjunto mínimo de reglas debía producir una diversidad máxima.</p>

<p>-- extraido del <a href="http://pelulamu.net/ibniz/">sitio oficial</a></p>
</blockquote>

me encotraba en un taller del hackmitin y durante esa charla un "ranchero"
estaba con un wallpaper muuuuhh raro con cosas graficas extrañas y daba la
vaga imprecion que lo controlaba con una especie de brainfuck.

Por un momento imagine que era una extraña herramienta para ver la instalacion
de programas (o trafico de red o procesos o algo asi) de forma psicodelica, por
lo que tuve que preguntar que jodidos era eso y me dijo que se llamaba ibniz y
estaba dentro de los repos de debian, aunque casi no conocia documentacion de
como funciona

mas tarde lo pude instalar de los repos de debian (`apt install ibniz`) y efectivamente era esa cosa
rara.

Para los que se encuentren en arch esta dentro de AUR y para los demas su
repo es https://github.com/viznut/IBNIZ, aunque su codigo se dejo abandonado (o
quiza se considero terminado) hace 6 años

## Que es exactamente?

aqui hago una contraccion de los ojos hasta parecer asiatico y tambien me
pregunto que jodidos es... no estoy muy seguro, como que te visualiza la memoria
de un algo y tambien hace ruiditos de las operaciones matematicas que le metes
(*advertencia*: antes de ejecutar bajar el sonido, pues puede ser agobiante)

tiene licencia zlib y si quieres compilarlo necesitaras tener las librerias SDL
1.2 y tambien algunas de X11, en mi caso como casi siempre ya las tenia
instaladas y con el siguiente proceso basto

por cierto, el repo que aparece en AUR es un fork del proyecto original con la
ultima modificacion fechada hace un año y por ello es la que tomo para la
instalacion, ademas tiene una seccion con ejemplos interesantes, como un
mandelbrot. Obviamente por las fechas el codigo difiere del original en algun
punto, una muesta de esto es contar con mas opciones en la linea de comandos y
que al menos el ejemplo del mandelbrot no me funciono con el programa original

## instalacion a mano

``` sh
git clone https://github.com/PoroCYon/IBNIZ/
cd IBNIZ
make
./bin/ibniz
```

para probar algunos ejemplos (ejecutando bash)

```
./bin/ibniz -c "$(cat examples/ibnizdemo.ib)"
./bin/ibniz -c "$(cat examples/mandelbrot.ib)"
./bin/ibniz -c "$(cat examples/julia.ib)"
./bin/ibniz -c "$(cat examples/bitmapzoomer.ib)"
```

### Uso

si presionas `TAB` aparece/desaparece el editor del "codigo de entrada", si este
esta visible y presionas `F12` aparece la ayuda

cuando as puesto una entrada formada por operaciones y algunas funciones, la
puedes *hechar a andar* (y detener) con `F1`, reiniciar con `F2` y terminar con `ESC` y ya esta, basicamente eso
es todo, tienes algunas funciones basicas para la edicion del texto y tambien
puedes ir probando lineas comentando y descomentando codigo

un buen ejemplo para iniciar es ejecutar lo sigiente

```
./bin/ibniz -c "$(cat examples/oneliners.ib)"
```

abrir el editor (con `TAB`) y comentar/descomentar lineas

la opcion `-c` es para pasar tu "codigo" desde el aranque, por ejemplo,
tonteando aparecieron dos patrones que me gustaron bastante

``` sh
./bin/ibniz -c '4*r+q'
./bin/ibniz -c '45*r+q'
```

para finalizar, hay varios forks mas de ibniz, el que tiene la modificacion mas
reciente (hace 6 dias) es [este](https://github.com/jminor/IBNIZ/), ademas tambien trae un
readme, una pagina de documentacion y enlaza a un [demo-tutorial](https://www.youtube.com/watch?v=aKMrBaXJvMs)
super chulo!

happy hacking!
