#include <string.h>

int strend( char *s, char *t ){
  size_t ws = strlen( s );
  size_t wt = strlen( t );

  if( ws < wt || s == 0 || t == 0 ) return 0;

  s += ws - 1;
  t += wt - 1;
  while( wt ){
    if( *s-- != *t-- ) return 0;
    wt--;
  }

  return 1;
}
