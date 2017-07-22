+++
tags = ["ramen", "anime",]
title = "Ramen I"
draft = true
date = "2017-04-02T21:08:41-06:00"
categories = ["post"]

+++

Hace unas semanas que no publico naha, que por haber cosas recomendaciones o
temas no han faltado, pero entre la pereza y la programacion, no ha salido naha.

Como paleativo e imitando otros blogs (kofff... [onda hostil](http://ondahostil.wordpress.com), [quijote libre](http://quijotelibre.com))
abro esta seccion para contar en que ando, prefiero poner una post de una tematica particular, pero ya sera cuando
termine este mes.

## Katata

El motivo principal del silencio literario fue *katana*, un componenten del
proyecto *morg* (que encontraran dentro de las etiquetas del lado derecho de
este blog). Dicho componente conseptualmente se encarga de tomar el formato de
documentacion en texto plano y regresar una estructura *<q>sencilla</q>* con el
documento digerido de forma *<q>sencilla</q>*, encabezados, <q>tabla de contenidos</q>,
parrafos, enfasis, listas, dialogos, abouts, tablas, comandos y configuracion

en el libro *The Go Programming Language* (del que hare una reseña cuando
termine de leerlo y del que recomiendo su lectura) muestran una <q>libreria</q>
de nombre `x/net/html` con la cual parsear un documento html, para regresar una
estructura en forma de lista gerarquica o algo asi. Esto sirvio de inspiracion
para iniciar el modulo katana... aunque como muchas otras cosas al enfrentar el
codigo lo encontre demasiado complejo e innentendible, asi que pase de todo y
comence a programar a lo loco.

Primero surgio el fichero `markup.go` que es una estructura/objeto donde se
almacena el resaltado, y los comandos `@` de texto

Una vez que la cosa funciono, comence con la estructura del documento en si, que
no deja de ser un nodo, con slices de nodos que en teoria representan la seccion
y su contenido (todo recursivo), peeeeero no lo estructure de forma
convencional, asi que tengo un arreglo (slice) de nodos que representan los
encabezados del documento, y al mismo tiempo, sirve de tabla de contenidos, aunque
los encabezados en si no estan anidados, todos son <q>hermanos</q> la asociacion
queda a juicio de quien utilize la estructura

asi tenemos que

```
TOC []DocNode
    |- [0] Encabezado Uno
    |- [1] Encabezado Dos
    |- [2] Encabezado Tres
    |- [3] Encabezado Cuatro
    ...
```

y cada encabezado

```
Encabezado
 Contenido []DocNode
           |- [0] Parrafo
           |- [1] Lista
           |- [2] Otro Parrafo
           |- [3] Tabla
           ...
```

y cada parrafo, lista, o cosa

```
parrafo, lista, o cosa
 Contenido []DocNode
           |- [0] Cosa
           |- [1] Lista
           |- [2] Otra cosa
           |- [3] Otra cosa mas o no
           ...
```

cada nodo, es un objeto de tipo interface, que tiene dos metodos, uno para
optener el tipo de nodo y otro para optener su informacion, el contenido por
otra parte se optiene con un simple bucle atravez de la estructura.

No me quiero extender demasiado, ya que la explicacion de esto y los motivos por
los que lo estructura asi, pueden requerir unas horas de platica, dibujos y
revisar el codigo (que como costumbre mia, no incluye ni un jodido
comentario...).

para concluir ahora *biskana*, el modulo para exportar el ducumento adelgaso de
forma compulsiva, y utiliza una pantilla de texto para crear el html, como hace
el cms *hugo*. Aun falta agregar muchas pruebas, corregir unos detalles, agregar
opciones de exportacion y demas. De momento la siguiente semana voy a comenzar a
programar una interfaz de texto para visualizar los documentos, despues el
buscador...

espero presentar esto en alguna charla del flisol, aunque si no consigo
colaboradores, es posible que termine ofreciendo el tema a alguna
organizacion/empresa y salir de mi miseria... o dedicarle un año mas al tema,
aunque esto ultimo lo veo dificil

en fin, el codigo esta en el repo, tengo algunos reparos con las plantillas de
texto y no termino de visualizar como parcear las tablas, ni como dibujarlas

(pd: mientras leo, voy revisando el libro de Go, cuando publique la reseña, actualizo el
matiral (o no), mas  o menos iba por el 50 y algo %, lo pause por ponerme a
programar e implementar algunas cosas, hace dos semanas)

## 4k
### Kuzu no Honkai

Ufffffff, que sabroso final, cada capitulo es una delicia extraña, actualizo el
post del tema, con un enlace de descarga, lastimozamente no tengo espacio para
mas cosas en mi disco duro, ni idea que que pueda borrar, el ciclo de
eliminacion de materiales para vizualizar nuevas cosas ha llegado a su limite,
te odio internet, deja de compartir o dame un disco con un chilion de teras (con
un tera mas podria sobrevivir unos meses)

Pues eso, que pasen a ver, cuando resuelva el dilema de almacenamiento la
volvere a ver!

### otras cosas

Tambien vi *Tekkon Kinkreet*, m-a-r-a-v-i-l-l-o-s-a, peli de animacion de
calidad sublime

```
magnet:?xt=urn:btih:299fd6aec4cfbdc5b250a433ee4fd21b390d4d04&dn=TekkonKinkreet%20720p%20%5bac3%20ITA%20ENG%20JAP%20sub%20ITA%20ENG%20FRA%20SPA%20POR%5d%20by%20Salvo.mkv&tr=http%3a%2f%2fopen.nyaatorrents.info%3a6544%2fannounce&tr=http%3a%2f%2ftracker.ex.ua%2fannounce&tr=http%3a%2f%2finferno.demonoid.ph%3a3389%2fannounce&tr=udp%3a%2f%2ftracker.justseed.it%3a1337%2fannounce&tr=http%3a%2f%2fcpleft.com%3a2710%2fannounce&tr=udp%3a%2f%2ffr33dom.h33t.to%3a3310%2fannounce&tr=http%3a%2f%2ffr33dom.h33t.to%3a3310%2fannounce&tr=udp%3a%2f%2ftracker.openbittorrent.com%3a80%2fannounce&tr=http%3a%2f%2f10.rarbg.com%3a80%2fannounce&tr=udp%3a%2f%2ftracker.publicbt.com%3a80%2fannounce&tr=http%3a%2f%2ftracker.publicbt.com%2fannounce&tr=udp%3a%2f%2ftracker.istole.it%3a80%2fannounce&tr=udp%3a%2f%2ftracker.ccc.de%3a80%2fannounce&tr=http%3a%2f%2fexodus.desync.com%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.1337x.org%3a80%2fannounce&tr=udp%3a%2f%2ftracker.tntvillage.scambioetico.org%3a2710%2fannounce&tr=http%3a%2f%2ftracker.tntvillage.scambioetico.org%3a2710%2fannounce&tr=http%3a%2f%2ftracker.torrentbay.to%3a6969%2fannounce&tr=udp%3a%2f%2ftorrentbay.to%3a6969%2fannounce&tr=http%3a%2f%2ftorrentbay.to%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.yify-torrents.com%2fannounce&tr=udp%3a%2f%2f9.rarbg.com%3a2710%2fannounce&tr=udp%3a%2f%2fopen.demonii.com%3a1337%2fannounce&tr=http%3a%2f%2fsalvotnt.xoom.it%2fannounce.php&tr=http%3a%2f%2finfo2.netsons.org%2fannounce.php&tr=http%3a%2f%2fsalvotnt.co.nf%2ftrack.php&tr=http%3a%2f%2fsalvotnt.altervista.org%2fannounce.php&tr=udp%3a%2f%2ftorrents.ddunlimited.net%3a6969%2fannounce&tr=http%3a%2f%2ftorrents.ddunlimited.net%3a6969%2fannounce&tr=http%3a%2f%2ftracker.ilibr.org%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.istole.it%3a80&tr=http%3a%2f%2fexodus.desync.com%2fannounce&tr=http%3a%2f%2fsugoi.pomf.se%2fannounce&tr=http%3a%2f%2f94.228.192.98%2fannounce&tr=http%3a%2f%2fanimeita.url.ph%2fannounce.php
```

*Hasta el ultimo hombre*, una peli del señor Mel Guibson, que no termino de
enterder si intenta dejar una leccion o tener una excusa para ser *Violenta*(?),
je, je, mucha sangre, desmembramientos y perfosaciones, me gusta!

*Arrival* (la llegada), que bonita, en el podcast *La orbita de Endor* se
explayan (solo) un poco mas, recomendada

```
magnet:?xt=urn:btih:9c1872923ca650adca73e4b863c2c13a85d5e9d5&dn=Arrival%202016%201080p%20BluRay%20x264%20DTS-JYK&tr=udp%3a%2f%2ftracker.coppersurfer.tk%3a6969&tr=udp%3a%2f%2fzer0day.ch%3a1337&tr=udp%3a%2f%2fpublic.popcorn-tracker.org%3a6969&tr=udp%3a%2f%2ftracker.leechers-paradise.org%3a6969
```

*Train to Busan*, zombies coreanos(?)!, que bien echa esta, la escena donde los
zombies <q>frenan</q> es cuando menos creible, si fuese el dictador de un pais,
obligaria a mis basallos a representar una peli sangrienta, con sangre de verdad...

```
magnet:?xt=urn:btih:168637b7a074323f92b4d233383df90e7eb88ce0&dn=Train%20To%20Busan%20(2016)%20%5b1080p%5d%20%5bYTS.AG%5d&tr=http%3a%2f%2fexplodie.org%3a6969%2fannounce&tr=http%3a%2f%2ftracker.tfile.me%2fannounce&tr=http%3a%2f%2fbigfoot1942.sektori.org%3a6969%2fannounce&tr=udp%3a%2f%2feddie4.nl%3a6969%2fannounce&tr=udp%3a%2f%2ftracker4.piratux.com%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.trackerfix.com%3a80%2fannounce&tr=udp%3a%2f%2ftracker.pomf.se%3a80%2fannounce&tr=udp%3a%2f%2ftorrent.gresille.org%3a80%2fannounce&tr=udp%3a%2f%2f9.rarbg.me%3a2710%2fannounce&tr=udp%3a%2f%2ftracker.leechers-paradise.org%3a6969%2fannounce&tr=udp%3a%2f%2fglotorrents.pw%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.opentrackr.org%3a1337%2fannounce&tr=udp%3a%2f%2ftracker.blackunicorn.xyz%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.internetwarriors.net%3a1337%2fannounce&tr=udp%3a%2f%2fp4p.arenabg.ch%3a1337%2fannounce&tr=udp%3a%2f%2ftracker.coppersurfer.tk%3a6969%2fannounce&tr=udp%3a%2f%2f9.rarbg.to%3a2710%2fannounce&tr=udp%3a%2f%2ftracker.openbittorrent.com%3a80%2fannounce&tr=udp%3a%2f%2f9.rarbg.com%3a2710%2fannounce
```

logre juntar unas monedas para ir al templo y dejar la cooperacion:

- *Logan* mmmmmmm, pudo ser mejor. Si su proposito fue ser incomoda, lo
  logro. Buena sangre, lo de convertir una cruz en una *X mutante* es de las cosas
  mas bonitas que he visto

- *John Wick: Chapter 2*, no puedo resistir ver pelis donde salga el señor
  *neo*, el principio es continuista, para el intermedio ya estas dentro de la
  temitica *<q>es Jhon Wick</q>*, y el final? Soberbio, quiero ver lo que sigue.
  Aun encuerto, lo de <q>por que es Jhon Wick</q> dificil de aceptar, y la
  excusa para la secuela no tiene sentido, pero que mas da, diria que es mejor
  que la primera parte

- *Kong Skull Island*, mostruos!

para terminar, una buena persona, subio un par de torrentes, con series magnificas:
*Space Dandy*

```
magnet:?xt=urn:btih:aa266b5fd7c7ca7ebd296820488caf71757b2320&dn=%5bAniHenjin%5d%20Space%20Dandy%20%5bTV%20720p%5d&tr=http%3a%2f%2fopen.nyaatorrents.info%3a6544%2fannounce&tr=http%3a%2f%2ftracker.frozen-layer.net%3a6969%2fannounce
magnet:?xt=urn:btih:bb17866b65881296f73a3bb443db833859e123a2&dn=%5bAniHenjin%5d%20Space%20Dandy%20Season%202%20%5bTV%20720p%5d&tr=http%3a%2f%2fopen.nyaatorrents.info%3a6544%2fannounce&tr=http%3a%2f%2ftracker.frozen-layer.net%3a6969%2fannounce
```

un anime de aventura espacial, un poco a lo cowboy bebop, pero muy, muy
experimental, con capitulos literalmente lizergicos, una joya

*Nichijou*

```
magnet:?xt=urn:btih:5a899138b847a39a7c816ae94e08dba3e3566fc5&dn=%5bAniHenjin%5d%20Nichijou%20%5bTV%20720p%5d&tr=http%3a%2f%2fopen.nyaatorrents.info%3a6544%2fannounce&tr=http%3a%2f%2ftracker.frozen-layer.net%3a6969%2fannounce
```

anime que explora el humor japones hasta sus ultimas consecuencias, con... una
animacion que parece para crios y sin ningun tema cachondo. Visualizala o
muere!

## fonos

varios discos de Paul McCartney, mi beatle faborito (musicalmente) me gustan sus
primeros 5-7 albums, los ochentas son raros, algo de Steve Vai (Alive In An
Ultra World), tambien unos albums de Sonic Youth la que por muchos años fuese mi
banda faborita, <q>Chrome Dreams (I)</q> un disco unoficial de Neil Young, y un
puñado mas de nuevas he interesantes escuchas, tantas que ni me acuerdo del
orden/nombres...
