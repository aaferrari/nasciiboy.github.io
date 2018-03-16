+++
title      = "Java & Me(h)"
tags       = [ "howto", "java", "docu" ]
categories = [ "prog" ]
date       = 2017-11-10T14:57:41-06:00
+++

Por que [razones](https://picodotdev.github.io/blog-bitix/2015/05/10-razones-para-seguir-usando-java/)
concientes y sin coercion externa aprender java?

en mi caso, hice un solemne juramento de no aprender java (y quiza python,
js...) y en general nada 7 veces mas lento que C... porque cualquier lenguaje un orden
de magnitud mas lento que C, es directamente una basura... o tiene un ambito de uso
extremadamente especifico, como servir para crear extensiones o como
prompt. Fuera de este uso, nadie "serio" sacarlos deberia. Crear programas completos
directamente en esos lenguajes es una guarrada y una falta de
respeto por el espiritu que habita en el silicio. Por decir algo, es casi tan
aberrante como mi forma de escribir...

pero bueno, hace mucho tiempo que java merodea por el mundo, y en general es
unas 4-6 veces mas lento que C, asi que entra en la zona estelar de los lenguajes que
permiten la existencia de agua liquida. Entonces, por que mantenia una
resistencia interna a aprender java?

- todas las cosas hechas con Java dan la sensacion de estar lagueadas. (Arde en el
  infierto android)

- deriva de C++ y C++ no es un lenguje agradable para programar (si tocas todas
  sus posibilidades), por que tiene un monton de caracteristicas obscuras y
  sutiles, que lo hacen absurdamente complejo, dificil de leer e imposible de
  dominar (o no)

- hiede a empresarial, y las cosas empresariales no son divertidas, y yo viene a
  la programacion para estar cool (<== obscura referencia al manga GTO)


pero estonces, por que siquiera de estas explicaciones, que hechos se han
conjurado para ceder al mal?

basicamente, mientras continuo el trepidante camino en la programacion
autodidacta sin tener idea (de mates, english o adonde dirigirme), y a medida
que va creciendo la complejidad de las cosas que "planeo" programar, la
intuicion y sentido comun me dice que muchos de esos secretos ancestrales se
encuentran alla afuera

![](/img/believer.png)

o en el peor de los casos, estan cerca de ser ser promulgados, por alguien...

como apenas inicio mis andansas por el mundo de las mategicas y el engrish aun
es arido en sus detalles, para no desaprobechar ese regalo llamado ser el
fracasado treinton sin empleo que se queda en la pc todo el dia sin hacer nahhh
y que vive permanentemente en la banca rota... mejor leer cosas programacionales
en español, un  inquietante campo superpoblado con material que utiliza a
java como lenguaje universal, asi que por el bien del mundo, a joderse!

## Instalar Java

Casi todos los sistemas del Ñu traen un java instalado por defecto, como en el
caso de freidora el openjdk-1.8, pero con esto no nos vasta para comenzar a
"compilar" programos, hace falta instalar el paquete *devel* para optener el
programa `javac`. Ya que estamos (y por que en freidora 27 aparece en los repos)
pues mejor instalar lo ultimo de lo ultimo, por si lanzamos pestes, sus fancis no digan
que la causa es utilizar una version desfasada; ademas es casi completamente
compatible con el codigo vintage!

```
# paquetes del java-9
dnf -y install java-9-openjdk java-9-openjdk-devel

# le decimos al sistema que este va a ser el "java bueno"
# nos preguntara con un numero cual java poner por defecto
# el que tenga un =nueve= sera el efectivo
update-alternatives --config java

# lo mismo que el anterior pero para el javac
update-alternatives --config javac

# comprobamos que la version es correcta
java -version
javac -version

# no se que es esto, pero parece importante para el futuro
dnf -y install maven
```

luego, tenemos que configurar en nuestro shell las rutas donde el java buscara
las "librerias" para compilar sus cosas. Esto se hace estableciendo la variable `CLASSPATH`.

En `fish` ha sido asi (`~/.config/fish/config.fish`)

```
set --export CLASSPATH  '/usr/share/java:.:/home/mi-usuario/.java'
```

solo acepta rutas absolutas. Las rutas se separan por dos puntos (`:`).  La
primera es donde esta la libreria estandar (en freidora), la segunda, "el
punto", es para que busque en el directorio actual, y la tercera, para colocar
cualquier libreria externa que me encuentre por el internet sin comprometer el
sistema demaciado, y para no hacer cosas de root con frecuencia, ademas es una
carpeta oculta para no molestar

oh, como el java nueve es muy moderno, incluye un comando de tipo REPL, que
significa que podemos programar de forma interactiva. Solo hay que typear
`jshell` y voala, a programar sin compilaciones y con mucho
l-a-a-g-g-g-g-g-g. Este tipo de cosillas y sus tiempos de respuesta me ponen
nostalgico, como que estubiera en otro tiempo y asi fuera programar "de verdad",
fuera de sarcasmos, tiene su encanto!

encontre sobre esto del `jshell` en un libro (en ingles) llamado "Java 9
Programming By Example" de facil optecion, al menos en un sito llamado
*allitebooks*. jo, jo, jo, que jocosos los de la editorial del libro, que te
insitan a informar si lo encuentras por la red, me dan ganas (si lo continuo y es
interesante) de cobayisarlo, ya veremos

## El editor

fuuuhh, aver, en emacs hay un modo para esto, es decir lo basico, resaltado e
indentacion, si quieres mas pues a buscar por vias alternas.

Hay un modo externo que se llama **jdee**, con resaltado de errores,
autocompletado, documentacion, dos espacios de indentacion por defecto y otras
promesas mas, aunque la instalacon en mi caso no fue bien, creo que es algo
relacionado con las rutas de java.

Al ver que la cosa no iba muy fina, reverti los cambios y deje el emacs como al
inicio y toco ir por la segunda alternativa: un viscoso, (d)oloroso, consumista y
lentorro **IDE**... bueno la prueba se limito a **eclipse**, la unica conclusion
que puedo dejar sobre la experiencia, es que mi maquina no es apta para correr
estas cosas para developers modernos

asi que ha regresar al emacs "a pelo"

## Documentacion

Esto es un punto bastante jodido con java, no tengo ni puta idea sobre como se
organiza la libreria estandar, ni que tan lejos llega o como se utiliza. Para
volverlo aun mas complejo no hay documentacion en linea de comandos similar a
`man 3` o `go doc`.

La opcion de emergencia fue bajar los docs de Java para `zeal` y tampoco fue de
mucha ayuda, de nuevo no tengo idea de como se organiza|utiliza la libreria
estandar y abrir un libro (pdf en este caso) *especializado* para averiguar que
clase se utiliza para tal cosa, o como hereda de tal otra, no es una opcion que pueda
contemplar

## Thinking in JAVA, 2^da edicion

Vamos con la carnita, un libro viejuno de Java 2, de los años 2000, donde hablan
de las guerras de navegadores con el netscape vs el explorer y podian ejecutar
el java salvagemente con etiquetas html!

Tome este libro por que el codigo del autor me parecio mas que bonito en su
libro de Piensa en C++ (era joven). Tambien por que fue lo que encontre en
español, por que tiene muchas paginas, por que sale rapido en una busqueda con
terminacion *pdf* y por que el codigo fuente de los ejercios tiene *dos
espacios de indentacion*, haci lo hacia Stallman, haci lo hacia este autor, haci
lo hago yo y haci lo haran mis decendientes sinteticos.

El libro tiene una version 4, que data del 2006, en ingles asi que esta
descalificado, pero desde la pagina del autor pueden descargar el codigo de los
ejemplos y el libro (en ingles) en formato html de esta 2^da edicion. Aqui el [enlace al
zip](http://www.mindviewinc.com/downloads/TIJ-2nd-edition.zip)

o, y por si el enlace esta roto, bajarlo de [aca](/data/TIJ-2nd-edition.zip),
a esta le aplique un `dos2unix` a todos los ficheros, para no tener que ver el
*DOS* en el emacs

antes de continuar y si se quiere seguir el libro, es importante que
descomprinas el zip, tiene una carpeta con el libro y otra con el codigo fuente,
toma esta ultima y mueve/copia la carpeta `com` a donde sea
que tengas apuntando la variable `CLASSPATH`.

Una ves hecho esto vasta con entrar a la carpeta que se este estudiando y hacer
un `make`, casi todos los ejemplos compilan, excepto en los capitulos (creo que)
12 en adelante, cuando se pone a hacer cosas con GUI y por que tiene una feo
fetichismo de incluir sus librerias en cada ocacion.

Ahora si, que tal el libro?

un libro con DLC... el autor aprovecha cada ocacion que tiene para mencionar que
puedes bajar tal o cual material suyo en su web, y que por una modica cantidad
te ofrece ~~droga~~ las respuestas a los ejercicios, el resto, por supuesto
[inserta aqui efecto de susurrar al oido] *es gratis*. Algo molesto en mi opinion,
mas para venir en un libro comprado, con mencionarlo en el prefacio bastaba

Los primeros capitulos (hasta antes de la aparicon de herecia e interfaces) son bastantes
llebaderos, explica de forma condesada y clara muchas cosas, como que jodidos es
un recolector de basura (junto con sus inconvenientes que dan miedo), que es un
hilo del sistema, por que java esta diseñado como esta diseñado, su evolucion,
carencias y defectos

en el capitulo de la herencia las cosas se ponen turbias, te agobia con
un monton de caracteristicas obscuras. Fue entonces cuando el formato "Catalogo
de referencia" del libro salto a la conciencia. Seguramente por la propia
naturaleza ecleptica de java. El autor no duda en mencionar cada una de sus multiples
opciones y capacidades, lo que sumado a que el libro no te enseña a hacer nada
(por decirlo de alguna manera), hace dificil retener el sin numero de opciones

Cuando la cantidad de informacion es abrumadora como en este caso, recomiendo
entrar en modo paseo por tienda, ver que hay y si el vendedor se acerca, decirle que no
moleste. Todas estas opciones solo se retienen en el cortex luego que se
presentan los problemas mientras se va programando, ese es el momento donde
saber que exite una cosa (aunque no como hacerlo) regresa a nuestro recuerdo y
podemos ejecutar el aprendizaje teorica y practimamente, y quiza si es posible
con aplicaciones recurrentes, memorizarlo

cerca de la pagina 450 el material comenzo a parecer pesado.

Ya que la principal motivacion de leer el libro era enterarme que estan
exponiendo en algun ejemplo corto de algun libro intereante, no dedicarme a
programar en java, me plantee dejar la lectura y pasar a otra cosa. Pero
continue al siguente capitulo y aparecieron cosas relevantes. Si tambien vas
en modo paseo, almenos lee el inicio de cada capitulo y alguna seccion relevante

Como conclusion el libro es eso, un buen material de consulta.

Sobre java:

- Es un lenguaje pegote (o katamari), se le adiere todo, un monton de
  posibilades que incitan a hacer guarradas y no enterarte de lo que algun
  programador con preferencias exquisitas este haciendo

- La jerarquia, asociacion y documentacion de sus clases no es intuitiva

- "compilar" y "cargar" (`javac`, `java`) es un rollo y se siente lento

- El lenguaje no esta diseñado, es 🌈evolutivo🌈. Toma la inco(nsist|her)ente base de C++, la simplifica,
  y hace mas verbosa, un monton de clases, enfoques, palabras clave y especificadores con
  multiples significados que enturbian la 🌈experiencia🌈

y ya! bienvenidos los insultos y duelos a muerte!
