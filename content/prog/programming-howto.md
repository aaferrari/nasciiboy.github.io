+++
title      = "Programming Howto (19-01-18)"
tags       = [ "howto" ]
categories = [ "prog" ]
date       = 2018-01-19T21:58:23-06:00
+++

Hace tiempo que tenia intenciones de escribir mi version sobre por que la
programacion rockea y cual deberia ser el camino a seguir... je, je, pero como
estoy bastante lejos de considerarme "un programador" (de la misma forma que
solo considero a un musico a quien vive de la musica y/o reconosco y
apresio su obra). No se, pienso que unicamente los consejos de un experto
(«alquien que domina un tema tan a profundidad, que es capas de intuir,
investigar, aplicar y desarrollarlo de formas aun no documentadas») tienen valia
y son dignos de atencion... sin embargo, quien demonios es un experto?  he?
conoces a algun experto? yo no

asi que, sin ser ningun experto, pero dandomelas de cuñado + unos años de
bagancia, dispersion, lecturas aleatorias, libros decepcionantes, saberes
aprendidos (y olvidados por falta de aplicacion) y otros vaivenes de proyectos
que terminan llendo a ningun sitio, creo, he almacenado la suficiente
experiencia para almenos dar un par de consejos a mi yo del pasado si es que lee
esto de alguna forma

pero primero y copipasteando [un post](https://henrikwarne-com.cdn.ampproject.org/c/s/henrikwarne.com/2012/06/02/why-i-love-coding/amp/)
(en engrish) (con algunas modificaciones hirientes) "**Las razones por las que me encanta programar!**"

1. La alegría de hacer cosas. La programación se basa fundamentalmente en la
   creación de soluciones a problemas. Al final del día, se ha creado algo que
   no existía esa mañana, y eso es en sí mismo satisfactorio.

2. La fascinación de crear objetos complejos en forma de rompecabezas que
   entrelazan piezas móviles y verlas trabajar en ciclos sutiles, jugando con
   las consecuencias de los principios incorporados desde el principio.

3. La alegría de aprender siempre, que nace de la naturaleza no repetitiva de la
   tarea. Mientras uno construye el programa, se amplía constantemente la
   comprensión tanto del problema como de la solución. Además, casi no hay
   límite a lo se puede aprender para mejorar «lenguajes, algoritmos,
   metodología, herramientas, ...»

4. El programador, como el poeta, trabaja sólo ligeramente alejado de los
   pensamientos puros. Construye sus castillos en el aire, desde el aire,
   creando por el ejercicio de la imaginación. Sin embargo, el constructo
   programático, a diferencia de las palabras del poeta, es real en el sentido
   de que se mueve y trabaja, produciendo resultados visibles separados del
   propio constructo

5. La expresividad del código. Suena contraintuitivo, dada la especificación
   estricta de un lenguaje de programación, y las relativamente pocas
   construcciones que contiene (comparado con un lenguaje natural para humanos), pero
   hay un número casi infinito de formas de escribir un programa para resolver
   un problema dado (no trivial). Primero y ante todo, se decide el nombre de
   clases, métodos y variables, pero también el algoritmo, la partición de la
   lógica y finalmente la distribucion del codigo. Todos estos factores se
   combinan para dar al programador gran libertad para expresar la solución.

## Materiales

- Cualquier procesador donde pueda instalarse un sistema GNU (o BSD) (ni
  androides, o winbugs son dignos de la tarea, hay que formatear del disco esas
  aberraciones), si se trata de un hardware de la manzana puede servir, pero no
  te conformes con imitaciones genericas e instala GNU, con sus 3 letras, asi en
  grande y en mayuscula

  Con poder ejecutar una terminal puro y duro es suficiente para cacharrear, mas
  si se desa una experienca completa y con un entorno grafico GNOME (el mas
  chulo de todos), los requerimientos minimos serian

  - procesador de doble nucleo (basicamente cualquiera procesador de **sobremesa**
    salido en los ultimos 10 años, una laptop? ja, ja, ja y ja, si te va el
    BDSM, adelante)
  - al menos 3GB de ram, 2 en casos exepcionales y siendo bastante conservadores
    con el uso de esta. Preferentemente 4GB en adelente y de ser posible 8 para
    "jamas" tener ninguna preocupacion
  - 1TB de almacenamieto (HDD y/o SDD), para almacenar mucho codigo, libros y
    musica, seehh mucha musica. El almacenamiento nunca es suficiente, el
    interne es grande y generoso. Si esta dentro del presupuesto mejor montar
    una placa ATX o Micro ATX con 4 o mas puertos SATA
  - muchos puertos usb, nunca son suficientes: teclado, raton, adaptador wifi,
    gamepad inalambrico, cable del mobil, memorias, etc, etc

- Un monitor. Preferentemente dos con entradas acordes a la placa. Con cualquier
  monitor roñoso es posbile programar, pero como se va a pasar mucho tiempo con
  la vista fija leyendo, preferir la mejor calidad de imagen y
  resolucion. Tamaño? 17 pulgadas en adelante

- Un teclado en condiciones, con teclas que no se peguen, mecanico si entra en
  el presupuesto

- un raton que funcione, tambien que no sea roñoso (logitech tiene calidad y buen precio)

- unos audifonos de diadema, comodos y con calidad de sonido decente, no tienen
  que ser caros, solo confiables, sin ruido ni distorcion (llevo con unos sony
  MDR-ZX100 cerca de 3 años y han cumplido su funcion (~15 dolares))

- un cuaderno y pluma o lapiz. Mas que para tomar apuntes, para hacer dibujos y
  diagramas que ayuden a visualizar ideas

- una silla comoda, con movimiento reclinable, giratorio, pero que de soporte a
  la columna

## Preparativos

Aprende a instalar la distribucion GNU, romper particiones, cosas basicas de
repositorios y administracion del sistema. Ser un Sysadmin es aburrido y carente
de emocion, asi que no indagues demasiado

con cual (distro) empezar? **Debian**, instalas, configuras hasta que todo funcione y se
amolde a tus necesidades y te olvidas un par de años sobre actualizar cosas,
quiza si estas acostumbrado a los entornos "retro" pero con un toque de
elegancia Linux Mint. Otra opcion seria OpenSuse, anuque en esta simpre siento
que es algo incomoda-como-que-corporativa-o-algo-asi, no se.

Si el hardware es muy quisquilloso (o nuevo) prueba con fedora...

o si eres mas audas con algun derivado de Arch. Hay muchas distros por hay
fuera, pero ve a las grandes, con gente (mucha gente) detras y que no se queden en un
experimento

M-e-c-a-n-o-g-r-a-f-i-a, o si, aprendela! lo pospuse cerca de 3 años (despues de
la era del ñu) perdiendo el tiempo entre la lectura e ingresar datos
penosamente, picando teclas viendo el teclado

El entrenamiento sera de aproximadamente 3 meses hasta tener confiansa y
fluides, pero valdra cada segundo invertido, a diferencia de lo que la
modernidad indica, el teclado es (de momento) la interfaz mas eficiente para
interactuar con el sistema (nota: la [distografia](https://es.wikipedia.org/wiki/Disortograf%C3%ADa) y pesima redaccion es algo mas
dificultoso mejorar, incluso incurable).

Cual distribucion de teclado? español?  ingles?  ninguna! **programmer dvorak**
en ingles, buscate la vida, pero cambia los control, blockmayus (y otras teclas)
de posicion, asi:

![](/img/nascii-dvorak.svg)

Es preferible que aprendas ingles (aun pendiente), mas diria que los primeros
años del trayecto no es necesario, hay muchas cosas que requieren atencion y *los basicos*
estan en español. Por el trayecto y el contacto cotidiano (musical, visual y sintactico)
se aprende lo suficiente para apañarse, mas preparate apropiadamente en esa
lengua, tarde o temprano te sera necesaria

## the thing

antes de proseguir, una duda que tenia al principio y aqui es el sitio donde
debo responderla. Puedo aprender por mi cuenta o es necesario ir a un instituto
a que un iluminado me transmita estos misterios?

primero, la programacion es compleja y a la vez muy sencilla. Sus bases no
requieren ninguna habilidad intelectual exepcional... suponiendo que no seas subnormal... a
menos que tu subnormalidad radique en ser retraido, ensimismado, egolatra y obsesivo
compulsivo, situacion en donde la subnormalidad amolda perfectamante con un
equipo de computo y las largas horas que pasaras frente a este, descubriendo
un ancho e inabarcable oceano de conocimiento y diversion!

pero puesto al tema, vale la pena asistir a un aula o pagarle a un
tutor? diria que no, de hecho seria desperdiciar tiempo y dinero cuando aun no
sabes si eres apto, como saber si eres apto? si apredes lo eres, si no
pueeeessssshhh noh.

Si, alguien iniciado te puede ahorrar mucho, mucho tiempo indicando donde
deberias invertir tu esfuerzo o aclarando algunos puntos especificos. Aun asi,
la programacion (como cualquier otra cosa) requiere mas transpiracion y esfuerzo
que intelecto (quiza algo inerente al ineficiente "diseño humano"), es decir, para
aprender a programar y hacerlo bien, es necesario practicar, fallar, probar,
fallar de nuevo, olvidar, volver a intentar, aprender un nuevo "truco" mas y
repeter el proceso nuevamente, paso a paso durante unos cuantos años... cuantos?
los suficientes como para olvidar que algun dia no tenias ni puta idea y ahora
esos momentos preteritos parecen hilarantes, es mas, si alguien en tu mismo
estado inicial se acerca a preguntar por guia seguro que, o lo miras con
indiferencia, o con misericordia por el largo recorrido que tiene por delante

asi que en resumen, si! puedes aprender "por tu cuenta". La mejor y mas paciente
guia es un libro bien escrito, claro, en ocaciones explicito a niveles
pornograficos, en otras misterioso y arido

ahora si > que, como y por que... Aprende C, con Emacs, Bash y GCC

Si bien C no es "el lenguaje" mas cool del barrio, si que es base y fundamento
para la practica totalidad de lenguajes populares actuales, los principios estan
hay. Si, si, es verdad, C es severo, pero no demaciado, mas el esfuerzo que
viene con el aporta los siguientes puntos te seran de utilidad

- Con C, te haces una idea general de los fundamentos de la maquina,
  almacenamiento, procesamiento, texto, codigo ejecutable, compilacion,
  ejecucion, pero sobre todo, se desvela la magia detras del paradicma "UNIX",
  con la debida desmitificacion de la linea de comandos, tuberias, y retornos

- C es ridiculamente pequeño, solo tiene los rudimentos, pero no creas que sera
  sencillo, aun lo mas basico como saber hacer un bucle, un
  (post|pre)(incremento|decremento) tiene que ser dominado, switches,
  if-else's, declaracion de variables, arreglos, estructuras, funciones (y sus
  parametros), recursividad, punteros, punteros a funciones, arreglos con
  punteros a funciones, etc.

  Conocer sobre Programacion orientada a objetos es inecesario en este punto,
  es una complicacion adicional y prematura

- GCC y terminal, ohhh yhea! aprende los tres comandos minimos, a moverte por
  los directorios, crear ficheros, ejecutar programas y compilarlos, nada mejor
  que una pantalla obscura con letras intimidantes para sentirte poderoso

- Emacs! Editores hay cientos, Emacs, solo uno... (o no). Ningun programa que
  halla existido o existira le hace sombra a este imponente y glorioso
  interprete de elisp con piel de editor de texto, puede que desconoscas el
  significado de estas palabras, mas con dedicar una tarde a sus "atajos"
  fundamentales es suficiente para crear tus ficheritos de programacion

  Con el tiempo descubriras que emacs es abrumador, *el fruto mas puro que la
  programacion puede entregar*, no conoce fronteras ni limitaciones

- Cuando dices que "sabes" programar en C, se hace el silencio, los presentes
  se miran entre ellos y luego te miran con respeto... o no...

Sin importar el punto, herramiento, lenguaje o programa, lo que ha de aprenderse
es inmenso, en lugar de lanzarte directamente a la boragine informatica, tomalo
serenamente, una cosa a la vez, aprede cuando sea necesario, lee sobre nuevos
temas, sigue enlaces, pero no te comprometas, ni te exijas memorizacion alguna o
puedes abrumarte. Veras que con el tiempo recordaras sin notarlo aquellos
comandos, funciones y atajos que de verdad necesitas, e iras sumando
conocimentos incrementalmente... aunque el cerebro humano es limitado (llega un
momento en que el buffer se satura y cuando entra algo nuevo, algo sale sin que
te des cuenta...)

### Los libros

#### COMO PROGRAMAR EN C (/C++ (y/o Java)) 4th edicion (Deitel & Deitel)

  Son aproximadamente 500 paginas. Explicaciones detalladas y "didacticas",
  incrementales, muy incrementales.

  Puedes aprender de 0 a "iniciado", te dejara una idea muy clara de como es
  programar (en los "90" antes del internet... *programar "de verdad"*), eso si (con este como con
  todos los libros) intenta realizar todos los ejercicios que puedas, *TODOS*,
  haciendolos sabras si aprendiste algo o no, ademas, creo que solo asi se
  acondiciona el cerebro para esto

  Si hay una seccion que no terminas de entender, no te preocupes, sigue
  leyendo hasta el final, ejecuta los programas propuestos, meconografia si
  quieres y luego de ver el programa en accion intenta entender de que se
  trata, vuelve a leer el capitulo y asi lo tendras mas claro

  Sobre GCC, Bash apenas necesitas lo basico en algun post lo encontraras o en
  su defecto hojea [este](/data/bash.pdf) para bash y [este](/data/GCC.pdf) otro para
  gcc, sobre los makes, je, nunca lo aprendiste...

  de Emacs, con el tutorial integrado (`Ctrl-h` y luego `t`), tambien y aunque
  esta un poco retro y fuera de interne [rpublica](/data/rpublica-emacs.zip) o
  consulta la siguiente [recopilacion](http://quijotelibre.com/recursos-gnu-emacs-y-org-mode/) del quijote libre

#### C (K&R) (2^da version)

  Un libro aspero casi hostil, pero muy clarificador sobre como esta construida
  la biblioteca estandar, de hecho diria que enseña a implimentarla.

  El estilo esta algo desfasado y con seguridad nunca lo utilices en "el mundo real"

  Mas importante que las formas, es el contenido, diria que esta es la
  verdadera prueba, el bautiso de fuego

#### Pausa

  dedicate a programar en C, algo deverias tener en mente en este
  momento, esto te ayudara a afirmar los conocimientos.

  Si lo que te interesa son los videojuegos, programa algo en
  [ncurses](https://github.com/nasciiboy/NCURSES-Programming-HOWTO) ([tambien relacianado](http://nasciiboy.github.io/prog/cobaya.zip))

  luego, quiza lee superficialmente el resto del libro de Deitel
  para colocar en tu cerebro de que va eso del POO (o OOP), ademas de conocer
  los rostros de C++ y Java

#### The Go Programming Language

  uff, a las bases de C, se les recubre con un toque de "programacion moderno" y
  obtienes Go, un languje con una POO casi invisible ademas de poco
  convencional. Te suman una libreria estandar en condiciones, gestor de
  dependencias, documentacion, pruebas y "perfilado".

  Un todo en uno, que llebara tus bases a programas "grandes" sin sacrificar
  (demaciado) rendimiento ni incluir conceptos complejos, encima, como C es un
  lenguje compacto, puedes ver por [aca](https://github.com/nasciiboy/TGPL/)

#### Patrones de Diseño (GoF)

  el paso definitivo en el camino entre ser un programador mediocre sin respeto
  ni admiracion al espiritu que habita en el silicio... o un cuñao medio
  entendido.

  En resumen, unos diseños para ensamblar abstracciones sobre las abstracciones
  (sobre las abstracciones hardware) de lo que deberias saber en este punto


Apartir de aqui, puedes ingresar a la carrera (mates, sistemas, redes y esas
cosas que dan cache), buscar trabajo, o quiza si eres afortunado encerrarte a
programar en solitario una temporada por mero hobbie, o finalmente abandonar y
aprender otra cosa

happy hacking!
