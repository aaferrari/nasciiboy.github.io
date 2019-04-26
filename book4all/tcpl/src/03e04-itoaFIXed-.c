/* itoa: convierte n a caracteres en s */
/* reverse: invierte la cadena s en el mismo lugar */
#include <stdio.h>
#include <string.h>
#include <limits.h>

void reverse( char s[] ){
  int c, i, j;
  for( i = 0, j = strlen( s ) - 1; i < j; i++, j-- ){
    c = s[ i ];
    s[ i ] = s[ j ];
    s[ j ] = c;
  }
}


void itoa( int n, char s[] ){
  int i;
  unsigned x = ( n < 0 ) ? -n : n;

  i = 0;
  do {   /* genera digitos en orden inverso     */
    s[ i++ ] = x % 10 + '0';  /* toma el siguiente digito */
  } while( ( x /= 10 ) > 0 ); /* borralo                  */
  if( n < 0 )
    s[ i++ ] = '-';
  s[ i ] = '\0';
  reverse( s );
}


int main(){
  int i;
  char s[ 12 ];

  for( i = 0; i < 10; i++ ){
    itoa( i, s );
    printf( "n = %d - s = %s\n", i, s );
  }

  for( i = 0; i > - 10; i-- ){
    itoa( i, s );
    printf( "n = %d - s = %s\n", i, s );
  }

  i = INT_MIN + 1;
  itoa( i, s );
  printf( "n = %d - s = %s\n", i, s );

  i = INT_MIN;
  itoa( i, s );
  printf( "n = %d - s = %s\n", i, s );


  return 0;
}

/* output
n = 0 - s = 0
n = 1 - s = 1
n = 2 - s = 2
n = 3 - s = 3
n = 4 - s = 4
n = 5 - s = 5
n = 6 - s = 6
n = 7 - s = 7
n = 8 - s = 8
n = 9 - s = 9
n = 0 - s = 0
n = -1 - s = -1
n = -2 - s = -2
n = -3 - s = -3
n = -4 - s = -4
n = -5 - s = -5
n = -6 - s = -6
n = -7 - s = -7
n = -8 - s = -8
n = -9 - s = -9
n = -2147483647 - s = -2147483647
n = -2147483648 - s = -2147483648
*/
