#include <stdio.h>
#include <string.h>

int buf = 0;        /* buffer de un solo caracter                      */

int getch( void ){    /* obtiene un (posiblemente ya regresado) carácter */
  int tmp;
  if( buf ){
    tmp = buf;
    buf = 0;
    return tmp;
  } else return getchar();
}

void ungetch( int c ){ /* regresa carácter a la entrada */
  if( buf )
    printf( "ungetch: buf lleno\n" );
  else
    buf = c;
}
