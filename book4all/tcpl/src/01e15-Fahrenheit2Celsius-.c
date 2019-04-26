# include <stdio.h>

float fahrToCelsius( float fahr );

/* imprime la tabla Fahrenheit-Celsius
   para fahr = 0, 20, ..., 300; versión de punto flotante */
int main(){
  float fahr;
  int lower, upper, step;

  lower = 0;              /* límite inferior de la tabla de temperaturas */
  upper = 300;            /* límite superior                             */
  step = 20;              /* tamaño del incremento                       */
  fahr = lower;

  while( fahr <= upper ){
    printf( "%3.0f %6.1f\n", fahr, fahrToCelsius( fahr ) );
    fahr = fahr + step;
  }

  return 0;
}

float fahrToCelsius( float fahr ){
  return ( 5.0/9.0 ) * ( fahr - 32.0 );
}

/* output
  0  -17.8
 20   -6.7
 40    4.4
 60   15.6
 80   26.7
100   37.8
120   48.9
140   60.0
160   71.1
180   82.2
200   93.3
220  104.4
240  115.6
260  126.7
280  137.8
300  148.9
*/
