/* verificacion de valor resultante para lo exprecion getchar() != EOF */
#include <stdio.h>

main(){
  int c = getchar() != EOF;

  printf( "la exprecion getchar() != EOF regresa: %d\n", c );
}


/* output
a
la exprecion getchar() != EOF regresa: 1
*/

/* output
la exprecion getchar() != EOF regresa: 0
*/
