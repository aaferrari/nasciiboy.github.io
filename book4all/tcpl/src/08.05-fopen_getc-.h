#define NULL     0
#define EOF      (-1)
#define BUFSIZ   1024
#define OPEN_MAX 20   /* maximo numero de archivos abiertos a la vez */

typedef struct _iobuf {
  int cnt;             /* caracteres que quedan           */
  char *ptr;           /* posicion del siguiente caracter */
  char *base;          /* localizacion del buffer         */
  int flag;            /* modo de acceso al archivo       */
  int fd;              /* descriptor de archivo           */
} FILE;
extern FILE _iob[OPEN_MAX];

#define stdin   (&_iob[0])
#define stdout  (&_iob[1])
#define stderr  (&_iob[2])

enum _flags {
  _READ     = 01,       /* archivo abierto para lectura                 */
  _WRITE    = 02,       /* archivo abierto para escritura               */
  _UNBUF    = 04,       /* archivo sin buffer                           */
  _EOF      = 010,      /* ocurrio fin de archivo (EOF) en este archivo */
  _ERR      = 020       /* ocurrio un error en este archivo             */
};

int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p)      ((p)->flag & _EOF) != 0)
#define ferror(p)    ((p)->flag & _ERR) != 0)
#define fileno(p)    ((p)->fd)

#define getc(p)   (--(p)->cnt >= 0                              \
                   ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x,p) (--(p)->cnt >= 0                              \
                   ? *(p)->ptr++ = (x) : _flushbuf((x),p))

#define getchar()  getc(stdin)
#define putchar(x) putc((x), stdout)

FILE _iob[OPEN_MAX] = { /* stdin, stdout, stderr */
  { 0, (char *) 0, (char *) 0, _READ, 0 },
  { 0, (char *) 0, (char *) 0, _WRITE, 1 },
  { 0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2 }
};
