#include <stdio.h>

/* lower: convierte c a minuscula; solamente ASCII */
int lower( int c ){
  return ( c >= 'A' && c <= 'Z' ) ? c + 'a' - 'A' : c;
}


int main(){
  int i;
  char test[] = "ABCDEP aoeusnth 123AB\n";

  puts( test );

  for( i = 0; test[ i ] != '\0'; i++ )
    putchar( lower( test[ i ] ) );

  return 0;
}


/* output
ABCDEP aoeusnth 123AB

abcdep aoeusnth 123ab
*/
