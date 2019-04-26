/* invert( x, p, n ) regresa x con los n bits que inician en la
   posicion p invertidos */
#include <stdio.h>

void print2bin( unsigned int x ){
  int i;
  unsigned int mask = 0x80000000;
  for( i = 32; i > 0; i--, mask >>= 1 ){
    if( x & mask ) putchar( '1' );
    else           putchar( '0' );
  }
}

unsigned invert( unsigned x, unsigned p, unsigned n ){
  return x ^ (~(~0U << n) << ( p - n ) );
}

int main(void)
{
  unsigned i = 0x0a0a0a0a;
  unsigned k;
  int p = 6;
  int n = 4;

  k = invert(i, p, n );

  print2bin( i );
  printf(" = %3u\n", i);
  print2bin( k );
  printf(" = %3u p = %d n = %d\n", k, p, n);

  return 0;
}
