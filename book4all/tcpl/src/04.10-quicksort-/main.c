/* prueba el funcionamiento de qsort */
#include <stdio.h>

#define SIZE 10

int parray( int v[], int size ){
  int i;

  for( i = 0; i < size; i++ )
    printf( "%4d", v[ i ] );

  putchar( '\n' );
}

int main(){
  int v[ SIZE ] = { 7, 6, 1, 5, 0, 2, 9, 8, 4, 3 };
  void qsort( int v[], int left, int right );

  parray( v, SIZE );
  qsort( v, 0, 9 );
  parray( v, SIZE );


  v[ 0 ] = 7, v[ 1 ] = 6, v[ 2 ] = 1, v[ 3 ] = 5, v[ 4 ] = 0;
  v[ 5 ] = 2, v[ 6 ] = 9, v[ 7 ] = 8, v[ 8 ] = 4, v[ 9 ] = 3;

  parray( v, SIZE );
  qsort( v, 3, 9 );
  parray( v, SIZE );

  return 0;
}


/* output  $ gcc main.c qsort.c
   7   6   1   5   0   2   9   8   4   3
   0   1   2   3   4   5   6   7   8   9
*/
