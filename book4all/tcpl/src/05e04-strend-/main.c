#include <stdio.h>

int main(){
  int strend( char *, char * );
  int i;
  char *test[] = {
    "GNU not is UNIX",
    "GNU not is LINUX",
    "GNU a hurd of \\~{N}u's",
    "GNU like UNIX",
    "NIX"
  };
  char * keyword = "UNIX";

  i = sizeof( test ) / sizeof( *test );
  while( i-- )
    printf( "string = %25s keyword = %s strend = %d\n\n",
            test[ i ], keyword, strend( test[ i ], keyword ) );

  return 0;
}


/* output  $ gcc main.c strend.c
string =                       NIX keyword = UNIX strend = 0

string =             GNU like UNIX keyword = UNIX strend = 1

string =    GNU a hurd of \~{N}u's keyword = UNIX strend = 0

string =          GNU not is LINUX keyword = UNIX strend = 0

string =           GNU not is UNIX keyword = UNIX strend = 1

*/
