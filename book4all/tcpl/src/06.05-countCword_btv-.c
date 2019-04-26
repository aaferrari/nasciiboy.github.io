#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct tnode {           /* el nodo del albor     */
  char *word;            /* apunta hacia el texto */
  int count;             /* numero de ocurrencias */
  struct tnode *left;    /* hijo a la izquierda   */
  struct tnode *right;   /* hijo a la derecha     */
};

struct tnode *addtree( struct tnode *, char * );
void treeprint( struct tnode * );
int getword( char *, int );


/* conteo de frecuencia de palabras  */
int main(){
  struct tnode *root;
  char word[ MAXWORD ];

  root = NULL;
  while( getword( word, MAXWORD ) != EOF )
    if( isalpha( word[ 0 ] ) )
      root = addtree( root, word );

  treeprint( root );
  return 0;
}


#include <stdlib.h>

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


/* treeprint: impresion del arbol p en orden */
void treeprint( struct tnode *p ){
  if( p != NULL ){
    treeprint( p->left );
    printf( "%4d %s\n", p->count, p->word );
    treeprint( p->right );
  }
}


/* getword: obtiene la siguiente palabra o caracter de la entrada */
int getword( char *word, int lim ){
  int c;
  char *w = word;

  while( isspace( c = getchar() ) )
    ;

  if( c != EOF ) *w++ = c;
  if( !isalpha( c ) ){
    *w = '\0';
    return c;
  }

  for( ; --lim > 0; w++ )
    if( !isalnum( *w = getchar() ) ){
      ungetc( *w, stdin );
      break;
    }

  *w = '\0';
  return word[ 0 ];
}


/* output
uno uno dos tres cuatro cinco seis siete ocho
nueve dies dees dies diez como really shure jarlforrtfff
   1 cinco
   1 como
   1 cuatro
   1 dees
   2 dies
   1 diez
   1 dos
   1 jarlforrtfff
   1 nueve
   1 ocho
   1 really
   1 seis
   1 shure
   1 siete
   1 tres
   2 uno
*/
