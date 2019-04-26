#include <stdio.h>

#define  ON  1
#define OFF  0

/* reemplaza cada cadena de uno o mas blancos por un solo blanco */
main(){
  int c, space;

  space = OFF;
  while( ( c = getchar() ) != EOF ){
    if( space == OFF ){
      if( c != ' ' )
        putchar( c );
      if( c == ' ' ){
        space = ON;
        putchar( c );
      }
    }
    if( space == ON ){
      if( c != ' ' ){
        space = OFF;
        putchar( c );
      }
    }
  }
}


/* output
  1
 1
      1   2    3   5   4  5   6  4  8 7        9
 1 2 3 5 4 5 6 4 8 7 9
1        2      3  4 5 6   7 8  9              0
1 2 3 4 5 6 7 8 9 0
*/
