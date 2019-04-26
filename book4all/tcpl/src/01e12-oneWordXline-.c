#include <stdio.h>
#define  IN 1   /* en una palabra */
#define OUT 0   /* fuera de una palabra */

/* imprime una palabra por linea */
main(){
  int c, word;
  word = OUT;

  while( (c = getchar() ) != EOF ){
    if( word == IN ){
      if( c == ' ' || c == '\n' || c == '\t' ){
        word = OUT;
        putchar( '\n' );
      } else putchar( c );
    }

    if( word == OUT ){
      if( c != ' ' && c != '\n' && c != '\t' ){
        word = IN;
        putchar( c );
      }
    }
  }
}

/* output
	a b	c  d  e   	f  g   h
a
b
c
d
e
f
g
h
123 1234 12345		0
123
1234
12345
0
*/
