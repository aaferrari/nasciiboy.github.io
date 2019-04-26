/* dcl: reconoce una declaracion */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };


int gettoken( void );
int tokentype;                       /* tipe del ultimo token          */
char token[ MAXTOKEN ];              /* cadena del ultimo token        */
char datatype[ MAXTOKEN ];           /* tipo de dato = char, int, etc. */
char out[ 1000 ];                    /* cadena de salida               */

/* undcl: convierte una descripcion verbal a declaracion */
int main(){
  int type;
  char temp[ MAXTOKEN ];

  while( gettoken() != EOF ){
    out[ 0 ] = '\0';
    strcpy( out, token );

    while( (type = gettoken()) != '\n' )
      if( type == PARENS || type == BRACKETS )
        strcat( out, token );
      else if( type == '*' ){
        sprintf( temp, "(*%s)", out );
        strcpy( out, temp );
      } else if( type == NAME ){
        sprintf( temp, "%s %s", token, out );
        strcpy( out, temp );
      } else
        printf( "entrada invalida en %s\n", token );

    printf( "\n%s\n", out );
  }

  return 0;
}


/* regresa el siguiente token */
int gettoken( void ){
  int c;
  char *p = token;

  while( ( c = getchar() ) == ' ' || c == '\t' )
    ;
  if( c == '(' ){
    if( ( c = getchar() ) == ')' ){
      strcpy( token, "()" );
      return tokentype = PARENS;
    } else {
      ungetc( c, stdin );
      return tokentype = '(';
    }
  } else if( c == '[' ){
    for( *p++ = c; (*p++ = getchar() ) != ']'; )
      ;
    *p = '\0';
    return tokentype = BRACKETS;
  } else if( isalpha( c ) ){
    for( *p++ = c; isalnum( c = getchar() ); )
      *p++ = c;
    *p = '\0';
    ungetc( c, stdin );
    return tokentype = NAME;
  } else
    return tokentype = c;
}


/* output
x () * [] * () char

char (*(*x())[])()

x [] char

char x char[]
*/
