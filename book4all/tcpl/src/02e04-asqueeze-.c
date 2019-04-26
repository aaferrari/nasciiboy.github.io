/* squeeze( s1, s2 ) borra cada caracter de s1 que coincida con
   cualquier caracter de la cadena s2                           */
#include <stdio.h>

#define LIMIT 1024

void squeeze( char s1[], char s2[] );
int myGetline( char s[], int lim );

int main(){
  char s1[LIMIT];
  char s2[LIMIT];

  while( myGetline( s1, LIMIT ) ){
    myGetline( s2, LIMIT );
    squeeze( s1, s2 );
    printf( "\n%s\n", s1 );
  }

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

void squeeze( char s1[], char s2[] ){
  int i, ii, iii;
  int match;

  for( i = iii = 0; s1[ i ] != '\0'; i++ ){
    match = 0;

    for( ii = 0; s2[ ii ] != '\0' && !match; ii++ )
      if( s1[ i ] == s2[ ii ] ) match = 1;
    if( !match ) s1[ iii++ ] = s1[ i ];
  }

  s1[ iii ] = '\0';
}


/* output
0123456789 0123456789 0123456789
02468

13579 13579 13579
aoeui snthd ;,.py lrcgf 'qjkx zvwmb aoeui snthd
aei[ &t

ousnhd;,.pylrcgf'qjkxzvwmbousnhd
*/
