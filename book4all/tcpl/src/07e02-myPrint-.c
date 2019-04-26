#include <stdio.h>
#include <ctype.h>

#define MAXWIDTH 15

/* myPrint: toma la entrada y la despliega de forma sensata */
int main(){
  int c = 0;
  int width = 0;
  int nl;

  while( (c = getchar()) != EOF ){
    nl = 0;

    if( ++width > MAXWIDTH  ){
      putchar( '\n' );
      width = 0;
      nl = 1;
    }


    if( c == '\n' ){
      if( !nl ) putchar( '\n' );
      width = 0;
    } else {
      if( isprint( c ) ) putchar( c );
      else printf( "0x%x", c );
    }

  }

  putchar( '\n' );

  return 0;
}


/* output  $ ./downcase
123456789012345
123456789012345
123456789012345678901234567890
123456789012345
678901234567890
aoeu aoeui snth snthd aoeu snth
aoeu aoeui snth
 snthd aoeu snth
  huon onte a
  huon onte a
oe
oe
uonte un noeth onuh eu sonte
uonte un noeth
onuh eu sonte

*/
