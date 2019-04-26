#include <stdio.h>
#include <stdlib.h>  /* para atof() */
#include <math.h>    /* para fmod() */

#define MAXOP   100  /* máx tamaño de operando u operador   */
#define NUMBER  '0'  /* señal de que un número se encontró  */
#define STRING  '1'  /* señal de que una cadena se encontró */


int getop( char line[], char s[] );
void push( double );
double pop( void );
double top( void );
void clear( void );
void string_funct( char s[] );


/* calculadora polaca inversa */
int main( int argc, char *argv[] ){
  int type;
  double op1;
  double op2;
  char s[ MAXOP ];

  if( argc == 1 ){
    printf( "expr ARGUMENT(s)\n" );
    return 1;
  }

  argc--;
  argv++;

  while( argc ){
    while( ( type = getop( *argv, s ) ) != EOF ){
      switch( type ){
      case NUMBER:
        push( atof( s ) );
        break;
      case STRING:  /* funcion matematica     */
        string_funct( s );
        break;
      case '?':     /* imprime tope de pila   */
        printf( "\t%.8g\n", top() );
        break;
      case '<':     /* sacar ultimo elemento  */
        printf( "\t%.8g\n", pop() );
        break;
      case '&':     /* duplicar tope de pila  */
        push( top() );
        break;
      case '~':     /* intercambiar elementos */
        op1 = pop();
        op2 = pop();
        push( op1 );
        push( op2 );
        break;
      case '!': /* limpiar la pila         */
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
        printf( "\t%.8g\n", top() );
        break;
      default:
        printf( "error: comando desconocido %s\n", s );
        break;
      }
    }

    argc--;
    argv++;
  }

  return 0;
}


/* $ gcc main.c push-pop.c getop.c -lm */
/* output $ ./a.out 2 3 4 + \* ?
	14
*/

/* output $ ./a.out 10 seta 2 setb getb geta pow ? -1024 fabs ? - ?
	1024
	1024
	0
*/
