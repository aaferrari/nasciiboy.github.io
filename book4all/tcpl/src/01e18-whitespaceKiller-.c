#include <stdio.h>

#define MAXLINE 1024     /* tamaño máximo de la línea de entrada */
#define YES        1     /* para control de lineas con '\n'      */
#define NO         0

int myGetline( char line[], int maxline );

/* este programa elimina los blancos al final de lineas
   asi como tambien suprime las lineas en blanco */
int main(){
  int len;               /* longitud actual de la línea */
  char line[MAXLINE];    /* línea de entrada actual     */
  int newline;           /* getline finalizo con '\n'?  */

  while( ( len = myGetline( line, MAXLINE ) ) > 0 )
    if( len > 0 ){
      if( line[len - 1] == '\n' ){
        newline = YES;
        if( len - 2 >= 0 ) len = len - 2;
        else               len =       0;
      } else {
        newline =  NO;
        len = len - 1;
      }

      while( len >= 0 &&
             line[len] == '\t' ||  line[len] == ' '
             ){
        line[len ] = '\0';
        len--;
      }

      if( len >= 0 ){
        printf( "%s", line );
        if( newline == YES && len > 0 ) putchar( '\n' );
      }
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
linea con tres espacios y dos tabuladores y nueva linea
linea con tres espacios y dos tabuladores y nueva linea

proxima linea espacios, tabulacion y nueva linea
proxima linea espacios, tabulacion y nueva linea


linea teminada con EOFlinea teminada con EOF

fin
fin

*/
