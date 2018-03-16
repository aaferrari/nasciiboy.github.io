+++
title      = "Raptor Down"
tags       = [ "regexp" ]
categories = [ "prog" ]
date       = 2017-10-27T16:58:55-05:00
+++

![](/img/rocky.jpg)

## El Conteo Final

De los pocos proyectos presentables que tengo, la libreria de expresiones
regulares (estilo) "raptor" contiene lo suficiente de mi... que aun si el
fastidio se presentara mañana y dejara de programar, seria suficiente para
sentirme satisfecho

incluso inclui algunas caracteristicas "avanzadas" (no regexp) de otros motores,
por ejemplo una exprecion `texto.*mas-texto` en *raptor* era
`texto(mas-texto)*#!mas-texto`, algo que denomine como <q>negacion de
expresiones</q>

perooo, la negacion de expresiones requeria romper con la sencilles de la libreria (o
motor o como se diga). Tenia la ambicion de encontrar una forma de simplificar
las caracteristicas avanzadas de otros proyectos a la vez que incrementaba su
rendimiento. Con esta idea en mente, me dispuse a examinar el motor de
expresiones regulares que forma parte de la libreria estandar del lenguaje de
programacion Go, intentando desde luego alcanzar la grandeza...

## Gore

Casi por norma general ocurre que me adentro en un proyecto ajeno y me pierdo
entre dependencias y recorridos entre un fichero a otro, mientras trato de hacer
una imagen global de lo que esta pasando. Pese a que en Golang mi orientacion es
superior que en C, o C++, me perdi bastante, aunque llege a apreciar que el parseo
no ocurre en el paquete principal de codigo, si no que sucede en otro "de
sintaxis", donde tambien se realiza una *simplificacion* del recorrido de las expresiones.

Los resultados de transformar la expresion en algo util se depositan en una
estructura, que tiene un arreglo con todos los datos necesarios y un arreglo de
sub-expresiones o sea punteros del mismo tipo para cuando se requiere por
ejemplo en agrupaciones, alternacion y conjuntos, agrupar expresiones dentro de
otras expresiones

La optimizacion, de la expresion regular, se realiza revizando caso a caso los
elementos que tiene la expresion y se siplifican cuando es posible cambiando el
tipo de subexprecion por otro, eliminando anidamiento o agrupando varias
expresiones como una sola

Una vez compilada la regexp, la busqueda (que no entendi muy bien) ocurre mas
que por iteracion por la cadena de ingreso, mediante operaciones especificas
considerando cada valor, posicion y tipo de la expresion, por ejemplo si debe buscarse al
inicio o al final, si es una expresion de tipo cadena, un conjunto, y luego
mediante funciones con la libreria `strings` se realiza el trabajo sucio de los
casos sencillos

## Say, Goodbay

imaginaba que encontraria algo por el estilo, al examinar (o mejor dicho intuir
pues no llegue a enterder) un motor regexp *serio*.

La libreria regexp estandar es por decirlo de algun modo una fabrica con muchos
empleados especializados en una labor pequeña sin nungun glamour ni emocion, un
monton de trabajo manual automatizado convertido a codigo, je, je, je, yo queria
encontrar algo mas del estilo de la fabrica le willy wonka, con un rio de
gominolas y Oompa-loompas cantores

veo a las expresiones regulares como un sistema conformado de (por decir) 3
reglas con el que se pueden generar patrones de complejidad y extencion
arbitrarios para casos de uso asombrosos aunque limitados. En contraste, las
expresiones (no) regulares actuales extienden estas normas incrementando la
complejidad a cambio de perder la "elegancia", hay belleza hay? el codigo debe
ser bello?

en este punto, se me acurasara (seguro con razon) de cazador de lo paranormal,
como quien se creee una religion y busca significados ocultos sumando las letras
de mil formas distintas hasta estar agusto. Con todo, asi es como veo el codigo,
como algo que tiene que ser sencillo y con belleza o al menos intentar aproximarse

un tanto desilucionado, regrese a mi motor y lo despoje de la caracteristica
esoterica `#!`, con lo cual se redujo la complejidad a su expresion mas simple y
gano algo de rendimiento en las [pruebas](https://nasciiboy.github.io/raptorVSworld/index.html),
entre 500 y 1000 milisegundos en cada competencia, y en algunos
casos aislados, el tiempo se redujo a la mitad, hubo que renunciar a dos
expresiones donde ahora aparece un **N/A**, pero aun asi, el rendimiento en
general, es suficiente como para substituir honradamente a la libreria estandar

Es momento de decir adios al raptor, bueno, no, lo seguire utilizando en mis
programas y como prueba de programacion con cada nuevo lenguaje que intente, hay
motores mucho mas eficientes, con mas caracteristicas, trabajo y complejidad,
cuando necesite de su poder los usare, cuando no tirare del raptor y si hace
falta eficiencia, a programar a mano

Supongo que con el nuevo panorama podria hacerme responsable y terminar la
escritura del **manual para escribir un motor de expresiones regulares sin tener
ni idea**, alias *Raptor-book*

Ohh, modifique el resto de la familia de versiones, regexp 3 y 4 en C
y la version 3 en Go, pero sin mucho empeño ni comprobaciones mas alla de las
que estaban en las pruebas, jo, es complicado mantener el nivel cuando hay que
modificar lo mismo 6 veces en dos lenguajes, por el camino, tambien desaparecio
un bicho en patrones con agrupaciones que se presentan al final de una
expresion de una manera que no alcanzo a entender... si funciona y aprueba, que
mas da!
