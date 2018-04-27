+++
title      = "IntroARM"
tags       = [ "asm", "arduino" ]
categories = [ "prog" ]
date       = 2018-04-19T18:36:32-05:00
+++

**"Introducción a la arquitectura de computadores con QtARMSim y Arduino"** es
un libro que encontre (el año pasado) en [openlibra](https://openlibra.com/es/book/introduccion-a-la-arquitectura-de-computadores-con-qtarmsim-y-arduino)
cuya insulsa portada (como casi todo lo de openlibra) oculta un material
bastante didactico (je, esto ultimo a consideracion... respecto a los otros
titulos de openlibra), ameno, directo e
interesante sobre la arquitectura de computadoras.

El libro centra su atencion en la arquitectura ARM de 32 bits desplegando
ejemplos en ensamblador (instrucciones Thumb Cortex-M0 estilo GNU) y luego
aplicando (mas o menos) practicamete los conocimentos sobre la placa
[Arduino Due](https://www.arduino.cc/en/Guide/ArduinoDue) [ATSAM3X8E]... para
encender y apagar un led! (esto es si es un "hello word" bien rudo!)

![](/img/ArduinoDue.jpg)

En realidad, ni el asm, ni la placa arduino tienen mucha importancia pues no
dejan de ser un conducto para mostrar los entresijos y filosofias relacionadas
con el funcionamiento conceptual de los procesadores, su programacion y luego
mas tarde su interaccion y gestion con dispositivos de entrada y salida
varios. De hecho, y aunque el ensamblador que nos muestra el libro es bastante
bonito (quitando su manera extrabagante de pasar datos de memoria a los registros y
viceversa), en todo el libro, no se expone ninguna razon para utilizar
ensamblador, mas alla (claro esta) de poder ver su funcionamiento en vivo y a
todo c-o-l-o-r.

y bueno, el libro, codigo y herramientas necesarias para su estudio se
encuentran en la siguiente direccion (oficial): http://lorca.act.uji.es/libro/introARM/

para que la programacion en asm no quede como un ejercicio autista donde
tenemos que imaginar que esta pasando, se propone utilizar una interfaz grafica
de un emulador de arm (`spim`) llamada [QtARMSim](http://lorca.act.uji.es/project/qtarmsim/)

segun las intrucciones de la pagina tendriamos que seguir los siguientes pasos
para hacernos con "los programas"(, o asi los hice yo):

    apt install gcc-arm-linux-gnueabi
    apt install python3-pyside python3-pip ruby spin
    pip3 install qtarmsim

    # si se quiere actualizar
    # pip3 install --upgrade qtarmsim

... es curioso, como un libro centrado en asm y que en sus propias paginas
expone la necesidad de hacer que la interaccion del usuario con un programa
tiene que ser practica, tubieron la brilante idea de implementar el entorno
grafico utilizando (asqueroso) python... no es que la interfaz sea fea, cargada
o innecesaria ni mucho menos (mi mas sincera alabanza), sino que a la hora de interactuar con el editor de
texto incorporado, el lag puede ser insufrible (puto python). Otra cosa curiosa
del p-y-t-h-o-n, ocurre cuando instalas sus mierdas y luego al ejecutarlas en lugar de
"interpretar" los programas, te aparecen sendos mensajes de error, como me
sucedio en freidora 27. Tras varios intentos, apaños y busquedas por internet,
la solucion menos dolorosa fue utilizar una maquina virtual con debian e ir a
probar suerte...

no veia muy claro eso de instalar virtualbox, asi que por mera investigacion
prove con `gnome-boxes` (que ya venia instalada). Baje la iso estable
(DVD|torrent) de debian 9.4.0 y segui la sujerencia de gnome-cajas en hacer una
instalacion rapida (o algo asi). Aproximadamente 15 minutos mas tarde,
unicamente ingresando el nombre de usuario, contraseña y dimencion de la
particion, tenia un debian fluido y eficiente corriento con 2 procesadores,
21GiB de disco y 1GiB de ram (con Gnome Shell) consumiendo ~500MiB de ram y muy
poco consumo de procesador... hasta mover-una-ventana-con-el-raton-a-lo-loco!

me sorprendio lo rapido que arranca una maquina virtual en (quemu) boxes, lo
ligerita que va, e igualmente lo rapido que se apaga. Como puntos negativos dire
que la captura del teclado nunca se hizo presente y que fue necesario
reconfigurar el teclado en la maquina virtual (a programmer dvorak), porque
venia en ingles; asi que todo lo ingresado estaba mal, mas al contar con un
portapapeles (de texto) compartido se puede escribir en la maquina anfitrion
e ir a pegar (con tecla de opciones(?)) en cualquier lado.

pero bueno, todo esto no era sobre gnome-boxes, era sobre el libro. Tras probar
que el entorno funcionaba sin inconveniente alguno sobre debian y que el entorno era
intuitivo y despliga la informacion suficiente y de manera comoda, continuemos con la
travesia.

Los ejercicios en ensamblador son pequeños, claros y lo suficientemente
explicados como para no perderse. Hecho en falta que en la pagina oficial, no se
incluya un comprimido con el codigo en ensamblador del libro, asi que
[aqui](/data/asm-code.zip) esta una compilacion en zip.

A diferencia de lo que comentaba sobre el post del tutorial del
[z80-speccy](../z80-spectrum/) en este material se dedican varias secciones a
explicar estrategias y convenciones sobre el paso de parametros entre las
subrutinas. Ademas, como no podia ser de otra manera, el procesador y su
capacidades tambien evolucionaron. En este procesador tenemos 16 registros
ortogonales de 32 bits

- r0-r3  > paso y recivo de parametros a subrutinas
- r4-r12 > libres para el programador
- r13    > SP (puntero de pila)
- r14    > LR (registro enlace)
- r15    > PC (putero del programa)

las instrucciones son menos complejas que las del z80, vastante mas comodas como
`add rn, rn, rn` donde se pasan dos registros a sumar y un registro donde
depositar el resultado. Otro ejemplo seria la intruccion de uso de la pila `push
{rn, rn, rn-rn}` y su complemento `pull {rn, rn, rn-rn}` que no solo puede pasar
mas de un registro, tambien un rango entero de registros, wouau puro rock-and-roll!

como comentaba al inicio, aun tomando la lectura sin intenciones de aplicar sus
enseñansas codificadoras, el enfoque didactico es muy estimulante para el que
tenga interes en conocer los entresijos rugosos de un "computador", que por aca
ni se mitifica, ni se espanta al lector con leyendas medievales de complejidades
imposibles (como muchos hacen con los niñatos y les dicen que p-y-t-h-o-n "es
bonito y facil", ha, una guerra es lo que les hace falta)

La segunda parte del material continua su labor didactica ahora mostrando como
interactua el procesador con el mundo. Tambien pasa bastante tiempo liandola con
el ensamblador y el arduino, mas, no termino de enterarme a cuenta de
que. Aunque me parece genial que se pongan a educar sobre el asm, el arduino y
su entorno no tienen pinta de estar prestos a liarse a programar en otra cosa
que no sea C/C++, pero bueno, tampoco es que me enoje ni nada similar... (por
que, no tomar una consola de videojuegos arm como conducto?... si la hay... o
es que no...)

de esta parte del libro, destaco las secciones de interrupciones y conocer al
(voz cavernosa y con eco) **DMA** (/voz cavernosa y con eco) (Direct Memory Access)

finalmente, el ultimo tercio del liblo, esta formado por una referencia (muy)
tecnica de las E/S, el reloc e interrupciones disponibles en el arduino. Luego
un par de resumenes del asm y tambien la infaltable seccion de sistemas de
numeracion, para finalmente cerrar con indices y cosas de libros

Ahora, como con el tutorial del z80, muestran como declarar if's, else's, for's y
while's, pero donde esta el siempre amado y necesario **`switch`**?

Para terminar, en open libra hay un material mas o menos relacionado, con un
temario algo similar [ARM Cortex-M práctico: Introducción a los microcontroladores STM32 de St](https://openlibra.com/es/book/arm-cortex-m-practico-introduccion-a-los-microcontroladores-stm32-de-st)
que va mas de C. Tiene el pecado de aplicar sus enseñansas sobre aplicaciones
ventaneras, pero rescato su explicacion sobre las ramas de los procesadores
ARM.

Si os gustan los libros, ir a openlibra, poner 5 estrellas, like & subscribe
