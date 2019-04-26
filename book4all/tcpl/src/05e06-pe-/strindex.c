#include <stdio.h>

#define MAXLINE 1000 /* longitud máxima por línea de entrada */

int getLine( char *line, int max );
int strindex( char *source, char *searchfor );

char *pattern = "ould"; /* patrón por buscar */

/* encuentra todas las líneas que coincidan con el patrón */
int main(){
  char line[ MAXLINE ];
  int found = 0;

  while( getLine( line, MAXLINE ) > 0 )
    if( strindex( line, pattern ) >= 0 ){
      printf( "%s", line );
      found++;
    }

  return found;
}

/* getline: trae línea y la pone en s, regresa su longitud */
int getLine( char *s, int lim ){
  char *i = s;
  int c;
  while( lim-- && ( c = getchar() ) != EOF && c != '\n' )
    *s++ = c;

  if( c == '\n' ) *s++ = c;
  *s = '\0';

  return s - i;
}
/* strindex: regresa el índice de t en s, -1 si no existe */
int strindex( char *s, char *t ){
  int i, j, k;
  int ii = -1;
  for( i = 0; s[ i ]; i++ ){
    for( j = i, k = 0; t[ k ] !='\0' && s[ j ] == t[ k ]; j++, k++ )
      ;
    if( t[ k ] == '\0' ) ii = i;
  }

  return ii;
}


/* output
could
could
not
cos
mot mould
mot mould
*/
