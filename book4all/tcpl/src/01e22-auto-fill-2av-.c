#include <stdio.h>

#define MAXLINE 1024   /* tamaño máximo de la línea de entrada */
#define SPLIT     10   /* caracteres maxmos por linea 80 +  \n' + '\0'     */

int myGetline( char s[], int lim );
int splitLine( char line[], char splitline[], int width );
void copy( char to[], char from[], int n );

/* este programa divide lineas mayores de n caracteres representados
   por la constante SPLIT, la divicion ocurre despues del ultimo
   caracter no blanco                                                 */
int main(){
  int len;                 /* longitud actual de la línea    */
  int lensplit;            /* longitud de linea dividida     */
  char line[MAXLINE];      /* línea de entrada actual        */
  char splitline[MAXLINE]; /* linea dividiva                 */

  while( ( len = myGetline( line, MAXLINE ) ) > 0 ){
    while( len > SPLIT + 1 ){
      lensplit = splitLine( line, splitline, SPLIT );
      printf( "%s\n", splitline );
      copy( line, &line[ lensplit ], '\0' );
      len -= lensplit;
    }

    if( len ) printf( "%s", line );
  }

  putchar( '\n' );
  return 0;
}

/* getline: lee una línea en s, regresa su longitud */
int myGetline( char s[], int lim ){
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

int splitLine( char line[], char splitline[], int width ){
  int i = 0;
  int splitPos = width;

  while( i < width ){
    if( line[ i ] == ' ' || line[ i ] == '\t' ) splitPos = i;
    i++;
  }

  if( splitPos < width ) copy( splitline, line, splitPos++ + 1 );
  else {
    while( line[ i ] != '\0' &&
           line[ i ] != ' '  && line[ i ] != '\t' )
      i++;

    splitPos = i;
    copy( splitline, line, splitPos );
  }

  return splitPos;
}

void copy( char to[], char from[], int n ){
  int i;
  i = 0;
  if( n == '\0' )
    while( ( to[i] = from[i]) != '\0' )
      ++i;
  else{
    while( i < n ){
      to[i] = from[i];
      ++i;
    }

    to[ i ] = '\0';
  }
}


/* output -> #define SPLIT     10
0123456789 0 2 4 6 8 01234567890123456789 0123456789 0123 567
0123456789
 0 2 4 6
8
01234567890123456789

0123456789
 0123 567

*/
