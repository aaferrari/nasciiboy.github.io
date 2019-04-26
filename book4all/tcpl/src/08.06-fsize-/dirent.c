#include "dirent.h"
#include "syscalls.h"
#include <sys/types.h>
#include <sys/stat.h>

#ifndef DIRSIZ
#define DIRSIZ 14
#endif

struct direct {                /* entrada del directorio              */
  ino_t d_ino;                 /* numero de inodo                     */
  char d_name[ DIRSIZ ];       /* los nombres largos no tienen '\0'   */
};

int fstat( int fd, struct stat * );

#include <fcntl.h>
#include <stdlib.h>

/* my_opendir: abre un directorio para llamadas de my_readdir */
myDIR *my_opendir( char *dirname ){
  int fd;
  struct stat stbuf;
  myDIR *dp;

  if( (fd = open( dirname, O_RDONLY, 0 ))      == -1
      || fstat( fd, &stbuf )                   == -1
      || (stbuf.st_mode & S_IFMT )             != S_IFDIR
      || (dp = (myDIR *)malloc( sizeof( myDIR ) )) == NULL )
    return NULL;

  dp->fd = fd;

  return dp;
}

/* my_closedir: cierra un directorio abierto por my_opendir */
void my_closedir( myDIR *dp ){
  if( dp ){
    close( dp->fd );
    free( dp );
  }
}

#include <sys/dir.h>        /* estructura local del directorio  */
#include <string.h>

/* my_readdir: lee en secuencia las entradas de un directorio      */
Dirent *my_readdir( myDIR *dp ){
  struct direct dirbuf;    /* estructura local de directorio    */
  static Dirent d;         /* regreso: estructura transportable */

  while( read( dp->fd, (char *)&dirbuf, sizeof( dirbuf ) )
         == sizeof( dirbuf ) ){
    if( dirbuf.d_ino == 0 )    /* entrada que no esta en uso    */
      continue;

    d.ino = dirbuf.d_ino;
    strncpy( d.name, dirbuf.d_name, DIRSIZ );
    d.name[ DIRSIZ ] = '\0';   /* asegura la terminacion        */
    return &d;
  }

  return NULL;
}
