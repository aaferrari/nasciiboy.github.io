#include <stdio.h>

/* reemplaza tabulacion por "\t", retroceso por "\b" y
   diaganal invertida por "\\"                         */
main(){
  int c;

  while( ( c = getchar() ) != EOF ){
    if( c >= 0 ){
      if( c < '\b' )
        putchar( c );
      if( c == '\b' )
        printf( "\\b" );

      if( c > '\b' ){
        if( c == '\t' )
          printf( "\\t" );

        if( c > '\t' ){
          if( c < '\\' )
            putchar( c );
          if( c == '\\' )
            printf( "\\\\" );
          if( c > '\\' )
            putchar( c );
        }
      }
    }
  }
}


/* output
	0  \  0
\t0  \\  0
\	\
\\\t\\
*/
