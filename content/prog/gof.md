+++
title      = "Desing Patterns (GoF)"
tags       = [ "txt" ]
categories = [ "prog" ]
date       = 2018-03-13T20:55:49-06:00
+++

Cuando era "pequeño", al oir *Patrones de diseño*, lo unico que mi diminuta mente
consebia era a un grupo de programadores a tope de egocentrismo, gozosos de
inventarse terminos rimbombantes y pretenciosos, que solo ellos pudieran
entender mientras reian y con una mano sujetaban sus monoculos y con la otra
un a-y-h-p-a-d

En aquella epoca de ignorancia, cada vez que iniciaba a programar algo
medianamente complejo, siempre me preguntaba si no existia algun escrito
perdido que proporcionara las herramientas para extructurar el codigo de forma
organica, audaz e inteligente, como si de diseñar un organismo se tratara, donde
todo funcionara en una armonica melodia y cada segmento de codigo tomara el
lugar de un instrumento musical identificable, a la vez que se mezclaba con
todos los demas.

Resulta pues, que sin proponermelo, fuera por la disposicion del codigo de
ejemplo en los libros, por el uso de comandos del sistema o por necesidad y
cabezoneria de resolver ciertos problemas, algunas de estas formas misticas de
estructurar el codigo fueron apareciendo e incorporandose en forma de
experiencia practica, no muy racionalizada, pero aun asi interiorizada en los musculos

mas sorprendente aun, fue descubrir, que estas "tecnicas para organizar codigo"
ya existian y no estaban ocultas. Resulta que aquella palabra extravagante
*Patron de diseño* era eso mismo que estube buscando desde el inicio, "el metodo
para estructurar el codigo de una forma razonable, inteligente (y en ocaciones organica)"

... y el material donde se presentaron a sociedad los patrones lleba por nombre
*Desing Patterns: Elements of Reusable Object-Oriented Software* o tambien
apodado como *GoF*

... y la mejor manera que encuentro para presentar el material, no es otra que
dejar unos extractos:

>  Los estudios de programadores expertos de lenguajes convencionales muestran
>  que el conocimiento y la experiencia no se organizan simplemente en torno a la
>  sintaxis, sino en estructuras conceptuales mayores, tales como algoritmos,
>  estructuras de datos y modismos, asi como en maneras de lograr un determinado
>  objetivo. Los diseñadores probablemente no piensan en la notacion
>  que estan usando para documentar su diseño, sino que intentan comparar la
>  situacion actual de diseño con planos, algoritmos, estructuras de datos y
>  modismos que han aprendido en el pasado.

>  Los informaticos nominan y catalogan las estructuras de datos y algoritmos,
>  pero no suelen dar nombre a otros tipos de patrones. Los patrones de diseño
>  proporcionan un vocabulario comun que los diseñadores usan para comunicar,
>  documentar y explorar alternativas de diseño. Los patrones de diseño hacen que
>  un sistema parezca menos complejo, permitiendonos hablar de el con un mayor
>  nivel de abstraccion del que permite una notacion de diseño o un lenguaje de
>  programacion. Los patrones de diseño elevan el nivel en el que diseñamos y
>  discutimos diseños con nuestros colegas.

>  Una vez que haya absorbido los patrones de diseño, su
>  vocabulario de diseño cambiara casi con toda seguridad. Hablara directamente
>  en terminos de los nombres de los patronesde diseño. Se oira asi mismo decir
>  cosas como "aqui deberiamos usar el patron Observer", o "extraigamos una
>  estrategia de estas clases".

tambien:

> Una de las mejores cosas de los patrones es que apartan las decisiones de
> diseño del reino de la mera intuicion. Permiten que los autores sean
> explicitos sobre las ventajas e inconvenientes que proporcionan, lo que
> facilita ver los fallos de sus patrones y discutir con ellos.

y finalmente la definicion misma de los patrones ::

> Un patron de diseño nomina, da los motivos y explica sistematicamente un
> diseño general que resuelve un problema de diseño recurrente en los sistemas
> orientados a objetos. Describe el problema, la solucion, cuando aplicar este
> y sus consecuencias. Tambien ofrece trucos de implementacion y ejemplos. La
> solucion es una disposicion general de clases y objetos que resuelven el
> problema. Esta adaptada e implementada para resolver el problema en un
> determinado contexto.

imposible explicarlo mejor!

Solo unas breves anotaciones personales para el yo del pasado:

Primero, al libro le hace falta codigo "real" (almenos en la vercion que poseo.
La vercion en ingles menciona un CD con material, pero desconosco su alcance).
Se presentan fragmentos de codigo solo lo suficientemente desarrollados
como para (si se presta atencion y se guarda dicho codigo con avaricia) poder
crear una implementacion "basada en" y hacerla funcionar. Esto no cumple
demaciado con mis estadares didacticos para subnormal, pero es mejor que nada.

Segundo, se utilizan diagramas algo cripticos con una sintaxis "inventada y
vieja", asi que revisar el apendice que habla de ello, para darle algo de
sentido. Ademas para el codigo utilizan un C++ "primitivo" y algo de otro
lenguaje llamado smalltalk, que aunque sencillo (en el caso de tener un bagaje
minimo con C++) seguramente no sera donde termines aplicando los patrones

y finalmente, La secciones de Implementacion, Codigo de Ejemplo y Usos Conocidos
de cada patron, en una primer lectura pueden abrumar y/o quedar en nada. Son
muchos patrones (aunque varios con aplicaciones "similares"), lo mas sensato es
enterarse donde, como y para que aplicarlos, asociarlos con su nombre y luego ya
si se da la oportunidad, investigar como implementar una vercion en codigo
practico y de ser posible, implementarla en el lenguaje donde te sientas comodo

y ya esta, este jodido año estara en su mayoria dedicado a conocer, implementar
y adaptar patrones. Chahh, con esto y dominar las interfaces/composicion (y
canales) de Go sera mas que suficiente... si no se cuela otro hobbie por
medio... asm para gameboy (love2d, rust, (e)lisp, asm de arduino, haskell,
educacion escolarisada, trabajo(???)), no te acerces, alejate, a-l-e-j-a-t-e

## cobaya

    git clone https://github.com/nasciiboy/GoF_Desing-Patterns

Como cualquier material que me importe un poco, Patrones de Diseño (GoF) ha
valido una adaptacion al formato de marcas (siempre en desarrollo, lento, lento
desarrollo del) morg (patrones == mas-desarrollo).

La mision comenzo a principios de noviembre (... supongo, porque el primer commit
es del 2 de diciembre). El material de referencia fue un pdf
infecto en español de aquellos que traen "fotocopias".

Lo primero fue transcribir a mano alzada palabra a palabra. Al principio probe a
aplicar un ocr, pero la tecnologia esa aun entrega resultados bastante jodidos,
sobre todo si como en este caso el texto no se ve y esta dispuesto de forma
optima. Lo mas dificultoso, fueron las secciones finales del PDF, pues tenia paginas en
desorden, asi como algunos bordes de texto desaparecido.

Luego de la mecanografiada vino una revision superficial, y al mismo tiempo (con
otro pdf algo infecto) la adaptacion del material en ingles al morg,
que es de donde se extraen las imagenes en el producto final. Al principio la
idea era hacer una version en SVGs de las imagenes, tanto para la version en
ingles como en español... pero es mucho, mucho trabajo y en este momento no
tengo el interes (o necesidad) para hacerlo.

ya terminada tanto la adaptacion en ingles (sin correccion alguna y apenas
uno que otro enfasis del texto, solo adaptacion) como la primer revision
del texto en español, llego el momento de leer a detalle el material y aprender
formalmente, o esa era la idea. En la segunda revision, se corrigieron muchas
distografias, algunas tan aberrantes como **patrnose** (patrones), lol, como es
posible escribir de esa manera? digo, entiendo substituir un caracter por alguno
en su cercania en el teclado, pero cambiar varias letras de posicion unicamente
puede revelar desordenes cognitivos exacervados ... ademas de eso, se corrigieron "lineas
repetidas", palabras "inventadas" y oraciones no incluidas.

No todos los errores los inclui, algunos ya estaban presentes en el material
traducido y los deje tal cual.

Para las regiones en el PDF que no estaban visibles, utilice el traductor y la
version en ingles

Finalmente el repositorio cuenta con versiones en html de los materiales, solo
por que el exportador del morg lo permite y para que quien no concuerde con mi
vision de documentacion en texto plano disponible directamente en el "editor" de
texto (emacs (por el momento como apaño) y con un marcador de por medio) tambien pueda aprovecharlo.

si te es de utilidad y ademas corriges algunos palabros y encima quieres
agregarlos al repo pero sin que quede registrado, puedes enviarme el texto
corregido tal cual por correo (ademas de la cuenta habitual (ver el fondo),
tengo cuenta en protonmail, tambien como nasciiboy), cifrar y tomar
consideraciones extra... claro, solo si se considera que difundir la cultura (en
todas sus formas) es incorrecto.

El resto, como revisar, enfatizar y corregir la version en ingles, asi como todo
lo relacionado con las imagenes, lo dejo en manos de las generaciones por venir

(o coloque un mandelbrot como "caratula" del libro, porque no se... hay algo que
diga mas patron y diseño que un mandelbrot?)

happy typping!
