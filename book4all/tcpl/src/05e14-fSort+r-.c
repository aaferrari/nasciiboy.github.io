#include <stdio.h>
#include <string.h>

#define MAXLINES 5000       /* max # de lineas a ordenar     */

char *lineptr[ MAXLINES ];  /* apuntadores a lineas de texto */

int readlines( char *lineptr[], int nlines );
void writelines( char *lineptr[], int nlines, int reverse );
void Qsort( void *lineptr[], int left, int right,
            int (*comp)(void *, void * ));
int numcmp( char *, char * );

/* ordena lineas de entrada */
int main( int argc, char *argv[] ){
  int nlines;               /* numero de lineas de entrada leidas */
  int numeric = 0;          /* 1 si es ordenamiento numerico      */
  int reverse = 0;          /* 1 para imprimir en orden inverso   */

  int c;
  while( --argc > 0 && (*++argv)[0] == '-' )
    while( c = *++argv[ 0 ] )
      switch( c ){
      case 'n': numeric = 1; break;
      case 'r': reverse = 1; break;
      default:
        printf( "find: illegal option %c\n", c );
        return 1;
      }


  if( argc > 1 && strcmp( argv[ 1 ], "-n" ) == 0 )
    numeric = 1;
  if(( nlines = readlines( lineptr, MAXLINES )) >= 0 ){
    Qsort( (void**) lineptr, 0, nlines - 1,
           (int (*)( void*, void* ) )( numeric ? numcmp : strcmp ) );
    writelines( lineptr, nlines, reverse );
    return 0;
  } else {
    printf( "entrada demasiado grande para ser ordenada\n" );
    return 1;
  }
}

#define MAXLEN 1000   /* max longitud de cualquier linea de entrada */
int getLine( char *, int );
char *alloc( int );

/* readlinos: lee lineas de entrada */
int readlines( char *lineptr[], int maxlines ){
  int len, nlines;
  char *p, line[ MAXLEN ];

  nlines = 0;
  while( ( len = getLine( line, MAXLEN ) ) > 0 )
    if( nlines >= maxlines || ( p = alloc( len ) ) == NULL )
      return -1;
    else {
      line[ len - 1 ] = '\0'; /* elimina caracter nueva linea */
      strcpy( p, line );
      lineptr[ nlines++ ] = p;
    }

  return nlines;
}

/* writelines: escribe lineas de salida */
void writelines( char *lineptr[], int nlines, int reverse ){
  if( reverse ){
    while( nlines )
      printf( "%s\n", lineptr[ --nlines ] );
  } else {
    int i;
    for( i = 0; i < nlines; i++ )
      printf( "%s\n", lineptr[ i ] );
  }
}


/* getLine: lee una linea en s, regresa su longitud */
int getLine( char *s, int lim ){
  char *i = s;
  int c;
  while( lim-- && ( c = getchar() ) != EOF && c != '\n' )
    *s++ = c;

  if( c == '\n' ) *s++ = c;
  *s = '\0';

  return s - i;
}

#define ALLOCSIZE 10000            /* tamano del espacio disponible       */

static char allocbuf[ ALLOCSIZE ]; /* almacenamiento para alloc           */
static char *allocp = allocbuf;    /* siguiente posicion libre            */

char *alloc( int n ){              /* regresa un apuntador a n caracteres */
  if( allocbuf + ALLOCSIZE - allocp >= n ){   /* si cabe    */
    allocp += n;
    return allocp - n;                        /* antigua p  */
  } else return 0;                 /* no hay suficiente espacio           */
}

void afree( char *p ){             /* almacenamiento libre apuntado por p */
  if( p >= allocbuf && p < allocbuf + ALLOCSIZE )
    allocp = p;
}

/* Qsort: clasifica v[left]...v[right] en orden ascendente */
void Qsort( void *v[], int left, int right,
            int (*comp)(void *, void *) ){
  int i, last;

  void swap( void *v[], int, int );

  if( left >= right )  /* no hace nada si el arreglo contiene */
    return;            /* menos de dos elementos              */
  swap( v, left, (left + right) / 2 );
  last = left;
  for( i = left + 1; i <= right; i++ )
    if( (*comp)(v[ i ], v[ left ]) < 0 )
      swap( v, ++last, i );
  swap( v, left, last );
  Qsort( v, left, last - 1, comp );
  Qsort( v, last + 1, right, comp );
}

#include <stdlib.h>

/* numcmp: compara s1 y s2 numericamente */
int numcmp( char *s1, char *s2 ){
  double v1, v2;
  v1 = atof( s1 );
  v2 = atof( s2 );
  if(      v1 < v2 ) return -1;
  else if( v1 > v2 ) return  1;
  else               return  0;
}

void swap( void *v[], int i, int j ){
  void *temp;

  temp = v[ i ];
  v[ i ] = v[ j ];
  v[ j ] = temp;
}


/* output $ ./a.out -nr
45 uno
13 dos
999 tres
7 cuatro
9 cinco

999 tres
45 uno
13 dos
9 cinco
7 cuatro

*/

/* output $ ./a.out -r
45 uno
13 dos
999 tres
7 cuatro
9 cinco

999 tres
9 cinco
7 cuatro
45 uno
13 dos

*/
