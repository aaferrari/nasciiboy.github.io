/* strcpy: copia t hacia s; version dos con apuntadores */
void strcpy( char *s, char *t ){
  while( ( *s++ = *t++ ) != '\0' )
    ;
}
