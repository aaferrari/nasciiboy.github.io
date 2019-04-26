#include "syscalls.h"

int main(){
  char buf[ BUFSIZ ];
  int n;

  while( (n = read( 0, buf, BUFSIZ )) > 0 )
    write( 1, buf, n );

  return 0;
}


/* output
1234567891123456789212345678931234567894123456789512345678961234567987
1234567891123456789212345678931234567894123456789512345678961234567987
aoeu sth aoeu
aoeu sth aoeu
*/
