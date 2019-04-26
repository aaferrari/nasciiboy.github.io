#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getLine( char *s, int lim );

/* find: imprime lineas que coinciden con el patron del 1er. argumento */
int main( int argc, char *argv[] ){
  char line[ MAXLINE ];
  int found = 0;

  if( argc != 2 ) printf( "Usage: find pattern\n" );
  else
    while( getLine( line, MAXLINE ) > 0 )
      if( strstr( line, argv[ 1 ] ) != NULL ){
        printf( "%s", line );
        found++;
      }

  return found;
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


/* output  $ ./a.out ind
find a ind
find a ind
or no
or yes
ind
ind
*/
