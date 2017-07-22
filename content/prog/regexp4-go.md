+++
categories = ["prog"]
date = "2017-07-15T21:36:03-05:00"
draft = true
tags = ["regexp"]
title = "regexp4-go (dia cero)"

+++

![](/img/regexp4.png)

**regexp4** es un "motor" de expresiones regulares de la familia de los motores
regulares *Recursive Regexp Raptor*, o expresado de otra forma: una libreria de
expresiones regulares hecha desde cero, reinventando la rueda (o no) de la
manera (que para mi es la) mas simple posible. sin arboles de evaluacion, ni
liberacion de memoria, ni cosas raras o esa es la intencion, almenos de las
versiones en **C**

cual es entonces la necesidad de que exista esta version en go, podrias
preguntar. Pues segun mi escasa educacion programacional, la simplesa de los
motores raptor es tal, que pueden implementarse en cualquier lenguaje sin recurrir
a ninguna caracteristica no implementada en el lenguaje en si, es decir, sin
recurrir a ninguna libreria, incluyendo a las librerias estandar.

Siguiendo esta creencia (quiza sin fundamentos) y a modo de prueba de las
caracteristicas de un lenguaje de programacion supongo que hare una costumbre
programar un raptor en cada ocacion que pueda. Ademas el modelo raptor aunque
bastante desarrollado no es perfecto, asi pues, con cada nuevo concepto
aprendido, logro profundizar un poco en busca de una mejor implementacion o el
incremento de caracteristicas segun las facilidades que otorgue el lenguaje

existen dos versiones de la libreria las regexp3 donde a cada iteracion
valiendose de la recursividad, la expresion regular se convierte en
instrucciones que pueden evaluarse. En las regexp4 en lugar de interpretar la
regexp a cada paso primero se "compila"... lo que la hace comporativamente mas
eficiente

la libreria parte de la version en C y la sintaxis es compatible con esta
version en Go, pero por algunas facilidades que proporciona nativamente este
ultimo lenguaje y por su orientacion a objetos esta no tiene limitacion (que no
sean de hardware) del numero de capturas, la longitud y complejidad de la
expresion y ademas es concurrentemente segura

bueno, bueno, vamos con los detalles morbosos... esta version adapta sin mucho
empeño la regexp3 (go) a la version 4. Fueron necesarios varios dias con poco
enfoque donde los momentos de lucides escaceaban, primero aparecio un bicho por no
incrementar un indice del que tarde dos <s>dias</s> sesiones en darme cuenta y
luego por otras 4 seciones las pruebas que contenian "conjuntos" (`[...]`) se
resistian a funcionar, jo, el problema fue no colocar las constantes correctas
dentro de un `switch`, je, por un momento me planteee hacer pruebas de cada
una de las funciones hasta asegurar que todas hicieran lo que se suponia deberia
de hacer... lo cual no es trivial

aunque en apariencia sencilla, cada uno de los componentes esta obscuramente
relacionado, y debe realizar su tarea en perfecta armonia con los demas, por
ello es necesario ponerse en serio con el asunto, y ya que esto escapaba un poco
de mi control, solo me limite a ejecutar las pruebas preexistentes y tambien a
comprobar el funcionamiento con *morg*, asi pues una vez superadas las pruebas,
pese a no estar muy seguro de como "interactuava" la maquinaria, confie en las
muchas horas invertidas en la version en C y otras tantas en regexp3 en Go,
luego subi el repositorio a modo de respaldo

Como antes mencione la sistaxis de la regexp es uniforme en todas las versiones,
ademas regexp3 (Go) y la presente compartiran la misma "*API*", mas esta version
sera extendida con un par de funciones mas (tentativamente) `Compile` y
`TextMatch` (o algo asi), aprovechando las capacidades de "compilacion" (tambien
programado de cero) en una forma singular a la que nombre "*tabla de
instrucciones*" y en esta ocacion pretenciosamente las instrucciones de la tabla
lleban el prefijo `asm`

en fin, [aqui](https://github.com/nasciiboy/regexp4/) encontraran el
repositorio, los *readmes* son un copia y pega de la version regexp3 cambiando
el 3 por 4

happy hacking!
