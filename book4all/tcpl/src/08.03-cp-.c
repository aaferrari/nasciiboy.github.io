#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "syscalls.h"
#define PERMS 0666  /* lectura y escritura para propietario, grupo y otros */

void error( char *, ... );

/* cp: copia f1 a f2 */
int main( int argc, char *argv[] ){
  int f1, f2, n;
  char buf[ BUFSIZ ];

  if( argc != 3 )
    error( "Uso: cp de hacia" );

  if( (f1 = open( argv[1], O_RDONLY, 0 )) == -1)
    error( "cp: no se puede abrir %s", argv[1] );

  if( (f2 = creat( argv[2], PERMS )) == -1)
    error( "cp: no se puede crear %s, modo %03o", argv[2], PERMS );

  while( (n = read( f1, buf, BUFSIZ )) > 0 )
    if( write( f2, buf, n ) != n )
      error( "cp: error de escritura en el archivo %s", argv[2] );

  return 0;
}

// #include <stdio.h>
#include <stdarg.h>

/* error: imprime un mensaje de error y muere */
void error( char *fmt, ... ){
  va_list args;

  va_start( args, fmt );
  fprintf( stderr, "error: " );
  vfprintf( stderr, fmt, args );
  fprintf( stderr, "\n" );
  va_end( args );
  exit( 1 );
}
