+++
categories = ["post"]
date = "2017-07-01T15:05:47-05:00"
draft = true
tags = ["ramen"]
title = "Ramen V"

+++

![](/img/inbo.png)

por que si tubiera resuelto el sustento de por vida, seguiria haciendo lo mismo
que hago ahora, hago lo que hago ahora aunque no tenga sustento

lol, y como contar mis pasatiempos dispersos es mas sencillo que programar algo
chulo, la seccion del ramen tendra un flujo constante mientras haya un pc al
alcance

para empezar, sigo leyendo, corrigiendo y haciendo practicas del libro de Go,
que voy por el 56%, mencionar que cada vez me gusta mas el lenguaje con su
peculiar orientacion a objetos e interfaces, de a poco empiezan a calar en el
cerebro

buscando algunos repos de Go por pasar la tarde encontre una libreria que
implementa varios modelos de color (entre ellos HSL) https://github.com/lucasb-eyer/go-colorful,
je, es gracioso que muchas veces solo encuentras lo que buscas, hasta que sabes
exactamente que buscar

tambien y para los ratos donde el sueño/aburricion/tedio no es apto para el
estudio (que es la mayoria del dia) y encaminado a conseguir unas monedas,
ademas de servir al proyecto de "aprender ingles por osmosis" comence y
termine una maquetacion preliminar del aparentemente pilar fudamental de la
literatura informatica el **SICP** (Structure and Interpretation of Computer
Programs)

por lo poco que pude entender, es un exaustivo y amplio libro para aprender a
programar (en un dialecto de Lisp llamado Scheme) cosas variadas, interesantes y
complejas

me resusta dificil comprender por que no hay una traduccion al español ya
terminada, para que no tenga que hacerla yo... bueno hay un [intento](https://github.com/sarabander/sicp) que data del
2014, aunque solo abarca la introduccion y un poco del primer capitulo.

Como el libro esta bajo una licencia permisiva, o eso entendi prentendo hacer
una recolecta o poner un boton de donacion para llebar a cabo ese proyecto en
concreto, que estimo llebara alrededor de 5 a 8 meses para entregar algo bueno
sin (obviamente) llegar a ser profesional, pero eso ya tendra mayor explicacion
cuando concrete una exportacion de morg a html, pues hay un bicho enorme que no
idetifico y el programa de exportacion se rompe... y me llebara almenos una o
dos semanas robustecer el codigo con lo aprendido hasta el momento en go

mientras tanto decidi dividir el comando de resaltado de "cosas" matematicas en
dos: `@m(` para simplemente etiquetar como "esto se supone es una formula o algo"
y `@M(` para indicar "esto es una formula y ha de interpretarse primero" es
decir es latex o algo parecido

tambien agrege un nuevo comando de bloque, con nombre tentanivo `srci` (lo
pronuncio "sorci"), que tendria este aspecto

```
..srci parametros-opcionales > lenguaje
  > (el codigo del lenguaje)
  lo que seria la salida del lenguaje
< srci..
```

es decir, es un bloqe de codigo, que representa una secion interactiva de algun
lenguaje y su salida, de hay la *i* (por interactivo o interpretado), donde
`lenguaje` es el lenguaje en turno, el `>` es el prompt y todo lo que continue
hasta el fin de linea es la entrada en dicho lenguaje (de ser necesario la
entrada se expande por varias lineas cuando terminan con `\`) y lo demas se supone
es la salida, ademas planeo que si el lenguaje es *bash* o similar se admita
como prompt `$` y `#`, asi:

```
..srci > bash
  $ echo "hola mundo
  hola mundo
  # rm -rf /
  ...
< srci..
```

(nota: este tipo de comando es (sera) distinto de un bloque de codigo reproducible,
aunque no descarto la ipotetica posibilidad que tambien sea ejecutable)

si bien el parseo no es muy complicado, seria preferible tener una libreria
customizada y nativa, al respecto encontre dos opciones, aunque ninguna termina
de ser lo que busco

primero [go-highlight](https://github.com/d4l3k/go-highlight) escrita en go, que
resalta el codigo aceptablemente, aunque con el inconveniente de tener las
reglas de analisis de los lenguajes algo *horrendos* (por decir algo) pues estan
en json (de una linea) dentro de una libreria que se parsea y luego se pasa a
estructura.... por que no solo puso estructuras o un json?, ademas depende de
tener instalado pcre (en C), para que el asunto funcione

y el segundo, es una libreria/programa del proyecto GNU, [**source-highlight**](https://www.gnu.org/software/src-highlite/) que probablemente lo tengas en los
repos y hace lo mismo que pygments, pero escrita en C++, con sus lexers (creo
que asi se dice) mucho mas bonicos sin tener las mas de 200000 lineas de codigo
de pygments

este lo quiero estudiar a fondo, aunque estoy oxidado y siempre que toco codigo
ageno termino frustrado, es una capacidad que no logro habilitar en mi
configuracion neuronal por mas que lo intente

mmmm, aunque el asunto parece y supuse sencillo, pase una tarde entera
intentando substituir pygmentize por source-highlight sin coseguirlo, algo
extrañø sucede entre la forma de hacer "evoltorios" de go con el sistema
(paquete `exec`) y como lee y procesa source-highlight la entrada y salida
estandar, en vendad termine frustrado, sin resultado alguno

y eso es todo en cuanto asuntos informaticos

## 4K

**Colosal** Una peli regulera que juega en varias ligas al mismo tiempo:
comedia, drama y creaturas gigantes, todo muy ligero. Si tenia algun mensaje, paso
desapersivido

**La espada sagrada** un anime que entra en la categoria de "cosas que veo antes
de dormir y puede que me duerma en el proceso", naaada, algo que encontre en
yutube, que pasa sin pena ni gloria, es de una chica de pecho exuberante que
quiere ser guerrera pero la derrotan al primer intento y se encuentra con un
interes romantico traumatizado, aderesado con el poder de la determinacion, la
amistad o algo asi... no se por que veo estas cosas...

**Shuumatsu no Izetta**. En un mundo alternativo ambientado en la primer (o
segunda) guerra mundial, la ultima y mas poderosa de las brujas, que se creian
ya extintas, interviene en el conflicto para ayudar a su amiga/interes-romantico
que resulta ser la princesa de un pequeño reino. Bueno, es estretenido cuando se
adelantan las escenas soft-lesbian, jo, que le pasa al anime (o a mi) con los
romances homosexuales ambiguos, se quieren? se desean? o es algun tipo de
fanservice a interpretacion del expectador? no es que esta obra sea nada
grandioso, pero se arruinan con este conflicto(?) sentimentaloide barato

**Little Witch Academia** ver a chikas con varas entre las piernas esta de moda
en japon, aunque, en esta serie dejan de lado el fancervise corrosivo para
contarnos otra historia de determinacion testaruda sobre como una chika sin
talentos de ningun tipo, se esfuerza por algun dia ser como el centro de su
admiracion: la (atractiva) bruja shiny chariot luego de haber asistido a uno de
sus expectaculos magicos. La historia cuenta las aventuras de la pequeña
aprendis de bruja en la academia Luna Nova acompañada de sus amiguiñas, todo con
una buena animacion de "estilo" disney. Personalmente recomiendo ver antes la
ova de 30 minutos que por su calidad y fandom se convirtio en esta serie,
es genial! la serie por otro lado esta muy bien

**El Padrino (I y II)** vi esto en busca de una experiencia trascendental y me
encontre con dos pelis "normales" con buena musica y un estilo cinematografico
"antiguo"

vi las versiones "restauradas" de 3 y 3 1/2 horas, mmm, son un producto
interesante de una epoca distinta, sin zooms ni intrepidos movimientos de
camara, en su lugar se cuenta con buenas actuaciones, desarrollo de pensonajes,
tencion, etc

desconosco que papel juegan estas peliculas en la historia del cine, quiza por
esto me parecen bien a secas, si son un pilar en la "ultra violencia" lo podria
entender mejor. Prefiero la primera sobre la segunda por la transicion de
michael de conderito a alien de grandes e inquietantes ojos negros sin vida,
producto de sus viles pero necesarias acciones, o eso me parecio

la segunda parte es mas grande, mas cara y mas violenta, e, inecesaria, por que
se vuelve tan malote el michael? por que me cuentan el origen del padrino?

no se, fue interesante verla como una investigacion de la interaccion social,
donde las estructuras de gerarquia social se forman por el rol que interpreta
cada participante

    magnet:?xt=urn:btih:70ea7386aaf775171baa22ebd6818f7302be0789&dn=Saga%20El%20Padrino%20720p%20Latino&tr=udp%3a%2f%2ftracker.coppersurfer.tk%3a6969&tr=udp%3a%2f%2fopen.demonii.com%3a1337&tr=udp%3a%2f%2fexodus.desync.com%3a6969&tr=udp%3a%2f%2fzer0day.ch%3a1337&tr=udp%3a%2f%2ftracker.leechers-paradise.org%3a6969

vere la tercera parte aver que tal, y luego un ciclo por pelis ancestrales
supustamente fundamentales: *scarface*, *casa blanca*, *ciudadano kane*,
*metropolis* y haber que mas cae

## txt

**Ender el Xenocida** + **Hijos de la mente**, huuuuff, que cambio, que placer,
que maravilla, no hay comparacion entre estas dos lecturas y mi anterior lectura
(la radio de Darwin). Los hechos continuan inmediatamante donde termino **la voz
de los muertos**, cierto es que estas dos lecturas (la segunda la levo al 28%)
son un solo libro dividido en dos partes, no es tan movida como la voz de los
muertos, aun asi es una magnifica lectura, cuando termine una reseña en
condiciones

## Fonos

**Archive** creo que solo me queda por escuchar un album de esta magnifica
banda, si los hubiera conocido mas joven ocuparian un podio entre en lo mas alto,
quedara pues esperar unos años antes de que eso ocurra o aparesca algo superior,
de momento mis discos faboritos son *Controlling Crowds*, *Noise*, *With Us Until You're
Dead*, *You All Look The Same To Me* y *Ligts*, ja, ninguno de sus albums tiene
desperdicio incluido el desconectado

**Morcheeba**, continuando con las cosas electro-algo-trip-hop cayo esto, sus
dos primeros albums son de escucha facil, muy muy buenos, el tercero ni lo
recuerdo y el cuarto a ido cobrando fuerza a base de eschuchas en bucle debidas
a la pereza de pensar la seleccion musical, el resto aun esta en descarga

    magnet:?xt=urn:btih:1502490247ccabf3059ae605e20d1c40bfa4d8f4&dn=Morcheeba.Discography.Lossless&tr=udp%3a%2f%2ftracker.coppersurfer.tk%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.opentrackr.org%3a1337%2fannounce&tr=udp%3a%2f%2ftracker.zer0day.to%3a1337%2fannounce&tr=udp%3a%2f%2ftracker.leechers-paradise.org%3a6969%2fannounce&tr=udp%3a%2f%2f9.rarbg.com%3a2710%2fannounce&tr=udp%3a%2f%2fexplodie.org%3a6969%2fannounce


**Codona** (+ Codona II y Codona III) sigo sin conservar en la mente su sonido,
pero me ha gustado el raga-rock este

    magnet:?xt=urn:btih:20b05892e8d19f8bb2655fd141cb53858f9d7bdf&dn=Codona%20-%20The%20Codona%20Trilogy%20(2008)%20%5bFLAC%5d%20%7bECM%202033-35%7d%20%7b3CD%7d&tr=udp%3a%2f%2ftracker.coppersurfer.tk%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.opentrackr.org%3a1337%2fannounce&tr=udp%3a%2f%2ftracker.zer0day.to%3a1337%2fannounce&tr=udp%3a%2f%2ftracker.leechers-paradise.org%3a6969%2fannounce&tr=udp%3a%2f%2f9.rarbg.com%3a2710%2fannounce&tr=udp%3a%2f%2fexplodie.org%3a6969%2fannounce

Camel (Rajaz), Beatles, ELO y Neil Young, unos viejos conocidos han
complementado el sountrack, tambien reescuche Queen y Queen II, pero aun
reconociendo calidad, sigo sin ser capaz de disfrutar su sonido
