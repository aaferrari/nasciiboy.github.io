/* convierte una cadena de digitos hexadecimales
   en su valor entero equivalente */
#include <stdio.h>
#include <ctype.h>

#define LIMIT 10

int htoi( char s[] );
int myGetline( char s[], int lim );
void copy( char to[], char from[], int n );

int main(){
  char s[ LIMIT ];
  int dec;

  printf( "hex --> 2 --> int\n > " );

  while( myGetline( s, LIMIT ) ){
    if( ( dec = htoi(s) ) != EOF )
      printf( " 2dec: %d\n > ", dec );
    else
      printf( " VALOR NO VALIDO\n > " );
  }

  printf( "see you later ^ ^\n" );

  return 0;
}


int myGetline( char s[], int lim ){
  int c, i;

  for( i=0; i < lim-1 && ( c = getchar() ) != EOF && c != '\n'; ++i )
    s[i] = c;

  if( c == '\n' ){
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}

void copy( char to[], char from[], int n ){
  int i;
  i = 0;
  if( n == '\0' )
    while( ( to[i] = from[i]) != '\0' )
      ++i;
  else{
    while( i < n ){
      to[i] = from[i];
      ++i;
    }

    to[ i ] = '\0';
  }
}

int htoi( char s[] ){
  int i, dec;

  if( s[ 0 ] == '0' && toupper( s[ 1 ] ) == 'X' )
    copy( &s[ 0 ], &s[ 2 ], '\0' );

  for( i = 0, dec = 0; s[ i ] != '\0'; i++ ){
    if( toupper( s[ i ] ) >= 'A' && toupper( s[ i ] ) <= 'F' )
      dec = 16 * dec + ( toupper(s[ i ] ) - 'A' + 10 );
    else if( s[ i ] >= '0' && s[ i ] <= '9' )
      dec = 16 * dec + ( s[ i ] - '0' );
  }

  return dec;
}


/* output
hex --> 2 --> int
 > ff
 2dec: 255
 > fff 2dec: 4095
 > 10 2dec: 16
 > 1ff
 2dec: 511
 > 100 2dec: 256
 > 0x00f
 2dec: 15
 > 0X0ab
 2dec: 171
 > 0xfff
 2dec: 4095
 > see you later ^ ^
*/
