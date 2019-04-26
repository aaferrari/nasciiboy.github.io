#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

char buf[BUFSIZE];    /* buffer para ungetch */
int bufp = 0;         /* siguiente posición libre en buf */

int getch( void ){    /* obtiene un (posiblemente ya regresado) carácter */
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch( int c ){ /* regresa carácter a la entrada */
  if( bufp >= BUFSIZE )
    printf( "ungetch: demasiados caracteres\n" );
  else
    buf[ bufp++ ] = c;
}

void ungets( char s[] ){
  int i = strlen( s );
  while( i && bufp < BUFSIZE ) buf[ bufp++ ] = s[ --i ];

  if( i ) printf( "ungets: demasiados caracteres\n" );
}
