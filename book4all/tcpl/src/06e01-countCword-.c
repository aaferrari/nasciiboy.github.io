#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS ( sizeof keytab / sizeof(struct key) )

struct key {
  char *word;
  int count;
} keytab[] = {
  { "auto",     0 },
  { "break",    0 },
  { "case",     0 },
  { "char",     0 },
  { "const",    0 },
  { "continue", 0 },
  { "default",  0 },
  { "do",       0 },
  { "double",   0 },
  { "else",     0 },
  { "enum",     0 },
  { "extern",   0 },
  { "float",    0 },
  { "for",      0 },
  { "goto",     0 },
  { "if",       0 },
  { "int",      0 },
  { "long",     0 },
  { "main",     0 },
  { "register", 0 },
  { "return",   0 },
  { "short",    0 },
  { "signed",   0 },
  { "sizeof",   0 },
  { "static",   0 },
  { "struct",   0 },
  { "switch",   0 },
  { "typedef",  0 },
  { "union",    0 },
  { "unsigned", 0 },
  { "void",     0 },
  { "volatile", 0 },
  { "while",    0 } };

enum CSTAT { CODE, COMMENT, SQUOTE, DQUOTE, END };

enum CSTAT getword( char *, int );
int binsearch( char *, struct key *, int );

/* cuenta palabras reservadas de c */
int main(){
  int n;
  char word[ MAXWORD ];
  enum CSTAT type;

  while( ( type = getword( word, MAXWORD ) ) != END ){
    switch( type ){
    case CODE   :
      if( isalpha( word[ 0 ] ) )
        if( (n = binsearch( word, keytab, NKEYS )) >= 0 )
          keytab[ n ].count++;
      break;
    case COMMENT: break;
    case SQUOTE : break;
    case DQUOTE : break;
    }
  }

  for( n = 0; n < NKEYS; n++ )
    if( keytab[ n ].count > 0 )
      printf( "%4d %s\n", keytab[ n ].count, keytab[ n ].word );

  return 0;
}

/* binsearch: encuentra una palabra en tab[ 0 ]...tab[ n - 1 ] */
int binsearch( char *word, struct key tab[], int n ){
  int cond;
  int low, high, mid;

  low = 0;
  high = n - 1;
  while( low <= high ){
    mid = ( low + high ) / 2;
    if( ( cond = strcmp( word, tab[ mid ].word ) ) < 0 )
      high = mid - 1;
    else if( cond > 0 )
      low = mid + 1;
    else return mid;
  }

  return -1;
}

/* getword: obtiene la siguiente palabra o caracter de la entrada */
enum CSTAT getword( char *word, int lim ){
  int c, nc;
  char *w = word;
  static enum CSTAT status = CODE;

  c = getchar();

  while( !isalpha( c ) && c != EOF && c != '_' ){
    if( status == CODE ){
      if(      c == '\'' ) status = SQUOTE;
      else if( c == '"'  ) status = DQUOTE;
      else if( c == '/'  )
        if( ( nc = getchar() ) == '*' )
          status = COMMENT;
        else ungetc( nc, stdin );
    } else if( status == COMMENT ){
      if( c == '*' )
        if( ( nc = getchar() ) == '/' )
          status = CODE;
        else ungetc( nc, stdin );
    } else if( status == SQUOTE  ){
      if( c == '\'' )
        status = CODE;
    } else if( status == DQUOTE )
      if( c == '"' )
        status = CODE;

    c = getchar();

    while( isspace( c ) ) c = getchar();
  }

  if( c == EOF ) return END;

  *w++ = c;

  for( ; --lim > 0; w++ ){
    if( !isalnum( c = getchar() ) && c != '_' ){
      ungetc( c, stdin );
      break;
    }

    *w = c;
  }

  *w = '\0';
  return status;
}


// output
// #include <stdio.h>
//
// int main( void ){  /* inicia el programa          */
//   printf( "main manda\n" );
//
//   return 0;        /* informa terminacion exitosa */
// }
//
//    1 int
//    1 main
//    1 return
//    1 void

/* output
main main_  _main int _int _int in_t
   1 int
   1 main
*/
