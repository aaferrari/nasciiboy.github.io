#include "syscalls.h"

/* getchar: entrada de un caracter simple sin buffer */
int getchar( void ){
  char c;

  return (read( 0, &c, 1 ) == 1) ? (unsigned char) c : EOF;
}
