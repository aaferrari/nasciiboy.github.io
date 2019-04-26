#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

/* diff: compara dos archivos e imprime la primer linea donde difieren */
int main( int argc, char *argv[] ){
  FILE *fpa, *fpb;
  char *prog = *argv;  /* nombre del programa para errores */

  if( argc != 3 ){     /* llamada erronea informa y sale   */
    fprintf( stderr, "USO: %s arg1 arg2\n", prog );
    exit( 2 );
  } else {
    if( (fpa = fopen( *++argv, "r" )) == NULL ){
      fprintf( stderr, "%s: no se puede abrir %s\n", prog, *argv );
      exit( 2 );
    } else if( (fpb = fopen( *++argv, "r" )) == NULL ){
      fprintf( stderr, "%s: no se puede abrir %s\n", prog, *argv );
      fclose( fpa );
      exit( 2 );
    } else {
      int nl = 1;
      char *ra, *rb;
      char stra[ MAX_LINE ], strb[ MAX_LINE ];

      while( nl ){
        ra = fgets( stra, MAX_LINE, fpa );
        rb = fgets( strb, MAX_LINE, fpb );

        if( strcmp( stra, strb ) != 0 ){
          printf( "%3d:\n%s%s", nl, stra, strb );
          nl = -1;
        }

        if( !ra || !rb || nl == -1 ){
          fclose( fpa );
          fclose( fpb );
        }

        nl++;
      }

      if( ferror( stdout ) ){
        fprintf( stdout, "%s: error al escribir stdout\n", prog );
        exit( 2 );
      }

    }   /* fpa & fpb OK */
  }     /* argc == 3    */

  exit( 0);
}

/* output  $ ./a.out 07e06-diff-.c 07e06-diff-.c~
  2:
#include <stdlib.h>
#include <string.h>
*/

/* output  $ ./a.out
USO: ./a.out arg1 arg2
*/

/* output  $ ./a.out 07e06-diff-.e 07e06-diff-.c~
./a.out: no se puede abrir 07e06-diff-.e
*/

/* output  $ ./a.out 07e06-diff-.c 07e06-diff-.e
./a.out: no se puede abrir 07e06-diff-.e
*/
