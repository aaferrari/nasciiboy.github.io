#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100      /* tamano maximo de palabra             */
#define DNCMP     6      /* n primeros caracteres de comparacion */

int ncmp;                /* main set n caracteres de comparacion */
char
pcmp[ MAXWORD ] = "";    /* palabra para realizar comparacion    */

struct tnode {           /* el nodo del albor     */
  char *word;            /* apunta hacia el texto */
  int count;             /* numero de ocurrencias */
  struct tnode *left;    /* hijo a la izquierda   */
  struct tnode *right;   /* hijo a la derecha     */
};

struct tnode *addtree( struct tnode *, char * );
void treeprint( struct tnode * );

enum CSTAT { CODE, COMMENT, SQUOTE, DQUOTE, END };

enum CSTAT getword( char *, int );


/* conteo de frecuencia de palabras  */
int main( int argc, char *argv[] ){
  char word[ MAXWORD ];
  struct tnode *root;
  enum CSTAT type;

  if( argc > 2 ){
    printf( "ccw: opcion ilegal\n"
            "uso: ccw n  # primeros n caracteres identicos\n"
            "              en cada grupo de palabras\n" );
    return 1;  /* salida con un poco de gracia */
  } else if( argc == 2 ){
    if( isdigit( (*++argv)[0] ) ){
      ncmp = atoi( *argv );
    } else {
      printf( "ccw %s<--opcion ilegal\n"
              "uso: ccw n  # primeros n caracteres identicos\n"
              "              en cada grupo de palabras\n", *argv );
      return 1; /* salida con un poco de gracia */
    }
  } else ncmp = DNCMP;

  root = NULL;
  while( (type = getword( word, MAXWORD )) != END ){
    switch( type ){
    case CODE   :
      root = addtree( root, word );
      break;
    case COMMENT: break;
    case SQUOTE : break;
    case DQUOTE : break;
    }
  }

  treeprint( root );
  return 0;
}


/* talloc: crea un tnode */
struct tnode *talloc( void ){
  return (struct tnode *) malloc( sizeof( struct tnode ) );
}


/* strdup: crea un duplicado de s */
char *mystrdup( char *s ){
  char *p;
  p = (char *) malloc( strlen( s ) + 1 );  /* +1 para '\0' */
  if( p != NULL ) strcpy( p, s );

  return p;
}


/* addtree: agrega un nodo con w, en o bajo p */
struct tnode *addtree( struct tnode *p, char *w ){
  int cond;
  if( p == NULL ){           /* llego una nueva palabra */
    p = talloc();            /* crea un nuevo nodo      */
    p->word = mystrdup( w );
    p->count = 1;
    p->left = p->right = NULL;
  } else if( (cond = strcmp( w, p->word )) == 0 )
    p->count++;              /* palabra repetida        */
  else if( cond < 0 )        /* menor que el contenido del subarbol izquierdo */
    p->left  = addtree( p->left,  w );
  else                       /* mayor que el contenido del subarbol derecho   */
    p->right = addtree( p->right, w );

  return p;
}


void cmpprint( int count, char *word ){
  if( strncmp( pcmp, word, ncmp ) == 0 )
    printf( "%4d %s\n", count, word );
  else {
    strcpy( pcmp, word );
    printf( "\n%4d %s\n", count, word );
  }
}

/* treeprint: impresion del arbol p en orden */
void treeprint( struct tnode *p ){
  if( p != NULL ){
    treeprint( p->left );
    cmpprint( p->count, p->word );
    // printf( "%4d %s\n", p->count, p->word );
    treeprint( p->right );
  }
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


/*  $ ./a.out 2
main maon maoo maun miau wauu int int_ int_ _int cast deb

   1 _int

   1 cast

   1 deb

   1 int
   2 int_

   1 main
   1 maon
   1 maoo
   1 maun

   1 miau

   1 wauu
*/
