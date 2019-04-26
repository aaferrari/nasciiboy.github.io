#include "syscalls.h"

/* getchar: version con buffer simple */
int getchar( void ){
  static char buf[ BUFSIZ ];
  static char *bufp = buf;
  static int n = 0;

  if( n == 0 ){  /* el buffer esta vacio */
    n = read( 0, buf, sizeof buf );
    bufp = buf;
  }

  return ( --n >= 0 ) ? (unsigned char) *bufp++ : EOF;
}
