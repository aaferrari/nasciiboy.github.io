/* itoa: convierte n a caracteres en s */
/* reverse: invierte la cadena s en el mismo lugar */
#include <stdio.h>
#include <string.h>

/* itoa: convierte n a caracteres en s */
void itoa( int n, char s[] ){
  int len;

  if( n / 10 ){
    itoa( n / 10, s );
  } else {
    if( n < 0 ){
      s[ 0 ] = '-';
      s[ 1 ] = '\0';
    } else s[ 0 ] = '\0';
  }

  if( n < 0 ) n = -n;

  len = strlen( s );
  s[ len   ] = n % 10 + '0';
  s[ ++len ] = '\0';
}

int main(){
  int i;
  char s[ 12 ];

  i = -123456;
  itoa( i, s );
  printf( "n = %10d  s = %10s\n", i, s );

  i =  123456;
  itoa( i, s );
  printf( "n = %10d  s = %10s\n", i, s );

  i = 0;
  itoa( i, s );
  printf( "n = %10d  s = %10s\n", i, s );

  return 0;
}

/* output
n =    -123456  s =    -123456
n =     123456  s =     123456
n =          0  s =          0
*/
