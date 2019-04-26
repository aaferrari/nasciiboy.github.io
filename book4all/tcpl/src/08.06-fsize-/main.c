#include <stdio.h>
#include <string.h>
#include "syscalls.h"
#include <fcntl.h>            /* banderas para lectura y escritura             */
#include <sys/types.h>        /* typedefs                                      */
#include <sys/stat.h>         /* estructura regresada por stat                 */
#include "dirent.h"


void fsize( char * );

/* imprime tamaños de archivos */
int main( int argc, char *argv[] ){
  if( argc == 1 )             /* default: directorio actual                    */
    fsize( "." );
  else
    while( --argc > 0 )
      fsize( *++argv );

  return 0;
}


void dirwalk( char *, void (*fch)(char *) );

/* fsize: imprime el tamaño del archivo "name" */
void fsize( char *name ){
  struct stat stbuf;

  if( stat( name, &stbuf) == -1 ){
    fprintf( stderr, "fsize: no se tiene acceso a %s\n", name );
    return;
  }

  if( (stbuf.st_mode & S_IFMT) == S_IFDIR )
    dirwalk( name, fsize );

  printf( "%8ld %s\n", stbuf.st_size, name );
}

#define MAX_PATH 1024

/* dirwalk: aplica fcn a todos los archivos de dir */
void dirwalk( char *dir, void (*fcn)(char *) ){
  char name[ MAX_PATH ];
  Dirent *dp;
  myDIR *dfd;

  if( (dfd = my_opendir( dir )) == NULL ){
    fprintf( stderr, "dirwalk: no se puede abrir %s\n", dir );
    return;
  }

  while( (dp = my_readdir( dfd )) != NULL ){
    if( strcmp( dp->name, "." ) == 0 || strcmp( dp->name, ".." ) )
      continue;   /* se ignora a si mismo y a su padre  */
    if( strlen( dir ) + strlen( dp->name ) + 2 > sizeof( name ) )
      fprintf( stderr, "dirwalk: nombre %s %s demasiado largo\n",
               dir, dp->name );
    else {
      sprintf( name, "%s/%s", dir, dp->name );
      (*fcn)( name );
    }
  }

  my_closedir( dfd );
}


/* output  $ ./a.out ../../tcpl.org
  695777 ../../tcpl.org
*/
