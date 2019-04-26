#include <stdio.h>

#define MAXLINE 1024       /* tamaño máximo de la línea de entrada */
#define SBLANK  "       "  /* cadena de sustitucion colacada por cada tabulador */

int myGetline( char line[], int maxline );

/* este programa reeplaza tabuladores por =n= espacios
   representados en la cadena SBLANK */
int main(){
  int len;               /* longitud actual de la línea */
  int i;                 /* contador de impresion       */
  char line[MAXLINE];    /* línea de entrada actual     */

  while( ( len = myGetline( line, MAXLINE ) ) > 0 )
    if( len > 0 ){
      i = 0;
      while( i <= len ){
        if( line[i] != '\t' ) putchar( line[i] );
        else                  printf( "%s", SBLANK );

        i++;
      }
    }

  putchar( '\n' );
  return 0;
}

/* getline: lee una línea en s, regresa su longitud */
int myGetline( char s[],int lim ){
  int c, i;

  for( i=0; i < lim-1 && ( c = getchar() ) != EOF && c != '\n'; ++i )
    s[i] = c;

  if( c == '\n' ){
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}


/*output
tabulador	tabulador	nueva linea
tabulador       tabulador       nueva linea
3\t			EOF3\t                     EOF

3\t     		\n
3\t                     \n


*/
