/* squeeze( s1, s2 ) borra cada caracter de s1 que coincida con
   cualquier caracter de la cadena s2                           */
#include <stdio.h>

#define LIMIT 1024

int any( char s1[], char s2[] );
int myGetline( char s[], int lim );

int main(){
  char s1[LIMIT];
  char s2[LIMIT];
  int match;

  printf( "s1 (fin con EOF)\n" );
  while( !myGetline( s1, LIMIT ) );

  printf( "\ns2 (fin con EOF)\n" );
  while( !myGetline( s2, LIMIT ) );

  match = any( s1, s2 );

  if( match >= 0 ){
    printf( "\ncoincidencia en la posicion %d\n", match );
  } else printf( "\nsin coincidencia\n" );

  return 0;
}



int myGetline( char s[], int lim ){
  int c, i;

  for( i=0; i < lim-1 && ( c = getchar() ) != EOF && c != '\n'; i++ )
    s[i] = c;

  if( c == '\n' ) s[i++] = c;

  s[i] = '\0';

  return i;
}

int any( char s1[], char s2[] ){
  int i, ii;

  for( i = 0; s1[ i ] != '\0'; i++ ){
    for( ii = 0; s2[ ii ] != '\0'; ii++ )
      if( s1[ i ] == s2[ ii ] ) return i;
  }

  return -1;
}


/* output
s1 (fin con EOF)
0123456789

s2 (fin con EOF)
7
coincidencia en la posicion 7
*/

/* output
s1 (fin con EOF)
0123456789 013456789
s2 (fin con EOF)
a
sin coincidencia
*/
