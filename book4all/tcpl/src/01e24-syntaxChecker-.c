/* syntax checker based on Stefan Farfeleder's solution
   http://clc-wiki.net/wiki/K%26R2_solutions:Chapter_1:Exercise_24 */
#include <stdio.h>


#define MAX_LINE  1024
#define MAX_STACK 1024

#define CODE         0      /* nada de lo siguiente    */
#define COMMENT      1      /* dentro de un comentario */
#define QUOTE1       2      /* dentro de ' '           */
#define QUOTE2       3      /* dentro de " "           */

int myGetline( char s[], int lim );

int main(){
  char line[MAX_LINE];
  char stack[MAX_STACK];

  int status = CODE;
  int error  =    0;
  int top    =    0;
  int nline  =    1;

  int i;
  char ch;

  while( myGetline( line, MAX_LINE ) ){
    for( i = 0; ( ch = line[ i ] ) != '\0'; i++ ){
      if( ch == '\n' ) nline++;

      if( status == CODE ){
        if(      ch == '\'' )         status = QUOTE1;
        else if( ch == '"'  )         status = QUOTE2;
        else if( ch == '/'  ){
          if( line[ i + 1 ] == '*' ){ status = COMMENT; i++; }
        } else if( ch == '(' || ch == '[' || ch == '{' ){
          if( top < MAX_STACK ) stack[ top++ ] = ch;
          else{
            printf( "Pila llena\n" );
            return 1;     /* salida con un poco de gracia */
          }
        } else if( ch == ')' || ch == ']' || ch == '}' ){
          if( top == 0 ){ /* encuentra llave de cierre pero la pila esta vacia */
            printf( "Linea %d: Llave %c encontrada sin contraparte.\n",
                    nline, ch );
            error = 1;
          } else {
            char open = stack[ --top ];

            if( ( ch == ')' && open != '(' ) ||
                ( ch == ']' && open != '[' ) ||
                ( ch == '}' && open != '{' ) ){
              printf( "Linea %d: Cierre '%c' ne coincide con abertura '%c'.\n",
                      nline, ch, open );
              error = 1;
            }
          }
        }
      } else if( status == COMMENT ){
        if( ch == '*' )
          if( line[ i + 1 ] == '/' ){  status = CODE; i++; }
      } else if( status == QUOTE1  ){
        if( ch == '\\' ) i++;
        else if( ch == '\'' )          status = CODE;
      } else if( status == QUOTE2 ){
        if( ch == '\\' ) i++;
        else if( ch == '"' )           status = CODE;
      }
    }
  }

  if(      status == COMMENT ) printf( "El codigo termina dentro de un comentario!\n" );
  else if( status == QUOTE1  ) printf( "El codigo termina dentro de comilla simple!\n" );
  else if( status == QUOTE2  ) printf( "El codigo termina dentro de comilla doble!\n" );
  else if( top == 0 && error == 0 ) printf( "El codigo parece estar OK.\n" );

  if( top > 0 )    /* aun queda algu en la pila */
    for( i = 0; i < top; i++ )
      printf( "Encontrada apertura '%c' sin contraparte.\n", stack[ i ] );

  return 0;
}

/* getline: lee una línea en s, regresa su longitud */
int myGetline( char s[], int lim ){
  int c, i;

  for( i=0; i < lim-1 && ( c = getchar() ) != EOF && c != '\n'; ++i )
    s[i] = c;

  if( c == '\n' ){
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}
