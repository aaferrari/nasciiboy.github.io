+++
categories = ["prog"]
date = "2017-05-29T22:02:43-05:00"
draft = true
tags = ["docu"]
title = "El Lenguaje De programacion Go"

+++

golang, el lenguaje de <q>programacion de sistemas</q> de la gente de google con
el que planea llebar a cabo sus mas retorcidos y stalkerosos deseos.

Hoy y tras pocos meses de programacion y muchas horas de investigacion
linguistica intentando entender el english, les traigo una reseña de la biblia
de golang (Go para los amigos) <em>The Go Programming Language</em> (en adelante
TGPL o GPL(?))

## el libro

los usa-americanos tinen sus medidas extravagantes, siguiendo su ejemplo, yo
mido la extencion de un documento en las lineas (de 80 columnas indentadas) que
abarca, por ejemplo, 7000-10000 lineas suelen ser la extencion regular de una
novela, debajo de esta cantidad es un trabajo corto, superior de esta es extenso
y superior a las 20000 lineas ya es <em>muy extenso</em>, aunque <em>Dune</em>
utiliza (y muy bien) la friolera y descomunal cantidad de 34150 lineas.

Pues bien TGPL son 21426 lineas, repartidas a partes iguales entre explicaciones
y codigo fuente, si quieres la extencion en paginas cerca de 400, aunque yo no
confiaria en esta medida

La mayor parte del libro se utiliza para mostrar la forma de hacer las cosas en
Go, sintaxis, ideologia y paquetes. Haciendo un simil con C seria algo asi como
que te enseñåran a hacer muchas herramientas del sistema, mas una guia de gcc,
make y alguna cosa mas.

Se asume que ya conoces al menos un lenguaje de programacion, particularmente C o
alguno de su descendencia, y aunque no es necesario, que manejes programacion
orientada a objetos y/o concurrencia es deseable, antes de iniciar esta aventura

No es un manual para no iniciados, es decir, para quien no tenga ya asumido en
su ser lo que es programar, resultara hostil, diria que es apto como tercer o
cuarto libro de programacion

Se enseña a construir aplicaciones no triviales, utilzando la rica libreria
estandar del lenguaje, aunque la mayoria encaminadas al tema web, ninguna es
despreciable, incluso se propone la construccion de un parser de espreciones-S y
un pequeño interprete para un lenguaje de programacion, aunque no se llega a
profundizar veraderamente en ningun tema, se da lo suficiente como para
enfrentar cualquier propuesta sin temor (jo, lo dice quien no ha hecho mas de 4
ejericios, en serio, eso es lo mas denso, ni en la vastedad de internet he
localizado a un intrepido programador que alla concluido tal mision)

Lo mismo se aplica para las secciones que explican la herramienta principal del
lenguaje, que es compilador, perfilador (primera ves que utilizo algo asi),
administador de paquetes, "visor" de documentacion y muchas cosas mas. Nos dicen
de que va el tema y luego saltan al sugiente punto... es este caso aunque
suficiente para iniciar, si hecho en falta mayor detalle, pues varios comandos
requieren un orden y sintaxis nada evidentes, siendo mas bien conjuros o trucos
misteriosos

en resumen, recomendo su lectura a cualquiera, en particular si se biene de C o
C++ y se aspira a lenguajes mas desapegados de la maquina, sin topar de lleno en
abstracciones incomprensibles

## el lengueje

el libro esta muy bien!, que tal el lenguaje?

bueno, desde la perspectiva de un aficionado a C, que ha pasado por C++, bash y
un ligero viaje por lisp, el lenguaje me gusta mucho, aunque no puedo perdonarle
que inponga un estilo arbitrario de como han de indentarse y separarse las
sintrucciones, es decir el formateo, biniendo de C tener llaves para
instrucciones sencillas (una instruccion) me parece atroz, por no decir forzar la
posicion de apertura y cierre de las demas llaves, sobre todo en intstrucciones
`else`, no lo soporto esteticamente!, hooo y utilizar tabs para indentar, deben
arder en la hogera, y como te obligan a esto, simple si no cumples su mierda
formato no compila...

dejando atras este no precisamente poco importante aspecto, tenemos el
inmobiliacio habitual de los descendientes de C, ifs, elses, else ifs,
funciones, arreglos, switches, return, gotos y bucles for, caresiendo de bucles
while y do while, pero sumando slices, que son una especie de arreglo con
crecimiento dinamico automagico (el lenguaje tien recolector de basura), mapas
hash, una funcion llamada `defer`, `gorutinas` para programacion concurrente,
<q>canales</q> para pasar datos a las gorutinas y asegurar que completen su
ciclo, pero sobre todo y quiza lo mas interesante del lenguaje su orientacion a
objetos no evidente

claro, el lenguaje tiene una forma <q>peculiar</q> de organizar sus parametros
(al revez) que no pocas veces me ha causado transtornos cuando regreso a tocar
C, pero lo que mas me gusta es que no intenta ser innecesariamente complejo en
ningun aspecto, es mas, los programas son casi imperativos, la orientacion a
objetos aparece por si sola, aunque lo "metodos" requieren un poquito mas

por defecto utiliza codificacion unicode utf-8, incorporando una utilidad
llamada `range` que nos entrega los caracteres unicode sin tener que recurrir a
esotericas librerias, a si como convecion automagica de entre `runas` unicode 32
a cadenas de caracteres utf-8, si necesitamos mas ya toca recurrir a la libreria
estandar

por cierto, aunque el nucleo del lenguaje es compacto (bravo) la libreria
estandar es muy rica, te da un servidor web, analisis en cadenas, codificadores,
compresores y otro monton de cosas

es sencillo crear programas relativamente complejos con estas facilidades,
aunque encuentro incomoda la herramienta de documentacion para linea de comandos

no te voy a mentir, la libreria estandar es amplia, pero carece de librerias
nativas para graficos y esto es un punto flaco, tomando en cuenta que si te
apegas a la libreria estandar tus programas son multiplataforma y que el
costructor de programas es por naturaleza multiplataforma. Lamentablemente, veo
poco probable que algun dia llegue a tener librerias nativas para estos
menesteres... a menos que el gestor de paquetes pueda meter sus manos en el
gestor de paquetes del sistema en si (apt, dnf, yum, etc)

sobre esto, me encanta como administra las "librerias"/paquetes externos, nada
de buscar por internet, ni compilar a mano, ni naaah, el solito busca las
dependencias y las enlaza. Nunca perdonare al comite de los estandares de C y
C++, por no copiar este aspecto y evolucionarlos de forma razonable, si hicieran
su labor no tendria que aparecen Go

respecto a la concurrencia, no tenia ninguna experiencia previa, era un tema
mistico, magico y misterioso y sin embargo he podido implementar un tipo
concurrente, aunque no se, encuentro un poco criptica las formas en que esta
implementada, aunque como digo desconosco como se haga esto en otros lenguajes,
de momento la puedo usar sin muchos complejos ingorando una parte que tenia que
ver con bucles for, captura de variables y cosas concurrentes que no me quedo
muy clara en el libro

### cosas feas

ademas del jodido formateo? cast, cast, cast por todas partes, y si no aplicas
cast, he?, creas una varible extra con el cast apropiado al inicio de la funcion...
teniendo que asignar memoria extra...?

tan dificil y peligroso es asumir que el programador sabe que es lo que hace con
los tipos que escoge y en consonancia hacer conversion automatica de tipos, digo
con tener conversion autamatica en llamadas a fuciones seria un gran alivio,
pero no, ademas ni ellos resepetan su estricto y seguro tipado (ironia), pues
aveces hacen convesiones automaticas para ciertas tareas, a sabiendas de lo poco
practico de tal tipado, quedando mas que evinciado en su elecion de regresar
`int`s aun en valores que deverian ser unsigned

no le haria mal separar la herramienta en varias utilidades, en particular para
la documentacion, pruebas y perfilado

tener un solo paquete por directorio es bueno, pero en paquetes conseptualmente
extensos puede ser dificil averiguar la procedencia de una funcion, no es grave
y es principalmente un problema del programador no distribuir el codigo de forma
coherente, pero aun asi se vuelve dificil seguir la logica de un programa extenso

### conclucion

Me gusta y lo recomiendo como lenguaje secundario, si bien es cierto que tiene
un fuerte enfoque para aplicaciones web, es un lenguaje de proposito general,
con un rendimiento aceptable

segun pruebas mias, su rendimiento esta entre 3 a 4 veces mas lento que su
homologo en C, es decir, si un pragrama demora 1, en Go, demora 4 o 5, bueno no?
si, eheemee, aun tengo conflictos psicologicos al saber que va 3 o 4 veces mas
lento que C, pero bueno al menos no es 100 veces mas lento como el
<q>fabulosisimo</q> python o JS

momento, tengo que sacarlo de mi sistema, no programes con python, ni JS, no lo
hagas, por fabor, no son lenguajes poro programar por mas (falsamente) simples o
elgentes que sean, los lenguajes interpretados son para extender programas o
para servir como prompts, no para crear algo de cero. Sirve de algo tardar unas
horas menos programando en esos lenguajes cuando pasaras la eternidad
ejecutandolos lentamente? hay lo dejo

Go apenas se encuentra en los limites que considero un rendiminto aceptable.

Entre 7 y 10 veces mas lento que C, sin importar el paradigma, solo podre
considerar al lenguaje una <q>curiosidad</q> intelectual

## porg

durante el ultimo mes, he estado traduciendo o mas bien dando sentido a la
traduccion de las maquinas sobre el libro en cuestion, pueden optener el codigo
con

    git clone https://github.com/nasciiboy/TGPL.git
    cd TGPL

abren los ficheros `html` en su navegador de confianza (pista: el que tiene un
sufijo `es`, es el que esta en español

para crear el material desde el codigo

    go get -u https://github.com/nasciiboy/morg
    morg toHtml The-Go-Programming-Language.morg

o

    morg toHtml The-Go-Programming-Language_es.morg

para ver el fichero directamente en su terminal, utilice `morg tui fichero.morg`

si quiere colorizar el codigo en la exportacion a html, necesita tener instalado
`pygmentize` (python pygments), y agregar `pygments` a `options` (dentro del
documento), asi:

    ..options > pygments


en fin, una labor estandar de traduccion a mi estilo sin acentos.

apenas es lo suficientemente entendible, y apenas dare mi primer lectura seria
al libro y de paso corrijo algunas cosas.

tuve problemas al localizar muchas cosas, pero si quieres colaborar a mejorar un
manual que nunca iba a aparecer en españøl, tienes mi correo y clave gpg abajo

happy hacking, en la proxima entrega nasciiboy inc. por cierto si retiran este
sitio de internete, dadle asilo
