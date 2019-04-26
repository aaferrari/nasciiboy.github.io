#include <stdio.h>

/* binsearch: encuentra x en v[ 0 ] <= v[ 1 ] ... <= v [ n -n ] */
int binsearch( int x, int v[], int n ){
  int low, high, mid;
  low = 0;
  high = n - 1;
  while( low < high ) {
    mid = ( low + high ) / 2;
    if( x <= v[ mid ] ) high =     mid;
    else                low  = mid + 1;
  }

  return( x == v[low] ) ? low : -1;
}

int main(){
  int x = 1;
  int v[ 10 ] = { 1, 5, 7, 9, 11, 13, 20, 55, 77, 94 };
  if( binsearch( x, v, 10 ) !=  -1 ) puts( "fount match" );
  else                               puts( "no match"    );

  return 0;
}
