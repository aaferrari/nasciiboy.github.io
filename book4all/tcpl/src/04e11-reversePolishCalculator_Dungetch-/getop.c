#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: obtiene el siguiente operador u operando numérico */
int getop( char s[] ){
  int i, c;
  static int buf = 0;

  if( buf == 0 ) s[0] = c = getch();
  else {
    s[0] = c = buf;
    buf = 0;
  }

  while( c == ' ' || c == '\t' )
    s[0] = c = getch();
  s[1] = '\0';

  i = 0;

  if( isalpha( c ) ){
    while( isgraph( c = getch() ) )
      s[ ++i ] = c;
    s[ ++i ] = '\0';

    buf = c;

    if( i < 2 ) return s[ 0 ];

    return STRING;                /* cadena o caracter          */
  }

  if( !isdigit( c ) && c != '.' && c != '-' )
    return c;                     /* caracter                   */

  if( isdigit( c ) || c == '-' )  /* reúne la parte entera      */
    while( isdigit( s[ ++i ] = c = getch() ) )
      ;
  if( c == '.' )                  /* reúne la parte fraccionaria */
    while( isdigit( s[ ++i ] = c = getch() ) )
      ;
  s[i] = '\0';

  buf = c;

  if( s[0] == '-' && !isdigit( s[ 1 ] ) && s[ 1 ] != '.' )
    return '-';

  return NUMBER;
}
