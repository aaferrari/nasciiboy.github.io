#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUMBER  '0'
#define STRING  '1'

void cpy( char d[], char s[] ){
  int i = 0;
  while( ( d[ i ] = s[ i ] ) != '\0' ) i++;
}

/* getop: obtiene el siguiente operador u operando numérico */
int getop( char line[], char s[] ){
  int i, c;
  int il = 0;

  while( ( ( s[0] = c = line[ il++ ] ) == ' ' || c == '\t' ) && c != '\0' )
    ;

  if( c == '\0' ) return EOF;
  s[1] = '\0';

  i = 0;

  if( isalpha( c ) ){
    while( isgraph( c = line[ il++ ] ) )
      s[ ++i ] = c;

    s[ ++i ] = '\0';

    cpy( line, &line[ --il ] );

    if( i < 2 ) return s[ 0 ];

    return STRING;                /* char o cadena de caracteres */
  }

  if( !isdigit( c ) && c != '.' && c != '-' ){
    cpy( line, &line[ il ] );
    return c;                     /* simbolo solitario           */
  }

  if( isdigit( c ) || c == '-' )  /* reúne la parte entera       */
    while( isdigit( s[ ++i ] = c = line[ il++ ] ) )
      ;
  if( c == '.' )                  /* reúne la parte fraccionaria */
    while( isdigit( s[ ++i ] = c = line[ il++ ] ) )
      ;
  s[i] = '\0';

  cpy( line, &line[ --il ] );

  if( s[0] == '-' && !isdigit( s[ 1 ] ) && s[ 1 ] != '.' )
    return '-';

  return NUMBER;
}
