typedef long Align;       /* para alineamiento al limite mayor           */

union header {            /* encabezado del bloque                       */
  struct {
    union header *ptr;    /* siguiente bloque si esta en la lista libre  */
    unsigned size;        /* tamaño de este bloque                       */
  } s;
  Align x;                /* obliga a la alineacion del bloques          */
};

typedef union header Header;

static Header base;            /* lista vacia para iniciar               */
static Header *freep = 0;      /* inicio de una lista libre              */

/* malloc: asignador de almacenamiento de proposito general              */
void *my_malloc( unsigned nbytes ){
  Header *p, *prevp;
  Header *morecore( unsigned );
  unsigned nunits;

  nunits = (nbytes + sizeof( Header ) -1) / sizeof( union header ) + 1;
  if( (prevp = freep) == 0 ){     /* no hay lista libre aun              */
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }

  for( p = prevp->s.ptr; ; prevp = p, p = p->s.ptr ){
    if( p->s.size >= nunits ){    /* suficientemente grande              */
      if( p->s.size == nunits )   /* exacto                              */
        prevp->s.ptr = p->s.ptr;
      else {                      /* asigna la parte final               */
        p->s.size -= nunits;
        p += p->s.size;
        p->s.size = nunits;
      }

      freep = prevp;

      return (void *)(p + 1);
    }

    if( p == freep )              /* dio la vuelta a la lista libre      */
      if( (p = morecore( nunits )) == 0 )
        return 0;                 /* nada libre                          */
  }
}

void *my_calloc( unsigned nbytes ){
  unsigned char *p = (unsigned char *)my_malloc( nbytes );

  if( p ){
    while( nbytes-- )
      p[ nbytes ] = (unsigned char)0;
  }

  return p;
}

#include <unistd.h>               /* sbrk()                              */
#define NALLOC 1024               /* minimo # de unidades por requerir   */

/* morecore: solicita mas memoria al sistema */
Header *morecore( unsigned nu ){
  char *cp;
  Header *up;
  void free( void *);

  if( nu < NALLOC ) nu = NALLOC;

  cp = sbrk( nu * sizeof( Header ) );
  if( cp == (char *) -1 )         /* no hay nada de espacio              */
    return NULL;

  up = (Header *) cp;
  up->s.size = nu;
  free( (void *)(up + 1) );

  return freep;
}

/* free: coloca el bloque ap en la lista vacia */
void free( void *ap ){
  Header *bp, *p;

  bp = (Header *)ap - 1;          /* apunta al encabezado de un bloque   */
  for( p = freep; !(bp > p && bp < p->s.ptr ); p = p->s.ptr )
    if( p >= p->s.ptr && (bp > p || bp < p->s.ptr) )
      break;                      /* libera bloque al inicio o al final  */

  if( bp + bp->s.size == p->s.ptr ){             /* une al nbr superior    */
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
  } else
    bp->s.ptr = p->s.ptr;

  if( p + p->s.size == bp ){                     /* une al nbr inferior    */
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
  } else
    p->s.ptr = bp;

  freep = p;
}

#include <stdio.h>
int main(){
  char *pm, *pc, *pb;
  unsigned n = 5;
  void printmem( char *, unsigned );


  pm = my_malloc( n );
  printmem( pm, n );
  free( pm );

  putchar( '\n' );

  pc = my_calloc( n );
  printmem( pc, n );
  free( pc );

  putchar( '\n' );

  return 0;
}

void printmem( char *mem, unsigned size ){
  if( mem )
    while( size-- )
      printf( "%3x ", (unsigned char)*mem++ );
}


/* output
  0   0   0   0   0
  0   0   0   0   0
*/
