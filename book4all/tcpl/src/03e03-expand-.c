/*
  expand( s1, s2 ) expande notacion abreviada como =a-z= proveniente
  de la cadena =s1=, en una lista equivalente completa =abc...xyz= en
  s2. Estan permitidas tanto mayusculas como minusculas asi como
  digitos
*/

#include <stdio.h>

#define SIZE  1024
#define OK       1
#define KO       0

int myGetline( char s[], int lim );
void expand( char s1[], char s2[] );
int okRange( int from, int to );

int main(){
  char s1[ SIZE ], s2[ SIZE ];

  while( myGetline( s1, SIZE ) != 0 ){
    expand( s1, s2 );
    puts( s2 );
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

void expand( char s1[], char s2[] ){
  int i, ii;

  for( i = ii = 0; s1[ i ] != '\0'; i++ ){
    if( s1[ i ] == '-' ){
      if( i == 0 || s1[ i + 1 ] == '\0' ) s2[ ii++ ] = '-';
      else if( okRange( s1[ i - 1 ], s1[ i + 1 ] ) ){
        s2[ ii++ ] = s1[ i - 1 ];
        while( s2[ ii - 1 ] < s1[ i + 1 ] ){
          s2[ ii ] = s2[ ii - 1 ] + 1;
          ii++;
        }
      }
    }
  }

  s2[ ii ] = '\0';
}

int okRange( int from, int to ){
  if( from <= to ){
    if     ( from >= '0' && from <= '9' &&
             to   >= '0' && to   <= '9' ) return OK;
    else if( from >= 'A' && from <= 'Z' &&
             to   >= 'A' && to   <= 'Z' ) return OK;
    else if( from >= 'a' && from <= 'z' &&
             to   >= 'a' && to   <= 'z' ) return OK;
    else return KO;
  } else return KO;
}

/* output
-0-9a-zA-C-H
-0123456789abcdefghijklmnopqrstuvwxyzABCCDEFGH
*/
