#include <stdio.h>

/* cuenta los caracteres de la entrada; 2a. versión */
main(){
  double nc;

  for( nc = 0; getchar() != EOF; ++nc )
    ;

  printf( "%.0f\n", nc );
}

/* output
1234567890
11
*/
