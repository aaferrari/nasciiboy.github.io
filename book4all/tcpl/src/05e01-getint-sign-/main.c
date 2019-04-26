#include <stdio.h>

#define SIZE 10

int getint( int * );

int main(){
  int a[ SIZE ];
  int tot;
  int i;

  for( i = 0; i < SIZE && getint( &a[ i ] ) > 0; i++ );

  tot = 0;
  while( i-- ) tot += a[ i ];

  printf( "tot = %d\n", tot );

  return 0;
}


/* output  $ gcc -Wall main.c getint.c getch-ungetch.c
10
10
+10
++
tot = 30
*/
