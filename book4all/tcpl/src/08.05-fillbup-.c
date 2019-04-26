#include "syscalls.h"
#include "08.05-fopen_getc-.h"

#include <stdlib.h>  // malloc

/* _fillbuf: asigna y llena un buffer de entrada */
int _fillbuf(FILE *fp)
{
  int bufsize;

  if ((fp->flag&(_READ|_EOF|_ERR)) != _READ)
    return EOF;
  bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
  if (fp->base == NULL)  /* sin buffer aun             */
    if ((fp->base = (char *) malloc(bufsize)) == NULL)
      return EOF;        /* no puede obtener un buffer */
  fp->ptr = fp->base;
  fp->cnt = read(fp->fd, fp->ptr, bufsize);
  if (--fp->cnt < 0) {
    if (fp->cnt == -1)
      fp->flag |= _EOF;
    else
      fp->flag |= _ERR;
    fp->cnt = 0;
    return EOF;
  }
  return (unsigned char) *fp->ptr++;
}
