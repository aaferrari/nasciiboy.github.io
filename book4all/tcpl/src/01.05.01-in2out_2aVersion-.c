#include <stdio.h>

/* copia la entrada a la salida; 2a. versión */
main(){
  int c;

  while( ( c = getchar() ) != EOF )
    putchar(c);
}

/* output
a b c d
a b c d
a
a
1234567890
1234567890
*/
