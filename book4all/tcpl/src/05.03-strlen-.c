/* strlen: regresa la longitud de la cadena s */
int strlen( char *s ){
  int n;
  for( n = 0; *s != '\0'; s++ )
    n++;

  return n;
}
