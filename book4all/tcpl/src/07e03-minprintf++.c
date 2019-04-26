#include <stdarg.h>
#include <stdio.h>

/* minprintf: printf minima con lista variable de argumentos */
void minprintf( char *fmt, ... ){
  va_list ap;           /* apunta a cada arg sin nombre en orden     */
  char *p, *sval;
  int cval, ival;
  double dval;

  va_start( ap, fmt );  /* hace que ap apunte al 1er. arg sin nombre */
  for( p = fmt; *p; p++ ){
    if( *p != '%' ){
      putchar( *p );
      continue;
    }

    switch( *++p ){
    case '%' :
      putchar( '%' );
      break;
    case 'c' :
      cval = va_arg( ap, int );
      putchar( cval );
      break;
    case 'o':
      ival = va_arg( ap, int );
      printf( "%o", ival );
      break;
    case 'x':
      ival = va_arg( ap, int );
      printf( "%x", ival );
      break;
    case 'X':
      ival = va_arg( ap, int );
      printf( "%X", ival );
      break;
    case 'd' :
      ival = va_arg( ap, int );
      printf( "%d", ival );
      break;
    case 'f' :
      dval = va_arg( ap, double );
      printf( "%f", dval );
      break;
    case 's' :
      for( sval = va_arg( ap, char *); *sval; sval++ )
        putchar( *sval );
      break;
    default:
      putchar( *p );
      break;
    }
  }

  va_end( ap );         /* limpia cuando todo esta hecho             */
}


int main(){
  minprintf( "%der %% %s%c", 1, "linea de prueba", '\n' );

  return 0;
}


/* output
1er % linea de prueba
*/
