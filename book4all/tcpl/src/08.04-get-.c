#include "syscalls.h"

/* get: lee n bytes de la posicion pos */
int get( int fd, long pos, char *buf, int n ){
  if( lseek( fd, pos, 0 ) >= 0 )  /* se sitia en pos */
    return read( fd, buf, n );
  else
    return -1;
}
