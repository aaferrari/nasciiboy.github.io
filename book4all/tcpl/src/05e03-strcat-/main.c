#include <stdio.h>

int main(){
  void strcat( char *, char * );

  char s[1024] = "Emacs ";
  char *t = "Rocks";

  puts( s );
  strcat( s, t );
  puts( s );

  return 0;
}


/* output  $ gcc main.c strcat.c
Emacs
Emacs Rocks
*/
