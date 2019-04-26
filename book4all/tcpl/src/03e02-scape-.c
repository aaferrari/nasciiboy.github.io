/* la funcion escape( s, t ) convierte caracteres como nueva linea
   o tabulacion en secuencias de escape visibles.
   unescape convierte secuencias de escape en caracteres reales   */
#include <stdio.h>

#define LIMIT 1024

int myGetline( char s[], int lim );
void scape( char s[], const char t[] );
void unescape( char s[], const char t[] );


int main(){
  char s[LIMIT];
  char t[LIMIT];
  int len;

  while( ( len = myGetline( t, LIMIT ) ) != 0 ){
    scape( s, t );
    printf( "%s\n", s );
    unescape( t, s );
    printf( "%s", t );
  }

  return 0;
}



int myGetline( char s[], int lim ){
  int c, i;

  for( i=0; i < lim-1 && ( c = getchar() ) != EOF && c != '\n'; i++ )
    s[i] = c;

  if( c == '\n' ) s[i++] = c;

  s[i] = '\0';

  return i;
}

void scape( char s[], const char t[] ){
  int i = 0;
  int ii = 0;
  int c;

  while( ( c = t[ i++ ] ) != '\0' ){
    switch( c ){
    case '\a': s[ ii++ ] = '\\';  s[ ii++ ] = 'a'; break;
    case '\b': s[ ii++ ] = '\\';  s[ ii++ ] = 'b'; break;
    case '\t': s[ ii++ ] = '\\';  s[ ii++ ] = 't'; break;
    case '\n': s[ ii++ ] = '\\';  s[ ii++ ] = 'n'; break;
    case '\v': s[ ii++ ] = '\\';  s[ ii++ ] = 'v'; break;
    case '\f': s[ ii++ ] = '\\';  s[ ii++ ] = 'f'; break;
    case '\r': s[ ii++ ] = '\\';  s[ ii++ ] = 'r'; break;
    default  :                    s[ ii++ ] =   c; break;
    }
  }

  s[ ii ] = '\0';
}

void unescape( char s[], const char t[] ){
  int i = 0;
  int ii = 0;
  int c;

  while( ( c = t[ i++ ] ) != '\0' ){
    switch( c ){
    case '\\':
      switch( c = t[ i++ ] ){
      case 'a' : s[ ii++ ] = '\a'; break;
      case 'b' : s[ ii++ ] = '\b'; break;
      case 't' : s[ ii++ ] = '\t'; break;
      case 'n' : s[ ii++ ] = '\n'; break;
      case 'v' : s[ ii++ ] = '\v'; break;
      case 'f' : s[ ii++ ] = '\f'; break;
      case 'r' : s[ ii++ ] = '\r'; break;
      case '\0': s[ ii++ ] = '\\';
                              i--; break;
      default  : s[ ii++ ] = '\\';
                 s[ ii++ ] =    c; break;
      }
      break;
    default   :  s[ ii++ ] =    c; break;
    }
  }

  s[ ii ] = '\0';
}


/* output
tabtab          nl
tabtab\t\tnl\n
tabtab		nl

\n

*/

/* output
\\
\
\n

\n\n\n%nl
\n\n\n%nl\n



%nl
\t\v\a\r\n
\t\v\a\r\n\n




\n


\n

tab	nl
tab\tnl\n
tab	nl
\t\t\t\rEOF\t\t\t\rEOF
EOF
*/
