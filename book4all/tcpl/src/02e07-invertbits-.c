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
  unsigned y = ~x;
  y >>= p - n;
  y &= ~( ~0 << n );
  y <<= ( p - n );

  x &= ( ~0 << p ) | ~( ~0 << ( p - n ) );
  return x | y;
}

int main(void)
{
  unsigned i = 0x57f7f5;;
  unsigned k;
  int p = 8;
  int n = 8;

  k = invert(i, p, n );

  print2bin( i );
  printf(" = %3u\n", i);
  print2bin( k );
  printf(" = %3u p = %d n = %d\n", k, p, n);

  return 0;
}
