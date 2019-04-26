/* strlen: regresa la longitud de s */
int strlen( char s[] ){
  int i;

  i = 0;
  while( s[ i ] != '\0' ) i++;

  return i;
}
