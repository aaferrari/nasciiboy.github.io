/* strcat: concatena t al final de s; s debe ser suficientemente grande */
void strcat( char s[], char t[] ){
  int i, j;

  i = j = 0;
  while( s[ i ] != '\0' )   /* encuentra el fin de s */
    i++;
  while( ( s[ i++ ] = t[ j++ ] ) != '\0' ) /* copia t */
    ;

}
