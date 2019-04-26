#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100      /* tamano maximo de palabra */

struct tnode {           /* el nodo del albor     */
  char *word;            /* apunta hacia el texto */
  int count;             /* numero de ocurrencias */
  int *list;             /* aparicion x nl        */
  struct tnode *left;    /* hijo a la izquierda   */
  struct tnode *right;   /* hijo a la derecha     */
};

struct tnode *addtree( struct tnode *, char *, int );
void treeprint( struct tnode * );
int blacklist( char **, char * );
int getword( char *, int );

/* conteo de frecuencia de palabras  */
int main(){
  char word[ MAXWORD ];
  struct tnode *root;
  int nl;

  char *ignore[] = {
    "el",
    "y",
    "a",
    "al",
    NULL
  };

  root = NULL;
  while( nl = getword( word, MAXWORD ) ){
    if( !blacklist( ignore, word ) )
      root = addtree( root, word, nl );
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


int *addnum( int *list, int nl ){
  int *pl;
  int i = 0;

  if( list ){
    while( list[ i ] ) i++;

    if( nl != list[ i - 1 ] ){
      pl = (int*)malloc( sizeof( int ) * i + 2 );

      i = 0;
      while( pl[ i ] = *list++ ) i++;
      pl[ i++ ] = nl;
      pl[ i ] = 0;
      list = pl;
    }
  } else {
    list = (int*)malloc( 2 * sizeof( int ) );
    *list = nl;
    *(list + 1) = 0;
  }

  return list;
}

/* addtree: agrega un nodo con w, en o bajo p */
struct tnode *addtree( struct tnode *p, char *w, int nl ){
  int cond;
  if( p == NULL ){           /* llego una nueva palabra */
    p = talloc();            /* crea un nuevo nodo      */
    p->word = mystrdup( w );
    p->count = 1;
    p->list = NULL;
    p->list = addnum( p->list, nl );
    p->left = p->right = NULL;
  } else if( (cond = strcmp( w, p->word )) == 0 ){
    p->count++;              /* palabra repetida        */
    p->list = addnum( p->list, nl );
  } else if( cond < 0 )      /* menor que el contenido del subarbol izquierdo */
    p->left  = addtree( p->left,  w, nl );
  else                       /* mayor que el contenido del subarbol derecho   */
    p->right = addtree( p->right, w, nl );

  return p;
}


/* treeprint: impresion del arbol p en orden */
void treeprint( struct tnode *p ){
  if( p != NULL ){
    treeprint( p->left );
    printf( "%15s #%4d - Lines:", p->word, p->count );
    while( *(p->list) )
      printf( " %3d", *(p->list++) );
    putchar( '\n' );
    treeprint( p->right );
  }
}


int blacklist( char **list, char *word ){
  while( *list )
    if( strcmp( *list++, word ) == 0 ) return 1;

  return 0;
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


/*  $ ./a.out 2
el main tine un int a el void
un main y un void tinen un return
char * void no es main ni return
           char #   1 - Lines:   3
             es #   1 - Lines:   3
            int #   1 - Lines:   1
           main #   3 - Lines:   1   2   3
             ni #   1 - Lines:   3
             no #   1 - Lines:   3
         return #   2 - Lines:   2   3
           tine #   1 - Lines:   1
          tinen #   1 - Lines:   2
             un #   4 - Lines:   1   2
           void #   3 - Lines:   1   2   3
*/
