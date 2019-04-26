#include <stdio.h>
#include <stdlib.h>  /* para atof() */

#define MAXOP   100  /* máx tamaño de operando u operador */
#define NUMBER  '0'  /* señal de que un número se encontró */

int getop( char [] );
void push( double );
double pop( void );

/* calculadora polaca inversa */
int main(){
  int type;
  double op2;
  char s[ MAXOP ];

  while( ( type = getop( s ) ) != EOF ){
    switch( type ){
    case NUMBER:
      push( atof( s ) );
      break;
    case '+':
      push( pop() + pop() );
      break;
    case '*':
      push( pop() * pop() );
      break;
    case '-':
      op2 = pop();
      push( pop() - op2 );
      break;
    case '/':
      op2 = pop();
      if( op2 != 0.0 )
        push( pop() / op2 );
      else
        printf( "error: divisor cero\n" );
      break;
    case '\n':
      printf( "\t%.8g\n", pop() );
      break;
    default:
      printf( "error: comando desconocido %s\n", s );
      break;
    }
  }

  return 0;
}


/* output $ gcc main.c push-pop.c getop.c getch-ungetch.c

error: pila vacía
	0
4 5 + 46 8 - +
	47

error: pila vacía
	0
10 5 - 10 5 - + 2 +
	12
5 +
error: pila vacía
	5

error: pila vacía
	0
*/
