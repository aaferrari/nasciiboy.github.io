#include <stdio.h>

#define MAXVAL 100   /* máxima profundidad de la pila val   */

int sp = 0;          /* siguiente posición libre en la pila */
double val[MAXVAL];  /* valores de la pila                  */

/* push: introduce f a la pila */
void push( double f ) {
  if( sp < MAXVAL )
    val[ sp++ ] = f;
  else
    printf( "error: pila llena, no puede efectuar push %g\n", f );
}

/* pop: extrae y regresa el valor superior de la pila */
double pop( void ){
  if( sp > 0 )
    return val[ --sp ];
  else {
    printf( "error: pila vacía\n" );
    return 0.0;
  }
}

double top( void ){
  if( sp > 0 ) return val[ sp - 1 ];
  else {
    printf( "error: pila vacía\n" );
    return 0.0;
  }
}

void clear( void ){ val[ sp = 0 ] = 0; }
