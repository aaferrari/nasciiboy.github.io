+++
title      = "LineageOS, Feeds & Feel"
tags       = [ "howto" ]
categories = [ "prog" ]
date       = 2018-04-13T14:26:21-05:00
+++

Luego del primer [flasheo al m8](../m8) probe un poco las "apps" de yutu que
venian disponibles en f-droid y aquella vez no llegue muy lejos antes de
instalar las gapps... por el yutu y alguna cosa de la playstore, como ivoox,
firefox o vlc.

Tras aquello, el dispositivo paso de ser un lineage a un androide googlero
practicamente en todo sentido: las apps comenzaron a fastidiar con registros y
actualizaciones (yutu), el playstore comienzo a hacer sus reviciones de
seguridad, y nuevos procesos permanentes en segundo plano aparecieron haciendo
quien sabe que cosas `¯\_(ツ)_/¯`.

tener yutu es caro, quiza demaciado y android, android es una
mierda. Cierto es que no ocupo mucho el dispositivo, por dos razones, primero, la
pantalla tiene un touch perjudicado y segundo, es android y eso no vale para nada,
nada que no sea consumir pasivamente y ver porno.

y asi hubiera seguido con el movil hasta el fin de los tiempos, hasta que una
"broma" de parte del equipo de lineageOS hizo aparecer un mensaje perturbador

![](/img/coin.png)

que? (me pregunte) la pagina del porno no se conforma con minar criptocurrencias
cuando veo un video, ahora a colado un bicho en el sistema? (ha, ha, ha, que
cachondos los de lineage)

esto ademas de traer la sensacion de completa vulnerabilidad, vino acompañado
por un cabreo que desemboco en (cual winbugs) borrar y reinstalar, ahora por
supuesto sin google de por medio, almenos, hasta donde se pudiera

segui el antes enlazado listado de pasos para el flasheo, y volvio a aparecer el
mensaje de los graciosos del lineaje, je, fue hay donde me entere de lo que se
trataba ![x-d]!

Despues toco ir a [f-droid](https://f-droid.org/) descargar el apk y transferirla
al dispositivo desde el pc (por comodidad). Lo mismo sucedio con vlc, al que hay
que rebuscar por [aca](https://www.videolan.org/vlc/download-android.html).
Finalmente intente con firefox, mas el enlace de su apk no lo encontre.

Probando con f-droid esta ice-cat, pero al igual que la ultima ocacion que la
probe, se queda como que en eterna carga al pasar del buscador a una pagina, asi
que se fue y se quedo el navegador por defecto.

Luego toco buscar algun reemplazo para el yutu. Los primeros en caer fueron
NewPipe que es usable, y MinTube que tras varios intentos el resultado siempre
fue un crasheo.

je, el repo de f-droid tiene muchas cosas sin actualizarse, algunas de las que
encontre +6 años, otras que parecen abandonadas o a medio hacer. Quitando
algunas cosillas, es un panorama bastante triste, aun asi, que asco da programar
para androides, de verdad que poco o ningun interes me despierta, ja, ja, ja,
quiza cambie de opinion cuando los moviles no sean meros juguetes y corran GNU
con papeles y letras grandes, con Gnome por supuesto, aunque tambien seria
suficiente ejecutando kde o en ultima instancia una terminal pelada y confiable
sin modo grafico alguno, iendo de un lugar a otro con un teclado mecanico
bajo el sobaco o colgado en la espalda

Mientras tanto, es un grato placer compartir un par de reemplazos potables para
substituir los principales usos del aparato (obviando vlc para los videos,
Música para la musica y el navegador pal porno)

## SkyTube

[SkyTube](http://skytube-app.com/) es un leector de rss especializado en los
feeds de youtube. No se crashea, tiene una interface agradable, util, puedes ver
comentarios, el canal de donde procede un video, subcribirte y hacer busquedas

Se pierde aquello de dar likes, pero no creo que eso sea ningun defecto, igual y
es un paso necesario en el desadoctrinamiento del like. Lo mismo sucede con los
comentarios, podemos verlos mas no dejarlos.

Agregar nuestros feeds, lejos de lo que se podria imaginar es una tarea
sencillisima. Por alguna razon que no logro entender, el mismo yutu nos ofrece
una lista con todas las subcripciones que tenemos en formato opml (xml) para que la
podamos agregar a un leector... enserio? por que? un inflitrado que evita a los
hippiosos caer por completo en las garras de alphabet? puaghh

solo debemos ir a https://www.youtube.com/subscription_manager, seguir hasta el fondo de
la pagina y darle a **Exportar Subcripciones**

para mi cuenta se genero el siguiente fichero [subscription_manager.xml](/media/data/subscription_manager.xml)
(le he cambiado la extencion, agregando `.xml` al final).

A continuacion un desglose. La clasificacion es dificil de encajar para varios
canales, por ejemplo **petercarter**, **Pilingino** o **el gordo otaku**
(incluso **DayoScript**) que clasificaria directamente como "montaje visual",
pero por centrar sus contenidos en un area mas que en otra termino por
colocarlos en algo menos exotico, como en *dispersion cultural* o *anime*.

Dedico la categoria Dispersion cultural a aquellos canales sin una tematica
particularmente enfocada a una rama de la dispersion, o que son dificiles de
clasificar, como en el caso de Adult Swim, que incluye videos musicales,
animacion experimental, pachequismos, spin-offs y visarradas varias. En la misma
categoria coloco tambien a Esquizofrenia Natural donde hablan de filosofia(s), se
realizan analisis socioculturales y de vez en cuando un minidocumental.

Describir textualmente cada uno de los canales seria extenuante. Como unica seña
de atencion aquellos titulos en Bold son los que recomiendo consumir sin ninguna
reserva, y otros de nombre poco descriptivo, traen un guion y su tematica a un
lado.

Bueno, sin mas distracciones **"la lista"**

### dispersion cultural

- [Adult Swim](https://www.youtube.com/channel/UCgPClNr5VSYC3syrDUIlzLw)
- [Comunidad Espiral](https://www.youtube.com/channel/UCq8G6Hp2GKAzXCUqeED8T5g)
- [Cordura Artificial](https://www.youtube.com/channel/UCb8GKeOvI7WsFUkB4UVAeXA)
- [DayoScript](https://www.youtube.com/channel/UCVBkwO6Ok1De0UfNZdo7-Ag)
- [Drugslab](https://www.youtube.com/channel/UCvRQKXtIGcK1yEnQ4Te8hWQ)
- [**Esquizofrenia Natural**](https://www.youtube.com/channel/UCf_MY8uWjWH8gwzFK6vCAmg)
- [**Mireda Producciones**](https://www.youtube.com/channel/UCiMTyGpwgqp_dmNWv-y0tfQ)
- [**petercarter**](https://www.youtube.com/channel/UCXP63FzhPbL41mPx2P2g7Cw)
- [PIPEXMAN](https://www.youtube.com/channel/UCTBQ_wav5XVjd7hZMwE87jQ)
- [**Quetzal**](https://www.youtube.com/channel/UCoyJ3DSiNZhuJgg0qNZC4yg)
- [SOY ATEO Y QUÉ](https://www.youtube.com/channel/UCRJdUHPy8evgqT5CVl-mxyQ)
- [Talking Vidya](https://www.youtube.com/channel/UC3-87zhQFd6poByHjBVyJwA)
- [TL2Bie – kaijus y mostruos](https://www.youtube.com/channel/UCSN5hYxFPJme8FHEjx5cCyA)

### musica

- [**KEXP**](https://www.youtube.com/channel/UC3I2GFN_F8WudD_2jUZbojA)
- [**Manual Guitarra Eléctrica**](https://www.youtube.com/channel/UCeEMAgqm5qFzFJ-BuKOpgew)
- [moonbowmusicmovie](https://www.youtube.com/channel/UCvpGdJBiZ52seEhUldZGwvA)
- [Rockandplay Daniel](https://www.youtube.com/channel/UCcgmiH5T9xkemVExTNwJ58Q)
- [Stephanie Jones](https://www.youtube.com/channel/UCbidH1GEKpLWmjjzdUEJHqQ)
- [will guitar shop cali](https://www.youtube.com/channel/UCVScA3WHef_-0eCAgBPbpRA)

### vg

- [Artemio Urbina](https://www.youtube.com/channel/UCEh5UPBv0alseI62OJhnKow)
- [Game Back](https://www.youtube.com/channel/UC2S36yOxggUtJJXUGrBygKg)
- [**JackTech – gameboy**](https://www.youtube.com/channel/UC008MpfclY6ap-QGzoTMNKg)
- [Leyendas & Videojuegos](https://www.youtube.com/channel/UCMnZ3qm76jc3SUi9Z-5OdcA)
- [My Life in Gaming](https://www.youtube.com/channel/UCpvtp7mH0Cdq8FQUxcjDq0Q)
- [Retro Game Mechanics Explained](https://www.youtube.com/channel/UCwRqWnW5ZkVaP_lZF7caZ-g)
- [Scanliner](https://www.youtube.com/channel/UCWz51s7gd-p55UXY_xm69FQ)
- [The 8-Bit Guy](https://www.youtube.com/channel/UC8uT9cgJorJPWu7ITLGo9Ww)
- [VGMAZ](https://www.youtube.com/channel/UCsr88iMWjPrD4Qb0o378gJQ)

### animacion

- [**ANIMACIÓN ARTESANAL**](https://www.youtube.com/channel/UCDowdnFPgoQ2fkDm5owjuAA)
- [Axolotl de la Animacion](https://www.youtube.com/channel/UCV1pDNNo5IdJimT-41m0Mfw)
- [Cinestesia Anime](https://www.youtube.com/channel/UCAf6gSVlDsn1MLF7v6d2ObQ)
- [DementJG](https://www.youtube.com/channel/UC5dGiPeNiyaiWi9vLwTRPEw)
- [D.o.c.](https://www.youtube.com/channel/UCfrv5jKw0uB-U6E0SiqAHAg)
- [**Don't Hug Me .I'm Scared**](https://www.youtube.com/channel/UCZOnoLKzoBItcEk5OsES2TA)
- [**El Gordo Otaku**](https://www.youtube.com/channel/UCcwuEaYuxaCRrBMRPlBWe0A)
- [El Rulz](https://www.youtube.com/channel/UCJKIA81F-M6CL5hzs35Nk7Q)
- [Entre Libros Y Waifus](https://www.youtube.com/channel/UCglFJNHHyXws4EXebrYHb2Q)
- [Eselpedré](https://www.youtube.com/channel/UCiANIRWeIIw1Je5EsJkR8eQ)
- [Jodyhar](https://www.youtube.com/channel/UCECTpjxj_stfEtlJ2RWTfow)
- [Kalcifer Vallarta](https://www.youtube.com/channel/UC6rXfIPNdLthA4fO-3rBNGw)
- [LaOveja Extra](https://www.youtube.com/channel/UC3MwWFJks6MFI5BF4CHSfWA)
- [La Oveja](https://www.youtube.com/channel/UCvxh70bpc4DgUX8qAmxCFjA)
- [MemoReviews](https://www.youtube.com/channel/UC5AgQIntQhWwVmCYrktnZAQ)
- [Minutos Para Otakus](https://www.youtube.com/channel/UCZHlhifZJzY5H-aeeZGPwVA)
- [**Pilingino**](https://www.youtube.com/channel/UC6PcGXqquqBQql4vAVnfrLA)
- [Qki Jose](https://www.youtube.com/channel/UC8C99zBE9T9Nxq1S58VJUbA)
- [ReseñasSinCafeína](https://www.youtube.com/channel/UCeglxdFllZYMhUkneB-ICgg)
- [Rokudo JE](https://www.youtube.com/channel/UC_s1fc6OJewmoZA3xEvz02g)
- [**Soge YT**](https://www.youtube.com/channel/UCVwXSnbknU8Jpqij4UcFR0w)
- [**Tenes Milanesas Graciela**](https://www.youtube.com/channel/UC9ThvriaM_zXVxRzadVKq1Q)
- [Trim Prism](https://www.youtube.com/channel/UCu04BQKewqmSTgxw3-L3ptw)
- [**Yururin**](https://www.youtube.com/channel/UCfqbkBHXZTbotSh_BBMHrgw)
- [Zander KB](https://www.youtube.com/channel/UCEBxn0h5J2nNwJdwMcj8z1w)

### humor

- [**Como Deberia Haber Terminado**](https://www.youtube.com/channel/UCgyhGX2FNKqDJwU0-Nw4wUg)
- [Cosos de Dichi](https://www.youtube.com/channel/UCvbJ1wi_rrDpEkR2lIVIPUw)
- [Dichi Delizioso](https://www.youtube.com/channel/UCPUu6wV3B2Bxd1RA3mzdAmw)
- [**Erizos Oficial** – el Dr. Pangolin y su ejercito de animalitosbebe](https://www.youtube.com/channel/UCvXlZUC_OKinSCmJiXrPDGQ) (ver el video de los mapaches)
- [Eddie FD](https://www.youtube.com/channel/UCRVs5xUK5sW1v2j4Dd5XU-A)
- [Eddie Fox](https://www.youtube.com/channel/UCa-edCymk0G91lZ3G5zh9Qw)
- [Eder](https://www.youtube.com/channel/UC_EB3uk-Pkp1tRSKGXANPng)
- [**ElSmosh** – honest trailers (español)](https://www.youtube.com/channel/UCgESfl93BM2y85abdt8BcZw)
- [Gin Dondake Fandubs](https://www.youtube.com/channel/UC66hb8VcpF4X6blJekn0-Nw)
- [**Te lo resumo**](https://www.youtube.com/channel/UCw7Bz6EHxlnOoBUBlJZCWCw)

### GNU, ciencia y cacharreo

- [Medialab-Prado](https://www.youtube.com/channel/UCkHEa9kk6QvKUR3MXM2Ob6Q)
- [ladecadence](https://www.youtube.com/channel/UCQ0p7ObPat3ptpv1-6K0kHA)
- [mirmoz7 – arduino](https://www.youtube.com/channel/UCu_Z5p91wZGETcCZ1_t8gww)
- [**Motores Patelo**](https://www.youtube.com/channel/UC8hgTHwt2gZSe2QNkWK4bqw)
- [RincónIngenieril](https://www.youtube.com/channel/UC6I9GGVWsnkHdbFEYDvFo8w)
- [Viajando por Planetas](https://www.youtube.com/channel/UCn1ZIiP-Zcm6kmUA_gkULBA)
- [MindMachineTV](https://www.youtube.com/channel/UCxOQ-HjJws0Nrh7v-05cxCw)
- [El ingeniero TOPs](https://www.youtube.com/channel/UCaqFBDA_pSsRvKjy-jiYcNg)
- [DesarrolloWeb.com](https://www.youtube.com/channel/UCQZyH9sRRjvtZhMw-ldRvXQ)
- [El Robot de Platón](https://www.youtube.com/channel/UCaVPhFg-Ax873wvhbNitsrQ)
- [KDE España](https://www.youtube.com/channel/UCbxMnO9P8uxetvy2sngjLwg)
- [Computerphile](https://www.youtube.com/channel/UC9-y-6csu5WGm29I7JiwpnA)
- [Pon un ingeniero en tu vida](https://www.youtube.com/channel/UCSF6lzFPhRm84E7e7gX19gw)
- [Mike Zamansky–using Emacs](https://www.youtube.com/channel/UCxkMDXQ5qzYOgXPRnOBrp1w)
- [Hardware 360º](https://www.youtube.com/channel/UC40Ztmc_11leuUR-tHh_irQ)
- [Graf Log - videos viejos de mates](https://www.youtube.com/channel/UCFVQmYJ5ToD5yN1kog8xBRw)
- [emacsrocks](https://www.youtube.com/channel/UCkRmQ_G_NbdbCQMpALg6UPg)
- [Escuela Superior de Informática UCLM](https://www.youtube.com/channel/UCUG9f0C5_pLvobfH-IEupBw)
- [UMA MOOC](https://www.youtube.com/channel/UCYCpka3pIEGYjjcrssW10FQ)
- [Yu-Jie Lin – capturas de terminal](https://www.youtube.com/channel/UCYgk0h0P55kxFgNLF6E-uKA)
- [LinuxCabal](https://www.youtube.com/channel/UCZbjyqToF-4qmGNwYrhqQtQ)

## ANTENNAPOD

fuuuuhhhhh, para substituir ivoox la situacion no es tan sencilla. Antes de intentar
conseguir la lista de feeds habia probado en el equipo con gpodder tanto en el
movil como en la PC, sin embargo, carecer de un reproductor, en especial uno que
guarde la posicion de escucha de los pod lo descarta inmediatamente.

Luego en la maquina prove con vocal (que venia en los repos de freidora)... y no
era ni fino, ni comodo de utilizar.

El tercer intento, totalmente inesperado (aque creo que jessica del podcast
birras y bits lo menciono en alguna ocacion) tiene todo lo necesario y mas! Con
una calidad inmerecida, casi fuera de lugar comparando con la mayoria de
proyectos libres (y privativos), o dicho de otro modo, deja a la altura del betun
la cosa lamentable que entrega ivoox. La app en cuestion se llama
[ANTENNAPOD](http://antennapod.org/)

Ahora, vamos al asunto principal: conseguir la lista de feeds que ivoox
enmascara mesquinamente con sus enlaces opacos... por que lo hace (?), mas si
(hasta donde tengo entendido) ni siquiera es que almacene los capitulos en sus
servidores.

En fin, el procedimiento es

- ir a ivoox en el navegador
- loguearse
- click en **Mis Subscripciones**
- click en **Compartir**
- luego de marcar todos los podcast como publicos, enviarnoslo por correo
- abrir el correo y seguir el enlace al navegador
- gurdar la pagina del navegador (C-s) con nombre `subs.html` para abreviar
- abrir en un editor la pagina html o utilizar las herramientas de manipulacion
  de texto de los sistemas *nix

resulta que la pagina con las subscripciones compartida tiene en cada elemento
`<meta itemprop=\"url\" content=\"http://www.ivoox.com/.*"` la direccion html al
canal de cada podcast al que estamos subcritos, y con un poco de trabajo,
podemos convertir esa direccion html al feed rss

para esto substituiremos en el enlace, la seccion de texto `.html` por `.xml` y
tambien la seccion `_sq_` (en algun caso puede ser `_aj_`) por `_fg_`. Por ejemplo

    http://www.ivoox.com/podcast-cierta-ciencia_sq_f171785_1.html

quedaria como:

    http://www.ivoox.com/podcast-cierta-ciencia_fg_f171785_1.xml

el inconveniente aqui seria conservar a ivoox como  intermediario entre nuestro
podcast y el feed, pero creo es un mal (de momento) aceptable

para ayudar en la transformacion del fichero en nuestros enlaces, tengo el
siguiente conjunto de pasos en elisp, ir al fichero `subs.html`

```
(defun ivoox-killer ()
  "Separa los correos en lista_correos.txt"
  (interactive)
  (goto-char (point-min))
  (while (re-search-forward "</\\w+>" nil t)
    (replace-match "\n" nil nil))
  (goto-char (point-min))
  (delete-non-matching-lines "<meta itemprop=\"url\" content=\"http://www.ivoox.com/")
  (goto-char (point-min))
  (while (re-search-forward " +<meta itemprop=\"url\" content=\"" nil t)
    (replace-match "" nil nil))
  (goto-char (point-min))
  (while (re-search-forward "\">" nil t)
    (replace-match "" nil nil))
  (goto-char (point-min))
  (while (re-search-forward "\\.html" nil t)
    (replace-match ".xml" nil nil))
  (goto-char (point-min))
  (while (re-search-forward "_.._" nil t)
    (replace-match "_fg_" nil nil)))
```

cargar la funcion elisp y ejecutar `M-x ivoox-killer`

o desde la terminal ejecutar

    grep -Eo '<meta itemprop=\"url\" content=\"http://www.ivoox.com/[^"]+"' subs.html | sed 's/_.._/_fg_/g' | sed 's/\.html/.xml/g' | awk -vFS=\" '{ print $4 }'

me gustaria decir que eso seria todo, pero no, unicamente conseguiremos los
feeds en texto plano. Luego hay que convertirlos a un formato xml especial y
darle la extencion `.opml`, esta tarea es un ejercicio para el lector. Se puede
tomar como referencia este (mi) listado [antennapod-feeds.opml](/media/data/antennapod-feeds.opml)
(ya pasado por antennapod, y cambiando los feeds ivoox por las direcciones fuente
cuando fue posible)

Como con yutu, aqui el desglose de los feeds

### dispersion cultural (o charlas)

- [Antimateria](http://feeds.feedburner.com/antimateriapodcast)
- [El Podcast de Logan](http://www.ivoox.com/podcast-podcast-logan_fg_f1179598_1.xml)
- [**El precipicio**](http://www.poderato.com/precipicio1/_feed/1)
- [LODE -archivos ligeros-](http://www.ivoox.com/podcast-lode-archivos-ligeros_fg_f159048_1.xml)
- [**Loquemeimagino Podcast**](http://www.ivoox.com/podcast-loquemeimagino-podcast_fg_f144451_1.xml)
- [One Piece Podcast](http://www.ivoox.com/podcast-one-piece-podcast_fg_f1160246_1.xml)
- [**Podcast El Precipicio**](http://www.ivoox.com/podcast-podcast-el-precipicio_fg_f176717_1.xml)
- [**Podcast El Vuelo del Fénix**](http://www.ivoox.com/podcast-podcast-el-vuelo-del-fenix_fg_f146467_1.xml)
- [Podcast interYnet](http://www.ivoox.com/podcast-interynet_fg_f133744_filtro_1.xml)
- [**Podcast La Biblioteca de Trantor**](http://www.ivoox.com/podcast-podcast-la-biblioteca-trantor_fg_f13178_1.xml)
- [Podcast La Espada de Damocles](http://www.ivoox.com/podcast-podcast-la-espada-damocles_fg_f170523_1.xml)
- [Radio ELA: Emisora Libre Autogestionada. 100.0 FM Madrid](http://radioela.org/spip.php?page=backend)
- [**Tú no has tenido infancia**](http://feeds.feedburner.com/TuNoHasTenidoInfancia)
- [**Vivo entre Muggles**](http://www.ivoox.com/podcast-vivo-entre-muggles_fg_f1157962_1.xml)

### musica

- [**Del Bit a la Orquesta**](http://www.spreaker.com/show/511735/episodes/feed)
- [**ScoreVG**](http://www.ivoox.com/podcast-scorevg_fg_f1153825_1.xml)
- [6x3](http://api.rtve.es/api/programas/58211/audios.rss)
- [**La Ruleta Rusa**](http://www.ivoox.com/ruleta-rusa_fg_f1156570_filtro_1.xml)

### vg

- [**Arcadia Gamers**](http://www.arcadiagamers.com/rss.xml)
- [El Club Vintage](http://www.ivoox.com/podcast-club-vintage-videojuegos-clasicos-80-s_fg_f18511_1.xml)
- [**Game Over**](http://www.ivoox.com/podcast-game-over_fg_f1366_1.xml)
- [Podcast Hyrule Project](http://www.ivoox.com/podcast-podcast-hyrule-project_fg_f172144_1.xml)
- [**RetroActivo Podcast**](http://www.ivoox.com/podcast-retroactivo-podcast_fg_f110956_1.xml) (los primeros son los mejores)

### txt y radio-novelas

- [El gran apagón](http://www.ivoox.com/podcast-gran-apagon_fg_f1293671_1.xml)
- [La biblioteca invisible](http://www.ivoox.com/podcast-biblioteca-invisible_fg_f1170900_1.xml)
- [**Podcast de Verne y Wells Ciencia Ficción**](http://www.ivoox.com/podcast-podcast-verne-wells-ciencia-ficcion_fg_f1100419_1.xml)

### cine

- [**El Octavo Pasajero**](http://www.ivoox.com/podcast-octavo-pasajero_fg_f14315_1.xml)
- [**Desde Abajo Podcast: Cine de Terror, Sci-fi y más**](http://www.ivoox.com/podcast-desde-abajo-podcast-cine-terror-sci-fi-y_fg_f153707_1.xml)

### GNU y afines

- [**Autodefensa Informatica**](https://autodefensainformatica.radioalmaina.org/feed/)
- [Birras y Bits](https://birrasybits.wordpress.com/feed/)
- [Código Podcast](http://www.ivoox.com/podcast-codigo-podcast_fg_f192247_1.xml)
- [Command Line Heroes](https://feeds.pacific-content.com/commandlineheroes)
- [Compilando Podcast](https://compilando.audio/index.php/feed/podcast/)
- [cuevatux](http://feeds.feedburner.com/Cuevatux?format=xml)
- [Devuanita](http://www.ivoox.com/podcast-devuanita_fg_f1231954_1.xml)
- [El Desarmador](https://eldesarmador.org/podcast.xml)
- [**El Geek Errante**](http://elgeekerrante.com/podcastfiles/geekerrante_podcast.xml)
- [Fran Casas](https://www.ivoox.com/podcast-fran-casas_fg_f1449982_1.xml)
- [Las Crónicas del Linuxverso](http://www.ivoox.com/podcast-cronicas-del-linuxverso_fg_f1444265_1.xml)
- [**Libresfera**](http://www.ivoox.com/podcast-libresfera_fg_f136150_1.xml)
- [**Pánico en el núcleo**](http://www.ivoox.com/podcast-panico-nucleo_fg_f17378_1.xml)
- [Podcast de KDE España](http://www.ivoox.com/podcast-podcast-kde-espana_fg_f1249423_1.xml)
- [**Podcast Linux**](https://feedpress.me/podcastlinux)
- [Radioliberada el podcast](https://radioliberadaelpodcast.wordpress.com/feed/)
- [**Reality Cracking**](http://www.ivoox.com/podcast-reality-cracking_fg_f159955_1.xml)
- [Tuxllefia](http://www.ivoox.com/podcast-podcast-tuxllefia_fg_f1309696_1.xml)
- [We Developers](http://www.ivoox.com/podcast-we-developers_fg_f146574_1.xml)

### humor

- [**Gravina82**](http://feeds.feedburner.com/Gravina82?format=xml)
- [**kombustible podcast**](http://www.ivoox.com/podcast-kombustible-podcast_fg_f142184_1.xml)
- [**La Calabazota Blog**](https://lacalabazota.wordpress.com/feed/)

### ciencia

- [Ciencia nuestra de cada dia](http://www.ivoox.com/podcast-ciencia-nuestra-cada-dia_fg_f11450_1.xml)
- [Ciencia y Genios](http://www.ivoox.com/podcast-ciencia-genios_fg_f11449_1.xml)
- [Cierta Ciencia](http://www.ivoox.com/podcast-cierta-ciencia_fg_f171785_1.xml)
- [El neutrino](http://www.ivoox.com/podcast-neutrino_fg_f132713_1.xml)
- [El Radioscopio](http://www.ivoox.com/podcast-radioscopio_fg_f128060_1.xml)
- [Hablando con Científicos](http://www.ivoox.com/podcast-hablando-cientificos_fg_f11448_1.xml)
- [La Fábrica de la Ciencia  (LFDLC)](http://www.ivoox.com/podcast-fabrica-ciencia-lfdlc_fg_f1100722_1.xml)
- [Podcast Catástrofe Ultravioleta](http://www.ivoox.com/podcast-podcast-catastrofe-ultravioleta_fg_f1107209_1.xml)
- [**Podcast Desde el Sur: explorando el Cosmos**](http://www.ivoox.com/podcast-podcast-desde-sur-explorando-cosmos_fg_f15085_1.xml)
- [Principio de Incertidumbre](http://www.ivoox.com/podcast-principio-incertidumbre_fg_f114134_1.xml)
- [Quilo de Ciencia](http://www.ivoox.com/podcast-quilo-ciencia_fg_f17805_1.xml)

## EOF

al igual que varios albums, muchos podcast han acompañado mis pasos, la mayoria
de los aqui listados han sido escuchados por completo casi como un proyecto
personal incluso algunos de cantidad colosal como arcadia gamers y game over, o
varios de los que produce ciencia-es (que no los marco como recomendables, pero
todos tienen una gran calidad).

Unos vienen, otros se van o van siendo olvidados en el trancurso de cambiar de
cuenta y nicks. Algunos mas han desaparecido y unos pocos los atesoro en el
disco duro, cada cual aportando nuevas sensaciones, visiones e ideas en un
momento especifico.

Antes o despues, varias visiones que al inicio parecian desafiantes ahora se han
vuelto añejas o simplonas, quiza mostrando lo rapido que evoluciono... o
exponiendo lo facil que es influenciar a este maleable sujeto.

Solo por hacer mencion de algunos de los ausentes, aniGame Radio (de lo primero
que escuche), "capa, guitarra y game-over" (creo el primero), el podcast de
tuxinfo, los documentales de la pastilla-roja, las japonesadas de UPML o uno que
ya no recuerdo el nombre donde unos estudiantes de filosofia de por mi varrio
hablaban de novelas de ciencia ficcion.

Gracias a esos "hacedores" que comparten directamente y sin recelo (casi
siempre) sus obseciones mas profundas, sea con un micro de mierda o desde
equipos profecionales, por uno, dos o cien programas
