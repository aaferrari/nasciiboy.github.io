#include <stdio.h>

#define  ON 1
#define OFF 0

const int lim = 10;

/* equivalencia de condicion de ciclo while sin && o || */
int main(){
  int c, i;
  char next = ON;
  char s[ lim ];

  printf( "while( ( i < lim-1 && (c = getchar()) != '\\n' && c != EOF );\n" );

  for( i = 0; next; i++ ){
    if( i < lim - 1 ){
      if( (c = getchar()) != '\n' ){
        if( c == EOF ) next = OFF;
        else           s[i] =   c;
      } else           next = OFF;
    } else             next = OFF;
  }

  s[ i ] = '\0';

  printf( "see you later: %s\n", s );

  return 0;
}

/* output
while( ( i < lim-1 && (c = getchar()) != '\n' && c != EOF );
0123456789
see you later: 012345678
*/

/* output
while( ( i < lim-1 && (c = getchar()) != '\n' && c != EOF );
emacs !!!!
see you later: emacs !!!
*/
