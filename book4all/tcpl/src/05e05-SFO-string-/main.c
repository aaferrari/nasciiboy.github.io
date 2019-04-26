#include <stdio.h>

void strncpy( char *, char *, unsigned int );
void strncat( char *, char *, unsigned int );
int  strncmp( char *, char *, unsigned int );

int main(){
  char s[ 1024 ];

  strncpy( s, "GNU not is UNIX", 11 );
  puts( s );

  strncat( s, "UNIXXX", 4 );
  puts( s );

  printf( "s = %s, t = %s, strncmp 3 = %d\n",
          s, "GNUs", strncmp( s, "GNUs", 3 ) );

  printf( "s = %s, t = %s, strncmp 5 = %d\n",
          s, "GNUs", strncmp( s, "GNUs", 5 ) );

  printf( "s = %s, t = %s, strncmp 4 = %d\n",
          s, "GNUs", strncmp( s, "GNUs", 4 ) );

  return 0;
}


/* output $ gcc main.c string.c
GNU not is
GNU not is UNIX
s = GNU not is UNIX, t = GNUs, strncmp 3 = 0
s = GNU not is UNIX, t = GNUs, strncmp 5 = -83
s = GNU not is UNIX, t = GNUs, strncmp 4 = -83
*/
