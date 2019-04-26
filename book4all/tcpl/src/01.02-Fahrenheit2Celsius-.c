#include <stdio.h>
/* imprime la tabla Fahrenheit-Celsius
   para fahr = 0, 20, ..., 300 */

main(){
  int fahr, celsius;
  int lower, upper, step;

  lower = 0;              /* límite inferior de la tabla de temperaturas */
  upper = 300;            /* límite superior                             */
  step = 20;              /* tamaño del incremento                       */
  fahr = lower;

  while( fahr <= upper ){
    celsius = 5 * (fahr - 32) / 9;
    // printf("%d\t%d\n", fahr, celsius);
         printf( "%3d %6d\n", fahr, celsius );
    fahr = fahr + step;
  }
}

/* output
  0    -17
 20     -6
 40      4
 60     15
 80     26
100     37
120     48
140     60
160     71
180     82
200     93
220    104
240    115
260    126
280    137
300    148
*/
