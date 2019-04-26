#include <stdio.h>
/* cuenta los caracteres de la entrada; 1a. versión */
main(){
  long nc;
  nc = 0;

  while( getchar() != EOF ) ++nc;

  printf( "%ld\n", nc );
}

/* output
1234567890
11
*/
