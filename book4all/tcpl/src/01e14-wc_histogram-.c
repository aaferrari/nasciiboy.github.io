#include <stdio.h>

/* imprime el histograma de las frecuencias con que se
   presentan diferentes caracteres liedos a la entrada */
main(){
  int c, i, ii, nwhite, nother;
  int ndigit[10];
  nwhite = nother = 0;

  for( i = 0; i < 10; ++i ) ndigit[i] = 0;

  while( ( c = getchar() ) != EOF )
    if( c >= '0' && c <= '9' )
      ++ndigit[ c - '0' ];
    else if( c == ' ' || c == '\n' || c == '\t' )
      ++nwhite;
    else
      ++nother;

  printf( "\ndigits:\n" );

  for( i = 0; i < 10; ++i ){
    printf( "%-10d", i );

    for( ii = 0; ii < ndigit[i]; ii++ )
      putchar( '*' );

    putchar( '\n' );
  }

  printf( "\nespacios blancos:\n%-10d", nwhite );
  for( i = 0; i < nwhite; i++ )
    putchar( '*' );

  printf( "\n\nother:\n%-10d", nother );
  for( i = 0; i < nother; i++ )
    putchar( '*' );

  putchar( '\n' );
}

/* output
0 1 2 3 4 5 6	7 8	90
a b c d e f g	h i	jk
digits:
0         **
1         *
2         *
3         *
4         *
5         *
6         *
7         *
8         *
9         *

espacios blancos:
19        *******************

other:
11        ***********
*/
