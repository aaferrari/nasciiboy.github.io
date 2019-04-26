#include <stdio.h>

#define SIZE 10

void parray( int v[], int n ){
  int i;
  for( i = 0; i < n; i++ )
    printf( "%3d", v[ i ] );
}

void shellsort( int v[], int n ){
  int gap, i, j, temp;
  for( gap = n/2; gap > 0; gap /= 2 )
    for( i = gap; i < n; i++ )
      for( j = i - gap; j >= 0 && v[ j ] > v[ j + gap ]; j -= gap ){
        temp = v[ j ];
        v[ j ] = v[ j + gap ];
        v[ j + gap ] = temp;
      }
}

int main(){
  int v[ SIZE ] = { 9, 8, 7, 6, 5,
                    4, 3, 2, 1, 0 };

  parray( v, SIZE );
  putchar( '\n' );

  shellsort( v, SIZE );

  parray( v, SIZE );
  putchar( '\n' );

  return 0;
}
