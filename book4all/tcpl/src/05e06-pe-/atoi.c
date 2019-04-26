#include <stdio.h>
#include <ctype.h>

/* atoi: convierte s a entero */
int atoi( char *s ){
  int n, sign;

  while( isspace( *s ) ) s++;   /* ignora espacios en blanco */

  sign = ( *s == '-' ) ? -1 : 1;
  if( *s == '+' || *s == '-' )  /* ignora el signo           */
    s++;
  for( n = 0; isdigit( *s ); s++ )
    n = 10 * n + ( *s - '0' );

  return sign * n;
}



int main(){
  int n;
  char s[ 11 ] = "1234567890";

  n = atoi( s );
  printf( "%d\n", n );

  return 0;
}


/* output
1234567890
*/
