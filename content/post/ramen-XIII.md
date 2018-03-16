+++
title      = "Ramen XIII"
tags       = [ "ramen", "fonos", "4k", "java" ]
categories = [ "post" ]
date       = 2017-11-05T19:55:02-06:00
+++

**nota mental**, cuando aplicas fuego a una tecla de laptop intentando borrar el
simbolo (de las ventanas)... esta se deforma alarmantemente rapido y queda inservible.

en esta entrega mas divagacion y cosas previas...

![](/img/better.jpg)

primero me pregunte por que el **htop** (o algun otro monitor de sistema) no
mostraba las estadisticas de la temperatura o de la grafica, ni siquiera de
la integrada, y luego comence la
[busqueda](https://askubuntu.com/questions/387594/how-to-measure-gpu-usage) poco
fructifera de algun programo.

lo mas cercano a la solucion, sin instalar drivers privativos ni cosas raras,
fue el paquete `intel-gpu-tools` (en freidora) y luego como root y con la fuente
de la consola muy chikita ejecutar  `intel_gpu_top`. De paso tambien me instale
`glances` como monitor de sistema suplente, al siempre incombustible `htop`

llebo un tiempo con boinc en el androide, y en la maquina no pude echar a andar
el asunto hasta dar con
[este](https://fedoraproject.org/wiki/Installing_and_running_BOINC_client_in_Fedora_21)
enlace. Mi maquina no es nada muy alla, haci que se pone lentorra cuando se
ejecuta, aun con restricciones grandes. Para no desistalarlo lo configure
en ejecucion solo cuando la maquina no esta en uso.

ooooh desgracia, una tarde la maquina se puso rara y crei que el dia del juicio
al disco musical habia llegado, luego no supe que jodidos pasaba,
se congelo el sistema y se negaba a arrancar, lo unico que alcanzaba a decir era algo con
respecto a los sata... el segundo mayor temor era que la placa fuera la
agonizante.

A prodar a instalar otra distro, me dije, al no encontrar una solucion y para
descartar culpables, probe con manjaro y no hubo suerte, luego regrese con la
distro inombrable (~~fedora 27~~) y hubo suerte, quitando el inconveniente que no
hay manera de apagar el equipo ... excepto reiniciando y apagando el switch en el
interludio, ja, ja, ja

continuando con *las cosas de java*, el lenguaje comienza a hacerse demaciado
complejo he inecesariamene vervoso. Haaa, eran tiempos preteritos y no sabian por
donde ir. El libro de *pensar en java*, por su parte tampoco me motiva
demaciado, no es malo, pero no le veo gracia, ya voy por la pagina 300, acabando
de ver las interfaces. En definitiva Go es pura magia solo visible cuando ves a
sus ancestros

por el camino aprendi (creo) eso de la variable `CLASSPATH`, aunque mejor usar
rutas relativas. Para configurar esta variable en fish (`~/.config/fish/config.fish`)

    set --export CLASSPATH  '/usr/share/java:.'

tambien me pase un rato viendo enlaces en el blog de bitix sobre java, rescato
el de [razones para usar java](https://picodotdev.github.io/blog-bitix/2015/05/10-razones-para-seguir-usando-java/)

para terminar un poco de poesia

> Si presume de lo rápido que ha desarrollado su producto, la gente se quejará de su rendimiento.

> Si usted presume de lo bien que su producto funciona, la gente se quejará de su tiempo de desarrollo.

> Si usted no se jacta de ninguno de los dos, la gente asumirá que está desarrollando en Java.

(extraido de [aqui](https://web.archive.org/web/20070222084110/http://destraynor.com/serendipity/index.php?/archives/102-Programming-Theorems.html))

## 4K

**Kimi no na wa** Tengo la teoria, por las obras que he visto del director de
este trabajo (The Place Promised in Our Early Days, 5 Centimeters Per Second (mi
favorita y que me deja roto), The Garden of Words y Voices of a Distant Star),
que de joven por razones extrabagantes termino siendo amigo de una chika
peculiar con cabello negro

El, era un roboto, y con el roce y el paso del tiempo con la femina, descubrio
que tenia sentimientos, especificamente sentimientos romanticos, los cuales mas
tarde solo pudo identificar como *amar*. Era un cobarde, razon por la cual
aunque ambos dos se apresiavan, nunca llego a mas, termino obsecionado
platonicamente y repite una y otra ves sus vivencias melancolicas, romanticas
idealizadas, filme a filme, donde por fin encuentran desarrollo, pues en la
realidad la chika y el terminaron distanciados por el azar y de forma
irresoluble... bueno es solo una ipotesis, para nada basada en vivencias
personales...

en fin, la opinion, mmmmmhh, una peli normalita, la de la chika muda con voz de
robot fue una avalancha de mas cosas en este cuerpo decadente

    magnet:?xt=urn:btih:89f142e5a30d32d7a1616cc8db9009070f465adc&dn=Kimi.No.Na.Wa.2016.JAPANESE.BluRay.1080p.x264.AAC.5.1.-.Hon3y&tr=udp%3a%2f%2ftracker.leechers-paradise.org%3a6969&tr=udp%3a%2f%2ftracker.coppersurfer.tk%3a6969&tr=udp%3a%2f%2fopen.demonii.com%3a1337&tr=udp%3a%2f%2fexodus.desync.com%3a6969&tr=udp%3a%2f%2fzer0day.ch%3a1337

**Tsuki ga Kirei** anime normalito, con animacion bonita aunque generica, si lo
dejas unos dias es dificil identificar donde ibas con solo ver el inicio de los
episodios.

Lo cosa se centra en un par de estudiantes de nivel medio y su romance "bonito"
sin mas... hasta que el descubre que la chica por su "inocencia" esta jodida de
la cabeza, esta se torna poseciva y exigente y lo agota emocionalmente
orillandolo a la desesperacion, o si, no sabe que hacer, asi es el mundo?

luego ella, se entera que el lleba una amistad bastante agradable con una de sus
amigas y esta amiga a su ves le comenta que tambien "le late" el mismo tipo
generico, entonces se deprime, se pregunta por que las cosas no salen bien y si
asi es el mundo?

entonces, ambos ante la cruda, compleja y poco hollywodense realidad, desiden
dar fin al romance inperfecto, pero a diferencia de hablarlo, fuerzan
instintivamente la ruptura, cometiendo actos sucios, para que la otra parte vea su jodida naturaleza
*inocente*. Luego crecen y se dan cuenta de lo imbeciles que estaban, hacen las
relacones (pese a estar casados, oh, pecadores) y siguen con sus pendejas
existencias

... bueno, no, por el episodio 6 te ponen "el episodio recapitulatorio" de todas
las series con dos pesos de presupuesto, luego vi el episodio 7 y seguia sin
ocurrir nada interaste, pase al final buscando algo de gore... y no habia nada

**Labyrinth of Flames** del hasta ahora desconocido (para mi) Studio Fantasia,
llega esta ova autoconclusiva con mucho carisma y estilo de animacion|comedia
90's y braguitas + humos otakus desbordantes con olores a
Gainax, bajarlo pronto... por el dia

    magnet:?xt=urn:btih:d98910b9f521f02d660d67e29f0f380573d15bcb&dn=%5bEUR%5d_Labyrinth_of_Flames&tr=http%3a%2f%2fnyaa.tracker.wf%3a7777%2fannounce&tr=http%3a%2f%2ftracker.frozen-layer.com%3a6969%2fannounce&tr=http%3a%2f%2ftracker.frozen-layer.net%3a6969%2fannounce

**Osomatsu San**, aver, si te gusta Gintama en sus puntos mas hilarantes esto te
va a gustar bastante. Es humor absurdo japones, eso quiere decir que en momentos
puedes reir y en otros no encontrar sentido a lo que se muestra y en otros
ponerse introspectivo o profundo.

No tenia idea de su existencia hasta hasta ver un video de *Mireda
Producciones*, que explica mucho mejor de que va esto y por que es
interesante. Jo, JO, JoO, el primer episodio es un poco especial, pero en cada
momento aprovecha para tirar criticas y reirse de si mismo y su industria

    magnet:?xt=urn:btih:e8b421f739ebcb143b717311b6838a24ab05714e&dn=%5bPuyaSubs!%5d%20Osomatsu%20san%20%5bBatch%5d&tr=http%3a%2f%2ftracker.frozen-layer.com%3a6969%2fannounce&tr=http%3a%2f%2fopen.nyaatorrents.info%3a6544%2fannounce&tr=http%3a%2f%2ftracker.frozen-layer.net%3a6969%2fannounce

apenas voy por el capitulo 6, mientras tanto aprovecho para compartirlo al
tiempo que lo consumo lentamente. Son 25 episodios y en estos momentos estan
transmitiendo la segunda temporada, en fin, a bajar y conservar en el disco, que
en mi caso tardo bastantes dias en completarse la descarga y como ya es material
"viejo" seguro el torrent quedara desanparado en no mucho tiempo... pocas cosas
son mas bonitas que ver que el torrent que te gusta se comparte regularmente!

## Fonos

**Blade Runner 2049**, buff, lo baje antes de ver la peli (entrega anterior) y
se fue al limbo en /dev/null. Tras ver la cinta ya tiene mas sentido, aunque
sigue siendo flojo, lo conservare por mero coleccionismo

    magnet:?xt=urn:btih:402f84f695ae9e8b9a4f525903845d7699f63f57&dn=Hans%20Zimmer%20%26%20Benjamin%20Wallfisch%20-%20Blade%20Runner%202049%20(2017)%20%5bFLAC%5d&tr=udp%3a%2f%2ftracker.coppersurfer.tk%3a6969&tr=udp%3a%2f%2ftracker.leechers-paradise.org%3a6969&tr=udp%3a%2f%2fexodus.desync.com%3a6969&tr=udp%3a%2f%2fzer0day.ch%3a1337&tr=udp%3a%2f%2fopen.demonii.com%3a1337

**Living Field** (The Pillows), otro disco mas de "los almohadas", fummmm, que
pasada entre (soft?) reggae, pop japo-ingles y guitarras cosmico-playeras, una
pasada!

tambien pasaron por las auriculares **Kool Spice** y **Please Mr. Lostman**,
discos anterir y siguiente, respectivamente, muy en la linea e igual de
disfrutables, me gusta en particular la ultima pieza del Kool Spice, pura ricura

(pese a ser infectos emepetreces, dejo el enlace)

    magnet:?xt=urn:btih:b77fa0f90c4fdd83d467f5f8c89d6ccc437d578c&dn=The%20Pillows&tr=udp%3a%2f%2f9.rarbg.com%3a2710%2fannounce&tr=udp%3a%2f%2ftracker.leechers-paradise.org%3a6969%2fannounce&tr=udp%3a%2f%2fexplodie.org%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.opentrackr.org%3a1337%2fannounce&tr=udp%3a%2f%2ftracker.coppersurfer.tk%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.zer0day.to%3a1337%2fannounce



**Ununiform** (Tricky) Ya habian pasado por estos oidos un par de discos de esta
banda "trip hop", pero no logro empatizar con sus notas, me va mas Portishead y
Massive Attack

    magnet:?xt=urn:btih:c8128f7b8b53d56ceef844f2c0b4c05283c4520d&dn=Tricky%20-%20ununiform%20(2017)%20%5bWEB%20FLAC%5d&tr=udp%3a%2f%2ftracker.coppersurfer.tk%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.opentrackr.org%3a1337%2fannounce&tr=udp%3a%2f%2ftracker.zer0day.to%3a1337%2fannounce&tr=udp%3a%2f%2ftracker.leechers-paradise.org%3a6969%2fannounce&tr=udp%3a%2f%2f9.rarbg.com%3a2710%2fannounce&tr=udp%3a%2f%2fexplodie.org%3a6969%2fannounce

**Kareshi Kanojo no Jijou ♥** (Shiro Sagisu) este es el score musical de una
serie que considero un genero en si, el *como karekano*. En su mayoria esta
compuesto por el Sagisu, que es el mismo de los ost de Evangelion y Shin
Godzilla (algun torrento pls?), esta  muy en la onda del tipo, algunas piezas
evangelicas recicladas y otras exclusivas.

Ameno y recomendable por si mismo, tiene bastantes pistas melancolicas de esas
que me dejan tocado y no puedo resistir repetir una y otra vez. Si ya tienes los
sonidos de NGE, sin duda es una piesa necesaria de la coleccion

    magnet:?xt=urn:btih:ff88c3a7e58b9b8aa360f85904a5c91423b1cc22&dn=Shiro%20Sagisu%20-%20Kareshi%20Kanojo%20no%20Jijou%20CD-BOX%20(1998)%20%5bFLAC%5d&tr=udp%3a%2f%2ftracker.coppersurfer.tk%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.opentrackr.org%3a1337%2fannounce&tr=udp%3a%2f%2ftracker.zer0day.to%3a1337%2fannounce&tr=udp%3a%2f%2ftracker.leechers-paradise.org%3a6969%2fannounce&tr=udp%3a%2f%2f9.rarbg.com%3a2710%2fannounce&tr=udp%3a%2f%2fexplodie.org%3a6969%2fannounce

**Eric Satie** (trabajos para piano) aparecio en el ricolino podcast de **Score
VG** y tambien como reminicencia de algun anime... son trabajos tan sencillos
como melancolicos y pegadisos. Como estos trabajos no suelen ser *discos
conceptuales* cuesta tomarlo en exclusiva, aun con esto en contra, seguro que te
agradan bastantes piesas

## txt

de nuevo sin libros... hubo un par de post chulos sobre cosas esotericas con la
programacion

http://theorangeduck.com/page/ascii-love-letter https://www.reddit.com/r/programming/comments/79jo46/ascii_a_love_letter/

y otro del simpre certero aunque poco contundente [asm86](https://asm86.wordpress.com/2017/10/30/eficiencia-del-software-contra-eficiencia-de-desarrollo/)

sayonara, bye, bye
