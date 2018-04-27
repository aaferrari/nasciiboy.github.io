+++
title      = "Ramen XX – Communication Breakdown"
tags       = [ "4k", "txt", "fonos" ]
categories = [ "post" ]
date       = 2018-04-21T19:55:17-05:00
+++

![](/img/2208.jpg)

Como es posible, que mientras creo dia a dia ir mejorando el kung-fu de la
informatica, caer presa del sindrome del impostor, sientiendo que no valgo para
nada... que mi codigo es basura, que no va a ningun lado y peor aun, suponer que
las ideas que impulsan su existencia son cuando minimo equivocadas. Imagino
pues, que al adquirir ciertos conocimientos (nunca suficientes) se llega a este
punto, donde se duda de las habilidades adquiridas... que no es que las alla
demostrado nunca, pero aun asi, asumo que las poseo (o poseere)

pero, de donde surgen estos traumas? de morg, por su puesto y su refactorizacion
en tramite, que pueden dar lugar a varios post extensos, llenos de consideraciones
sutiles y aproximaciones varias, la implementacion de un scanner, un scanner con
registro del posicionamiento sobre el texto, ventajas e inconvenientes de
exponer casi todos los componentes en una libreria y una aplicacion del patron
composite + decorator + strategy a la estructura de un documento... o
bueno, eso pensaba.

Llebo varios dias viendo fijamente a la pantalla, intentando "descubrir" una
manera de aplicar una estructura de patrones de diseño al documento parseado
a la cual se pueda aplicar un conjunto vario de exportadores. Aunque
algunos espejismos de una solucion audaz, elegante y sencilla, me han
dado esperanza, termino desesperado, sin encontrar una reconciliacion entre las
ideas y el codigo (seguramente debido a que *los patrones son sobre codigo, no
sobre estructuras de datos*). "Pero como, por que" (me cuestiono) chaaa, por que el navegador
no tiene soluciones para estas preguntas. Incluso cuestionando en reddit en un
foro especializado, ni siquiera los troles se aparecen

Como consuelo, luego de meditaciones extensas, llego a la conclusion que lo que
intento son meras quimeras, hacer dos pasos en uno solo: parsear la estructura
del documento independiente de cualquier interprete, para luego transformarla
al mismo tiempo en codigo ejecutable.

Viendo la unica aproximacion analoga que conosco para el mismo problema (un
parser de html) veo que es evidente la separacion entre pasarsear la estructura
del texto, para generar una estructura de datos y luego, hacer lo que se crea
prudente con ellos. En esta no inplementan ninguna funcionalidad en el documento
analizado, se limitan a identificar la estructura y elementos, sin atribuir
tipos (estructuras especificas), interfaces, herencia ni nada remotamente
cercano.

Teniendo como referencia anteriores momentos de frustracion, esperare que algun
proceso cerebral en segundo plano encuente una solucion, o en ultima instancia
adaptare el codigo del parser html (golang.org/x/net/html) para de una vez por
todas afinzar y extender sin miramientos la idea del morg a algo de verdad usable por los
mortales

heeeeem! destacare que en medio de las reformas, decidi que los comandos `@` ya
no tendran dos lados. Contaran con ninguno (solo datos), uno (dividido), o n
lados (ahora ramas, o algo asi). Ja, Ja, Ja. por usar (sucio) markdown para escribir este blog, casi entro
en panico, pensando que tendria que corregir cientos de enlaces en algunos
trabajos de cobayas, pero, no!  afortunadamente segui la coherente convecion de
enlaces de org-mode y no tendre que hacer ningun cambio en lo ya escrito,
fuuuhh!

aun con esta batallita, pude sin proponermelo demaciado, iniciar y concluir la lectura
del libro de ensamblador arm y arduino (del que tengo la vercion 1, y 4 años
despues no tengo ni puta idea que hacer con ese cacharro).

Una lectura por demas satisfactoria, que no estoy seguro si por continuarla
justo despues de la del manual speccy (material con poca vocacion didactica), ha
sido muy sencillo de leer. No solo clarifico varios puntos opacos con la
programacion en asm, tambien hace aun mas sencillo continuar con otros titulos
mas densos, como uno de asm de intel de 32bits, u otro(s) de arquitectura de
ordenadores por hay suelto(s).

Aunque la lectura fue fluida, algo ayudo quedar sin internet por dia y medio,
gracias a lo cutres que son los modems de ... la compañia de la republica
babanera donde resido

Como el incidente con el modem ocurrio un miercoles, y ese es dia toca la
reunion del taller de sysadmin, probe un poco con aircrack, pero quedando
perdido al poco de intentar, le puse saldo al movil y feliz y asombrado pude ver
cruzar el internet del eter al dispositivo y de este al PC *sin cables*. Puagg! que magico y
miseterioso, aun me pregunto por que no hay un programa para hacer una red de
movil a movil utilizando sus habilidades de transmision celular. Tienen tan poca
potecia los trastos estos que solo por la intercepcion de las torres de
transmicion es viable su funcionamiento?

Que gusto sera cuando todo el mundo tenga internete satelital, libre, gratuito y
sin restricciones, porno, porno en todos partes!

Je, je, quiza lo que mas me facina (sin buscarlo) de aprender trucos nuevos
(aveces olvidando otros a cambio) o de conocer un nuevo e interesante programa,
es esa "sensacion de estreno" similar al que produce la adquisicion de hardware, musica
o libros.

finalmente, y mas de actualidad, se hacerca el **flisol** que si asisto este
año vedria a ser mi 5 vez.

Ya que en el anterior flisol y luego en el hackmiting, tuve la oportunidad de
mostrar los "avances" en morg, tenia la intencion de presentarlo nuevamente,
esta vez (como la primera (fes acatlan)) en un centro "academico", donde
quiza encontrar colaboradores, debates y algo resonancia.

La primer presentacion en el flisol hace un año, fue atropellada y amateur, mas
sirvio para mostrar algo mas ameno, estructurado y solido en el hackmiting (o
eso percibi). Hasi que en esta oportunidad esperaba bordarla. Mas la sede donde
tenia previsto mostrarlo fue cancelada y de las restantes, la unica que me
insitava a llevarla a cabo, ya esta un poco fuera de fecha.

Por si os interesa ver las "diapositivas" pueden bajar [este
zip](/data/morg.zip) hecho con reveal.js y algo de org-mode, no mui fino, pero
vistoso. Ya aprobechare para seguir madurando las ideas y si esta dentro del
presupuesto asistir al fes acatlan donde mas me ha gustado el evento, o al
rancho electronico, que nunca esta de mas ir a merodear por hay...

## 4k

Esta secion inicio con el vicionado de dos cintas: **Los caballeros de la mesa
cuadrada** y **La vida de brian**. Segun cuentan son de unos tales Monty Python
y tienen arto de divertidas... y si tienen su encanto, pero me han llegado tarde en el
trayecto como para ser relevantes. Tienen un guion inteligente a la par de
absurdo, con temas que encuentro de caracter universal.

Si bien encontre mas redonda la vida de brian, las "monturas" y aquella escena
de "vean la violencia inherente al systema" en la peli de la mesa cuadrada me
hace dificil decidir cual es mejor, pero como decia, llegaron tarde, ya
antes pasaron la excelsa saga, nichijou y gintama como para tener a estas cintas
en alta estima, aun asi fueron entretenidas, con momentos graciosos y un "que
diablos importa el presupuesto, hare mi propia pelicula!"

....

Una termporada de anime que llega a su fin. Por el camino perdi el interes en
unas series, al tiempo que aparecian otras nuevas en el horizonte.

**Death March kara Hajimaru Isekai Kyousoukyoku** Esta serie, es una cosa muy rara de
aquellas que solo es posilbe apreciar su verdadera naturaleza bien marihuano
(cof, cof, capitulo 6) pensando en cosas como: "sus intenciones son tan poco
sutiles, que aun no entiendo por que no es una obra de culto"...

...me explico, el planteamiento es estupido (como muchos otros isekai) un sujeto
(un programador en este caso) aparece en un mundo de fantasia abrutamente, y,
"por que si" esta super chetado, rodeado de chicas para satisfacer fetiches
varios, y encima tiene acceso a un menu del juego en todo momento, aunque (hasta
ahora) no puede salir del juego, hacer pausa o teletransportarse. Y asi, pasa el
dia a dia del desasonado protagonista, apareciendo logros pomposos cada 2
minutos por cada cosa que hace, subiendo habilidades "al vuelo", conquistando
corazones y derrotando obstaculos sin la mas minima tension, pero aqui mismo es
donde esta lo interesante. Auque no lo parezca es una satira desvergonzada sobre
el genero, al mismo tiempo una critica-complice a los observadores, donde con la
atencion suficiente y un estado mental apropiado, es posble entrar en en juego
tipo: "esta bien, querido grupo de animadores, muestrenme la siguiente
estupides, mientras sus personajes 2d me ven directamente a los ojos"

jo, puede que sea eso, o haber visto el cap. 6 bien colocado... pero lo he
revisionado y aun encuentro aquello. Meeeh, lo guardare en el archivo para la
siguiente fumada

    magnet:?xt=urn:btih:1b0afe5d6ded6394a4a7f50c4c48d9f6e5b9e7c0&dn=%5bPuyaSubs!%5d%20Death%20March%20kara%20Hajimaru%20Isekai%20Kyousoukyoku%20%5b1080p%5d%5bBatch%5d&tr=http%3a%2f%2fnyaa.tracker.wf%3a7777%2fannounce&tr=http%3a%2f%2fanidex.moe%3a6969%2fannounce&tr=http%3a%2f%2ftracker.frozen-layer.com%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.opentrackr.org%3a1337%2fannounce&tr=udp%3a%2f%2fipv4.tracker.harry.lu%3a80%2fannounce&tr=http%3a%2f%2ftracker.frozen-layer.net%3a6969%2fannounce

**Koi wa Ameagari no You ni** la serie que a primera vista podria ser la
fantacia de un virgocuevano cuarenton (que una jovensuela se enamore
insintentemente de ti), con el pasar de los episodios deja claro que de material
para paja, poco tiene. Es mas una "revanada de vida" o costumbrismo
idealisado de gente normal y cosas bien normales que suceden todos los dias, (el
bromance de la prota con su amiga, es algo bien normal?). Je, Je, llevadera, con
un final poco complaciente, quiza demaciado maduro para lo que esperaba

**Osomatsu san 2**, Fuuuuhh, como la primera temporada, capitulos magnificos,
buenos, experimentales y reguleros, con un primer ending super-chulo! Por mera
coincidencia con el anime isekai (en la misma secion nebulosa), tambien encontre
el capitulo 6 como una revelacion magica, mistica y misteriosa... pero ya no me
acuerdo de que iba.

    magnet:?xt=urn:btih:ce38967406d1f4201a981820126cf2dc1c1ff843&dn=%5bPuyaSubs!%5d%20Osomatsu-san%202%20%5bBatch%5d&tr=http%3a%2f%2fnyaa.tracker.wf%3a7777%2fannounce&tr=http%3a%2f%2fanidex.moe%3a6969%2fannounce&tr=http%3a%2f%2ftracker.frozen-layer.com%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.opentrackr.org%3a1337%2fannounce&tr=udp%3a%2f%2fipv4.tracker.harry.lu%3a80%2fannounce&tr=http%3a%2f%2ftracker.frozen-layer.net%3a6969%2fannounce

**Karakai Jouzu no Takagi-san** ha, una serie de rollmance jugueton "tierno",
exitante (sin mostrar nahhh) y juvenil. Ha, tiene mucho de "dia a dia" que
pronto se complementa con historias de personajes secundarios, pero mantiene el
interes de inicio a fin sin exigirte nada a cambio

    magnet:?xt=urn:btih:b63c20839a06e321797d95088ad7b5c3a68a6763&dn=%5bPuyaSubs!%5d%20Karakai%20Jouzu%20no%20Takagi-san%20%5b1080p%5d%5bBatch%5d&tr=http%3a%2f%2fnyaa.tracker.wf%3a7777%2fannounce&tr=http%3a%2f%2fanidex.moe%3a6969%2fannounce&tr=http%3a%2f%2ftracker.frozen-layer.com%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.opentrackr.org%3a1337%2fannounce&tr=udp%3a%2f%2fipv4.tracker.harry.lu%3a80%2fannounce&tr=udp%3a%2f%2fopen.stealth.si%3a80%2fannounce&tr=http%3a%2f%2ftracker.frozen-layer.net%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.coppersurfer.tk%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.leechers-paradise.org%3a6969%2fannounce

**Overlord II** puag, con lo entretenida y dinamica que fue la primer temporada,
esta seguda parte es una divagacion leeenta de un lado a otro sin un fin
claro. Algunas batallas en el tramo final estan chidas, sin embargo, aunque al
final de los episodios (finales) te dejan con ganas de ver lo siguiente, tras
cada inicio de capitulo el rollo se corta bastante rapido.

Siendo una produccion de madhouse, decepciona bastante, posiblemente se estaban
gastando sus mejores fichas en sakura, aunque esta aun no la veo

**3-Gatsu no lion 2** la primer temporada inicio como un drama medio
extraño de un deportista del shogi sobre su tortuosa relacion con su
familia adoptiva (en particular con su hermanastra) y termino como un compendio
de varias historias paralelas.

Para esta segunda parte se olvidan completamente de la hermana, del drama
familiar y se vuelcan de lleno con una historia de acoso escolar! heeEE?

aunque tiene momentos que dan pereza, y seguirla con la regularidad de la
emicion fue dificil, tiene episodios donde dejan fluir la animacion intercalando
entre lo abstracto y lo epico, mientras en el "mundo real" solo se juegue una
partida entre dos vejestorios. Em, en global una buena inversion de tiempo, algo
mas exigente que la media y con momentos animacionales con factura *shaft*

**Mahoutsukai no Yome** we, en lo referente a la animacion aqui esta el
concursante con peor nota, tirandote desplazamiento en imagenes estaticas, una y
otra vez. La tematica dramatica ciclica, desgasta la formula lentamente, aun asi
se las arreglan para dar una ligera (muy ligera) sensacion de avance en los
protagonistas. Eso si, lo [mary sue](https://es.wikipedia.org/wiki/Mary_Sue) de
la peliroja no se lo quita nadie. Me costo llegar al final, lograrlo fue en
mucho producto de la inercia. Si tiene continuacion, pasare de largo

Y eso es todo en cuanto a la temporada, dejo por concluir Gintama, que aun me
faltan ~10 episodios, otras que calleron por el camino a los pocos capitulos
(como citrus, ramen daisuki koizumi-san, miira no kaitaka (guahhg)) y otras aun
por visionar, como violeta siempre jardin, yuru camp, garo vanishing line y
otras mas, a la espera de encontrar al menos algo agradable.

De la temporada en curso, unicamente (y por que no lo puedo evitar) seguire a
boku no hero academia! (y a la infamemente infinita one piece)

....

**A Quiet Place** peli de estreno... meeh, realmente esperaba sufrir un poco
de tencion, pero no logre entrar en el juego, como no tampoco logre entrar con

**Titanes del pacifico 2**, tiran por la borda cualquier cosa minimamente seria,
y se dedican de lleno a la accion sin fundamento casi salida de los power
rangers. No recuerdo muy bien la primera, pero me gusto bastante. Para esta
ubiera valido mas un torrent que acudir al templo

**Ready player one** Creo que lei el libro por recomendacion de la biblioteca de
trantor, y estubo muy bueno, en particular aquel resumen de "aqui esta usted" al
inicio del libro. Mas el final, si bien congruente con su espiritu, lo encontre
aburrido.

En la peli por su parte, no aguanto la geta del prota, me es insoportable,
aunque su alter ego salido de final fantasy tampoco es que lo llebe muy
bien. Pese a ello, (y como no esperaba nada) juega sus cartas de
entretenimiento, manipulacion emocional y accion con bastante maestria.

Oasis no tiene la importancia que en la novela (aunque años vista, como podria
un invento asi monopolizar a la raza entera, donde estan los forks libres o la
competencia privativa?), ni el premio parace mejor que ganar la loteria, como
tampoco es creible que el grupito de los 5 (en un mundo globalizado) viviera en
la misma cuadra, o lo pequeña que es la batalla final, p-e-r-o ignorando eso, el
conjunto es fenomenal y merece pagar su entrada

**It Stains The Sands Red** la premisa escatologica de esta cinta sobre una
chica menstruando y un zombie que la huele, mantuvo el torrente de esto activo
por semanas esperando su conclucion. Lamentablemente, lo optenido fue un "meh".

Por tener una produccion independiente le daria un aprobado, aunque el trasunto
culposo y de madre torturada la regresan al meehh

## fonos

**The Crystal Method** musica electronica machacona de fondo, con buen denpa
simplemente recomendable

**Noragami no Oto** sucede muy de vez en cuando, que una serie recibe un OST
disfrutable de inicio a fin... habia visto la primer temporada, graciosa,
divertida y con inecesario drama del espiritu acompañante (entre shaman king y
samurai X (manga)). La segunda temporada tambien la vi, pero pierde
vastante. La gracia es que recientemente en una reseña de la serie mencionaban
a este, su material sonoro como un manjar exquisito y tenian toda lo jodida
razon, enjoy!

(ja, ja, ja, por alguna razon tenia en esta mente retorcida que "Kamisama
Hajimemashita" una pieza bastante melodica y buen rollo, era parte de esta
serie... por supuesto no era asi, eso es de otra serie un poco menos
varonil... pero bien ambientada en su ending, creo que esa pieza se llama
"Kamisama Onegai", buscar que igual y aun lo encuentran, la agrupacion que lo
toca se llama Hanae)

ya que el musico encargado del album anterior (noragami) ([Taku Iwasaki](https://es.wikipedia.org/wiki/Taku_Iwasaki)) parece tener el toque,
fue inevitable hacer una busqueda de sus trabajos, unas cuantas cosillas mas
en torrente, y reeeedescubriendo que ya habia escuchado a dicho compositor en el
OST de Tengen Toppa, aunque en aquella ocacion el sountrack me parecio soporifero.

La siguiente obra en caer fue el OST de Gatchaman Crowds, una produccion que en su
momento no me gusto casi nada (incluida la musica). La razon de terminar de ver
su primer temporada era su animacion decente y que ya le habia invertido varios
capitulos como para dejarla inconclusa...

Escuchada su sonoridad independientemente, esta muy bien, hasta la intro de la
cual tenia un mal recuerdo tiene sus impactos. Siendo menos machacon que el de noragami,
no cambia el abanico amplio de sonoridades, desde el fondo epico videojueguil a
solos operisticos y momentos pianito. **Sacrifice** me gusta mas que las otras,
tiene una epica a lo Tengen Toppa y encaja tan bien con el score del EVA 3.0 que
los Gatchamans simplemente no se la merecian (ni EVA 0.3), fuuuh! que pasada son
algunas de sus piesas, y lo bien que se le da crear estos buffets musicales

Como tercer plato, la segunda secion de noragami en D-o-s discos, el primero
inicia machacon y luego gira hacia musica de camara rotundamente
convencional... y le sale bien, maldicion, por cosas como esta es que bajo un
monton de material aleatorio (por encima de mis posibilidades) y lo dejo por hay olvidado esperando encontrar
alguna joya

resaltaria "pain" una combinacion de electro accion esoterico con pianito y
guitarra electrica

el disco dos, es lo mas flojo, bueno como fondo sin prestar atencion

lo siguiente fue **Akame ga Kill OST 1** (no he visto la obra que sonorisa). Mucho
mas etereo, en un ambiente que itera en ocaciones sobre el suspenso y el
ambientes naturales

Para rematar **Katanagatari OST Vol.1** y **Katanagatari OST Vol.2**.

Luego de escuchar todos estos materiales, encuentro una constante, ritmos
fiesteros happy raperos, electro-frenesi-sueve, suspenso exotico, ambiente, pero
quiza lo mas reconocible es un sonido "academico" melancolico con pianito, que
creo nos muestra la faceta mas profunda del musico, perfecta para esos momentos
con final de nudo en la garganta y lagrimilla

    // noragami no oto (I y II)
    magnet:?xt=urn:btih:e34c0d4426a5e778f61758b1b5e56fbfe0249b99&dn=%5bASL%5d_Various_Artists_-_Noragami_Original_Soundtrack_-_Noragami_no_Oto_%5bFLAC%5d_%5bw_Scans%5d.rar&tr=http%3a%2f%2fnyaa.tracker.wf%3a7777%2fannounce&tr=udp%3a%2f%2ftracker.istole.it%3a80%2fannounce&tr=udp%3a%2f%2ftracker.openbittorrent.com%3a80%2fannounce&tr=udp%3a%2f%2ftracker.publicbt.com%3a80%2fannounce%5c&tr=http%3a%2f%2fopen.nyaatorrents.info%3a6544%2fannounce&tr=udp%3a%2f%2ftracker.penis.com%3a80%2fannounce&tr=udp%3a%2f%2fopen.stealth.si%3a80%2fannounce&tr=udp%3a%2f%2ftracker.opentrackr.org%3a1337%2fannounce&tr=udp%3a%2f%2ftracker.coppersurfer.tk%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.leechers-paradise.org%3a6969%2fannounce
    magnet:?xt=urn:btih:552925040ce097d43c1477b7bca5d93cf87c1cc8&dn=Noragami%20Aragoto%20Original%20Soundtrack&tr=udp%3a%2f%2ftracker.leechers-paradise.org%3a6969&tr=http%3a%2f%2fmgtracker.org%3a2710%2fannounce&tr=udp%3a%2f%2ftracker.coppersurfer.tk%3a6969&tr=http%3a%2f%2ftracker.mg64.net%3a6881%2fannounce&tr=http%3a%2f%2fbt2.t-ru.org%2fann&tr=http%3a%2f%2fbt3.t-ru.org%2fann&tr=udp%3a%2f%2ftracker.opentrackr.org%3a1337&tr=udp%3a%2f%2ftracker.zer0day.to%3a1337
    // gatchaman crowds
    magnet:?xt=urn:btih:55c98a630bd7fb42fc96922c593ea9a1d89cdac9&dn=%5bAOI%5d%20GATCHAMAN%20CROWDS%20ORIGINAL%20SOUNDTRACK%20%5bFLAC%2bscans%5d.zip&tr=http%3a%2f%2fnyaa.tracker.wf%3a7777%2fannounce&tr=udp%3a%2f%2ftracker.openbittorrent.com%3a80%2fannounce&tr=udp%3a%2f%2ftracker.publicbt.com%3a80%2fannounce&tr=http%3a%2f%2fopen.nyaatorrents.info%3a6544%2fannounce&tr=udp%3a%2f%2fopen.stealth.si%3a80%2fannounce&tr=udp%3a%2f%2ftracker.opentrackr.org%3a1337%2fannounce&tr=udp%3a%2f%2ftracker.coppersurfer.tk%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.leechers-paradise.org%3a6969%2fannounce
    // akame ga kill
    magnet:?xt=urn:btih:2d070f8fc0d1cbcb10c3950df6b5db59172b409e&dn=%5bASL%5d_Iwasaki_Taku_-_Akame_ga_Kill_Original_Soundtrack_1_%5bFLAC%5d.rar&tr=http%3a%2f%2fnyaa.tracker.wf%3a7777%2fannounce&tr=udp%3a%2f%2ftracker.istole.it%3a80%2fannounce&tr=udp%3a%2f%2ftracker.openbittorrent.com%3a80%2fannounce&tr=udp%3a%2f%2ftracker.publicbt.com%3a80%2fannounce%5c&tr=http%3a%2f%2fopen.nyaatorrents.info%3a6544%2fannounce&tr=udp%3a%2f%2ftracker.penis.com%3a80%2fannounce&tr=udp%3a%2f%2fopen.stealth.si%3a80%2fannounce&tr=udp%3a%2f%2ftracker.opentrackr.org%3a1337%2fannounce&tr=udp%3a%2f%2ftracker.coppersurfer.tk%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.leechers-paradise.org%3a6969%2fannounce
    // katanagatari
    magnet:?xt=urn:btih:9588639f830331f45cf4434ab39ac008a0f8c62a&dn=%5bcpx%5d%20%e3%80%8c%e5%88%80%e8%aa%9e%e3%80%8d%e5%8a%87%e4%b8%ad%e6%a5%bd%e6%9b%b2%e9%9b%86%ef%bc%8f%c2%abKatanagatari%c2%bb%20Soundtrack%20(flac%2bscans)&tr=udp%3a%2f%2ftracker.coppersurfer.tk%3a6969&tr=udp%3a%2f%2ftracker.opentrackr.org%3a1337%2fannounce&tr=udp%3a%2f%2ftracker.openbittorrent.com%3a80&tr=udp%3a%2f%2fopen.demonii.com%3a1337


Tambien continue la escucha de Gary Moore. **Back on the streets** es una maravilla!
quitando la primer pieza, por ochenterosa, por lo demas un imprecindible

planeaba un recorrido completo al artista,  siguiendo con **Corridors of
Power**... y bueno... un tropezon ochenteroso en toda regla, wahaaah lo escuche
completo y dejo un regusto melodioso plastificado muy desagradable. Ya retomare
cuando lo olvide. Para quitar el regusto desagradable, retome a Roy Buchanan. Aunque no me
acuerdo que escuche, fue mejor

Un miembro del reddit de Reeeehheeeheeheeeyyhh (Ayanami) subio una album
conceptual dedicado a la peli-azul de ojos rojos

https://mileslarge.bandcamp.com/album/the-wonderful-world-of-rei-ayanami

un trabajo undergrond sincero y apasionado "con papeles". je, je, no lo pondria
en los 100 albums de nasciiboy, pero su lugarcito se merece en la carpeta de
~50GiB de musica evangelica

**Babymetal – Babymetal** creo en el anterior ramen enlace al video del dempa de
yururin, hay hablaban un poco de esta banda y por alguna razon obscura, ya habia
visto uno de sus videos "aidol artifisiosos" (pista 3) que bueno, tenia algo de
gracia, aunque no la suficiente como para ir a descargar su material. COmo si
fuese conspiracion cosmica, en las novedades flac de Nyaa, pusieron unas
fanversion de algunos de los albums corrigiendo el material original para
agregarle el tan menospreciado rango dinamico. Asi pues, tras dejarlo madurar
(`( ͡° ͜ʖ ͡°)`) le reserve una sita en la agenda

no se, dificilmente lo llevaria por hay difundiendo su estilaco por las redes,
mas no negare que como meme funciona. Quiza lo que mas me a gustado son algunos
coritos que traen al recuerdo el intro de un anime adorable llamado zattai karen
children, <q>Yeah! Let's try! d-a-i-t-a-a-a-n</q>, ja, ja, ja, aun no tengo muy
claro el publico que aquella obra, por la advertencia de prender la luz supongo
que era para niños, aunque algunas escenas me hacen pensar que quiza estaba
dirigido a las creaturas de la noche...

y finalmente un mega atracon por la musica de **Kahimi Karie** que abarco sus 8
albums de estudio, desde el 97 al 2010 (+ 4 albums de compilaciones). Con las
cantantes japonesas y los gustos idol de nyaa coger material requiere una
verificacion previa, je, esta simplemente sono a popsito desenfadado y asi es,
e-x-e-p-t-o que la musica que sale suena amateur, como de tu conocida que dice
que canta y no sale mal, aunque no llenara un estadio, aunque tiene un toque de
gusto culposo, un poco tonto y cool que consigue que no puedes evitar pasar a
la siguiente cancion con la expectativa de encontrar algo como minimo igual o mas
divertido.

Los primeros dos albums son los mas relevantes, y aunque no descarto ninguno, a
medida que pasa el tiempo, la vocalista se toma cada vez en mas en serio su voz,
pasando del happy-pop-experimental(?) a lo directamente (frances?)
alternativo. Mehhh, estubo tan chido que hasta baje (casi) el resto de lo
incluido en el torrente.

    magnet:?xt=urn:btih:952d98c5fa827fad4ca0846601194165d639d017&dn=Kahimi%20Karie&tr=http%3a%2f%2fnyaa.tracker.wf%3a7777%2fannounce&tr=udp%3a%2f%2fopen.stealth.si%3a80%2fannounce&tr=udp%3a%2f%2ftracker.opentrackr.org%3a1337%2fannounce&tr=udp%3a%2f%2ftracker.coppersurfer.tk%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.leechers-paradise.org%3a6969%2fannounce

Por si buscan una referencia mas solida de lo que van a encontrar en este
material, es una combinacion ecleptica entre björk, los velvet underground, los
pixies y sonido electronico-electro-pop

## txt

finalmente, entre el trancurso del ultimo y este ramen, agregue la traduccion de
dos post que por su contenido no puede evitar colocar. No descarto, poner otros,
todos ellos bajo la etiqueta de trl, aunque tengan temanicas distintas

uno de los post que casi me proponia a traducir es este:

http://theorangeduck.com/page/the-software-thief

je, pero cuando lo comparti en reddit, llovieron los votos negativos, y algunas
opiniones contrarias pero igualmente enriquesedoras que me hicieron aparcarlo.

tambien aparecieron nuevas secciones del curso de emacs en la pipaplena, destaco:

https://lapipaplena.wordpress.com/2018/04/01/curso-emacs-26-calculos-which-y-hooks/

donde nos muestran un modo de calculadora rapida en emacs, que substituye el
hacer calculos en el entorno, en la terminal, en una aplicacion de calculadora
o cualquier otro apaño inferior. Para invocarla solo hace falta un `C-x * q`

"Acusación a la Sociedad Industrial: la deshumanización del universo". En el
blog del decrecimiento, aunque la mayoria de las veces sueltan post que
encuentro aburridisimos y sin interes, de vez en cuando unas ~5 veces al año
aparece material como el siguiente http://www.decrecimiento.info/2018/04/acusacion-la-sociedad-industrial-la.html

y aunque ya no me acuerdo de que eran los siguientes enlaces, los adjunto por
que ya los tenia anotados...

- http://www.spacjer.com/blog/2018/03/02/why-is-my-emacs-slow/
- https://blog.cerebralab.com/#!/blog/7
- https://www.reddit.com/r/programming/comments/891ces/the_end_of_windows/
- http://blog.koalite.com/2014/11/aprende-despacio/
- http://blog.koalite.com/2014/11/codigo-bonito-codigo-feo-codigo-que-funciona/

jo, jo, creo que con cada nuevo ramen, el tocho de texto crece progresivamente...
