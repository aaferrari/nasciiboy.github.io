#include <stdio.h>

#define SIZE 10

int getfloat( float * );

int main(){
  float a[ SIZE ];
  float tot;
  int i;

  for( i = 0; i < SIZE && getfloat( &a[ i ] ) > 0; i++ );

  tot = 0;
  while( i-- ) tot += a[ i ];

  printf( "tot = %f\n", tot );

  return 0;
}


/* output  $ gcc -Wall main.c getfloat.c getch-ungetch.c
10.5 10.05 -1 1.005
tot = 20.555000
*/
