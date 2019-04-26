#include "syscalls.h"
#include <fcntl.h>   // O_RDONLY
#include <stdlib.h>  // exit()

/* cat: concatena archivos */
int main( int argc, char *argv[] ){
  int fp;
  void filecopy( int ifp, int ofp );
  void error( char *, ... );
  char *prog = argv[ 0 ];   /* nombre del programa para errores     */

  if( argc == 1 )           /* sin args; copia la entrada estandar  */
    filecopy( 0, 1 );
  else
    while( --argc > 0 )
      if( (fp = open( *++argv, O_RDONLY, 0 )) == -1 ){
        error( "%s: no se puede abrir %s\n", prog, *argv );
      } else {
        filecopy( fp, 1 );
        close( fp );
      }

  exit( 0 );
}

/* filecopy: copia el achivo ifp al archivo ofp */
void filecopy( int ifp, int ofp ){
  int n;
  char buf[ BUFSIZ ];

  while( (n = read( ifp, buf, BUFSIZ )) > 0 )
    write( ofp, buf, n );
}

#include <stdio.h>  // fprintf
#include <stdarg.h> // va_* vfprintf

void error( char *fmt, ... ){
  va_list args;

  va_start( args, fmt );
  fprintf( stderr, "error: " );
  vfprintf( stderr, fmt, args );
  fprintf( stderr, "\n" );
  va_end( args );
  exit( 1 );
}


/* output  $ ./a.out
aoeui snthd 159753
aoeui snthd 159753
;,.plrcgyf'zvqwjmkxb
;,.plrcgyf'zvqwjmkxb
*/

// output  $ ./a.out 08e01-cat-.c
//#include "syscalls.h"
//#include <fcntl.h>   // O_RDONLY
//#include <stdlib.h>  // exit()
//
///* cat: concatena archivos */
//int main( int argc, char *argv[] ){
//  int fp;
//  void filecopy( int ifp, int ofp );
//  void error( char *, ... );
//  char *prog = argv[ 0 ];   /* nombre del programa para errores     */
//
//  if( argc == 1 )           /* sin args; copia la entrada estandar  */
//    filecopy( 0, 1 );
//  else
//    while( --argc > 0 )
//      if( (fp = open( *++argv, O_RDONLY, 0 )) == -1 ){
//        error( "%s: no se puede abrir %s\n", prog, *argv );
//      } else {
//        filecopy( fp, 1 );
//        close( fp );
//      }
//
//  exit( 0 );
//}
//
///* filecopy: copia el achivo ifp al archivo ofp */
//void filecopy( int ifp, int ofp ){
//  int n;
//  char buf[ BUFSIZ ];
//
//  while( (n = read( ifp, buf, BUFSIZ )) > 0 )
//    write( ofp, buf, n );
//}
//
//#include <stdio.h>  // fprintf
//#include <stdarg.h> // va_* vfprintf
//
//void error( char *fmt, ... ){
//  va_list args;
//
//  va_start( args, fmt );
//  fprintf( stderr, "error: " );
//  vfprintf( stderr, fmt, args );
//  fprintf( stderr, "\n" );
//  va_end( args );
//  exit( 1 );
//}
