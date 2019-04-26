# include <stdio.h>

/* imprime la tabla Fahrenheit-Celsius
   para fahr = 0, 20, ..., 300; versión de punto flotante */

main(){
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;              /* límite inferior de la tabla de temperaturas */
  upper = 300;            /* límite superior                             */
  step = 20;              /* tamaño del incremento                       */
  fahr = lower;

  printf( "fahrenheit -- celsius\n" );

  while( fahr <= upper ){
    celsius = ( 5.0/9.0 ) * ( fahr - 32.0 );
    printf( "%10.0f -- %7.1f\n", fahr, celsius );
    fahr = fahr + step;
  }
}

/* output
fahrenheit -- celsius
         0 --   -17.8
        20 --    -6.7
        40 --     4.4
        60 --    15.6
        80 --    26.7
       100 --    37.8
       120 --    48.9
       140 --    60.0
       160 --    71.1
       180 --    82.2
       200 --    93.3
       220 --   104.4
       240 --   115.6
       260 --   126.7
       280 --   137.8
       300 --   148.9
*/
