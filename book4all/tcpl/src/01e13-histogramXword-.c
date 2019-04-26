#include <stdio.h>
#define  IN 1   /* en una palabra */
#define OUT 0   /* fuera de una palabra */

/* imprime un histograma horizontal con la longitud de cada palabra */
main(){
  int c, word;
  word = OUT;

  while( (c = getchar() ) != EOF ){
    if( word == IN ){
      if( c == ' ' || c == '\n' || c == '\t' ){
        word = OUT;
        putchar( '\n' );
      } else putchar( '*' );
    }

    if( word == OUT ){
      if( c != ' ' && c != '\n' && c != '\t' ){
        word = IN;
        putchar( '*' );
      }
    }
  }
}

/* output
  1  		123 123456 'q "oa abcd
*
***
******
**
***
****

uno tres cinco cuatro siete ocho dos
***
****
*****
******
*****
****
***
*/
