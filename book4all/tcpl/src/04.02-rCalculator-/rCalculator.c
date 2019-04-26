#include <stdio.h>

#define MAXLINE 100

/* calculadora rudimentaria */
int main()
{
  double sum, atof(char []);
  char line[MAXLINE];
  int getLine(char line[], int max);

  sum = 0;
  while (getLine(line, MAXLINE) > 0)
    printf("\t%g\n", sum += atof(line));
  return 0;
}

/* output $ gcc rCalculator.c atof.c getline.c
1000
	1000
-475
	525
+25.025
	550.025
.025
	550.05
-500
	50.05
*/
