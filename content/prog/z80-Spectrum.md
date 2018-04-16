+++
title      = "Z80 Spectrum (tutorial speccy.org)"
tags       = [ "asm" ]
categories = [ "prog" ]
date       = 2018-04-15T21:36:36-05:00
+++

Entre aprender diseño de software, administracion de sistemas, elisp, ingles,
mates o cualquier otra asignatura que pudiera servir a desarrollar alguna habilidad
"productiva", he pasado parte del ultimo mes investigando la programacion
en ensamblador para una plataforma con mas de 35 años de antiguedad

La razon? los videojuegos! no por ser un jugon de pro (que ni consola tengo). Tampoco
esperando petarla con una creacion indi, sino por la mera admiracion a algunas
de las pocas obras que he podido catar (megaman y cave story).

Tras topar con un [tutorial](http://wiki.ladecadence.net/doku.php?id=tutorial_de_ensamblador)
(en español) sobre programacion en la GameBoy y comprobar que todo su codigo
fuera efectivo, al igual que las herramientas propuestas. En el recomendaban
como primer paso seguir el material del que vengo a comentar, porque como buen
robot que soy, hago caso a lo que se me dicen (generalmente (si biene en un
documento (y parece de interes))). Asi que antes de afrotar lo
relacionado al GameBoy (aunque tenia mas interes en aprender sobre la NES)
veamos este material

El [Curso de Ensamblador Z80 de Compiler Software](https://wiki.speccy.org/cursos/ensamblador/indice)
alojado en Speccy.org (para abreviar de aqui en adelante: "el curso", "el
tutorial" o "z80-speccy") se centra en la programacion en ensamblador, cosa que
festejo, primero por agregar el (Sr) ASM a las cosas que he probado, ha, ha, con lo
imponente que es decir ASM en frente de las personas y quedarte tan agusto

Segundo, porque luego de cacharrear con un par de lenguajes de programacion y
librerias, llego a la conclucion de que la mejor forma de conservar un
videojuego (o programa en general), eliminando distracciones, inconsistencias y
apaños, es hacerlo para una plataforma hardware (o software) consolidada e
inmutable. Y como nadie va a venir el dia de mañana a cambiar el hardware de la
NES o SNES, N64 o la GameBoy (las plataformas que me interesan) creo que si me
apego a las bases (mas basicas) de cada una de ellas hay quedara, por el resto
de los tiempos, mientras el sol, la luna, los evas, las computadoras y los
emuladores sigan existiendo.

Tercero, ademas de colgarme la medalla de "programar en ASM", conocer mas de cerca
la naturalesa metalica de la programacion, sin adornos, ni abstracciones era
algo que deseaba hacer desde el inicio. Dejar de lado las artilugios abstractos
y ver a la cara la realidad

y finalmente, el material esta en español que es una exepcion a la regla, ademas
con lo poco documentado que esta el desarrollo para las plataformas "vintage"
(que me interesan) aun siendo algo mas bien exotico (el Spectrum) tras concluir
la lectura, abre la puerta hacia nuevas plataformas. Despoja y desmitifica el
respeto mitificado que rodea a la palabra ASM, y en ultima instancia como
esperaba, la comprension (aunque aun superficial) sobre *"la maquina"* ha visto
incrementada su barra en unos cientos de puntos.

El material es extenso, como para un libro, los capitusos detallados y con mucho
codigo, siguendo un orden coherente y mas o menos progresivo. Digo esto ultimo,
porque hay que aprender un monton de caracteristicas antes de comenzar a verlas
en funcionamiento, y esto, como en las matematicas puede desmotivar al no ver
una aplicacion directa a cada nuevo aprendizaje.

Ya por su propia naturaleza, el ensamblador puede echar para atras a mucha
gente, y si la documentacion esta en un lenguaje ajeno (ademas de poco dominado)
es motivo suficiente para evitar el reto, mas con lo expuesto en este tutorial
es suficiente como rito iniciatico (y material de referencia). Es necesario
aclarar, que el material termina antes de construir un viedeojuego, de hecho
finaliza justo antes de mostrar como realizar animaciones

Se incluye muchas rutinas, una herramienta de ensamblado programada en C y
compilable sin mayores dificultads que escribir `make` (de hecho incluyen un
emulador construido por el tutorialista... compilo, pero no era una opcion en
mi maquina, se apodero del "modo grafico" (fullscreen (a dos pantallas)) y no
tenia boton de cerrar). Tambien se recomiendan emuladores (para GNU `fuse`),
programas de dibujo y otras varias utilidades, aunque la mayoria desarrolladas
para winbugs, ejutables (segun cuentan) con wine. Todo esto aderesado con
ricos packs de enlaces a webs con aun mas material relacionado

web, a web se aprecian los profundos y obsesionados misterios relacionados no
solo con el Spectrum, sino con su procesador. En toda regla un abismo truculento
de enlaces que lleban a sitios tan llenos de entusiasmo y nerdes, que... no
estoy seguro de querer formar parte de ello... mientras un viejillo carcacarrabias
advierte "no vayas por hay, no vayas por hay". Mas para que la trama tenga algun
interes, es bien sabido que se ha de terminar en ese lugar en un momento u otro.

Quiza, de entre los enlaces que apunta *el manual* encuentro de lo ma
extravagante http://www.ticalc.org/ un sitio dedicado a las calculadoras
programables, sus juegos desarrollados en asm (variantes del Z80) y aun mas los
[emuladores](http://www.ticalc.org/programming/emulators/software.html) que para
estos aparatos se desarrollan, incluidos sistemas operativos y "aplicaciones" de
todo tipo

en particular probe a compilar con dos emuladores: firebird

    # clonar su repo asi
    git clone --recurse-submodules https://github.com/nspire-emus/firebird

que al invocar el ejecutable congelo el sistema por completo y (a menos que se
tuviera m-u-c-h-a paciencia) sin retorno

como tambien [Cemu](https://github.com/CE-Programming/CEmu) (no relacionado con
el emulador de gamecube). Este no rompio nada, mas no logre descifrar el orden de
invocacion apropiado de rom, flash (o algo asi) que lo haria despertar

como anotacion, los procedadores de estas calculadoras programables,
apenas y tienen mas potencia que sus variables prehistoricas... pero no por ello
significa que sean aparatos economicos (al menos para mis presupuestos tendentes
a cero)

resumiendo, entre todas las plataformas que cuentan con el chip z80, su
simplicidad y el (ahora) variado, entusiasta y obseso mundo que tiene al
rededor, luego de aprender sus bases invariablemente obliga a tomar una
desicion, quedarse en el pais de las hadas (obesas y sudorosas) del z80 o
cual mision treki, continuar en busca de nuevas aventuras

### el vaile de hanoi

> Es un ejercicio inútil que, en el mejor de los casos, te confundirá y, en el
> peor, te dará la ilusión de que entiendes lo que está sucediendo. Los
> compiladores y CPUs modernos son indistinguibles de la magia. Cuando se
> enfrenta a una elección como la presentada por OP, escoja la versión que tenga
> más sentido para un lector humano y confíe en que el compilador haga su
> trabajo.
>
> (comentario en reedit, post [Is it better to write a < 11 instead of a <= 10?](https://redd.it/8c03xq))

Las [torres de hanoi](https://es.wikipedia.org/wiki/Torres_de_Han%C3%B3i) es un
rompecabezas donde los pasos a realizar para llegar a la solucion son bastantes
sencillos de entender, mas seguir un orden preciso en el intercambio de las
piezas es imperativo si es que se desea reducir la ya por cuenta propia ingente
cantidad de movimientos necesarios en la resolucion. Je, de este juego
visualizando aquel movimento en el puzle, ademas de encontrando cierta similitud
entre un limitado numero de registros donde se debe de copiar, mover, sumar,
restar recorrer y realizar operaciones, surgio eso del *vaile de hanoi* (eres un
heroe). La analogia debe ser mas bestia en un procesador moderno, de esos que
realizan prediccion de instrucciones y tienen nucleos multiples

Las bases del asm del z80 son faciles de asimilar, sin embargo, entre eso y
aprender las ~70 instrucciones (documentadas), las variantes de uso que tienen
(memoria, registros, modificacion a banderas), los registros en si mismos,
banderas, tiempos de ejecucion (t-estados) e interrupciones (por no mencionar la
relacion con el hardware de dibujado de pantalla, teclado y accesorios) no es
una tarea ni de cerca sencilla.

Por la barrera de conceptos minimos necesarios para comenzar a realizar algo
vistoso, y la necesidad de arrastrar los que se van presentando (no muy
didacticamente) aplicandolos a un dispositivo autista (que ni vez,
ni olles, ni hueles) sugiero tomar la lectura del documento en "modo turista";
es decir, leer superficialmente, recoger la idea principal o conocer que existe
"algun algo" y, ya si eso, terminada una primer visita determinar si volverias
al lugar a aprender la lengua, comer la comida y quiza volverte un residente.

El acermatiento que tome fue de leer y ejecutar todo hasta el capitulo 10
(aprox). Desde ese punto solo capturar la escencia, sin considerar las
truculencias del codigo, pero aun ejecutando los binarios para ver sus resultados.

Lejos de lo que creai, el ensamblador proporciona muchas facilidades, como
insertar distintos tipos de datos, en distintos formatos (incluidas cadenas de
texto) automaticamente en una direccion de memoria. Tambien proporciona
constantes, alias para las direcciones de salto, y la comodidad de establecer la
direccion de inicio para el codigo, lo cual, ofrece en la practica aquello
que en otros lenguajes vendrian a ser abstracciones basicas como las fucciones

No obstante, la gestion de que registros utilizar (y no utilizar), el uso de la
pila (que esta en la memoria), y operaciones directas con la memoria, no es algo
a lo que se dedique una seccion explicita, solo algunas menciones poco
profundas. Aun asi, si se tienen estas limitaciones en mente, supongo que no
debe ser muy dificil adaptarse.

Quiza lo mas dificultoso de utilizar en asm del spectrum, es no tener una
referencia sencilla con respecto a la posicion de ejecucion del codigo y el
estado global de lo que ocurre en el procesador, ademas de verificar el tiempo
global antes de las interrupciones, por ejemplo, conocer en que direccion esta
leyendo la pantalla la dibujando la ULA. (Encuentro comodo eliminar la necesidad
de timers, y esperar la interrupcion de dibujado)

Lo otro dificultoso, tiene que ver en como se organiza la memoria de dibujo, que
no es lineal. Los graficos del spectrum no estan optimizados para dibujar
graficos, sino caracteres, y por ello (segun cuenta el texto) los diseñadores
llegaron a la conclusion que lo mas eficiente era dividir la partalla en tres
secciones y cada una de estas en lineas intercaladas de lo que verdrian a ser
los caracteres y esto aunque salvable por "rutinas", no me gusta.

Otra cosa que no me gusta (y si encuenro un sistema que no lo contenga, no
regresare al Spectrum) es el ROM de basic. He, no lo controlo, esta hay ocupando
espacio y lo que hace es ejecutar BASIC. Si, cuenta con codigo reutilizable (no
portable) mas preferiria montareme un ejercito de rutinas por separado antes que
utilizar las que provee el aparato (varia de una version a otra del
Spectrum). Entiendo la necesidad en su tiempo de incorporarla (aunque podria
haber venido en un carchucho (cinta)) pero tenerla permanentemente, es como tener un
pixel muerto en la pantalla y verlo siempre.

Salvando esos inconvenientes, la falta de un visor global de los estados del
procesador, un contador que lleve un registro del tiempo disponible entre
interrupciones, la posicion de la ALU, mensajes de error de parte del
ensamblador, el basic, la extraña organizacione de la pantalla, la no
ortogonalidad del procesador, las instrucciones no documentadas y el lento
acceso a memoria, me ha gustado el procesador, por su transparecia en lo que
hace, no traer ningun sistema de proteccion ni ninguna gilipolles imbecil y lo
relativamente amigable que es el ensamblador (el lenguaje) que en el tutorial proponen

en mi novel ingorancia, si se pudiera, me gustaria tener un procesador con
almenos 512KiB de memoria sin latencia, entre 1 y 10 MiB de memoria con latencia,
y registros varios de 16 y 32 bits, casi todos ortogonales... y por pedir a
1GHZ, ja, ja, seria divertido trastear con eso.

## cobaya

la ultima modificacion al documento segun el sitio acurrio en 11-12-2010. Como
este sitio (ni ningun otro) tiene asegurada su permanencia en la red, y por
que prefiero leer tochos monopagina en lugar de secciones, respalde el manual,
lo puse en una sola pagina, cambie el estilo a un color negro y de paso aplique
`wget` a todas los sitios enlazados y los coloque en un repositorio (https://github.com/nasciiboy/Z80-Speccy)

No contiene una copia de todos los sitios (son mas de 12GiB), solo algunos, unicamente los
mas necesarios y algunas aplicaciones revelantes, las suficientes como para no
necesitar de internet para su estudio.

Aunque el html, ya era simple, lo simplifique aun mas con el objetivo de
cobayizarlo, pero de momento al desconocer la necedidad que de el tenga en el
futuro, no realizace la transcicion. Como las manipulaciones fueron muy a
mano, seguramente el html este roto por algun sitio.

alguna pagina como manuales.speccy.org sufrio modificaciones con `find`, `sed` y
`rename` en sus php cosas para convertirlas en html cosas. Primero aplique un
cambio en los enlaces internos con


    find . -type f -print0 | xargs -0 sed -i 's/\.php/.html/g'

y despues un renombre a los ficheros en si

    find . -name "*.php" -exec bash -c 'mv "$1" "${1%.php}".html' - '{}' \;

(ambos scripts, salidos directamente de stackoverflow)

y eso es todo, continuare con GameBoy, donde espero encontrar la mayoria de
caracteristicas que deseo, como pueden ser solo tener los minimos botones
necesarios, mayor configuracion de estos (no como el extraño comportamiento de
fuse el emulador de Spectrum), no encontrar un "OS", una memoria de video mas
amigable y un sistema de proteccion inexistente (ja, ja, ja) o almenos tan
sencillo como para ignorarlo.

... hoooooOOO, si! hay un programa que emula la lluvia de matrix en el Spectrum,
su codigo esta [aqui](/data/matrix-rain.asm) y lo encontre por [aca](http://www.retroprogramming.com/)

<center>
![](/img/matrix-rain-z80.png)
</center>

Bye, Bye
