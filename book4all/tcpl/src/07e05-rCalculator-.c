#include <stdio.h>

#define MAXLINE 100

/* calculadora rudimentaria */
int main(){
  float sum, dtmp;

  sum = 0;
  while( scanf( "%f", &dtmp ) )
    printf("\t%.2f\n", sum += dtmp );

  return 0;
}

/* output $ gcc rCalculator.c atof.c getline.c
1000
	1000.00
-475
	525.00
+25.025
	550.03
-.025
	550.00
-500
	50.00
+.05
	50.05
-49.05
	1.00
a
*/
