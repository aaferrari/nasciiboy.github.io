#define NULL     0
#define EOF      (-1)
#define BUFSIZ   1024
#define OPEN_MAX 20   /* maximo numero de archivos abiertos a la vez */

struct _flags {
  unsigned int _READ   : 1;      /* archivo abierto para lectura                 */
  unsigned int _WRITE  : 1;      /* archivo abierto para escritura               */
  unsigned int _UNBUF  : 1;      /* archivo sin buffer                           */
  unsigned int _EOF    : 1;      /* ocurrio fin de archivo (EOF) en este archivo */
  unsigned int _ERR    : 1;      /* ocurrio un error en este archivo             */
  char *n;
};

typedef struct _iobuf {
  int cnt;             /* caracteres que quedan           */
  char *ptr;           /* posicion del siguiente caracter */
  char *base;          /* localizacion del buffer         */
  struct _flags flag;  /* modo de acceso al archivo       */
  int fd;              /* descriptor de archivo           */
} FILE;
extern FILE _iob[OPEN_MAX];

#define stdin   (&_iob[0])
#define stdout  (&_iob[1])
#define stderr  (&_iob[2])

int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p)      ((p)->flag._EOF) != 0)
#define ferror(p)    ((p)->flag._ERR) != 0)
#define fileno(p)    ((p)->fd)

#define getc(p)   (--(p)->cnt >= 0                              \
                   ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x,p) (--(p)->cnt >= 0                              \
                   ? *(p)->ptr++ = (x) : _flushbuf((x),p))

#define getchar()  getc(stdin)
#define putchar(x) putc((x), stdout)
void puts( char *x ){
  char *ptr = x;
  while( *ptr )
    putchar( *ptr++ );

  putchar( '\n' );
}

FILE _iob[OPEN_MAX] = { /* stdin, stdout, stderr */
  { 0, (char *) 0, (char *) 0, { 1,0,0,0,0 }, 0 },
  { 0, (char *) 0, (char *) 0, { 0,1,1,0,0 }, 1 },
  { 0, (char *) 0, (char *) 0, { 0,1,1,0,0 }, 2 }
};

#include <fcntl.h>
#include <unistd.h>
#define PERMS 0666    /* lectura y escritura para propietario, grupo, otros */

/* iopen: abre un archivo, regresa un apuntador de archivo */
FILE *fopen( char *name, char *mode ){
  int fd;
  FILE *fp;

  if (*mode != 'r' && *mode != 'w' && *mode != 'a')
    return NULL;
  for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
    if ((fp->flag._READ || fp->flag._WRITE) == 0)
      break;                 /* se encontro una entrada libre */
  if (fp >= _iob + OPEN_MAX) /* no hay entradas libres        */
    return NULL;

  if (*mode == 'w')
    fd = creat(name, PERMS);
  else if (*mode == 'a') {
    if ((fd = open(name, O_WRONLY, 0)) == -1)
      fd = creat(name, PERMS);
    lseek(fd, 0L, 2);
  } else
    fd = open(name, O_RDONLY, 0);

  if (fd == -1)              /* no hubo acceso al nombre      */
    return NULL;

  fp->fd = fd;
  fp->cnt = 0;
  fp->base = NULL;

  if( *mode == 'r' ) fp->flag._READ = 1;
  else fp->flag._WRITE = 1;

  return fp;
}

#include <stdlib.h>  // malloc

int _flushbuf( int c, FILE *f ){
  int num_written, bufsize;
  unsigned char uc = c;

  if( f->flag._READ || !f->flag._WRITE || f->flag._EOF || f->flag._ERR )
    return EOF;

  if( f->flag._UNBUF ){
    return write( f->fd, &uc, 1 ) == 1 ? 1 : EOF;
  } else {
    if( f->base == NULL ){
      /* no buffer yet */
      if( (f->base = (char *)malloc(BUFSIZ)) == NULL){
        /* couldn't allocate a buffer, so try unbuffered */
        f->flag._UNBUF = 1;
        f->flag._ERR = 1;
        return EOF;
      } else {
        f->ptr = f->base;
        f->cnt = BUFSIZ - 1;
        *(f->ptr++) = uc;
      }
    } else {
      bufsize = (int)(f->ptr - f->base);
      num_written = write(f->fd, f->base, bufsize);
      f->ptr = f->base;
      f->cnt = BUFSIZ - 1;

      if (num_written == bufsize)
        return c;
      else {
        f->flag._ERR = 1;
        return EOF;
      }

    }
  }
}


/* _fillbuf: asigna y llena un buffer de entrada */
int _fillbuf(FILE *fp)
{
  int bufsize;

  if ((fp->flag._READ || fp->flag._EOF || fp->flag._ERR) == 0)
    return EOF;
  bufsize = (fp->flag._UNBUF) ? 1 : BUFSIZ;

  if (fp->base == NULL)  /* sin buffer aun             */
    if ((fp->base = (char *) malloc(bufsize)) == NULL)
      return EOF;        /* no puede obtener un buffer */

  fp->ptr = fp->base;
  fp->cnt = read(fp->fd, fp->ptr, bufsize);
  if (--fp->cnt < 0) {
    if (fp->cnt == -1)
      fp->flag._EOF = 1;
    else
      fp->flag._ERR = 1;

    fp->cnt = 0;
    return EOF;
  }
  return (unsigned char) *fp->ptr++;
}

int fflush( FILE *fp ){
  if( fp->flag._ERR )
    return EOF;

  fp->ptr = fp->base;
  if( fp->flag._UNBUF ) fp->cnt = 0;
  else fp->cnt = BUFSIZ - 1;

  return 0;
}


int fclose( FILE *fp ){
  if( fp < _iob + OPEN_MAX && fp >= _iob + 3 ){
    if( fp->base ) free( fp->base );

    fp->cnt = 0;
    fp->ptr = 0;
    fp->base = 0;
    fp->flag._READ = 0;
    fp->flag._WRITE = 0;
    fp->flag._UNBUF = 0;
    fp->flag._EOF = 0;
    fp->flag._ERR = 0;
    fp->fd = 0;
    return 0;
  }

  return EOF;
}
int main(){
  FILE * fp = fopen( "08e02-fopen_fillbuf-.c", "r" );

  char c = getc( fp );
  while( c != EOF ){
    putchar( c );
    c = getc( fp );
  }

  fclose( fp );

  return 0;
}
