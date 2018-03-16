+++
categories = ["prog"]
date = "2017-07-10T23:03:56-05:00"
tags = ["apt"]
title = "Webeloper – El navegador web"
+++

joder, que gracioso, ho, ho, ho, veamos si existe la remota posibiidad que nadie
utilize este (en mi mente) despectivo "titulo"...

... no ... bueno, que mas da, no se puede ser "innovador" todo el tiempo

hola, que tal, esta entrada trata de algunos de los navegadores web que he utilizado y
el por que, o esa es la idea

## Navegadores por terminal

Luego que comienza a agradarte la terminal, y con algo de nostalgia sintetica,
dices: "veamos eso del internet en la terminal, que igual va mejor que el
firefox en mi maquina agonizante con 500 megas de ram", y asi sin demasiado
esfuerso aqui esta la lista de navegadores de terminal que en algun momento
llege a utilizar (una a dos veces):

<code class="command" >w3m</code>, <code class="command" >lynx</code>, <code
class="command" >links</code> y <code class="command" >elinks</code> (en la
siguiente imagen aparecen de izquierda a derecha en ese orden)

![](/img/www.jpg)

tambien *eww*, que viene incluido en emacs

![](/img/www-eww.png)

si bien es el mas lento y apenas el menos feo (w3m gana la contienda), por el
simple hecho de venir en emacs no tiene comparacion en esta singular categoria,
ademas, en modo grafico pueden verse imagenes!

![](/img/www-eww-img.png)

es cierto que a los navegadores en modo texto el tiempo no los ha tratado bien,
pero las cookies, flash, drms, javascript y el contenido multimedia no son los
unicos culpables de su decadencia, pues en su mayor parte se debe al propio
lenguaje de la red **HTML**, o si! cuando cualquier hijo de vecino crea una
pagina amontonando etiqueta, sobre etiqueta sobre etiqueta, sin tener mucha
idea, hasta que optiene la representacion visual que desea, como esperan que
exista un programa que averigue las intenciones del "webeloper"? sigue siquiera
la mitad de la web una esquema estructural rigido para almacenar la informacion
y luego no se, hacer algo util con ella como optener solo el articulo principal?
o cualquier cosa imaginable pasa y luego a base de apaños en el otro gran mal
del mundo **CSS** se logra aparentar que las cosas estan bien hechas? digo, por
que si es necesario relegar todo a frameworks javascript para visualizar una
mierda pagina con *contenido estatico* que no tiene necedidad alguna de js, mas
que recolectar datos, poner anuncios y mostrar estadisticas, es mejor que la
humanidad se extinga...

haaaaaaa!! cuan odioso es css, por que tiene tantos parametros para hacer la
misma cosa, da la impresion que de ser un juego de azar... intentas una
propiedad y no funciona, pruebas con otra y se rompe, vas por la tercer opcion
y... no funciona, prebas con la ultima etiqueta recien salida del "estandar"
y... por fin (hay una etiqueta no ambigua para hacer cosas tan simples como
centrar el contenido de cualquier elemento? que el margen sea un margen y el
padding un padding y los porcentaje y em's no se saboteen entre si?)

cuenta asta dies, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0... je, era alreves pero no
importa

de entre los navegadores de texto ignorando a eww por su implicacion
con emacs, los mas potables son *links* y su sombra *elinks* que no solo
colorean las cosas, tambien tienen la decencia de dejar una agradable
indentacion a la izquierda y menus graficos.

## Navegadores Graficos

Y luego pasas de tu viejo pentium 4 a un flamante celeron con 8GB de ram y el
firefox sigue siendo lento, pero ahora consume mas ram que todo el sistema y sus
aplicaciones en conjunto... y las paginas se niegan a visualizarse si no vas
dispuesto a aceptar cualquier mierda inecesaria: fuentes de google, analiticas
con js, imagenes y videos que provienen de un sitio que necesita js, cookies,
los mensajes de las cookies, acortaderes de enlaces y publicidad

Reflexionas un poco y te dices no, no quiero toda esa basura, ni que mi
navegador delate todo lo que hago, utilizas firefox, (o el exitinto iceweacel o
icecat de GNU (este sin exteciones)) lo vitaminas con noScript, Privacy Bagner
uBlock Origin y cualquier otra extecion de software libre (porque no confias en
nada si no te dan el codigo), y ves lo que puedes y en casos extremos como ver
videos te comes uno que otro js

asi pues, solo con firefox complementado con feeds (que no necesitan porquerias
extras para darte lo unico que te interesa) y eww sobrevives lo mas fiel a tus
creencias... hasta que necesitas abrir un fichero html gordo, por ejemplo un libro
completo en un solo html que tarda casi un minuto en cargar, al que por mera
casualidad tienes la necesidad de modificarle el css y entre recarga y recarga
se pasan preciosos momentos

asi pues, que mas hay por hay fuera? en que otro navegador podria confiar?

chrome? no,

chromium? casi es lo mismo que chrome

un [espin](https://en.wikipedia.org/wiki/Chromium_(web_browser)#Other_browsers_based_on_Chromium) de chromium sin mierda? bueno podria ser
veamos, mmm, derivados exclusivos para las manzanas, derivados exclusivos para
las ventasas, forks con codigo cerrado... hey! aqui hay uno que parece prometodor
[*brave*](https://www.brave.com/)

![](/img/brave.png)

dicen que son "open source", mucho de seguridad, comunidad y pagos(?), veamos
tienen una compilacion para freidora... parece decente, algo modernoso

han borrado todo contacto con google y su google play, morbosamente su unica
extencion disponible es activar el flash? que dudoso, mucho de seguridad y
opciones por desactivar

no se, da un aire de *producto* para un nicho concreto, quiza no busco un
producto, segun esta desarrollado por ex-firefoxes, pero no me termina de
convencer, ademas no puede cambiarse de color la barra de direcciones y es
molesta, por otra parte, a diferencia de firefox carga un html gordo sin demora
*siempre y cuando* no le metas js (*mathjax*) o el rendimento cae en picada

haber aca hay otro derivado [*iridium*](https://iridiumbrowser.de/downloads/linux.html).
Este no parece un producto, y la gente que lo lleva a flote dice que tienen
lanzamientos cada que pueden por que no tienen gente/recursos suficientes
(hooooooo esto si es un desarrollo de software libre –digo para mis interiores),
ademas tiene repositorios para debian (y derivados), open suse y freidora


    dnf config-manager --add-repo https://dl.iridiumbrowser.de/fedora_25/iridium-browser.repo
    dnf install iridium-browser

la instalacion corrio sin ninguna complicacion, al igual que brave tambien carga
hachetemeeles gordos sin despeinarse

como inconvenientes diria que tiene la opcion de iniciar secion con gogle y la
dudosa capacidad de instalar extenciones de google play, aunque tambien se
pueden instalar cosas directo del codigo fuente

le instale ScriptSafe en modo paranoico, ni js, ni funtes externas,
botones sociales, ni analitics, tambien desactivadas cookies de todo sitio pues
en este navegador no voy a logear con nada (para eso mantrendre firefox), ademas
por cualquier duda tambien privacy bagner, uBlock Origin, un tema obscuro y una
extencion curiosa (GPL3) para sobreescribir los atributos css de las paginas [*Stylus*](https://github.com/openstyles/stylus)
(disponible tambien en firefox) que tiene cosas un poco turbias con js pero
parece ser confiable

y asi llego al final de este capitulo slice of life sin sentido donde con tres
navegadors y unas 8 pestañas abiertas consegui el dudoso logro de llegar a los
5GB de ram en uso

ps: tambien esta midori, pero tienes un navegador igual de lento, poco
configurable, que no esta a la ultima moda en csssssss
