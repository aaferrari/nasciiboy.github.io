#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAXVAL 100   /* máxima profundidad de la pila val   */

int sp = 0;          /* siguiente posición libre en la pila */
double val[MAXVAL];  /* valores de la pila                  */
double var[ 'z' - 'a' ];
double last = 0;

void push( double f );
double pop( void );
void string_funct( char s[] );
double top( void );
void clear( void );
double get_var( int nvar );
void set_var( int nvar, double val );

/* push: introduce f a la pila */
void push( double f ){
  if( sp < MAXVAL )
    val[ sp++ ] = f;
  else
    printf( "error: pila llena, no puede efectuar push %g\n", f );
}

/* pop: extrae y regresa el valor superior de la pila */
double pop( void ){
  if( sp > 0 )
    return last = val[ --sp ];
  else {
    printf( "pop: pila vacía\n" );
    return last = 0.0;
  }
}

void string_funct( char s[] ){
  if( !strncmp( "set", s, 3 ) ){
    set_var( s[ 3 ] - 'a', pop() );
  } else if( !strncmp( "get", s, 3 ) ){
    push( get_var( s[ 3 ] - 'a' ) );
  } else if( !strcmp( "last", s ) ){
    push( last );
  } else if( !strcmp( "fabs", s ) ){
    push( fabs( pop() ) );
  } else if( !strcmp( "sqrt", s ) ){
    push( sqrt( pop() ) );
  } else if( !strcmp( "pow", s ) ){
    double op2;
    op2 = pop();
    if( op2 != 0.0 )
      push( pow( pop(), op2 ) );
    else
      printf( "error: op1 igual a cero\n" );
  } else printf( "error: %s comando no soportado\n", s );
}

double top( void ){
  if( sp > 0 ) return last = val[ sp - 1 ];
  else {
    printf( "error: pila vacía\n" );
    return last = 0.0;
  }
}

void clear( void ){ val[ sp = 0 ] = 0; }

double get_var( int nvar ){
  if( nvar >= 0 && nvar <= 'z' - 'a' ) return var[ nvar ];
  else {
    printf( "error: %d variable inexistente\n", nvar );
    return 0;
  }
}

void set_var( int nvar, double val ){
  if( nvar >= 0 && nvar <= 'z' - 'a' ) var[ nvar ] = val;
  else printf( "error: %d variable inexistente\n", nvar );
}
