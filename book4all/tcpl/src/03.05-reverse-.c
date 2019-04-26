#include <string.h>

/* reverse: invierte la cadena s en el mismo lugar */
void reverse( char s[] ){
  int c, i, j;
  for( i = 0, j = strlen( s ) - 1; i < j; i++, j-- ){
    c = s[ i ];
    s[ i ] = s[ j ];
    s[ j ] = c;
  }
}
