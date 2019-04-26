#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
#define PNAME "fcat4pag"

int getLine( char *s, int lim, FILE *ifp );

/* find: imprime lineas que coinciden con el patron del 1er. argumento */
int main( int argc, char *argv[] ){
  long il = 0;
  char line[ MAXLINE ];
  FILE *fp;
  int number = 0, name = 0;

  while( --argc > 0 && (*++argv)[0] == '-' )
     while( *++argv[ 0 ] )
      switch( **argv ){
      case 'n': number = 1; break;
      case 'w': name   = 1; break;
      default:
        fprintf( stderr, "%s: illegal option %c\n", PNAME, **argv );
        return 0;
      }

  if( argc == 0 ){
    fprintf( stderr, "Usage: %s -n -w files\n", PNAME );
    return 0;
  }

  while( *argv ){
    if( (fp = fopen( *argv, "r" )) == NULL ){
      fprintf( stderr, "%s: %s: error opening file\n", PNAME, *argv );
      return 0;
    } else {
      il++;
      if( name   ) printf( "%s:", *argv );
      if( number ) printf( "%ld:", il );
      putchar( '\n' );

      while( getLine( line, MAXLINE, fp ) > 0 )
        printf( "%s", line );

      fclose( fp );
      argv++;
      puts( "----------------------------------------------------------------------" );
    }
  }

  return il;
}

/* getLine: lee una linea en s, regresa su longitud */
int getLine( char *s, int lim, FILE *ifp ){
  char *i = s;
  int c;
  while( lim-- && ( c = fgetc( ifp ) ) != EOF && c != '\n' )
    *s++ = c;

  if( c == '\n' ) *s++ = c;
  *s = '\0';

  if( c == EOF ) ungetc( c, ifp );

  return s - i;
}


/* output  $ ./a.out -wn
Usage: fcat4pag -n -w files
*/

/* output  $ ./a.out -wn a.e
fcat4pag: a.e: error opening file
*/

// output  $ ./a.out -wn 01.01-HolaMundo-.c 01.01-HolaMundo-.c
//01.01-HolaMundo-.c:1:
//#include <stdio.h>              /* incluye información acerca de la biblioteca estándar */
//
//main(){                         /* define una función llamada main
//                                   que no recibe valores de argumentos */
//                                /* las proposiciones de main están encerradas entre llaves */
//  printf( "hola, mundo\n" );    /* main llama a la función printf de biblioteca estándar
//                                   para escribir esta secuencia de caracteres;
//                                   \n representa el carácter nueva línea */
//}
//
//
///* output
//hola, mundo
//*/
//----------------------------------------------------------------------
//01.01-HolaMundo-.c:2:
//#include <stdio.h>              /* incluye información acerca de la biblioteca estándar */
//
//main(){                         /* define una función llamada main
//                                   que no recibe valores de argumentos */
//                                /* las proposiciones de main están encerradas entre llaves */
//  printf( "hola, mundo\n" );    /* main llama a la función printf de biblioteca estándar
//                                   para escribir esta secuencia de caracteres;
//                                   \n representa el carácter nueva línea */
//}
//
//
///* output
//hola, mundo
//*/
//----------------------------------------------------------------------
