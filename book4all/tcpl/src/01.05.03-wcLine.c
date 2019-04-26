#include <stdio.h>

/* cuenta las líneas de la entrada */
main(){
  int c, nl;

  nl = 0;
  while( ( c = getchar() ) != EOF )
    if( c == '\n' )
      ++nl;

  printf("%d\n", nl);
}

/* output
1
2
3
4
5
6
6
*/
