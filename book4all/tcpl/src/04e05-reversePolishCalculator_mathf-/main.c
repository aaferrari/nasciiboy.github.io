#include <stdio.h>
#include <stdlib.h>  /* para atof() */
#include <math.h>    /* para fmod() */

#define MAXOP   100  /* máx tamaño de operando u operador */
#define NUMBER  '0'  /* señal de que un número se encontró */

int getop( char [] );
void push( double );
double pop( void );
double top( void );
void clear( void );

/* calculadora polaca inversa */
int main(){
  int type;
  double op1;
  double op2;
  char s[ MAXOP ];

  while( ( type = getop( s ) ) != EOF ){
    switch( type ){
    case NUMBER:
      push( atof( s ) );
      break;
    case '?':   /* imprime tope de pila  */
      printf( "\t%.8g\n", top() );
      break;
    case '<':  /* sacar ultimo elemento  */
      printf( "\t%.8g\n", pop() );
      break;
    case '&':  /* duplicar tope de pila  */
      push( top() );
      break;
    case '~':  /* intercambiar elementos */
      op1 = pop();
      op2 = pop();
      push( op1 );
      push( op2 );
      break;
    case '!': /* limpiar la pila         */
      clear();
      break;
    case '$': /* fabs        */
      push( fabs( pop() ) );
      break;
    case '#': /* sqrt        */
      push( sqrt( pop() ) );
      break;
    case '^': /* pow         */
      op2 = pop();
      if( op2 != 0.0 )
        push( pow( pop(), op2 ) );
      else
        printf( "error: op1 igual a cero\n" );
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
      // printf( "\t%.8g\n", pop() );
      break;
    default:
      printf( "error: comando desconocido %s\n", s );
      break;
    }
  }

  return 0;
}


/* output $ gcc main.c push-pop.c getop.c getch-ungetch.c -lm
2 10 ^ ? -1000 $ ? 9 # ?
	1024
	1000
	3
*/
