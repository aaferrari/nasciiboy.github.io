+++
title      = "AWK"
tags       = [ "howto" ]
categories = [ "prog" ]
date       = 2018-03-05T20:37:52-06:00
+++

AWK es un lenguaje de programacion diseñado para procesar datos basados en
texto.

El comando awk tiene la sitaxis

    awk CODIGO TEXTO-DE-ENTRADA

awk toma el texto de entrada y lo divide en *Registros* (por defecto lineas delimitadas
por `\n`) y estas a su ves se dividen en campos (por defecto una secuencia de
caracteres que no sean un espacio).

una ves awk recive la entrada, realiza un bucle secuencial por sus registros
(lineas) y a estos les aplica una orden que tiene la syntaxis

    condicion { accion }

estas ordenes, pueden agruparse en una sola linea separandolas con punto y coma

    condicion_1 { accion_1 }; condicion_2 { accion_2 }; condicion_3 { accion_3 };

o con saltos de linea,

    condicion_1 { accion_1 }
    condicion_2 { accion_2 }
    condicion_3 { accion_3 }

## condicion

la condicion para ser positiva simplemente debe ser distinta a cero. Si esto es
asi y no se especifica una accion, por defecto se imprime el registro
actual con un salto de linea al final. Por ejemplo:

    $ printf "registro uno\nregistro dos\nregistro tres" | awk '1'

produce

    registro uno
    registro dos
    registro tres

si cambiamos la condicion por una cadena de caracteres, por ejemplo `awk '"cadena"'`, el
resultado seria identico, ya que una cadena tambien es <q>distinta a cero</q>

Ahora, los registros de awk se dividen en campos y estos pueden "invocarse" como
`$1` (primer campo), `$2` (segundo campo), `$3` (tercer campo) y asi
sucesivamente. Si el campo no existe, sera una cadena de caracteres vacia. El
campo `$0` contiene registro en si mismo (la linea)

Bien? Pues podriamos utilizar un campo especifico para compararlo con una cadena, de la
siguiente forma

    $ printf "registro uno\nregistro dos\nregistro tres" | awk '$1 == "registro"'

para de nuevo producir el resultado

    registro uno
    registro dos
    registro tres

por si no fuera suficiente, podemos comparar cada registro con una expresion
regular, asi:

    $ printf "registro uno\nregistro dos\nregistro tres" | awk '/re..stro/'

donde la seccion comprendida entre `/` y `/` vendria a ser la expresion
regular.

A continuacion tenemos un ejemplo mas elaborado aplicando la comparacion con dos
expresiones regulares unidas en una condicion OR:

    $ printf "registro uno\nregistro dos\nregistro tres" | awk '/uno/ || /dos/'

produciria

    registro uno
    registro dos

tambien podemos hace una busqueda de una expresion regular dentro de una cadena
con la sintaxis `"cadena" ~ /regexp/`... y por supesto esta cadena bien puede
ser un campo

    $ printf "registro uno\nregistro dos\nregistro tres" | awk '$2 ~ /^[a-z]{3}$/'

## accion

en la *accion* se permite especificar un variado numero de caracteristicas
propias de un lenguaje de programacion, como pueden ser condiciones `if`, bucles
`for`, `while`, `do-while`, declaracion de variables, asignaciones, invocacion a
funciones (nativas de awk y creadas por el usuario) y demas cosas magicas,
misticas y misteriosas como leer del teclado, leer ficheros o invocar comandos
del sistema

cuando se declara una accion "solitaria" se asume que la condicion es verdadera

    $ printf "registro uno\nregistro dos\nregistro tres" | awk '{print $2}'

imprimiria los campos dos de cada registro en una linea propia

    uno
    dos
    tres

por su parte con

    $ printf "registro uno\nregistro dos\nregistro tres" | awk '{print $2 " " $1}'

se invertiria el orden de los capos de entrada en la salida

    uno registro
    dos registro
    tres registro

si la funcion `print` no recive parametros, imprimiria el registro en si

## BEGIN & END

awk cuenta con dos "condiciones" especiales que permiten realizar acciones antes
de que inicie el bucle por los registros (condicion `BEGIN`) y despues de que
este termine (condicion `END`)

    $ printf "registro uno\nregistro dos\nregistro tres" | awk 'BEGIN{print "inicio – invirtiendo entrada"};END{print "inversion finalizada"};{print $2 " " $1};'

produce

    inicio – invirtiendo entrada
    uno registro
    dos registro
    tres registro
    inversion finalizada

el orden de las condiciones `BEGIN` y `END` no tiene importancia... a menos que
se declaren mas de una vez, en cuyo caso se evaluaran segun aparescan

## ficheros

a medida que el *codigo* enviado a awk aumenta de complejidad podemos colocarlo
en un fichero e indicarle a awk donde se encuentra el codigo de la forma

    $ awk -f fichero-de-codigo entrada-de-texto

## scripts

tambien podemos crear un script en si, al que "enviar" la entrada. Por ejemplo:

```
#! /usr/bin/awk -f

# esto es un comentario
# aqui el inicio
BEGIN{print "inicio – invirtiendo entrada"}

# aqui la(s) condicion(es)
{print $2 " " $1}

# aqui el final
END{print "inversion finalizada"}
```

colocado en un fichero de nombre "prueba.awk", se invocaria como

    $ ./prueba.awk entrada-de-texto

o

    $ printf "registro uno\nregistro dos\nregistro tres" | ./a.awk


(*NOTA* awn se encuentra en `/usr/bin/awk` y/o `/bin/awk`)

## un simple sumador de campos

```
#! /usr/bin/awk -f

# esto es un comentario
# aqui el inicio
BEGIN {
    campo_a = 0
    campo_b = 0
    print "----- -----"
}

# aqui la(s) condicion(es)
{
    printf( "%5d %5d\n", $1, $2 )
    campo_a += $1
    campo_b += $2
}

# aqui el final
END {
    print "===== ====="
    printf( "%5d %5d\n", campo_a, campo_b )
}
```

un ejemplo de uso

    $ printf "1 3\n2 6\n3 9\n4 12" | ./a.awk

produce

    ----- -----
        1     3
        2     6
        3     9
        4    12
    ===== =====
       10    30

## miscelanea

canbiar la variable interna `IGNORECASE` a un valor distinto de 0, proboca que
awk ignore la diferencia entre mayusculas y minusculas


la funcion interna `sub(a, b)` busca la primer coincidencia con una cadena, numero o regexp en el
registro actual (`a`) y la substituye por un numero o cadena (`b`)

la funcion interna `gsub(a, b)` tiene los mismos parametros de `sub` solo que se realizan
substituciones *para todas* las coincidencias

una forma rudimentaria para capturar agrupaciones dentro de un array (solo gawk)

    gawk 'match($0, pattern, ary) {print ary[1]}'

ejemplo:

    printf "abcdef\nbkhtne" | gawk 'match($0, /b(.*)e/, a) {print a[1]}'

una forma de iterar por los caracteres de un registro/cadena

```
{
  split($0, chars, "")
  for (i=1; i <= length($0); i++) {
    printf("%s\n", chars[i])
  }
}
```

iterar sobre los campos

```
{ for( i=1; i<=NF; i++ ) print "linea:" NR ":campo:" i ":" $i }
```

## enlaces y cosas

- [AWK paso a paso... y sin usar el ratón](http://web.archive.org/web/20060622132928/http://www.linux-es.org:80/art.php?id=206)
- [El lenguaje de programacion awk/gawk](http://xavi.ivars.me/arxius/manuals/awk/manual_awk.pdf)
- https://es.wikipedia.org/wiki/AWK
- https://stackoverflow.com/questions/2957684/awk-access-captured-group-from-line-pattern

un "juego" escrito en awk:

    $ git clone https://github.com/TheMozg/awk-raycaster
    $ cd awk-raycaster

    # reducir el tamaño de los caracteres de terminal hasta que se vea bien
    $ awk -f awkaster.awk
