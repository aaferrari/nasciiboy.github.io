#include <stdio.h>

int main(){  /* calculadora rudimentaria */
  double sum, v;

  sum = 0;
  while( scanf( "%lf", &v ) == 1 )
    printf( "\t%.2f\n", sum += v );

  return 0;
}


/* output
10
	10.00
10
	20.00
-10
	10.00
990
	1000.00
-.05
	999.95
*/
