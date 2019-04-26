#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main( int argc, char ** argv ){  /* lower: convierte la entrada a minusculas */
  int c;

  if( strstr( *argv, "upcase" ) ){
    while( (c = getchar()) != EOF )
      putchar( toupper( c ) );

    return 0;
  } else if( strstr( *argv, "downcase" ) ){
    while( (c = getchar()) != EOF )
      putchar( tolower( c ) );

    return 0;
  }

  printf( "ERR argv[0] == \"%s\", [upcase|downcase]\n", *argv );
  return 1;
}


/* output  $ ./downcase
THE HATEFUL EIGHT by Tarantino
the hateful eight by tarantino
*/

/* output  $ ./upcase
THE HATEFUL EIGHT by Tarantino
THE HATEFUL EIGHT BY TARANTINO
*/

/* output  $ ./a.out
ERR argv[0] == "./a.out", [upcase|downcase]
*/
