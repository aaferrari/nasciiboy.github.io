+++
title      = "blackfriday"
tags       = [ "morg", "go" ]
categories = [ "prog" ]
date       = 2017-10-27T17:42:32-05:00
+++

![](/img/bf.jpg)

Durante la modificacion del morg, habia escrito esto junto con otras notas
vagas en una bitocora de abordo que trata de ser FIFO, aunque si no mantengo la
constancia comienza a crecer y crecer hasta volverse incomoda. Asi pues (y como
el post anterior) a despejar algunas de esas divagaciones

## Como (no) construir un parser para un lenguaje de marcas (ligeras)

con *morg* (parser y lenguaje de marcas ligueras inventado por yo) la
construccion al igual que casi todas mis mierdas, fue fruto de reinventar la
rueda + prueba y error constantes, tratando de mantener una cierta sencilles...
mientras la raices de la incertidubre sobre si el proyecto llegaria a ser
funcional o quedaria truncado por la ignorancia y malas deciciones de diseño
orientadas en su mayoria por la aleatoriedad, me consumen lentamente

una de las primeras deciciones luego de la mudanza a Go, fue trabajar con
strings o slices de bytes, los primeros son inmutables, peeero todas las
funciones que trabajan con documentos (de la libreria estandar y mas alla) optan
por utilizar slices de bytes.

En principo me parecio que los strings son mejor opcion, pues me aseguro de no
fastidiar lo que el usuario envie a el exportador, ademas que hacer recorridos
por la cadena mediante `range`s es muy sencillo, con el agregado de
soportar unicode.

Por el otro lado, trabajar con bytes, evita una conversion extra (de bytes a
strings) y supuestamente son mas eficientes, pero venido como soy de C, donde se
suponque que las cadenas constantes son mas eficientes, la duda sigue presente

Otro tema y creo que mas crucial es como recorer y diseccionar los
datos de entrada, opteniendo los supuestos componentes del lenguaje,
encabezados, parrafos, notas, resaltado, listas, definiciones, etc, y casi igual
de importante como organizarlos en una forma conveniente tanto para yo como
programador, como para yo como usuario del programa y de ser posible lanzar
advertencias cuando se localicen datos de entrada erroneos

ante tal reto y sin "documentos tecnicos" que conosca (o entienda), la unica
opcion en el corto plazo, no es otra que meterse a lo bruto con algun proyecto
de programacion que ofresca descaradamente su codigo a todo mundo, aqui es donde
entra la libreria [blackfriday](https://github.com/russross/blackfriday) de un
tal *russross* para parsear markdown, escrita en Go... lol, hace tiempo intente
con cosas en C y python... donde el codigo me resulto incomprensible...

## como lo hace russross

utiliza slices de bytes, en lugar de cadenas, buffers del paquetes `bytes` como
contenedores del resultado, tanto en llamadas internas como en los
*renderizadores* del documento parceado e igual que morg no regresa error
alguno, solo slices vacios (`nil`)

interesante es su parseo en si, asigno funciones con caracteres "centinela"
para identificar los objetos, envia el slice de datos a la funcion respectiva,
junto con la estructura del documento y esta almacena el resultado y regeresa la
longitud de bytes leeidos que se suponen forman parte del elemento

mas interesante, es que toma dos pasos de parseo sobre el documento, la primera
para normalizar el docuemento (quitar los saltos de linea a lo windows `\r\n`,
cosa que no hare por asco a windows y trabajar solo con saltos unix `\n`),
extraer referencias, normalizar bloques de codigo y copiar el resto tal cual,
todo byte a byte o a slices, en el buffer. El segundo reccorido por el documento
es para el parseo "serio" donde corta y renderiza el resto de cosas.

Me llama la atencion, que aunque utiliza `bytes.Buffer`, no los haga crecer
desde un inicio para disminuir las asignaciones de memoria, no es que sea
realmente necesario... je, optimizacion premutura, el mal!

otra desicion relevante toma cuando al llamar al parser del documento, hay que
enviarle un *renderizador* que es una interfaz con 31 funciones, la cual se
encarga en unica instancia de entregar el resultado como texto plano en forma de
slice de bytes, bueno, eficiente o practico? dificil saberlo, blacfriday entrega
un render para HTML y otro experimental para latex, aunque por la naturazela de
markdown dificimente sera satisfactorio, pero siendo markdown, un mero
*facilitador* de HTML, no hay necesidad de generar otra cosa que no sea HTML, un
poco futil ecuentro la cortecia de entregar "renders" en blackfriday, cuando el
parseo y exportacion van juntos, unidos, en las entrañas del parser.

En morg, no lo tenia (ni tengo) muy claro, en la primer version, el parser y el
render son entes separados, unidos solo por la estructura "organizada" que
entrega el primero, deje en manos del render hacer lo que le venga en gana con
la estructura, sin embargo, al cambiar constantemente esta, hay que hacer una
labor de actualizacion en los *n* renders, en *n* cambios, quiza un punto
intermedio vendria bien, para la siguiente version; que te entrege la estructura
en bruto y cuente con una interfaz que trabaje como plantilla de exportacion,
aunque, las sutilezas del lenguaje de marcado a exportar, vuelven a esto un
rigido inconveniente, pese a lo sencillo de definir unas cuantas reglas
genericas

creo que pandoc, cuando examina un docuemnto, lo convierte a una estructura
"maestra" y luego con ella ya se lo manda a sus renders, me siento mas comodo con esta
opcion, pero como aun no le hago al haskell, tendre que esperar para comprobarlo
de primera mano

## conclucion

tentado estoy a trabajar con bytes, aunque creo que trabajar con `bytes.Buffer`
no representa una gran mejora y obliga a incluir un paquete extra, je, je, tengo
algun complejo muuu grande con incluir librerias, aunque sean las estandar,
tengo un problema... repite tu mantra, esta en la libreria estandar, es bueno y
necesario, en la libreria estandar esta, necesario y bueno es usarlo

utilizar bytes, requiere modificaciones drasticas en regexp4 que solo maneja
strings, o un monton de conversiones de ida y vuelta.

que hacer? bytes y strings, dos caras de la misma moneda, separadas por la no
conversion de tipos automatica, para la ocultacion de cadenas como punteros, en
estas deciciones Go-leanas es cuando extraño a C, cuando aparecen estas
estructuras que no estoy seguro si se replican a cada copia/asignacion o
trabajan con los mismos datos de fondo

en resumen blackfriday (digo, luego de tres intentos por comprenderla hasta no
terminar de leer seriamente el TGPL), no era tan alien, ni complejo como parecia
en un principio, que esta furtemente atado a las limitaciones de markdown, al
igual que sus renderes y por ello no se ve forzado a implementar una estructura
que almacene el documento, pues no maneja elementos, anidados sobre elementos
anidados, sobre elementos aninados, peroooo dentro de sus limitaciones tecnicas,
hace bien su labor
