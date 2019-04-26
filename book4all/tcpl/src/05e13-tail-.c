#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAXLINES 5000      /* max # de lineas por ordenar    */

char *lineptr[ MAXLINES ]; /* apuntadores a lineas de texto  */

int readlines( char *lineptr[], int nlines );
void writelines( char *lineptr[], int nlines );


/* ordena lineas de entrada */
int main( int argc, char *argv[] ){
  int nlines;               /* numero de lineas de entrada leidas */
  int ntail;                /* numero de lineas a imprimir        */

  switch( argc ){
  case 1: ntail = 10; break;
  case 2:
    if( (*++argv)[ 0 ] == '-' )
      ntail = atoi( ++*argv );
    else {
      printf( "ejemplo de uso: tail -10\n" );
      return 1;
    } break;
  default:
    printf( "ejemplo de uso: tail -10\n" );
    return 1;
  }

  if( ( nlines = readlines( lineptr, MAXLINES ) ) >= 0 ){
    putchar( '\n' );

    /* se tienen suficientes lineas */
    if( ntail >= 0 && ntail < nlines )
      writelines( lineptr + ( nlines - ntail ), ntail );
    /* se solicitaron mas lineas de las disponibles o
       hay menos de las solicitadas */
    else
      writelines( lineptr, nlines );
    return 0;
  } else {
    printf( "error: entrada demasiado grade para ordenarla\n" );
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
void writelines( char *lineptr[], int nlines ){
  int i;
  for( i = 0; i < nlines; i++ )
    printf( "%s\n", lineptr[ i ] );
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


/*  $ ./a.out
linea 1
linea 2
linea 3

linea 1
linea 2
linea 3
*/

/*  $ ./a.out
linea 1
linea 2
linea 3
linea 4
linea 5
linea 6
linea 7
linea 8
linea 9
linea 10
linea 11

linea 2
linea 3
linea 4
linea 5
linea 6
linea 7
linea 8
linea 9
linea 10
linea 11
*/

/*  $ ./a.out -2
linea 1
linea 2
linea 3
linea 4
linea 5

linea 4
linea 5
*/
