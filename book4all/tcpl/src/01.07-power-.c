#include <stdio.h>

int power(int m, int n);

/* prueba la función power */
main()
{
  int i;

  for( i = 0; i < 10; ++i )
    printf( "%d %d %d\n", i, power( 2, i ), power( -3, i ) );

  return 0;
}

/* power: eleva la base a la n-esima potencia; n >= 0 */
int power( int base, int n )
{
  int i, p;
  p = 1;

  for( i = 1; i <= n; ++i )
    p = p * base;

  return p;
}

/* output
0 1 1
1 2 -3
2 4 9
3 8 -27
4 16 81
5 32 -243
6 64 729
7 128 -2187
8 256 6561
9 512 -19683
*/
