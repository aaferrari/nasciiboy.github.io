#include <stdio.h>

#define MAXLINE 1000  /* tamano maximo de la linea de entrada */

int getLine( char *line, int maxline );
void copy( char *to, char *from );

/* imprime la linea de entrada mas larga */
int main(){
  int len;                      /* longitud actual de la linea             */
  int max;                      /* maxima longitud vista hasta el momento  */
  char line[ MAXLINE ];         /* linea de entrada actual                 */
  char longest[ MAXLINE ];      /* la liena mas larga se guarda aqui       */

  max = 0;
  while( ( len = getLine( line, MAXLINE ) ) > 0 )
    if( len > max ){
      max = len;
      copy( longest, line );
    }
  if( max > 0 )                 /* hubo una linea                          */
    printf( "%s", longest );
  return 0;
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

/* copy: copia 'from' en 'to'; supone que td es suficientemente grande */
void copy( char *to, char *from ){
  while( *to++ = *from++ );
}


/* output
linea uno
linea ddooss
linea 3
linea ddooss
*/
