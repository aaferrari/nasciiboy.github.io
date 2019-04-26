#include <stdio.h>
#include <string.h>

/* reverse: invierte la cadena s en el mismo lugar */
void reverse( char s[] ){
  int len = strlen( s );
  char temp = s[ len - 1 ];

  if( len > 1 ){
    s[ len -1 ] = '\0';
    reverse( s + 1 );

    s[ len - 1 ] = s[ 0 ];
    s[ 0 ] = temp;
  }
}

int main(){
  char s[] = "cadena 1234567890";

  puts( s );
  reverse( s );
  puts( s );

  return 0;
}


/* output
cadena 1234567890
0987654321 anedac
*/
