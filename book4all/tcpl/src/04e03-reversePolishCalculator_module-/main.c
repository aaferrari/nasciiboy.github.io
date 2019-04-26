#include <stdio.h>
#include <stdlib.h>  /* para atof() */
#include <math.h>    /* para fmod() */

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
    case '%':
      op2 = pop();
      push( fmod( pop(), op2 ) );
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


/* output $ gcc main.c push-pop.c getop.c getch-ungetch.c -lm
10 -5 -
	15
-5 -5 *
	25
-10 -10 + -10 -10 + -
	0
-.25 -.25 + 10 -11 + -
	0.5
*/
