#include <stdio.h>
#include <ctype.h>

int main(){  /* lower: convierte la entrada a minusculas */
  int c;

  while( (c = getchar()) != EOF )
    putchar( tolower( c ) );

  return 0;
}


/* output
THE HATEFUL EIGHT by Tarantino
the hateful eight by tarantino
*/
