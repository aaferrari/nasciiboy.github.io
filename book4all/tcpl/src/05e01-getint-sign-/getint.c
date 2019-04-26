#include <ctype.h>
#include <stdio.h>   /* EOF */

int getch( void );
void ungetch( int );

/* getint: obtiene el siguiente entero de la entrada y lo asigna a *pn */
int getint( int *pn ){
  int c, sign;
  while( isspace( c = getch() ) ) /* ignora espacios en blanco */
    ;

  if( !isdigit( c ) && c != EOF && c != '+' && c != '-' ){
    ungetch( c );                 /* no es un numero           */
    *pn = 0;
    return 0;
  }

  sign = ( c == '-' ) ? -1 : 1;
  if( c == '+' || c == '-' )
    c = getch();

  if( !isdigit( c ) ){
    ungetch( c );
    *pn = 0;
    return 0;
  }

  for( *pn = 0; isdigit( c ); c = getch() )
    *pn = 10 * *pn + ( c - '0' );
  *pn *= sign;
  if( c != EOF )
    ungetch( c );
  return c;
}
