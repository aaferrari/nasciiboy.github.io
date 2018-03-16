+++
title      = "Ramen X – Infierno Mayoi"
tags       = [ "ramen", "fonos", "4k", "regexp" ]
categories = [ "post" ]
date       = 2017-09-08T11:53:17-05:00
+++

![](/img/gatari.jpg)

bitacora de abordo: ha pasado casi un mes desde el ultimo "encuentro", muchas
cosas sabrosas, informaticas y otros echos hilarantes (a nivel personal) podrian
merecer un registro, pero pondre lo que recuerde y algunas cosas que iba
escribiendo despistadamente.

Quiza lo mas relevante, es que me encuentro absorto en la aleatoria labor de
reescribir morg. El reencuentro empezo (manoceando codigo) aproximadamente hace
dos meses, luego de terminada la lectura del tgpl, reescribiendo unas funciones
basicas de manipulacion de `strings` (las extrañas cadenas de Go) y luego
replanteando, escribiendo, puliendo (y no pocas veces regresando al punto de
partida) cambios en las estructuras `Markup` y los "comandos de bloque". Dudas
surgieron, deberia estar todo el parser en un directorio monolitico? o mejor
subdividirlo en subdirectorios? o darles su propio paquete? al final ya que todo
es parte de un solo concepto de un lenguaje de marcado muy particular y
dificilmente sera utilizado por alguien mas, pues, casi todo lo puse en el mismo
paquete, eso si, dividido por ficheros, aunque esto trae el inconveniente para
los profanos, que deben leerse todos los ficheros antes de entender que hacen en
conjunto

mientras hacia esto, me encontre un BUG gordo en el motor de expresiones
regulares, que requirio un par de horas para ubicar su origen. Resumiendo, el
fallo, se presentaba en regexes de tipo `^cosas(agrupacion)+$` y se debia a no
restaurar la posicion de inicio cuando una agrupacion "falla" en su ultimo
recorrido, pero se cumple con su "volumen de repeticion minimo", es decir la
agrupacion es correcta... pero termina donde se supone debe terminar, que es
el fin de los datos de entrada, je, es bastante mas confuso y poco intiutivo de
lo que parace, mas no quiero abrumar al personal con una larga explicacion. La
solucion chapucera, fue eliminar una pequeña optimizacion que ahorra almenos 3
llamas a funciones, sinduda chapucero, aunque funcional

La moraleja, es, que con el tiempo y pruebas suficientes, saldran nuevos bichos en
tu programa, pese a todo el tiempo que allas invertido en el. Lo bueno? tengo un
pretexto-obligacion para toquetear el motor raptor-4 (Golang edition). El resto
de ediciones en C y regexp3 (Go), no reciviran una actualizacion inmediata,
quiza, solo cuando encuentre una iteracion que pueda llamar perfecta, como lo
fueron las versiones iniciales del libro del raptor... je, hay otras cosas en
las cuales dedicar el tiempo

luego de corregir las regexes, me lie unas tardes intentado hacer un analizador
de cosas que tienen "sintaxis de funcion" (`algo( "xy", 0.12, 12, pi, ... )`), con un numero de parametros
arbitrarios, para lo que eche mano de regexes y conteo de caracteres a lo
salvaje (+1, -1, +x, -x, ...), sin embargo al intentar implementar y reconocer
un numero arbitrario elementos con tipos distintos, la ofuscacion mental se hizo
presente.

la pantanosa situacion dejo de ser intimidante al recordar unas secciones del
libro de go, donde hacian un lexer, o algo asi y me puse a viajar y divagar en
busca de lexeres de codigo escritos en go, para terminar llendo a el codigo de
un paquete de la libreria estandar `text/scanner`, que en esencia recorre,
una entrada de datos caracter a caracter (unicode en utf-8), lleba un
recuento de la posicion actual de la entrada por linea y columna, y lo mas
interesante, reconoce espacios... y recolecta identificadores, comentarios,
enteros, flotantes, caracteres, cadenas y otros elementos sintacticos similares
a los que utiliza go,

la libreria (a mis hojos (**con H**)) tenia cosas muy raras, pues exigia un
"contrato" con un `io.Reader`, ademas de contar un raro buffer en un arreglo de
1024 bytes y otro buffer adicional de tipo `bytes.Buffer`, que ya es cosa seria
(para mi fortuna a ese paquete ya habia metido mano, lo que mas me gusta de la
libreria estandar de Go, es que la puedo enterder, a diferencia de libc, que
esta hasta arriba de macros y cosas raras)

customise el paquete para que solo tuviera lo necesario, sin buffers ni nada,
reconociera booleanos e informara de enteros octales, hexadecimales e ints de
forma explicita, con casi todos sus campos brutalmente expuestos (uuhhh)

luego de adquirir ese nuevo conocimento se me ocurrio modificar (nuevamente)
morg de raiz y todos sus componentes y en eso estoy, ofuscado, obsecionado y
exitado!  no dedicare tiempo a traducir, ni a otro lenguaje hasta que el asunto
funcione, porque en este aspecto no puedo pensar en otra cosa

en relacion con este particular tipo de adiccion, en reddid (en ingles) un tipo
colgo un post, que si no revelador o extenso, sentiras empatia al leerlo: https://web.archive.org/web/20130906141542/http://virtuecenter.com/blog/the_effects_of_computer_programming_on_the_brain.html

otro post interesante fue, http://www.danielallington.net/2016/09/the-latex-fetish/
donde el autor inicia una **guerra santa**, *Latex VS Word* Llamando fetichistas
a los usuarios de latex, no sin fundamentar sus acusaciones hechando abajo los
supuestos beneficios de utilizar latex... en comparacion con word. Concuerdo con
sus puntos, mas creo que los (ahora ficticios) beneficios de latex, *deben* ser
alcanzados creando un lengueje de marcas ligeras **poderoso**, **sencillo**,
**elegante**, pero sobre todo, **WYSIWYMAG** (What You See Is What You Mean And
Get) ja, ja, ja, haaaa, algun dia sera). Para ves comentarios en reddit ir a:
https://www.reddit.com/r/programming/comments/6tkoop/the_latex_fetish_or_dont_write_in_latex_its_just/
en ocaciones buenos post son undidos sin justificacion, darle un voto positivo

El ultimo registro de esta sesion es lo mas tremendo y ezpelusnante... chan,
chan, chan... chan, chan, chan... chan, tras abandonar, repudiar y menospresiar la
educacion escolarisada desde hace la mitad de mi existencia, me inscribi en una
preparatoria abierta, para poner en marcha un lividinoso proyecto que hara
(espero) paleativa mi situacion humana en el territorio donde habito.

El plan es terminar la "prepa" en unos 3 meses y seguir con mis mierdas de
intento de programador, tras lo cual entrare a la universidad en una carrera de
informatica, reciviendo una "beca salario" de unos 100 dolares mensuales, que ya
me bastan para subsistir como semi-persona y luego espero alguna oferta de
trabajo temporal o algo asi, jo, jo, el kit de la cuestion se oculta en el hecho
que comparado con los habituales residentes de esas instituciones de educacion
"superior", mi nivel basta para asombrar y resivir culto de la mayoria de mis
futuros colegas y poner en evidencia a alguno que otro profesor, uuuhhh espero
con ansias ese dia, o cuando una compañera de ascendencia oriental me pida ayuda
con algun tema y le responda: "es curioso, pero tu necesitas algo y yo necesito
algo...", ja, ja, ja, el sueño humedo de cualquier profesor, solo que no sere
profesor, sere alumno, oh si!

kof, bueno, ese es el plan, si se concluyen la primera y segunda fase que es
entrar en la uni y recivir la "beca salario" (el punto critico), en verdad
planeo quedarme para siempre en la academia, una vez que me dejen entrar, ya no
saldre!

## 4k

**Kizumonogatari** y **Owarimonogatari**, dentro del conglomerado global que
demomino cosas audiovisuales (cine, series, anime) ninguna obra destaca y
significa mas que EVANGELION (y su manga, que en mi mente estan fusionados, casi
indistinguibles), mas esto no significa que no lo acompañen otros referentes personales de
calidad equivalente, y las **Monogatari** cosas, obviamente tiene un lugar
priviligiado entre los dioses a los que decido adorar.

No, no es profunda como Evangelion, pero su estetica "monogatari" me mata. Si
hay una ley que impida enaltecer una obra deliciosa aunque poco nutritiva,
ninguna condena sera suficiente para sentir que he pagado su morboso,
incestuoso y fetichista placer sugestivo

**Over the garden Wall** sin esperarla, ni buscarla, broto en la lista de
recomendaciones del yutu con un correctisimo doblaje al español. Son mini
episodios de 10 minutos con cuentos basados en "animaciones folkloricas de gente
vieja" (>= 30). Como punto destacado, transmite algo del mal rollo que tienen
los dibujos animados primigenios

**Busou Shoujo Machiavellianism**, chicas tsundere con armas, en una especie de
harem de batallas con todos los fetiches y topicos, includo el de la 4^ta
pared. Bocadillo ligero y entretenido, ideal como transcicion luego de una densa
racha

**El Reino de los Sueños y la Locura**, documental del <s>estudio Ghibli</s>
rusueño <s>Coronel Sanders</s> Hayao Miyazaki... seguro hace falta considerar a
"miya" un dios para ver esto atentamente, ya que no entro en ese elitisimo
grupo, el filme y sus "personajes" me gritan a actuacion falsa mas que en un
documental chino de ciudadanos satisfechos. Que si, tiene algunos puntos
interesantes, como la aparicion del permanentemente extraño Anno y algunas
cosillas de Nausica, ademas de menciones a la princesa Kaguya (*Exelsior*) y un
poco de como hacen la ultima (por ahora) peli del miya (que aun no veo), ???
alguien mas se pregunta donde esta los "chinos" que hacen la animacion de verdad
???. Recomendable unicamente si quieres presumir de ser tan fan como para verte
un documental de esto

**the Century of the Self** Al final lo mas denso (disponible en el yutu, con
subtitulos). Esto son 4 episodios documentales de como el gobierno, las
corporaciones y los psicoanalistas en colaboracion con los avances tecnologicos
e informaticos han creado una sociedad de sujetos permanetemente
insatisfechos que expresan mediante poductos su individualidad

## fonos

**Voices of the Lifestream**. Las cosas bonitas insitan al fanatismo, y cuando
el fan es musico, dibujante o programador, que mas puede hacer que rendir
tributo a sus musas (con, o sin copyright de por medio). El
colectivo [OverClocked ReMix](http://ocremix.org/) se dedica a hacer musica
basada en videjuegos y ofresen la mayoria de su material de forma libre, hace
tres años fue una bonita coincidencia del buscador del internet, creo buscando
musica de MegaMan o Chrono Trigger, no es que sea muy jugon, pero esas dos obras
me ponen mal, la lista de torrents la encontraran
por [aca](http://ocremix.org/torrents)

segun su propia pagina tienen 113 albums, aunque en los torrents cuentan
con 70. No lo puedo asegurar, pero creo que el aumento de albums es debido a
incorporar otros proyectos que de inicio no formaban parte del colectivo, y
quiza por ello no estan incluidos en los torrentes.

Tampoco recuerdo de donde saque la lista de sus producciones, cuando baje su
material, lo mas viejo databa del 2004 y creo que ahora inicia por el 2009 (o
2011) en fin de cualquier forma es una gran biblioteca en calidad CD, o hasta
ahora mis favoritos son

- [Chronology - A Jazz Tribute to Chrono Trigger](magnet:?xt=urn:btih:790ac5557b3cd2774b2ed1b5283bdfdbbda16057&dn=Chronology%20-%20A%20Jazz%20Tribute%20to%20Chrono%20Trigger&tr=http%3a%2f%2fbt.ocremix.org%2fannounce)
- 25YEARLEGEND - A Legend of Zelda Indie Game Composer Tribute
- Final Fantasy IV - Echoes of Betrayal, Light of Redemption

**Juno Reactor**. Que tiene de interesante el tipo que proporciona algunas de
las sonoridades de matrix y texnholize? en un primer acercamiento por
*Transmissions* (1993) nada... luego de una "segunda oportunidad" con *Odyssey*
(recopilacion 1992-2003) ya suena tecnox-matrix dolmilsss, aunque de verdad su
punto algido lo alcanza con *Labyrinth* (2004), el resto son puntos intermedios
entre su sonido de fiesta drogui-hacker-extasis-bdsm (no se por que lo imagino asi) y
sonido envolvente-asfixiante-ambiental. En resumen recomendable, iniciar con
Odyssey y Labyrinth para no alienarse

    magnet:?xt=urn:btih:65ad20010a460ce573ea7a7af7f9e7d73700cdd6&dn=Schooltree%20-%20Heterotopia%20(2017)&tr=udp%3a%2f%2f9.rarbg.com%3a2710%2fannounce&tr=udp%3a%2f%2ftracker.leechers-paradise.org%3a6969%2fannounce&tr=udp%3a%2f%2fexplodie.org%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.opentrackr.org%3a1337%2fannounce&tr=udp%3a%2f%2ftracker.zer0day.to%3a1337%2fannounce&tr=udp%3a%2f%2ftracker.coppersurfer.tk%3a6969%2fannounce

**Gentle Giant** Segun la wikipedia, una de las mas grandes bandas de Rock
progresivo de todos los tiempos. Hum . . . estan chidos, de momento he escuchado
4 de sus albums, el primero esta muy bueno, aunque ninguno me ha puesto yonki

    magnet:?xt=urn:btih:47dcb412b126e04ef0f541cc964adfced6d182d3&dn=Gentle%20Giant%201970-1980%20Studio%20Discography%20FLAC&tr=udp%3a%2f%2f9.rarbg.com%3a2710%2fannounce&tr=udp%3a%2f%2ftracker.coppersurfer.tk%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.opentrackr.org%3a1337%2fannounce&tr=udp%3a%2f%2ftracker.leechers-paradise.org%3a6969%2fannounce&tr=udp%3a%2f%2fexplodie.org%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.zer0day.to%3a1337%2fannounce


**X&Y** (Coldplay) no estoy seguro si ya habia consumido o no este album, si asi
fue no le preste atencion. Recomendable para un momento s-e-c-i-b-l-e

**Happy Trails** (Quicksilver Messenger Service)

    magnet:?xt=urn:btih:02c6251fb20892fa966dffb17815e6b254333073&dn=Quicksilver%20Messenger%20Service%20-%20Happy%20Trails%20(1969)%20%5bFLAC%5d&tr=udp%3a%2f%2ftracker.zer0day.to%3a1337%2fannounce&tr=udp%3a%2f%2ftracker.leechers-paradise.org%3a6969%2fannounce&tr=udp%3a%2f%2fexplodie.org%3a6969%2fannounce&tr=udp%3a%2f%2f9.rarbg.com%3a2710%2fannounce&tr=udp%3a%2f%2ftracker.coppersurfer.tk%3a6969%2fannounce&tr=udp%3a%2f%2ftracker.opentrackr.org%3a1337%2fannounce

Jo, esto si es droga dura, tan efectiva que para bajar mas material de esta
banda me he puesto a erradicar scanns de albums

**Rebelión en la Granja** No es musica, es un cuento relatado por el podcast de
Verne y Wells ciencia ficción, diria que de escucha indispensable

    http://www.ivoox.com/verne-wells-ciencia-ficcion-rebelion-la_mf_20422478_feed_1.mp3
    http://www.ivoox.com/verne-wells-ciencia-ficcion-rebelion-la_mf_20541541_feed_1.mp3


## txt

**Programando con Racket 5**. Pues eso, que dejo aparcado un rato un tema y se me
borra del sistema neuronal... y para enterarme un rato de que iba el SICP pues,
tome este libro que estaba en españis hasta que el numero de caracteristicas del
lenguaje me abrumo.

Son aproximadamente 200 paginas, y llege hasta la 100, en este manual se resumen
las caracteristicas del lenguaje Racket, que tambien es aplicable para Scheme,
por decirlo de otra forma son notas selectas, o al final enseñan como hacer
guis con una libreria del lenguaje. No es que valla a programar nada en Scheme,
o algun lisp, aun asi sus enseñansas son aplicables a lenguajes que tiene
funciones lambda, aunque el truco de utilizar una u otra funcion en un `if` y
pasarle los argumentos al mismo tiempo, creo es un priviliegio solo de lisp y
sus descendientes
