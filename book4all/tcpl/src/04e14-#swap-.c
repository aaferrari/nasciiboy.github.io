#include <stdio.h>

#define swap( t, x, y ) { t tmp = x; x = y; y = tmp; }

int main(){
  int x = 5;
  int y = 7;
  float w = 7.744;
  float z = 4.477;

  printf( "x = %d\n"
          "x = %d\n"
          "x = %.3f\n"
          "x = %.3f\n", x, y, w, z );

  swap( int, x, y );
  swap( float, w, z );

  printf( "x = %d\n"
          "x = %d\n"
          "x = %.3f\n"
          "x = %.3f\n", x, y, w, z );

  return 0;
}


/* output
x = 5
x = 7
x = 7.744
x = 4.477
x = 7
x = 5
x = 4.477
x = 7.744
*/
