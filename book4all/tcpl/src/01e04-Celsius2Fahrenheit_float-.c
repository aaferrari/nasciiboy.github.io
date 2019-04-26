# include <stdio.h>

/* imprime la tabla Fahrenheit-Celsius
   para fahr = 0, 20, ..., 300; versión de punto flotante */

main(){
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;              /* límite inferior de la tabla de temperaturas */
  upper = 300;            /* límite superior                             */
  step = 20;              /* tamaño del incremento                       */
  celsius = lower;

  printf( "celsius -- fahrenheit\n" );

  while( celsius <= upper ){
    fahr = ( ( 9.0/5.0 ) * celsius ) + 32.0;
    printf( "%7.0f -- %10.1f\n", celsius, fahr );
    celsius = celsius + step;
  }
}

/* output
celsius -- fahrenheit
      0 --       32.0
     20 --       68.0
     40 --      104.0
     60 --      140.0
     80 --      176.0
    100 --      212.0
    120 --      248.0
    140 --      284.0
    160 --      320.0
    180 --      356.0
    200 --      392.0
    220 --      428.0
    240 --      464.0
    260 --      500.0
    280 --      536.0
    300 --      572.0
*/
