/* strcmp: regresa <0 si s<t, 0 si s==t, >0 si s>t */
int strcmp( char *s, char t* ){
  for( ; *s == *t; s++, t++ )
    if( *s == '\0' ) return 0;

  return *s - *t;
}
