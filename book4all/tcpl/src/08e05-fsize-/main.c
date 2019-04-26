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


//  Tamaño: 695777    	Bloques: 1360       Bloque E/S: 4096   fichero regular
//Dispositivo: 803h/2051d	Nodo-i: 3542091     Enlaces: 1
//Acceso: (0664/-rw-rw-r--)  Uid: ( 1000/nasciiboy)   Gid: ( 1000/nasciiboy)
//Contexto: unconfined_u:object_r:user_home_t:s0
//      Acceso: 2015-10-10 12:07:40.711875739 -0500
//Modificación: 2016-02-09 09:58:00.964612597 -0600
//      Cambio: 2016-02-09 09:58:00.964612597 -0600
//
//
//               mode_t    st_mode;        /* protection */
//               dev_t     st_rdev;        /* device ID (if special file) */

  printf( "Fichero: %s\n"
          "Tamaño: %ld     Bloques: %ld     Bloque E/S:  %ld     \n"
          "Dispositivo: %ld     Nodo-i: %ld     Enlaces: %ld\n"
          "Uid: ( %ld )     Gid: ( %ld )\n",
          name,
          stbuf.st_size, stbuf.st_blocks, stbuf.st_blksize,
          stbuf.st_dev, stbuf.st_ino, stbuf.st_nlink,
          stbuf.st_uid, stbuf.st_gid );
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
Fichero: ../../tcpl.org
Tamaño: 695777     Bloques: 1360     Bloque E/S:  4096
Dispositivo: 2051     Nodo-i: 3542091     Enlaces: 1
Uid: ( 1000 )     Gid: ( 1000 )
*/
