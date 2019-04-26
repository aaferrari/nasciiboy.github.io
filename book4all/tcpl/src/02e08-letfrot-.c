/* leftrot( x, n ) regresa x rotado a la
   derecha n posiciones de bits */
#include <stdio.h>

void print2bin( unsigned int x ){
  int i;
  unsigned int mask = 0x80000000;
  for( i = 32; i > 0; i--, mask >>= 1 ){
    if( x & mask ) putchar( '1' );
    else           putchar( '0' );
  }
}

unsigned letfrot( unsigned x, int n ){
  const unsigned int mask = 0x80000000;

  while( n-- ){
    if( x & mask ){
      x <<= 1;
      x |= 1;
    } else x <<= 1;
  }

  return x;
}

int main(void)
{
  // unsigned i = 0x0a0a0a0a;
  unsigned i = 2;
  unsigned k;
  int n = 4;

  k = letfrot(i, n );

  print2bin( i );
  printf(" = %3u\n", i);
  print2bin( k );
  printf(" = %3u  n = %d\n", k, n);

  return 0;
}
