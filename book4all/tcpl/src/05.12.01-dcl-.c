/* dcl: reconoce una declaracion */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl( void );
void dirdcl( void );

int gettoken( void );
int tokentype;                       /* tipe del ultimo token          */
char token[ MAXTOKEN ];              /* cadena del ultimo token        */
char name[ MAXTOKEN ];               /* nombre del identificador       */
char datatype[ MAXTOKEN ];           /* tipo de dato = char, int, etc. */
char out[ 1000 ];                    /* cadena de salida               */

/* convierte una declaracion a palabras */
int main(){
  while( gettoken() != EOF ){        /* 1er. token en la linea         */
    strcpy( datatype, token );       /* es el tipo de dato             */
    out[ 0 ] = '\0';
    dcl();                           /* reconoce el resto de la linea  */

    if( tokentype != '\n' )
      printf( "error de sintaxis\n" );
    printf( "%s: %s %s\n", name, out, datatype );
  }

  return 0;
}

void dcl( void ){
  int ns;

  for( ns = 0; gettoken() == '*'; )  /* cuenta *s */
    ns++;
  dirdcl();
  while( ns-- > 0 )
    strcat( out, " apuntador a" );
}

/* dirdcl: recenoce un declarador directo */
void dirdcl( void ){
  int type;

  if( tokentype == '(' ){            /* ( dcl )   */
    dcl();
    if( tokentype != ')' )
      printf( "error: falta )\n" );
  } else if( tokentype == NAME )     /* nombre de variable */
    strcpy( name, token );
  else
    printf( "error: nombre o (dcl) esperado\n" );

  while( ( type = gettoken() ) == PARENS || type == BRACKETS )
    if( type == PARENS )
      strcat( out, " funcion que regresa" );
    else {
      strcat( out, " arreglo" );
      strcat( out, token );
      strcat( out, " de" );
    }
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
