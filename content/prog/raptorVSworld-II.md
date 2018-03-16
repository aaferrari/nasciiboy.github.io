+++
title      = "Raptor VS Mundo"
tags       = [ "regexp" ]
categories = [ "prog" ]
date       = "2017-08-19T14:20:56-05:00"
+++

(Ya que la forma en que presenta github los readme's no es apropiada para una
extensa tabla, he agregado la comparativa como una pagina (oculta e
independentista) del blog: [aqui](https://nasciiboy.github.io/raptorVSworld/))

Hace tiempo que no actualizaba la **"Performance comparison of regular
expression engines"**, una prueba que tome prestada de *dark100* (nick de
sourceforge) so-pretexto de poner a prueba la version en Go de mi motor pueril
de expresiones regulares (alias Recursive Regexp Raptor), al cual profeso apego,
alegria y frustracion por el tiempo inmensurable que le he invertido.

Una cosa que me incomodaba del codigo preexistente, es que las pruebas estaban
centralizadas en un unico fichero en C que aglutinaba todos los motores y
pruebas, y al no tener C "namespaces", tenia conflictos con la version 3 y 4 de
la libreria, ademas de limitar los lenguajes que podian participar en la prueba
solo a C y C++.

![](/img/Computer-Guy.png)

Como pues organizar el asunto para incluir las pruebas? deberian tener un
"formato" unificado para aceptar datos de entrada y entregar datos de salida de
igual forma, como la unica manera que conosco de enviar informacion a "cosas" (en
C, C++ y Go) es por medio de argumentos, pues eso hice, proponiendo la interfaz
generica para cada concursante asi:

    $ ./concursante sujeto-de-pruebas ciclos prueba-1 prueba-2 ... prueba-n

donde el *sujeto-de-pruebas* son los datos objeto de las pruebas, en este caso
y tratando de machacar a los motores de expresiones regulares, un archivo de
20MB de texto puro y duro en ascii con formato utf8 al estilo unix, es decir con
saltos `\n` que es la unica forma decente de indicar un salto de linea (que le
den por culo al resto de formatos de codificacion)

una vez echo esto, como demonios llamar e identificar las pruebas, te podras
preguntar, pues llamando a todas las pruebas `bin.syntaxis.concursante` con un script
de bash, me respondi. Donde `syntaxis` denota el estilo, pues esta la sintaxis
"estandar" de expresiones regulares (que es algo asi como el estilo perl
simplificado) y por el otro lado tenia *mi* sintaxis comoda con la que escribi
el raptor, ademas que, existia la posivilidad que algun motor incluido o a
incluir, tubiera su sintaxis propia.

Con bash, poco me he puesto, lo encontre lioso, limitado y lento, asi que
obtendria a los concursantes con un `ls` y luego haria un bucle sobre el
resultado pasando el nombre del archivo de pruebas, el numero de ciclos y las
pruebas en si. OohHH, como demonios pasar pruebas que tiene la sistaxis de
cadenas de C, con bash? respuesta corta luego varios intentos, pruebas y una
busqueda: `$'cadena-formateada-estilo-c'`

Dudas tenia, acerca de como se enviaban internamente los parametros desde el
interprete, hasta el programa y como comunicarlos entre si. Por esta razon,
decidi en enviar solo el nombre del fichero sobre el cual efectuar las pruebas y
que cada programa se las arreglara para cargarlo, en lugar de enviar un
parametro de 20MB.

Segundo problema, como gestionar los resultados? la otra cosa que se hacer mas
en C y Go es escribir en ficheros, lo cuales se llamarian
`result.syntaxis.concursante`, siguiendo el estilo anterior, asi el programa que
se encargara de examinar los dator sabria quien y con que sintaxis se hizo cada
resultado. El fichero en si, esta formateado como lineas con el formato

    tiempo-en-ms coincidencias prueba

nada que explicar, solo la prueba, que es la exprecion aplicada, pero si esta
contiene saltos de lineas, tabuladores y otros signos raros no joderian el
resultado? Si, antes de escribir al fichero deben ser "normalizarlos", je, que
ironico, el problema inverso a enviar los parametros...

Tercer dilema, Como compilar las pruebas? con otro script de bash que encuentra
y ejecuta los ficheros con el formato `compile.concursante.sh`, ya cada
"compile" sabra como hacer sus cosas para generar su binario. Por ejemplo, para
las librerias regex en C y C++, se limitar a invocar un makefile, y para los
programas en Go, van al archivo fuente, lo compilan con `go build` y mueven el
binario al directorio principal

El ultimo problema, Como gestionar la informacion resultante? pues leer cada
fichero `result.*`, cargar en un arreglo cada uno "por lineas", optener una
muestra del las pruebas utilizadas por su sintaxis, comprobar que cada fichero
tiene el mismo numero de pruebas para "emparejarlas" e iterar por cada linea en
cada fichero mientras se construlle una tabla en html

optener un listado de ficheros en el directorio con bash, sencillo es, con C
complicado y no portable, con Go intermedio. Como para los ultimos 2 tendria que hacer una
seleccion adicional en busca de los nombres correspondientes a las prubas,
decidi enviar el nombre de las pruebas como parametros al programa encargado de
generar la tabla.

Bash que es practicamente un desconocido para mi, no era ni de cerca una
alternativa, utilizar awk era una posibilidad, pero solo me he puesto con el lo
suficiente para saber que podria hacerse. Luego intente con C, pero abandone
pronto... Cuanto daño hacen las comodidades modernas... en C nunca me acostumbre a
pedirle memoria al sistema y liberarla despues.

Asi que el encargado de analizar los resultados, escrito en Go esta y
el script en bash que ejecuta las pruebas le envia cuales son estos resultados

Un problema que deberia solucionar en proximas versiones, es advertir que el
resultado se coloca en un fichero llamado `table` si todo va bien, y que antes
de correr las pruebas se eliminan todas los ficheros `result.*`, por que cada
programa en C, se limita a agregar lineas al final de estos. Almenos un triste
`echo 'all ok, see "table"'` o un `cat` al resultado

comentar que cuando un motor no es capas de realizar una prueba, deberia colocar
como linea de resultado `"---"` y/o ser invocado con `"---"`, con el fin de
preservar la "paridad"

## Extra

Hu, nunca me senti bien, ni con bash, ni con make, aunque este ultimo es util,
conveniente y poderoso, sin llegar a ser lo criptico que es bash

En el camino, el reencuentro con C fue duro, olvide muchos `;`, parentesis y
formato para declara variables, aunque al final ya habia recupenado algo de
confiansa, pero no la suficiente como para programarme el analizador de los
resultados, me gustaria algun dia analizar esto en profundidad, aunque creo que
me quedare un largo periodo con Go, quiza regrese si en algun momento escribo un
manual para hacer videojuegos o en un lejano futuro agrego un lenguaje
customizado a la larga lista de lenguajes que compiten por la supremacia

aunque todos los participantes (en C) comparten una "plantilla" comun, hizo
falta un kilo mas de refinamiento, por ejemplo en el manejo de errores, aunque
casi todo esta solventado, en cambio en Go, pase por alto esto en la libreria
estandar de expresiones regulares, y en el generador del resultado, donde (en
parte por cachondo) deje en un mapa las rexp que se utilizan, por lo que la
columna de exmpresiones en la tabla se ordena al "azar"

de momento conforme con el resustado estoy y no tengo prisa por modificarlo en
el futuro cercano, mucho tiempo y dedicacion requiere para hacerlo mas "pro",
como de bash y make, no controlo mucho seguro lo encontraran pobre, se aceptan
*pull request*

el repositorio contaba con una traduccion al español, con lo cual sumaban tres
versiones de lo mismo (readme.hmtl, readme.org y readme-es.org), sumando esto
con las cuatro versiones de la libreria raptor y sus correspondientes dos
readmes, cada uno con una copia de la tabla de resultados y como no es un
proceso que hubiera automatizado, me carge el readme en español, de este repo,
mucho tiempo requeria mantenerlo a mano, deberia recapacitar aceptando las
virtudes de bash

para finalizar, por el camino encontre varias maneras de hacer un benchmark en
Go, ya lo contare (o no) en otro post, oooohhh como nuevo proyecto la proxima
mision es investigar en las entrañas de la libreria estandar de GO `"regexp"` e
incorporar algunos de sus obsenos trucoso para alcanzar una velocidad abrumadora
en texto simple, morir de lentitud en expresiones igualmente simples y ser
estandar en el resto, espero no terminar frustrado
