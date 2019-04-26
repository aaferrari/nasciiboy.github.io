void strncpy( char *s, char *t, unsigned int n ){
  while( n && ( *s++ = *t++ ) ) n--;

  *s = '\0';
}

void strncat( char * s, char *t, unsigned int n ){
  while( *s ) s++;
  while( n && ( *s++ = *t++ ) ) n--;

  *s = '\0';
}

int strncmp( char *s, char *t, unsigned int n ){
  for( ; *s == *t; s++, t++ )
    if( *s == '\0' || !--n ) return 0;

  return *s - *t;
}
