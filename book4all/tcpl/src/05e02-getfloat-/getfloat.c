#include <ctype.h>
#include <stdio.h>   /* EOF  */
#include <stdlib.h>  /* atof */

int getch( void );
void ungetch( int );

/* getfloat: obtiene el siguiente operador numérico */
int getfloat( float *pn  ){
  char s[1024];
  int i, c;
  while(( s[0] = c = getch() ) == ' ' || c == '\t' )
    ;
  s[1] = '\0';

  i = 0;

  if( isalpha( c ) ){
    while( isgraph( c = getch() ) )
      s[ ++i ] = c;
    s[ ++i ] = '\0';

    if( c != EOF )
      ungetch( c );

    *pn = 0;
    if( i < 2 ) return 0;

    return 0;                     /* no es un número            */
  }

  if( !isdigit( c ) && c != '.' && c != '-' ){
    *pn = 0;
    return 0;                     /* no es un número            */
  }

  if( isdigit( c ) || c == '-' )  /* reúne la parte entera      */
    while( isdigit( s[ ++i ] = c = getch() ) )
      ;
  if( c == '.' )                  /* reúne la parte fraccionaria */
    while( isdigit( s[ ++i ] = c = getch() ) )
      ;
  s[i] = '\0';
  if( c != EOF )
    ungetch( c );

  if( s[0] == '-' && !isdigit( s[ 1 ] ) && s[ 1 ] != '.' )
    return '-';

  *pn = atof( s );
  return 1;
}
