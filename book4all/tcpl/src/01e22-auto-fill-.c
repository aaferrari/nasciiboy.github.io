#include <stdio.h>

#define MAXLINE 1024   /* tamaño máximo de la línea de entrada */
#define SPLIT     10   /* caracteres maxmos por linea 80 +  \n' + '\0'     */

int myGetline( char s[], int lim );
int splitLine( char line[], char splitline[], int width );
void copy( char to[], char from[] );

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

      copy( line, &line[ lensplit ] );
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
  int iline, i;

  iline = width - 1;

  if( line[ iline ] == ' ' || line[ iline ] == '\t' ){
    iline++;
    while( line[ iline ] != '\0' &&
           ( line[ iline ] == ' ' || line[ iline ] == '\t' ) )
      iline++;

    for( i = 0; i < iline; i++)
      splitline[ i ] = line[ i ];
    splitline[ i ] = '\0';
  } else if( line[ iline + 1 ] == ' ' || line[ iline + 1 ] == '\t' ){
    iline += 2;
    while( line[ iline ] != '\0' &&
           ( line[ iline ] == ' ' || line[ iline ] == '\t' ) )
      iline++;

    for( i = 0; i < iline; i++)
      splitline[ i ] = line[ i ];
    splitline[ i ] = '\0';
  } else {
    while( iline >= 0 &&
           line[ iline ] != ' ' && line[ iline ] != '\t' )
      iline--;

    if( iline >= 0 ){
      for( i = 0; i <= iline; i++)
        splitline[ i ] = line[ i ];
      splitline[ i ] = '\0';
    } else {
      iline = width;
      while( line[ iline ] != '\0' &&
             line[ iline ] != ' ' && line[ iline ] != '\t' )
        iline++;

      if( line[ iline ] == ' ' || line[ iline ] == '\t' ){
        iline += 1;
        while( line[ iline ] != '\0' &&
               ( line[ iline ] == ' ' || line[ iline ] == '\t' ) )
          iline++;

        for( i = 0; i < iline; i++)
          splitline[ i ] = line[ i ];
        splitline[ i ] = '\0';
      } else {
        for( i = 0; i < iline; i++)
          splitline[ i ] = line[ i ];
        splitline[ i ] = '\0';
      }
    }
  }

  return i;
}

void copy( char to[], char from[] ){
  int i;
  i = 0;
  while( ( to[i] = from[i]) != '\0' )
    ++i;
}

/* output -> #define SPLIT     10
0123456789          012345      0123456 0 2 4 6 8
0123456789
012345
0123456 0
2 4 6 8
0000000000 11111111111111 2222222222
0000000000
11111111111111
2222222222
      22222222222222   222222222222222 33333333

22222222222222
222222222222222
33333333

*/
