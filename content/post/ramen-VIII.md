+++
title      = "Ramen VIII"
tags       = [ "ramen", "morg", "fonos", "4k" ]
categories = [ "post" ]
date       = "2017-08-01T21:15:24-05:00"
+++

![](/img/weRlEMh.jpg)

(**Advertecia**, el siguiente contenido tiene mucha fallas ortograficas, algunas
de ellas, fueron evidentes en una segunda revision, pero a su autor le hace
gracia dejarlas. Si considera inperdonable tal ultraje al lenguaje, por su
propio bien abstengase de leer)

Hey, por fin cambie el tema, no es mas bonito, de hecho es un *spaghetti CSS* a
medio hacer, je, je, ya lo ire "purificando" lenta y perezosamente, por que
pocas cosas hay mas aburridas que el "desarrollo" web. Por el momento (mi
coletilla personal) lo incluire en el codigo mismo del repo, cuando mejore ya
tendra su repo propio

relacionado con lo anterior, en el transcurso del aprendizage de hugo, y ya sin
ser un ingorante de golang (que tampoco hace falta para meterse con hugo)
encontre fastidioso la brillante idea de los desarrolladores de hugo sobre
documentarlo en un jodido [blog](https://github.com/gohugoio/hugoDocs), por que
escribir un libro en una solo "pagina", si lo puedes repartir en secciones
organizadas por "pesos" mientras modificas tu cms para satisfacer esta retorcida
caracteristica... y... de nuevo otro ser (de luz) tambien comulga con mis
intoleranctes ideas, asi que hace un par de años se curro un script en python 3
(que ironico) para crear una pagina con toda la documentacion (en markdown) y
visualizarla en [github](https://github.com/hamoid/long-hugo-doc/).

Que risas, como el tiempo pasa, los de hugo mudaron e incrementaron su
documentacion, asi que el escript dejo de funcionar, y, sin tener mucha idea, le
di una revision y logre que funcionara, haci que hice un issue al desarrolador
para incorporar los dos pequeños cambios. Por que no un pull request? era algo
que no pensaba usar otra vez y hacer un fork para algo asi parecia exesivo.
Desde luego mis propositos siempre son mas retorcidos (y menos nobles) de lo que
aparentan, pues se me ocurrio la feliz idea de joder a los de hugo, portando su
documentacion a morg, ademas como su licencia es permiciva, publicarlo como un
libro (pidiendo un pago) y ademas traducirlo... un par de horas invertidas
despues, me pregunto si vale la pena, si es mejor dejar morir ese pequeño
esfuerzo, si hugo es lo que busco (respuesta: aun no) y que papel juego en el destino cosmico, soy
acaso real?

en otros frentes, gogle fastidio el tema (css) black-translator, cambiando `.gb_T .gb_jg` por
`.gb_T .gb_ig`, hay que seguirle los pasos... ya actualizado ese post

tambien estoy a punto de terminar mi segundo recorrido de revision y "primer"
estudio serio del *The Go Programming Language*. Para ser sincero, cuando
publique la primer "pasada" pre-traductoria, tenia algo de miedo de accionar un
operativo para descubrir mi verdadera identidad y ser extraditado a USAmerica,
con el efecto secundario de asegurarme alimento y tiempo en prision para seguir
con mis cosas, encima cual baño de fuego, serviria de prefacio a las canciones que
harian de "nasciiboy el virtuoso"... lol, parace que las editoriales o la de
tgpl tiene buen corazon, eso, o como empiezo a sospechar, a pocos les importa una
mierda la programacion y mas si esta en españish...

mencionar que las utlimos tres capitulos del libro mas que un estudio, los leo
de forma casi anecdotica, eso de la reflexion y mas aun mesclar C con Go, no
tengo planes de combinarlo o entenderlo a profundidad por algun tiempo, dejando
eso de lado, el lenguaje me encanta, en serio que me encanta, aunque los gophers
son unos pesados sin personalidad

mientras tanto comence la busqueda de otra victima para continuar la mision de
convertirme en un "desarrollador Golang calificado", cuan grande fue mi sorpresa
de encontrar un libro (aparentemente) decente con licencia libre y
(parcialmente) traducido al español: *Build Web Application with Golang*

    git clone https://github.com/astaxie/build-web-application-with-golang.git

solo le he dado una vista superficial, pero promete bastante, si me gusta igual
colaboro en terminar la traduccion al español, aunque (de nuevo) el formato de
maquetar libros con markdown de fondo, no es lo mas acertado del mundo y menos
en capitulos con fichero propio, asi que cuando termine con el TGPL, le dare
una lectura para corroborar su calidad y de ser asi pues a hacer un version en
una sola pagina con morg... por que es con lo que mi jodida mente se siente
comodo, tiene una verison en epub y no es muy dificil generar un html unico con un
`cat *.md > book.md` y luego invocar a pandoc

finalmente, publique una pequeña recopilacion de juegos *FLOSS* hechos con
**love2D**, para tener victimas de mi aprendizage recreativo videojueguero
fresco indi rocker maker in the middle of the night, como pase mucho tiempo con
esta cosa y haciendole un (penoso) tema pospuse un algo la traduccion del sicp,
uuooohhh, haber si mejoro el ritmo, pero sobre todo haber si logro congeniar go, morg,
regexp(3|4), sicp, love2d, lua (y recientemente falsificacion de documentos
utilzando gimp) sin morir en el intento

mientras hacia la clasificacion de los juegos de floss, llegue a la
conclucion que la mejor forma seria poner cada pagina como "metadatos" o
adjuntos, mas o menos quedo asi

```
---
title     : "anput"
date      : 2017-07-25T01:26:49-05:00
draft     : false
categories: ["games"]
img       : "img/vg/anput.gif"
tags      : ["maze", "procedural"]
lover     : "0.10.2"
source    : "https://github.com/andmatand/anput"
licence   : ["BSD-2"]
external  : ["https://kittenm4ster.itch.io/anput"]
---

cosas en texto

## clone

   ...como clonar...

```

por mera casualidad, luego di con una vieja recopilacion de juegos en los foros
de love2d, que mas o menos utilizan algo similar en su wiki... maldicion, parece
que solo encuentro lo que busco cuando reinvento la rueda y se que buscar,
aunque... quiza no sea un completo desperdicio, pues aprendo como funciona la
rueda a lo bruto, ademas que puede que mi rueda pueda ser diferente

y bueno mientras llegaba a ese conocimiento, se me ocurrio incorporar (en morg)
"metadatos" ("arbitrarias") asi:

```
..labels > game
  ..name > MegaMan 2
  ..date > 1989
  ..copy > mit
  ...lo que sea...
```

y luego me dije, puede ser algo engorrosa esta sintaxis, por que no permitir
sintaxis alternativas

```
..json > game
  ...cosas json...
```

o *yaml*, o *toml*, y lugo me dije, bien y a que asociarian estos datos? habria
que reescribir cosas para saber si algo es una imagen, un texto o un encabezado
o lo que sea, por que de ser asi arruinaria muchas de las ideas previas. Luego
de un rato llegue a la conclucion que los metadatos (si en algun momento los
llego a implementar) deberian asociarse a la cosa inmediatamente previa, o algo
asi, solo son desvarios

## 4k

**castlevania**, sin llegar a ser un **Ninja Scroll**, las ovas de **Hellsing
Ultimate** o tener la epica de **berserk** o **Basilisk**, tenemos una buena
prueba de concepto, que aunque no calificaria como "para adultos" (ni tampoco a
las anteriormente sitadas, con la exepcion de algunas escenas en hellsing, epa!
basilisk en el preescolar! nasciiboy for president!), tiene momentos y fraces
chulas, burlas a la iglesia catolica (que nunca sientan mal) y a los discursitos
serios. Dadle una oportunidad!  (aunque sea por torrent... en esta ocacion no
puedo compartir el enlace por que es un tracker privado del que estoy a punto de
ser echado...)

**ScarFace**, toma un momento, imagina al Padrino, ahora imagina que el prota es
cubano y estamos en los 80 (creo), pues esto es esa historia, no hay una
familia... bueno si, pero no como la del padrino. Aqui el prota esta deseoso de
ascender lo mas rapido posible para... descubrir que su vida es una mierda y
terminar su historia jodiendo todo, para culminar en un epico decenlace.

El principio me costo, pero luego del minuto 40 fue mas llevadero, la vi en 4
seciones

    magnet:?xt=urn:btih:ce113f99560b99ca854442b03602b8954079942e&dn=Scarface%20(1983)%20%5b1080p%5d&tr=udp%3a%2f%2ftracker.leechers-paradise.org%3a6969&tr=udp%3a%2f%2fexodus.desync.com%3a6969&tr=udp%3a%2f%2fopen.demonii.com%3a1337&tr=udp%3a%2f%2fzer0day.ch%3a1337&tr=udp%3a%2f%2ftracker.coppersurfer.tk%3a6969


**Uchouten Kazoku** (temporada 2) Sin que lo esperara, de hecho sin ganas de
verlo, de hecho recondando poco de la primer temporada exepto que trataba de
unos tanukis o mapaches tranformables junto a tengus (o gente que vuela, no
cenesariamente con narices alargadas (sin eroticos resultados)), que fue linda y
entretenida sin pretencion alguna. Asi pues aparecio su segunda temporada y
luego de un mes en el almacen la comence a ver y en poco tiempo se termino la
reserva, diria que es mas y mejor que la primera, no es inecesaria por que no
tiene pretenciones tracendentales, ademas que tiene buena animacion,
"caracteres", estilo y se noto que los involucrados lo hacen con amor, el
suficente amor como para esperar un tiempo para entregar algo bonico

    magnet:?xt=urn:btih:f128543731f4641caf30f38be79988b5e2b8259d&dn=%5bPuyaSubs!%5d%20Uchouten%20Kazoku%20S2%20%5bBatch%5d&tr=http%3a%2f%2fanidex.moe%3a6969%2fannounce&tr=http%3a%2f%2ftracker.frozen-layer.net%3a6969%2fannounce&tr=http%3a%2f%2fnyaa.tracker.wf%3a7777%2fannounce&tr=udp%3a%2f%2fipv4.tracker.harry.lu%3a80%2fannounce&tr=http%3a%2f%2ftracker.frozen-&tr=udp%3a%2f%2ftracker.opentrackr.org%3a1337%2fannounce

## fonos

hace tiempo que no ocurria, pero he pasado unos dias con Led Zeppelin a tope!
hace unos doce años, cuando daba mis primeros y serios pasos en el
descubrimiento de la musica "refinada", sabia para mi interior, que si algun
llegaba el dia que dejara de disfrutar plenamente los rifs zeppelindrosos (o
peor aun a la juventud sonica (**Sonic Youth**)) ese dia, seria oficialmente un
jodido viejo sin sangre en las venas, sin el odio por el mundo que alimento mis
andansas por tanto tiempo... y aunque los momentos mas bajos han sido de
aburricion o completa falta de interes (similar (imagino) al sentimiento de
impotencia sexual) al punto de evitar colocar su sonido, decantandome por cosas
mas progre o electronicas.

Por ello estos cuantos dias "al limite" seran recordados como el "dia que llego
el invierto" o algo asi, Gratitud y reverencia eterna a Led Zeppelin

**Dragon** (Discografia), en realidad solo escuche 5 albums, el primero
**universal Radio** se encuentra a medio camino entre *Uriah Heep* y *Yes*,
bastante destacable, digno de una secion entera, el resto en cambio decae
feamente, el segundo *Scented Gardens For The Blind* con solo un par de escuchas
pase al siguiente, por desgracia, apartir de este ultimo su sonido se vuelve
soso y sin variacion entre uno y otro.

No continue su escucha y solo preservare el primero que si es digno de una banda
con nombre *Dragon*, que fue la razon de hacerle caso en el torrente

    magnet:?xt=urn:btih:ba2bbd2666b28f223ca5b662230b6eaeace87287&dn=Dragon%20-%20Studio%20Discography%201974%20-%201989&tr=udp%3a%2f%2ftracker.leechers-paradise.org%3a6969&tr=udp%3a%2f%2ftracker.coppersurfer.tk%3a6969&tr=udp%3a%2f%2fexodus.desync.com%3a6969&tr=udp%3a%2f%2fzer0day.ch%3a1337&tr=udp%3a%2f%2fopen.demonii.com%3a1337

**Arcade Fire: Everything Now**, mmhhh, esta agrupacion solo tiene dos albums a
destacar, su debut con titulo homonimo, con un sonido melancolico e inocente, y
el ahora penultimo *The Suburbs* que clasificaria como musica fiestera alegre,
rasgo que comparte con la produccion en cuestion, aunque esta es menos fiestera,
quiza mas pop, diria que con toques *Bowie* ochenteros o algo asi y algo de
*Gorillaz* y *Frank Black*. No lo esperaba, y estaba en el torrente...  un
postre ligero, diria

    magnet:?xt=urn:btih:85696c2b31b7c7d793fcccdb74588b96cb6531b7&dn=Arcade%20Fire%20-%20Everything%20Now%20(2017)%20FLAC&tr=udp%3a%2f%2ftracker.leechers-paradise.org%3a6969&tr=udp%3a%2f%2fopen.demonii.com%3a1337&tr=udp%3a%2f%2fexodus.desync.com%3a6969&tr=udp%3a%2f%2fzer0day.ch%3a1337&tr=udp%3a%2f%2ftracker.coppersurfer.tk%3a6969

a quien no le gusta el postre?
