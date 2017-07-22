+++
categories = ["vg"]
date = "2017-07-20T22:21:43-05:00"
draft = true
tags = [""]
title = "SShooter"

+++

> ¿Es posible que el software no sea como cualquier otra cosa, que está
> destinado a ser descartado: que el punto es siempre verlo como una burbuja
> de jabón?

El SICP esta lleno de fraces que reflejan la realidad, incluso la del "codigo
abierto", por que (casi) sin importar el titulo, si su desarrollo para,
seguramente quede destinado a desaparecer en la memoria de unos cuantos

Quiza por ello el desarrollo mas puro y duradero, es el que se realiza para
equipos especificos, por ejemplo en algun ensamblador de alguna consola
especifica, como la nes o el gameboy. En el PC, las cosas no son iguales, y aun
contando con el codigo, cuando no es extraordinariamente bueno, independiente
de modas y portable, dificilmente sobrevivira al cambio continuo de librerias...

Como es el caso de los dos (y quiza tres) siguientes juegos, todos de genero
"matamarcianos". No es que sea ningun conocedor, de hecho con estos solo he
jugado 4 (mas un par mas en el movil), el cuarto y primero (o segundo quitando
uno de nes), el maravilloso Star Fox 64, al que no puedo jugar por que el
emulador es demasido exigente para mi equipo maizoro

problablemente no puedan jugar a ninguno de ellos, pero de los pocos que
hay que pueden (o no) existir en el software libre, son de los mejores

## tumiki fighters

![](/img/tumiki.jpg)

Creo que esto tiene licencia mit, y creo que podia jugarse con el mando. El
primer encuetro con el fue en los repositorios de debian, y espero que
todavia siga hay, por que compilarlo me ha sido imposible

Esta hecho con el lenguaje de programacion **D**, del cual desconosco su
bondades, aunque de popularidad no puede presumir. Su autor, un japones durante
un tiempo se dedico a programar algunos juegos y dejar a disposicion el codigo,
pueden encontrar mas en su [pagina](http://www.asahi-net.or.jp/~cs8k-cyu/windows/tf_e.html) (ingles y
japones).

En principio sus juegos fueron diseñados para correr en winbugs, aunque hay (o hubo) [uno](http://tumiki.sourceforge.net/) o dos
intentos de portarlo a GNU/linux, que no pude compilar fuera de
debian. Curiosamente la forma mas sencilla de jugarlo es con wine

De los tres juegos mi favorito, me encanta su estilo y colores. En
cuanto a dificultad... no es para lisiados, nunca pase del tercer escenario

## garden of coloured lights

![](/img/garden.jpg)

Este juego tambien nacio en winbugs, pero a diferencia del anterior es GPL3 y
esta programado en C, pese a esto tampoco lo pude compilar, no busque la web que
lo vio nacer (alguna ves lo hice). Algo curioso es que aparentemente sigue en
desarrollo al menos en la [forja del codigo](https://sourceforge.net/projects/garden/) cambio de la
version 1.0.8 a 1.0.9

probar a compilarlo, la ultima vez que lo jugue fue en debian (incluido en los
repos), de los tres, el tercero en mi listado de buenos juegos libertarios de disparos

## Blue Revolver

![](/img/blue-5.jpg)

Hecho con [love2d](https://love2d.org/), aunque no por ello precisamente
software libre... sus creadores lo distribuyen ademas de ejecutable, como un
<code class="file" >.love</code> que es un simple <code class="file">.zip</code>
con el nombre modificado, que alberga el codigo y datos del juego, asi que de
alguna forma difusa podria considerarse de "codigo abierto", o almenos se podria
aprender algo y modificarlo a nivel personal (y quiza mas alla)

En su [pagina](http://bluerevolvergame.com/) encontraran un enlace a itchio una
pagina de juegos "indies", en donde ofrecen un demo con las primeras 2
misiones. La primera vez que vi este juego pesaba solo 15mb, ahora son mas
de 300! Aun se encuentra en fase de desarrollo, una muy larga fase de
desarrollo... si alguien compra el juego y me envia una copia no me molestare...

como decia, el juego esta desarrollado en love2d, exactamente con la version
0.9.1 (ja, ingenuo de mi, crei que la sugiente version de love seria la 1.0,
que tendrian una "API" estable y seria el momento de echarle un vistazo en
serio, pero los troles pasaron a la version 0.10.0).

La version actual de love es la 0.10.2 y el juego no correra con esta, incluso
modificando un fichero llamado <code class="file" >conf.lua</code>. Uno de los
inconvenientes de love, radica que entre version y version los juegos
dejan de funcionar, asi que vamos a compilar la version 0.9.1 (o si nuestra
distro trae esta version nos ahorramos el paso)

conseguir dependencias

    dnf builddep love

o en debian

    apt-get build-dep love

```
wget https://bitbucket.org/rude/love/downloads/love-0.9.1-linux-src.tar.gz
tar -zxvf love-0.9.1-linux-src.tar.gz
cd love-0.9.1
./configure # cruzar los dedos y esperar
./make      # de nuevo cruzar los dedos y esperar

# si todo fue bien
./src/love ruta-a-juego.love
```

![](/img/blue-7.jpg)

el juego es una pasada, el unico inconveniente es la resolucion, no se si
modificando la posicion del monitor, aparescan nuevas resoluciones, en cualquier
caso es una maravilla que acepta mando y configuracion de botones

como dirian en un podcast (de anecdotas, historia contemporanea y musica
rollmantica) llamado *ScoreVG*, disfruit!
