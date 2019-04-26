#include <stdio.h>
#include <ctype.h>

#define NUMBER  '0'
#define STRING  '1'

int getch( void );
void ungetch( int );

/* getop: obtiene el siguiente operador u operando numérico */
int getop( char s[] ){
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

    if( i < 2 ) return s[ 0 ];

    return STRING;                /* es una cadena              */
  }

  if( !isdigit( c ) && c != '.' && c != '-' )
    return c;                     /* no es un número            */

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

  return NUMBER;
}
