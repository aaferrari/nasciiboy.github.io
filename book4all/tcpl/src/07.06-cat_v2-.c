#include <stdio.h>
#include <stdlib.h>

/* cat: concatena archivos, version 2 */
int main( int argc, char *argv[] ){
  FILE *fp;
  void filecopy( FILE *, FILE * );
  char *prog = argv[ 0 ];   /* nombre del programa para errores     */

  if( argc == 1 )           /* sin args; copia la entrada estandar  */
    filecopy( stdin, stdout );
  else
    while( --argc > 0 )
      if( (fp = fopen( *++argv, "r" )) == NULL ){
        fprintf( stderr, "%s: no se puede abrir %s\n", prog, *argv );
        exit( 1 );
      } else {
        filecopy( fp, stdout );
        fclose( fp );
      }

  if( ferror( stdout ) ){
    fprintf( stdout, "%s: error al escribir stdout\n", prog );
    exit( 2 );
  }

  exit( 0 );
}

/* filecopy: copia el achivo ifp al archivo ofp */
void filecopy( FILE *ifp, FILE *ofp ){
  int c;
  while( (c = getc( ifp )) != EOF )
    putc( c, ofp );
}

/* output  $ ./a.out 07.06-cat_v2-.e | cat
./a.out: no se puede abrir 07.06-cat_v2-.e
*/

// output  $ a.out 07.06-cat_v2-.c
//#include <stdio.h>
//#include <stdlib.h>
//
///* cat: concatena archivos, version 2 */
//int main( int argc, char *argv[] ){
//  FILE *fp;
//  void filecopy( FILE *, FILE * );
//  char *prog = argv[ 0 ];   /* nombre del programa para errores     */
//
//  if( argc == 1 )           /* sin args; copia la entrada estandar  */
//    filecopy( stdin, stdout );
//  else
//    while( --argc > 0 )
//      if( (fp = fopen( *++argv, "r" )) == NULL ){
//        fprintf( stderr, "%s: no se puede abrir %s\n", prog, *argv );
//        exit( 1 );
//      } else {
//        filecopy( fp, stdout );
//        fclose( fp );
//      }
//
//  if( ferror( stdout ) ){
//    fprintf( stdout, "%s: error al escribir stdout\n", prog );
//    exit( 2 );
//  }
//
//  exit( 0 );
//}
//
///* filecopy: copia el achivo ifp al archivo ofp */
//void filecopy( FILE *ifp, FILE *ofp ){
//  int c;
//  while( (c = getc( ifp )) != EOF )
//    putc( c, ofp );
//}
