+++
categories = ["emacs"]
date = "2017-07-02T12:26:47-05:00"
draft = true
tags = [""]
title = "Por que GNU Emacs?"

+++

> Si el tiempo antes de precindir de interfaces para interactuar con los
> computadores se extiende lo suficiente, Emacs, terminara por ser un sistema
> operativo autosuficiente

coloca una pista de sonido, relajate y disfruta de este post al estilo *"lo que
otros IDEs no quieren que sepas"*, *"la increible historia de emacs, no podras
creer el final"*, *"Emacs el editor que no esperabas"*, ...

〜(￣△￣〜) he, pero es que yo utilizo (vim|VS|atom|eclipse|nano|...) y no necesito
un editor viejuno y raro!

(∿°○°)∿ tu-ru-ru-ru-ru-ru ohhh yeah! estoy mas cerca de un usuario basico, que
uno intermedio de Emacs, no tengo duda alguna que lo que sea que hagas con tu
editor actual lo podrias hacer con Emacs, que sea de forma sencilla, ya es otra
cosa, mientras tanto, piensa en el como un estupendo complemento/substituto para
varias herramientas, o un proyecto a largo o mediano plazo que estoy
absolutamene seguro disfrutaras

la forma mas simple para explicar por que emacs, seria **terminal vs
aplicaciones graficas**, para el segundo tienes un monton de interfaces
distintas no diseñadas para colaborar entre si, para el primero solo hace falta
un poco de aprendizaje antes de comenzar a concatenar acciones, que de otra forma
serian extenuantes

Emacs, es un interprete, que hace muchas cosas, pero todas ellas con una
"interfaz" comun, es decir, si sabes como moverte en un fichero de texto, sabes
como moverte en alguna de sus varias "aplicaciones", pues sus programadores
tratan de lograr una coherencia global en cuanto al significados de los comandos
que pueden aplicarse, y en caso de duda siempre tienes la documentacion a mano

｢(ﾟﾍﾟ) bueno, entoces ocupas emacs para hacer de todo?

＼_(￣、￣ 彡 ￣ー￣)_／ －☆・　・　・　‥……━━●

no, pero no hay dia que encienda el pc sin abrir varias instancias de emacs, diria que
paso el 80% del tiempo en emacs, con varias terminales

de ves en cuando aprendo un nuevo truco, mas, en Emacs, la distancia entre mis
habilidades y el dominio total, es tan grande como lo es el mar

(｡´>д<)っ彡 entoces que haces?

leer libros, maquetar libros, organizar/elimimar/navegar ficheros, programar, de
ves en cuando navegar por la red, ver irc, revisar feeds, algo de git y poco mas.

me gustaria leer tambien el correo, pero no he encontrado un tutorial para vagos

que? cual es el punto de hacer eso con emacs?

(｡´>д<)っ彡

1. como mayor virtud, esta la interfas uniforme, no importa la rareza del
   lenguaje de programacion, si es un visor rss, o un navegador de archivos, los
   comandos principiales cumplen el mismo proposito, es decir no tengo que
   recordar comportamientos independientes para cada situacion, ni navegar por
   raros menus o botones graficos misteriosos

2. la capacidad de configurar cualquier aspecto para que se adapte a mis
   necesidades y gustos no tiene comparacion, tanto si quiero o no menus,
   numeracion, tal o cual tipografia y color, puede configurarse de forma
   independiente o global segun nuestra necesidad

3. dired, un practico navegador de ficheros, con el que puedes hacer lo mismo
   que con un navegador grafico, solo que incorporado, sin tener que transitar a
   una aplicacion externa, con los beneficios que esto conlleva

4. bookmarks, tanto para una ruta especifica del sistema, como para una posicion
   dentro de un fichero de texto. Evitar escribir y recordar rutas, es muy
   liberador y comodo

5. anillo de la muerte, es como un portapapeles donde todo el texto que cortes o
   indicas expresamente se guarda de forma "circular", por supuesto, su
   comportamiento y presentacion pueden adaptarse para ser mas agradable (para mi
   ya es agradable)

6. anillo de marcas, esto es un registro de la posicion donde se realizan
   ciertas acciones, lo que te permite ir de un sitio a otro del
   dcumento/lo-que-sea y regresar a la posicion de partida sin buscar a lo bruto

7. registros, es algo a medio camino entre el anillo de la muerte y el de
   marcas, la diferencia esta en que "guardas" especificamente el
   contenido/posicion en un "registro"

8. busqueda, substitucion, busqueda-regexp y substitucion regexp. Lo primero es
   practico, lo segundo extremadamente poderoso, aunque al igual que la mayoria
   de motores de expresiones regulares la escritura es algo tortuosa

9. buffers, windos, frames. Esto es una terminologia propia de Emacs, lo primero
   es lo que se muestra en los "tabs" (windows), lo segundo los "tabs", los cuales
   pueden habitar varios en la misma "ventana" (frame) con cualquier contenido y
   posicion, una independiente de otra y lo tercero los frames son las
   "ventanas"... y esto sirve por ejemplo para tener un proyecto de programacion
   repartido en 3 areas de trabajo a dos monitores cada una con su "frame" de
   emacs (todos conectados) con ficheros varios o repetidos con distintas
   posiciones, algunas en la misma "ventana" dividida para maximisar el
   espacio... como lo que hacen com multiples terminales en la misma ventana,
   perooo util de verdad...

10. ejecucion de comandos del sistema. Estos pueden alimentarse con
    texto y mostrar, depositar o substituir otro texto. Util por ejemplo para
    hacer un `sort` y un `uniq` en una region especifica de un documento cualquiera

11. macros, junta los ultimos 6 puntos, agrupalos en una secuencia de acciones
    repetitiva, y vuala! algo a medio camino entre la automitizacion y lo manual,
    por ejemplo para transformar una documento de un formato a otro, o crear
    informacion, corregirla o todo junto

12. org-mode, esto es un lenguaje de marcas ligeras con los poderes especiales
    de Emacs, que sirve para muchas cosas, como para escribir un blog, como
    para hacer una lista de pendientes, o escribir un libro. Cierto es que ya no
    lo utilizo tal cual, pero fue inspiracion base de como debe ser el sistema
    de documentacion ideal, tambien lo utilzo para registrar la musica que
    escucho y anotar lo que hago en el dia

13. eww, un navegador de internete y tambien visor de html, muy potable, de
    hecho el mejor navegador en modo texto de los que he probado, tambien
    incluye sus propios marcadores

14. magit (requiere instalacion). La mas comoda y vistosa herramienta para
    interactuar con repositorios git

15. elfeed (requiere instalacion). El mas bonito visor de feeds, si lo sumamos
    con el navegador, o que puede invocar al navegador del sistema, optienes el
    combo perfecto

16. un gestor de paquetes para instalar extenciones sin mucha
    complicacion/configuracion


asi que por estas razones deberias empezar a aprender emacs hoy, para haci quisa
dentro de unos pocos meses o años alguien se digne a traducir el colosal manual
de emacs al español...

(tambien tiene corrector ortografico, que por cierto nunca utilizo)

## Por donde empiezo

Primero instala emacs, seguro que viene en los repositorios, Luego cuando lo
abras por vez primera presiona `Ctrl-h t` (`control` y `h` a la vez y luego `t`)
esto abre un breve tutorial suficiente para iniciar

Luego [cambia el tema](../first-theme/index.html) para que no te quedes ciego y
despues pues ver la [compilacion de recursos](http://quijotelibre.com/recursos-gnu-emacs-y-org-mode/) que ha hecho
*Quijote Libre*; al igual que el, recomiendo [la saga emacs](http://www.lapipaplena.org/emacs/) de la pipaplena, como
tambien algunos post (no muy organizados) en el [binario.net](https://elbinario.net/?s=emacs),
darse una vuelta por el [planet emacs en español](http://planet.emacs-es.org/)
y sus blogs afiliados, que es de lo poco realmente vivo en la comunidad
Emacs-hispana

hace mucho, mucho tiempo, pero no tanto, existio una pagina llamada
**rpublica.net**, sitio donde existia un exelente y aun vigente curso de
iniciacion a emacs, al que por su calidad realice un `wget` y por bagancia no he
"limpiado" para rendirle tributo, podeis descargar un zip con su
contenido [aqui](/data/rpublica-emacs.zip), descomprimir y abrir el fichero
`emacs.html` con el navegador

tambien dejo una pequeña chuleta que hice en mis primeros dias y aun me sigue siendo
util [chuleta-emacs](/data/chuleta-emacs.txt), puedes ponerla en un
marcador, por ejemplo de nombre *keys* y darle una exencion org y conquistar el
mundo

como consejo final, substituye al menos block-mayus por Control, o como en mi caso
tengo una configuracion customizada del mapeo programmer dvorak-en, en un teclado
con distribucion en ingles

![](/img/nascii-dvorak.svg)

si no has aprendido mecanografia haslo, y si ya sabes y es con qwerty, cambiar
vale cada hora requerida. Modificar la posicion de Ctrl, evita extraños
estiramientos no solo en Emacs, tambien en el resto de programas

desconosco si el mapeo de programmer dvarak-en es igual en todos los SOs,
al menos en freidora (y creo que tambien en debian) biene cargada de muchos
caracteres extra al presionar `alt gr`, por ejemplo, en conjunto con la n, te da
la ñ, y con comilla simple, pones acentos
