#include <stdio.h>

#define MAXLINE 1024     /* tamaño máximo de la línea de entrada */

int myGetline( char line[], int maxline );

/* este programa invirte el orden de
   impresion de la cadena de entrada */
int main(){
  int len;               /* longitud actual de la línea */
  char line[MAXLINE];    /* línea de entrada actual     */

  while( ( len = myGetline( line, MAXLINE ) ) > 0 )
    while( len >= 0 )
      putchar( line[ len-- ] );

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
linea terminada con nueva linea

aenil aveun noc adanimret aenil\n

n\linea termitada por EOFFOE rop adatimret aenil
*/
