#include <ctype.h>

/* atoi: convierte s a entero; version 2 */
int atoi( char s[] ){
  int i, n, sing;
  for( i = 0; isspace( s[ i ] ); i++ )  /* ignora espacio en blanco */
    ;

  sing = ( s[ i ] == '-' ) ? -1 : 1;
  if ( s[ i ] == '+' || s[ i ] == '-' ) /* ignora el signo          */
    i++;
  for ( n = 0; isdigit( s[ i ] ); i++ )
    n = 10 * n + ( s[ i ] - '0' );

  return sing * n;
}
