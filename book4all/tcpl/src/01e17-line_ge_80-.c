#include <stdio.h>

#define MAXLINE 1024     /* tamaño máximo de la línea de entrada */
#define MIN       80     /* tamaño minimo de lina a imprimir     */

int myGetline( char line[], int maxline );

/* imprime líneas de entrada de longitud mayor a MIN */
int main(){
  int len;               /* longitud actual de la línea */
  char line[MAXLINE];    /* línea de entrada actual */

  while( ( len = myGetline( line, MAXLINE ) ) > 0 )
    if( len > MIN ){
      printf( "%s", line );
    }

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
0123456789112345678921234567893123456794123456789512345678961234567897123456789
11111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111
00000000000000000000000000000000000000000000000000000000000000000000000000000000000
00000000000000000000000000000000000000000000000000000000000000000000000000000000000
---------------------------------
*/
