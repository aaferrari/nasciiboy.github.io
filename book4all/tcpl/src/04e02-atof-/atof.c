#include <ctype.h>

/* atof: convierte la cadena s a double */
double atof( char s[] ){
  double val, power, e, base;
  int i, sign, exponent;

  for( i = 0; isspace( s[ i ] ); i++ );  /* ignora espacios en blanco */

  sign = ( s[ i ] == '-' ) ? -1 : 1;

  if( s[ i ] == '+' || s[ i ] == '-' )
    i++;

  for( val = 0.0; isdigit( s[ i ] ); i++ )
    val = 10.0 * val + ( s[ i ] - '0' );

  if( s[ i ] == '.' )
    i++;

  for( power = 1.0; isdigit ( s[ i ] ); i++ ){
    val = 10.0 * val + ( s[ i ] - '0' );
    power *= 10;
  }

  e = 1;

  if( s[ i ] == 'e' || s[ i ] == 'E' ){
    i++;
    base = s[ i ] == '-' ? 0.1 : 10.0;
    if( s[ i ] == '-' || s[ i ] == '+' )
      i++;
    for( exponent = 0; isdigit( s[ i ] ); i++ ){
      exponent = 10 * exponent + ( s[ i ] - '0' );
    }
    while( exponent-- > 0 )
      e *= base;
  }

  return sign * val / power * e;
}

/* output $ gcc rCalculator.c atof.c getline.c
10e-5
	0.0001
10e5
	1e+06
10e-5
	1e+06
-10e5
	0.0002
10e-5
	0.0003
10e3
	10000
10.00e2
	11000
.52e2
	11052
*/
