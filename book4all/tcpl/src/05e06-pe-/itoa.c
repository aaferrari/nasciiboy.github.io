#include <stdio.h>
#include <string.h>

/* reverse: invierte la cadena s en el mismo lugar */
void reverse( char s[] ){
  int len = strlen( s );
  char temp = s[ len - 1 ];

  if( len > 1 ){
    s[ len -1 ] = '\0';
    reverse( s + 1 );

    s[ len - 1 ] = s[ 0 ];
    s[ 0 ] = temp;
  }
}

/* itoa: convierte n a caracteres en s */
void itoa( int n, char *s ){
  int sign;
  char *o = s;

  if( ( sign = n ) < 0 )      /* registra el signo        */
    n = -n;                   /* vuelve a n positivo      */

  do {   /* genera digitos en orden inverso               */
    *s++ = n % 10 + '0';      /* toma el siguiente digito */
  } while( ( n /= 10 ) > 0 ); /* borralo                  */
  if( sign < 0 )
    *s++ = '-';
  *s = '\0';
  reverse( o );
}

int main(){
  int n = 1234567890;
  char s[ 11 ];

  itoa( n, s );
  puts( s );

  return 0;
}


/* output
1234567890
*/
