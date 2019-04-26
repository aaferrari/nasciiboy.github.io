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
  double op2;
  char s[ MAXOP ];
  double temp1;
  double temp2;
  while( ( type = getop( s ) ) != EOF ){
    switch( type ){
    case NUMBER:
      push( atof( s ) );
      break;
    case 't':
      printf( "\t%.8g\n", top() );
      break;
    case 'p':
      printf( "\t%.8g\n", pop() );
      break;
    case 'd':
      push( top() );
      break;
    case 's':
      temp1 = pop();
      temp2 = pop();
      push( temp1 );
      push( temp2 );
      break;
    case 'c':
      clear();
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
25 15
t
	15
s t
	25
p
	25
t
	15
1 2 3 4 5 6 7 8 9
t
	9
c t
error: pila vacía
	0
c
t
error: pila vacía
	0
*/
