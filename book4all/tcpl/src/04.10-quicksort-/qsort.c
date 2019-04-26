/* qsort: ordena v[left]...v[right] en orden ascendente */
void qsort( int v[], int left, int right ){
  int i, last;
  void swap( int v[], int i, int j );

  if( left >= right )                          /* no hace nada si el arreglo contiene */
    return;                                    /* menos de dos elementos              */
  swap( v, left, ( left + right ) / 2 );       /* mueve el elemento de particion      */
  last = left;                                 /* a v[ 0 ]                            */
  for( i = left + 1; i <= right; i++ )         /* particion                           */
    if( v[ i ] < v[ left ] )
      swap( v, ++last, i );
  swap( v, left, last );                       /* regresa el elemento de particion    */
  qsort( v, left, last - 1 );
  qsort( v, last + 1, right );
}


/* swap: intercambia v[i] y v[j] */
void swap( int v[], int i, int j ){
  int temp = v[ i ];
  v[ i ] = v [ j ];
  v[ j ] = temp;
}
