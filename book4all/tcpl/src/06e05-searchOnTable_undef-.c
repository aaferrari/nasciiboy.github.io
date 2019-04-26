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

/* getword: obtiene la siguiente palabra o caracter de la entrada */
int getword( char *word, int lim ){
  int c;
  char *w = word;
  static int nl = 1;

  *w = '\0';

  c = getchar();
  while( !isalnum( c ) && c != '_' ){
    if( c == '\n' ) nl++;
    if( c == EOF  ) return 0;
    c = getchar();
  }

  *w++ = c;

  for( ; --lim > 0; w++ ){
    if( !isalnum( c = getchar() ) && c != '_' ){
      ungetc( c, stdin );
      break;
    }

    *w = c;
  }

  *w = '\0';
  return nl;
}

#define MAXWORD 100

int main(){
  struct nlist *np;
  char name[ MAXWORD ], tmp[ MAXWORD ];

  *name = 0;

  printf( " > name def\n"
          " > "           );

  while( getword( tmp, MAXWORD ) ){
    if( !*name ) strcpy( name, tmp );
    else if( strcmp( name, tmp ) != 0 ){
      install( name, tmp );
      *name = 0;
      printf( " > " );
    }
  }

  printf( "\nundef\n");

  while( getword( tmp, MAXWORD ) )
    if( np = lookup( tmp ) ){
      printf( "DEL - hash #%d, def->%s\n", hash( tmp ), np->defn );
      undef( tmp );
    } else
      printf( "%s no found\n", tmp );

  return 0;
}

/* output
 > name def
 > MAIN main
 > def defn
 >
undef
MAON
MAON no found
MAIN
DEL - hash #60, def->main
dof
dof no found
def
DEL - hash #50, def->defn
*/
