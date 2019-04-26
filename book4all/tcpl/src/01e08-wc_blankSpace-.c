#include <stdio.h>

/* cuenta espacios en blanco (espacio, tabulador y nueva linea) */
main(){
  int c, bs;

  bs = 0;
  while( ( c = getchar() ) != EOF ){
    if( c == '\n' ) ++bs;
    if( c == '\t' ) ++bs;
    if( c == ' ' ) ++bs;
  }

  printf("%d\n", bs);
}

/* output
1
2
3
4
5
6
6
*/
