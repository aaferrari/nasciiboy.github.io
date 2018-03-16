+++
categories = ["post"]
date = "2017-06-18T15:44:42-05:00"
tags = ["ramen"]
title = "Ramen IV"
+++

![](/img/jb130458.jpg)

bienvenidos a una nueva entrega de pasta acuosa, con bastante limon y sobras del
refri!

querido diario, sigo sin tocar morg, ni al raptor o tui, hasta no terminar con
el libro de Go, y aunque lento, van pasando los capitulos mientras completo
algunos ejercicios

siguiendo uno de estos retos, encontre particular fascinacion en el modelo de
color HSL, y al mismo tiempo la tristesa toco a mi puerta tras entender las
entrañas codificadas de este esquema, por que? por que es maravilloso, pero muy
caro, comparado con tres (o cuatro) simples bytes del modelo RGB

al principio crei que seria facil crear una funcion de conversion, regida por
variables de 0 a 255, mas sin embargo, se suele utilizar un valor de 0 a 360
para el matiz (hue), mientras la salutracion y luminancia echan mano de
variables de punto flotante de 64 bits, o desgracia, se hace de esta forma para
poder generar los coroles puros durante la tranformacion RGB, 0 (rojo), 120
(verde) 240 (azul), con saturacion en 1.0, y luminocidad en 0.5... ya solo por
las variables, se desperdicia mucho es-pa-cio, y al sumar las conversiones de
color tendriamos un proceso inecesariamente lento... pero eso es incompatible
con varibles de 0-255?  ni idea, supongo que es necesario por algun motivo
matemagico para optener todo el rango de convinaciones RGB o algo asi

larga vida a HSL y su intuitivo, aunque costoso modelo de color!

en otro campo, estube revisando el libro "Build Your Own Lisp" ([aqui](https://github.com/orangeduck/BuildYourOwnLisp))
sobre la construccion de un interprete en C en menos de 1000 lineas de codigo,
ho, ho, ho por supuesto es un gancho publicitario, pues con solo una de las
librerias que incluye en los encabezados, triplica esa cantidad.

dejando de lado esa pequeñes, hice una adaptacion previa del libro a morg que... empece hace un
año y deje por no requerdo que causa, la retome hace poco buscando conservar y
extender mis habilidades en C.

voy leyendo y maquetando una traduccion cutre del traductor, viendo si merece la
pena dedicar un esfuerzo serio, de momento al 25% del material, no lo tengo muy
claro, y es posible que la complejidad del material me revase pronto, de no ser
asi habra que hacer algo mas pro

aunque el material tiene lisencia CC, especificando que no se puede lucrar con
el... si de verdad es interesante habra que hacerse sin importar este pequeño
obstaculo y quiza, solo quiza, consultar a su autor para una publicacion
(digital) con fines lucrativos, sin dejar de lado, su libre disponibilidad para
quien lo necesite

## 4k

**South Park The Movie**, ya hace tiempo queria ver esta cinta, que es mas un
musical. Sin lograr acelerarme, fue un muy buen capitulo extendido, con las
habituales virtudes de esta poco valorada serie (yo lo pondria en las escuelas,
durante el almuerso)

    magnet:?xt=urn:btih:917c247d3034a22c968e59ebc6b2dc8a9c36842f&dn=South.Park.The.Movie.Bigger.Longer.And.Uncut.1999.720p.BluRay.x264-HDCLASSiCS%20%5bPublicHD%5d.mkv&tr=udp%3a%2f%2ftracker.leechers-paradise.org%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.coppersurfer.tk%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.zer0day.to%3a1337%2fannounce&tr=udp%3a%2f%2f9.rarbg.com%3a2710%2fannounce&tr=udp%3a%2f%2fexplodie.org%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.opentrackr.org%3a1337%2fannounce

**Pieles**, Hace tiempo, cuando era (mas) ingenuo, buscaba un material que
contubiera algo verdadera mente enfermiso, intentando conocer los limites de lo
que considero "normal", por el momento eso no ha aparecido, creo que la
conclusion mental fue "no hay nada que no sea normal", o algo asi

entoces que es pieles? ortera y con desagradables decorados, si habia una
historia no entendi de que iba, intenta ofender, causar reflecion, controversia
barata o solo es pretenciosidad?

una curiosidad si, si no detestas los coroles rosas, violetas fuertes, alguien
menciono ubuntu?

**Split** hoooo, por los podcast spoileroso que consumo sin precaucion alguna, esto
tenia buena pinta

pase la mayor parte del tiempo esparando la aparicon de la vestia y escenas de
maltrato emocional, cuando en verdad es una historia ligera sobre "las
posibilidades de la mente sobre la materia" o algo asi. Vale la pena esperar la
aparicion de la bestia, es divertido, el final me fue indiferente, pero como soy
un chico facil, ya espero la continuacion

**DNA²** (anime), esto es un entretenimiento superfluo + una evaluacion de las
tecnicas de animacion limitada, empledas hasta hace no mucho
tiempo... desplazamiento por imagenes fijas, mientras los dobladores y la
imaginacion ponen el resto. Util si has visto algo glorioso o cuando no quieres
pensar o emocinarte

Habra tambien escritura limitada, con muchos `...` (puntos)?

**Alien nine**, luego de DNA², encontre un capitulo suelto de esto... me hubira
gustado ver el resto

**SAO Abridged** Hay un canal en youtube llamado "Animacion Artesanal", hay
aprendi lo que es la animacion limitada... algo que destruyo la forma en que
veo la animacion, aunque en otros casos hace que alabe la maestria del director
al mantenerme expectante sin que pase nada en pantalla con musica, silecio o
monologos. En el ultimo video de ese canal, analizaron el camino del heroe
tomando como ejemplo Samurai Jack y Sword Art Online (SAO) (serie pasable solo y
unicamente en su primer arco).

Pues bien, en uno de los comentarios aparecio esta recomendacion, SAO
Condensado, que es una libre manipulacion/re-montage de los sucesos del primer arco de
la serie https://www.youtube.com/playlist?list=PLuAOJfsMefuej06Q3n4QrSSC7qYjQ-FlU,
de la forma mas coherente y comica que fue posible encontrar, los primeros 6
capitulos fueron hilarantes, especialmente el 3, aunque luego fue perdiendo
inpacto. Son algo asi como 3 horas, bastante agradables

dentro del oceano de los animes en transmision, el canario puesto en la mina
**Boku no Hero** sigue cantando, lo mismo para shingeki no bahamut y little
which academia, por su parte one piece... supenso... sigue siendo one piece

## txt

**La radio de Darwin**, lei esto como un intermedio, antes de continuar con la
saga de Ender. En el se exponen teorias sobre la evolucion de las especies, en
particular del animal humano, su explicacion sobre que todos los seres somos
nodos de un "sistema" y el adn es el banco de memoria de los calculos de dicho
sistema, es brillante!

Pese a esto, no lo recomiendo, almenos no sin comentar que es un libro muy
extenso inecerariamente (23,233 lineas), diria que me sobra al menos la mitad
del libro, sin poder explicar el por que, no me gusta la forma en que esta
escrito, de las tres tramas del inicio, solo me interesa la de los cromagnones,
y el libro no adquiere verdadero interes hasta despues de la mitad (en algunas
partes), tampoco me gusto el final, se deja de lado lo interesante. Al parecer
existe una segunda parte (peor escrita), pero no tengo interes en continuar.

Brilla en alugnos puntos, pero parece una serie de television regulera con solo
algunos minutos interesantes antes del fin de cada episodio

me quedo con una frace del libro que me gusto <q>Todo el mundo lo odia, pero debemos competir o terminamos en la calle</q>

ahora a retomar la saga de ender con <em>Ender el Xenocida</em>, espero mantenga
el nivel!

## fonos

**Archive** – de nuevo buscando musica eletronica descente, exponian el album
**Controlling Crowds** como una obra maestra, y razon no les falta

    magnet:?xt=urn:btih:ac6a19cb8ba3e1e07665e0e78c512c57d522f12a&dn=Archive%20-%20Controlling%20Crowds%20(2009)%20%5bLimited%20Edition%5d%20%5b2CD%5d%20%5bEAC-FLAC%5d&tr=http%3a%2f%2ftracker.thepiratebay.org%2fannounce&tr=udp%3a%2f%2ftracker.openbittorrent.com%3a80&tr=udp%3a%2f%2ftracker.ccc.de%3a80&tr=udp%3a%2f%2ftracker.publicbt.com%3a80&tr=http%3a%2f%2ffr33dom.h33t.com%3a3310%2fannounce&tr=http%3a%2f%2ftracker.torrenty.org%3a6969%2fannounce

**Archive** – y luego mas Archive, por descracia solo encontre una compilacion
de mp3s, formato que aborresco, hasta el momento he escuchado Londinium, Take My
Head, Ligts, With Us Until You're Dead, todos sobresalientes, por poner una
referencia, son algo entre el KId A de Radiohead y Portishead, con un ligero
toque otra sustancia que no logro identificar entre coldplay y arcade fire

    magnet:?xt=urn:btih:0c973bdea3a2f147ec035278da6e2ca042e291d5&dn=ARCHIVE%20-%20DISCOGRAPHY%20(1996-15)%20%5bCHANNEL%20NEO%5d&tr=udp%3a%2f%2ftracker.coppersurfer.tk%3a6969&tr=udp%3a%2f%2fexodus.desync.com%3a6969&tr=udp%3a%2f%2fzer0day.ch%3a1337&tr=udp%3a%2f%2fopen.demonii.com%3a1337&tr=udp%3a%2f%2ftracker.leechers-paradise.org%3a6969

**NieR Automata OST** – esta es una coleccion de 4 discos, no, no he jugado el
juego, de echo esperara en la lista de "algun dia si tengo pasta" junto al mario
galaxi, Gran turismo, Dead Space, balloneta, ..., la ultimos 10 dias dias solo he
dedicado los oidos a dos cosas (sobre todo a) NieR Automata y Archive

los primeros tres discos son 3 tecno, electro, melodico, melancolico, o algo asi
y el cuarto tiene sonido estilo chip tune

    magnet:?xt=urn:btih:d8909c8c64320596df95dd2292d0ed475010f21a&dn=NieR_Automata%20Original%20Soundtrack%20(OST)%20%5bFLAC%5d&tr=udp%3a%2f%2f9.rarbg.com%3a2710%2fannounce&tr=udp%3a%2f%2ftracker.coppersurfer.tk%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.leechers-paradise.org%3a6969%2fannounce&tr=udp%3a%2f%2fexplodie.org%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.opentrackr.org%3a1337%2fannounce&tr=udp%3a%2f%2ftracker.zer0day.to%3a1337%2fannounce

antes de caer en las garras de estos ultimos, hice un paseo por progachive y calleron

**Miles Davis** – Bitches Brew, In A Silend Way, Kind Of Blue, tres discos que
me sobrepasan, no estoy acostumbrado a estas sonoridades aunque reconosco su
calidad. Solo dire que no es musica para escuchar de fondo, reclama atencion o
terminara por alterar

**Jeff Beck** – Wired, de esto ya entiendo mas, buen album, en espera otros tres
(es rock instrumental (sin voces))

**Codona** – Codona, esto forma parte de una trilogia y tenia la clasificacion
de Raga Rock, sinceramente ya no me acuerdo como estaba, pero si fuera malo no
lo pondria, pero si fuera grandioso...
