#include <stdio.h>
#include <string.h>


#define MAXLINE 1024

int except = 0, number = 0, name = 0;

int grep( char *pattern, FILE *ifp, char *fname );
int getLine( char *s, int lim, FILE *ifp );


int main( int argc, char *argv[] ){
  char *pattern;
  int found = 0;
  FILE *fp;

  while( --argc > 0 && (*++argv)[0] == '-' )
     while( *++argv[ 0 ] )
      switch( **argv ){
      case 'x': except = 1; break;
      case 'n': number = 1; break;
      case 'w': name   = 1; break;
      default:
        fprintf( stderr, "grep: illegal option %c\n", **argv );
        return 0;
      }

  if( argc == 0 ){
    fprintf( stderr, "Usage: grep -x -n -w  pattern files\n" );
    return 0;
  }

  pattern = *argv++;

  if( !*argv ) found = grep( pattern, stdin, "stdin" );
  else
    while( *argv ){
      if( (fp = fopen( *argv, "r" )) == NULL ){
        fprintf( stderr, "grep: %s: error opening file\n", *argv );
        return 0;
      } else {
        found += grep( pattern, fp, *argv );
        fclose( fp );
      }

      argv++;
    }

  return found;
}

/* grep: busca patron en *ifp */
int grep( char *pattern, FILE *ifp, char *fname ){
  char line[ MAXLINE ];
  long il = 0;
  int found = 0;

  while( getLine( line, MAXLINE, ifp ) > 0 ){
    il++;

    if( (strstr( line, pattern ) != NULL) != except ){
      if( name   ) printf( "%s:", fname );
      if( number ) printf( "%ld:", il );

      printf( "%s", line );
      found++;
    }
  }

  return found;
}

/* getLine: lee una linea en s, regresa su longitud */
int getLine( char *s, int lim, FILE *ifp ){
  char *i = s;
  int c;
  while( lim-- && ( c = fgetc( ifp ) ) != EOF && c != '\n' )
    *s++ = c;

  if( c == '\n' ) *s++ = c;
  *s = '\0';

  if( c == EOF ) ungetc( c, ifp );

  return s - i;
}


/* output  $ ./a.out -wn return 07e07-grep-.c
07e07-grep-.c:26:        return 0;
07e07-grep-.c:31:    return 0;
07e07-grep-.c:41:        return 0;
07e07-grep-.c:50:  return found;
07e07-grep-.c:71:  return found;
07e07-grep-.c:86:  return s - i;
*/

/*  $ ./a.out -wn return
int main(){
  return 0;
stdin:2:  return 0;
}
*/
