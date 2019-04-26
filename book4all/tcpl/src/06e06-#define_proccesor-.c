#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct nlist {         /* entrada de la tabla:           */
  struct nlist *next;  /* siguiente entrada en la cadena */
  char *name;          /* nombre definido                */
  char *defn;          /* texto de reemplazo             */
};

#define HASHSIZE 101

static struct nlist *hashtab[ HASHSIZE ];  /* tabla de apuntadores */

/* hash: forma un valor hash para la cadena s */
unsigned hash( char *s ){
  unsigned hashval;

  for( hashval = 0; *s != '\0'; s++ )
    hashval = *s + 31 * hashval;

  return hashval % HASHSIZE;
}

/* lookup: busca s en hashtab */
struct nlist *lookup( char *s ){
  struct nlist *np;

  for( np = hashtab[ hash( s ) ]; np != NULL; np = np->next )
    if( strcmp( s, np->name ) == 0 )
      return np;   /* se encontro    */

  return NULL;     /* no se encontro */
}

int undef( char *name ){
  struct nlist *np;

  if( np = lookup( name ) ){             /* fue encontrado */
    free( (void *)np->name );            /* libera name    */
    free( (void *)np->defn );            /* libera defn    */
    free( (void *)np );                  /* libera np      */
    hashtab[ hash( name ) ] = NULL;

    return 1;
  }

  return 0;
}


/* install: coloca (name, defn) detro de hastab */
struct nlist *install( char *name, char *defn ){
  struct nlist *np;
  unsigned hashval;

  if( (np = lookup( name )) == NULL ){   /* no fue encontrado        */
    np = (struct nlist*) malloc( sizeof(*np) );
    if( np == NULL || (np->name = strdup( name )) == NULL )
      return NULL;

    hashval = hash( name );
    np->next = hashtab[ hashval ];
    hashtab[ hashval ] = np;
  } else                                 /* ya esta alli             */
    free((void *) np->defn);             /* libera la anterior defn */

  if( (np->defn = strdup( defn )) == NULL )
    return NULL;

  return np;
}

enum CSTAT { CODE, SCODE, COMMENT, SQUOTE, DQUOTE, END };

enum CSTAT getword( char *word, int lim ){
  int c, nc;
  char *w = word;
  static enum CSTAT status = CODE;

  c = getchar();

  char *simbols = "\n<>=![](){},;+-*&$";

  while( !isalnum( c ) && c != EOF && c != '_' && c != '#' ){
    word[ 0 ] = c; word[ 1 ] = '\0';
    if( strstr( simbols, word ) )
      return SCODE;

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

    while( c == ' ' || c == '\t' ) c = getchar();
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

#define MAXWORD 100

int main(){
  char word[ MAXWORD ];
  char defn[  MAXWORD ];
  enum CSTAT type;
  struct nlist *np;

  while( ( type = getword( word, MAXWORD ) ) != END ){
    switch( type ){
    case CODE   :
      if( word[ 0 ] == '#' )
        if( strcmp( word, "#define" ) == 0 ){
          getword( word, MAXWORD );
          getword( defn, MAXWORD );
          install( word, defn );
          break;
        }

      if( np = lookup( word ) )
        printf( "%s ", np->defn );
      else
        printf( "%s%s", word, strlen( word ) > 0 ? " " : "" );
      break;
    case SCODE: printf( "%s", word ); break;
    case COMMENT: break;
    case SQUOTE : break;
    case DQUOTE : break;
    }
  }

  putchar( '\n' );

  return 0;
}

/* output
#define MAX 10

#define MIN  0

int main(){
int main (){
int x = MAX;
int x =10 ;
int b = MIN;
int b =0 ;
if( x > b ) return 0;
if (x >b )return 0 ;
return 1;
return 1 ;
}
}
*/
