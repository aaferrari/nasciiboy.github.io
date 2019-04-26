#include <stdio.h>
#include <string.h>

#define MAXLINES 5000      /* max # de lineas por ordenar    */
#define ALLOCSIZE 10000            /* tamano del espacio disponible       */

char *lineptr[ MAXLINES ]; /* apuntadores a lineas de texto  */

int readlines( char *lineptr[], int nlines, char *buf, int maxbuf );
void writelines( char *lineptr[], int nlines );
void qsort( char *lineptr[], int nlines );

/* ordena lineas de entrada */
int main(){
  int nlines;                 /* numero de lineas de entrada leidas */
  char allocbuf[ ALLOCSIZE ]; /* almacenamiento para alloc          */

  if( ( nlines = readlines( lineptr, MAXLINES, allocbuf, ALLOCSIZE ) ) >= 0 ){
    qsort( lineptr, nlines );
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
int readlines( char *lineptr[], int maxlines, char *buf, int maxbuf ){
  int len, nlines;
  char *p, line[ MAXLEN ];
  char *allocp = buf;    /* siguiente posicion libre           */

  nlines = 0;
  while( ( len = getLine( line, MAXLEN ) ) > 0 )
    if( nlines >= maxlines ||
        ( p = (buf + maxbuf - allocp >= len) ? allocp : 0 ) == NULL )
      return -1;
    else {
      allocp += len;
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

  *s = '\0';

  return s - i;
}


/* shellsort: ordena v[0]...v[n-1] en orden ascendente */
void qsort( char *v[], int n ){
  int gap, i, j;
  char *temp;
  for( gap = n/2; gap > 0; gap /= 2 )
    for( i = gap; i < n; i++ )
      for( j = i - gap; j >= 0 && strcmp( v[ j ], v[ j + gap ] ) > 0; j -= gap ){
        temp = v[ j ];
        v[ j ] = v[ j + gap ];
        v[ j + gap ] = temp;
      }
}


/* output
654132
700000
644132
000001
000007
000008
000000
987845
419870


000000
000001
000007
000008
419870
644132
654132
700000
987845
*/
