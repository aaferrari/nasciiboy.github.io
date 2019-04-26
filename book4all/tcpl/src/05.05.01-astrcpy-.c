/* strcpy: copia t hacia s; version de subindices */
void strcpy( char *s, char *t ){
  int i = 0;
  while(( s[ i ] = t[ i ] ) != '\0' ) i++;
}
