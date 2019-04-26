#include <stdio.h>

/* copia la entrada a la salida; 1a. versión */
main(){
  int c;

  c = getchar();
  while( c != EOF ){
    putchar( c );
    c = getchar();
  }
}

/* output
a b c s d
a b c s d
a
a
1234567890
1234567890
*/
