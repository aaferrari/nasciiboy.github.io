#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

/* minprintf: printf minima con lista variable de argumentos */
int minscanf( char *fmt, ... ){
  va_list ap;           /* apunta a cada arg sin nombre en orden     */
  char *cval,*p, *sval;
  int  *ival;
  double *dval;

  int count = 0;

  va_start( ap, fmt );  /* hace que ap apunte al 1er. arg sin nombre */
  for( p = fmt; *p; p++ ){
    if( *p != '%' ){
      *p = getchar();
      continue;
    }

    switch( *++p ){
    case 'c':
      cval = va_arg( ap, char *);
      count += scanf( "%c", cval );
      break;
    case 'o':
      ival = va_arg( ap, int * );
      count += scanf( "%o", ival );
      break;
    case 'x':
      ival = va_arg( ap, int * );
      count += scanf( "%x", ival );
      break;
    case 'X':
      ival = va_arg( ap, int * );
      count += scanf( "%X", ival );
      break;
    case 'd' :
      ival = va_arg( ap, int * );
      count += scanf( "%d", ival );
      break;
    case 'f' :
      dval = va_arg( ap, double *);
      count += scanf( "%f", dval );
      break;
    case 's' :
      sval = va_arg( ap, char *);
      count += scanf( "%s", sval );
      break;
    default:
      break;
    }
  }

  va_end( ap );         /* limpia cuando todo esta hecho             */

  return count;
}


int main(){
  int a, b;
  char c, s[ 1024 ];
  float f;

  int count = minscanf( "%c%d%d%f%s", &c, &a, &b, &f, s );

  printf( "count = %d\n"
          "c = %c\n"
          "a = %d\n"
          "b = %d\n"
          "f = %f\n"
          "s = %s\n", count, c, a, b, f, s );

  return 0;
}


/* output
a 12 13 123.456 cadena de prueva
count = 5
c = a
a = 12
b = 13
f = 123.456001
s = cadena
*/

/* output
a b c d e
count = 2
c = a
a = 0
b = 32766
f = 0.000000
s = b
*/
