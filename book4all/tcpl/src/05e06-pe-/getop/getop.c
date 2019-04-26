#include <stdio.h>
#include <ctype.h>

#define NUMBER  '0'
#define STRING  '1'

int getch( void );
void ungetch( int );

/* getop: obtiene el siguiente operador u operando numérico */
int getop( char *s ){
  int c;
  char *o = s;

  while(( *s = c = getch() ) == ' ' || c == '\t' )
    ;
  *(s + 1) = '\0';

  if( isalpha( c ) ){
    while( isgraph( c = getch() ) )
      *++s = c;
    *++s = '\0';

    if( c != EOF )
      ungetch( c );

    if( s - o < 2 ) return *o;

    return STRING;                /* no es un número            */
  }

  if( !isdigit( c ) && c != '.' && c != '-' )
    return c;         /* no es un número            */

  if( isdigit( c ) || c == '-' )  /* reúne la parte entera      */
    while( isdigit( *++s = c = getch() ) )
      ;
  if( c == '.' )                  /* reúne la parte fraccionaria */
    while( isdigit( *++s = c = getch() ) )
      ;
  *s = '\0';
  if( c != EOF )
    ungetch( c );

  if( *o == '-' && !isdigit( *( o + 1 ) ) && *( s + 1 ) != '.' )
    return '-';

  return NUMBER;
}
