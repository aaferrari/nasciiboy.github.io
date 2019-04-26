#define ALLOCSIZE 10000            /* tamano del espacio disponible       */

static char allocbuf[ ALLOCSIZE ]; /* almacenamiento para alloc           */
static char *allocp = allocbuf;    /* siguiente posicion libre            */

char *alloc( int n ){              /* regresa un apuntador a n caracteres */
  if( allocbuf + ALLOCSIZE - allocp >= n ){   /* si cabe    */
    allocp += n;
    return allocp - n;                        /* antigua p  */
  } else return 0;                 /* no hay suficiente espacio           */
}

void afree( char *p ){             /* almacenamiento libre apuntado por p */
  if( p >= allocbuf && p < allocbuf + ALLOCSIZE )
    allocp = p;
}
