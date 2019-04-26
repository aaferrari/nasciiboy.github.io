#include <stdio.h>

#define MAXLINE 1024   /* tamaño máximo de la línea de entrada */
#define IN         1
#define OUT        0

int myGetline( char s[], int lim );

/* Este progama elimina comentarios dentro de progamas
   en lenguaje C, manteniendo la distribucion orginal
   del texto                                          */
int main(){
  int len;                 /* longitud actual de la línea    */
  int i;                   /* contador detro de cilo for      */
  int status = OUT;        /* dentro/fuera de comentario      */
  char line[MAXLINE];      /* línea de entrada actual        */


  while( ( len = myGetline( line, MAXLINE ) ) > 0 ){
    for( i = 0; i < len; i++ ){
      if( status ){
        if( line[ i ] == '*' && line[ i + 1 ] == '/' ){
          status = OUT;
          printf( "  " );
          i++;
        } else if( line [ i ] == '\n' ) putchar( '\n' );
        else putchar( ' ' );
      } else {
        if( line[ i ] == '/' && line[ i + 1 ] == '/' ){
          printf( "//" );
          i++;
        } else if ( line[ i ] == '/' && line[ i + 1 ] == '*' ){
          status = IN;
          printf( "  " );
          i++;
        } else putchar( line[ i ] );
      }
    }
  }

  putchar( '\n' );
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


// OUTPUT
// /* dentro del comentario
//
//    fuera del comentario */
//
// int main()   /* un comentario */ {
// int main()                       {
//   printf( "//* esto es un comentario *//" );  /* imprime ejemplo de comentario */
//   printf( "//* esto es un comentario *//" );
//
//
// } /* fin de
// }
//      funcion */
//
//
//
