+++
title      = "CAT"
tags       = [ "prog", "howto" ]
categories = [ "prog" ]
date       = 2018-03-23T21:41:50-06:00
+++

Hace tiempo, mucho tiempo, cuando iniciaba mis aventuras con C, tenia la urgente
necesidad de ingresar un "grafico" dentro de un arreglo de caracteres, el asunto
es que dicho grafico contenia por supuesto algunos caracteres "especiales" para
el propio C y en ese caso (segun mis primeras intuiciones) habia dos opcciones:
(1) escapar los caracteres o (2) colocar el grafico en un fichero y leerlo.

La primer opcion no me convencia, por que ensuciava el codigo desfigurando y
descuadrando el grafico. La segunda opcion aunque mas elegante,
requeria la lectura de un fichero externo a resguardo de quien sabe que
personaje de dudosas habilidades.

Asi pues, no recuerdo muy bien como, llegue a la siguiente solucion, que radica
en "romper" las macros del preprocesador de C.

cortar y pegar en un fichero (digamos `CAT.c`) o cliclar [aca](/data/CAT.c)


```
#include <stdio.h>
#include <string.h>

#define H 24
#define W 83
#define CAT( row, cont ) strcpy( &map[ row ][ 0 ], #cont )

int main(){
  char map[ H ][ W ];
  CAT( 0,"... ...         .........                   ........         ..............  ...");
  CAT( 1,"... .  ............      .............             ..........     ......      ..");
  CAT( 2,"............. _|      _|              ...     _|             ......   ..........");
  CAT( 3,"............. _|_|    _|    _|_|_|    _|_|_|  _|  _|      _|_|             .....");
  CAT( 4,"............. _|  _|  _|  _|    _|  _|_|      _|_|      _|_|_|_|           .....");
  CAT( 5,"............. _|    _|_|  _|    _|      _|_|  _|  _|    _|            ..........");
  CAT( 6,"............. _|      _|    _|_|_|  _|_|_|    _|    _|    _|_|_|   .............");
  CAT( 7,"..             .....                                         ........         ..");
  CAT( 8,"..            ..       ..  ...                 ..............                 ..");
  CAT( 9,"..  ...........         .... .............                                ......");
  CAT(10,"......                                         |                 |     .........");
  CAT(11,"......   __ \    __|  _ \   __|   __|     __|  __|   _` |   __|  __|       .....");
  CAT(12,"......   |   |  |     __/ \__ \ \__ \   \__ \  |    (   |  |     |       ..   ..");
  CAT(13,"......   .__/  _|   \___| ____/ ____/   ____/ \__| \__,_| _|    \__|        ....");
  CAT(14,"......  _|                                                            ....... ..");
  CAT(15,"....          . ............. .        ...............                      . ..");
  CAT(16,"....               ..          ........         ....  .....             ....  ..");
  CAT(17,".....          .....  .    _   _   _   _   _   _   ..        ... ...........  ..");
  CAT(18,".....   ........   ....   / \ / \ / \ / \ / \ / \   ........        ...       ..");
  CAT(19,".. ..            ...     ( b | u | t | t | o | m )         .    ................");
  CAT(20,".. . .       ....         \_/ \_/ \_/ \_/ \_/ \_/       .. ........          ...");
  CAT(21,".... .   .....  .....                            ........                  .....");
  CAT(22,".... .    .......              ................ ..    ..        ...........   ..");
  CAT(23,".... ..     ...............  ..........................   ......................");

  for( int i = 0; i < H; i++ )
    printf( ">>%.*s<<\n", 80, &map[ i ][ 1 ] );
}
```

Pueden compilar con `gcc -Wall CAT.c` y si sois incredulos, substituir `gcc` con `g++`,
`clang` o `clang++` que el compilador no va a lanzar ninguna alerta!

Como consideraciones especiales, el preprocesador **NO** escapara las comillas
al principio y final (por ello las columnas del arreglo tienen 2 caracters mas
(+1 del signo de terminacion `\0` que incluye `strcpy`)) y las comillas tienen que
ser pares.

podeis intentar con


```
  CAT( 0, """" );
  printf( ">>%s<<\n", &map[0][0] );
```

o tambien

```
CAT( 0, "\ \n\\" );
printf( ">>%s<<\n", &map[0][0] );
```

happy hacking!
