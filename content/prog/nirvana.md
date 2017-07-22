+++
categories = ["prog"]
date = "2017-04-20T11:54:03-05:00"
draft = true
tags = ["morg"]
title = "Nirvana"

+++

![](/img/katana-0.png)

**hu! ha!**, imparable el proyecto de programacion morg (nombre temporal) es (o
no), mientras tanto y a modo de respaldo (por si en algun momento me convierto
al lado privativo de la fuerza...) les presento las ultimas novedades
codificadas del proyecto

Primero se agrego **katana** que conceptualmente se encarga de parsear/cortar el
texto plano formateado, y regresar una estructura convenientemente estructurada
que facilita cualquier labor a realizar.

Dentro de la estructura se enucuentran los datos del documento y opciones,
ademas de un arreglo de **nodos**, llamado `Toc` donde cada elemento es un
encabezado (de cualquier nivel) que contiene los parrafos, listas, abouts,
tablas, comandos, etc.

Luego se agrego **nirvana** (nombre temporal) que conceptualmente se encarga de
desplegar visualmente los documentos. Al momento de escribir esto, solamente hay
un poco de codigo que muestra el documento en terminal.

Creo que este componente terminara por desaparecer, o incorparese de otra
manera, en fin...

Finalmente para que funsionase **nirvana** era necesario poder dibujar cosas en
terminal, siguiendo la <q>Canonical Way</q> tome codigo de internet (termbox-go)
sobre el cual edificar mi propia libreria de manejo de terminal, con casinos y
colegialas japonesas! el nombre? **tui** (text user interface) que esta
fuertemente impirado en ncurses, pero con un poco de orientacion a objetos

Ahora, la integracion entre **nirvana** y **tui** fue compleja, pues aun con el
documento parseado (katana), la interaccion entre el formato y su tratamiento a
<q>imagen</q> no es un asunto trivial, lo que termine haciendo fue agregar
interpretacion directa del formato en **tui** con un objeto llamado `Pad`

Bueno, bueno, estos son temas para charlas directas o libros extensos (escritos
por gente competente), el codigo esta echo al vapor con porciones grandes de
espageti, es decir, es un lio, aunque tiene un regusto, que deja la impresion de
llegar a ser algo molon algun dia en un futuro proximo.

Libero esta prematura version, con motivo de poder mostrarla en una sede del
flisol, para agregar o convencer, a seres que se una al proyecto.

No deja de ser una prueba de concepto. Muchas caracteristicas no fueron
implementadas, con otras no se que hacer para la version de terminal
(imagenes/videos), ademas la libreria grafica presenta algunos "artefactos"
ocacionalmente, creo que debidos al unicode.

Con todo, me sorprende el resultado, aun con la libreria de expresiones
regulares hecha en casa, la lectura del fichero, el parseo, transformaciones y
visualizacion, un documento que en pdf abarca casi 600 paginas, se despliega en
terminal en cerca de 2 segundos (sin programacion paralela, que de eso, aun no
conosco), alucinante! esta es la razon por la que utilizar lenguajes de
scripting es un error, el <q>desarrolla rapido, ejecuta lento</q> es un
desproposito! todo programa debe aspirar a la grandeza, a la eficiencia y ser
veloz!

oh, modifique un poco el comando. Ahora se utiliza `morg export
mi-documento.morg` para convertir del funte a html y `morg tui
mi-documento.morg` para mostrar el documento en terminal

si aun no tienen instalado morg, pero ya cuentan con go

```
go get -v github.com/nasciiboy/morg
```

o si ya lo tienes, para actualizar

```
go get -u -v github.com/nasciiboy/morg
```

(nota: aun no actualizo los readmes de proyecto, quiza en un par de dias)

me gustaria decir **Happy Haking**... pero ni el codigo, ni el formato estan aun
definidos por lo que trabajar en ellos en este momento puede ser (o no) una
perdida de tiempo... veanlo como un adelanto del 🌈futuro🌈

## Mooo

![](/img/katana-1.png)

unas **capturas** del invento en accion

![](/img/katana-2.png)

![](/img/katana-3.png)

![](/img/katana-4.png)

![](/img/katana-5.png)
