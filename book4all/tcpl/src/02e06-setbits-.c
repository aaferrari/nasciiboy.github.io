/* setbits regresa x con los n bits que inician en
   la posicion p iguales a los n bits mas a la derecha
   de y, dejando los otros bits sin cambio */
#include <stdio.h>

void print2bin( unsigned int x ){
  int i;
  unsigned int mask = 0x80000000;
  for( i = 32; i > 0; i--, mask >>= 1 ){
    if( x & mask ) putchar( '1' );
    else           putchar( '0' );
  }
}

unsigned setbits( unsigned x, unsigned p, unsigned n, unsigned y ){
  y &= ~( ~0 << n );
  y <<= ( p - n );
  x &= ( ~0 << p ) | ~( ~0 << ( p - n ) );
  return x | y;
}

int main(void)
{
  unsigned i = 0x57f7f5;;
  unsigned j = 0x7f;;
  unsigned k;
  int p = 32;
  int n = 8;

  k = setbits(i, p, n, j);

  print2bin( i );
  printf(" = %3u\n", i);
  print2bin( j );
  printf(" = %3u\n", j);
  print2bin( k );
  printf(" = %3u p = %d n = %d\n", k, p, n);

  return 0;
}
