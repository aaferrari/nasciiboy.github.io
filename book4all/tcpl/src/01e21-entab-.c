#include <stdio.h>

#define MAXLINE 1024   /* tamaño máximo de la línea de entrada */
#define SPC2TAB    8   /* cadena de sustitucion colacada por cada tabulador */

int myGetline( char s[], int lim );
void spc2tab( char line[], char tabline[], int width );

/* este programa reeplaza espacios par tabulaciones y espacios */
int main(){
  int len;               /* longitud actual de la línea    */
  char line[MAXLINE];    /* línea de entrada actual        */
  char tabline[MAXLINE]; /* lenea que contendra modificada */

  while( ( len = myGetline( line, MAXLINE ) ) > 0 ){
    spc2tab( line, tabline, SPC2TAB );
    printf( "%s", tabline );
  }

  putchar( '\n' );
  return 0;
}

/* getline: lee una línea en s, regresa su longitud */
int myGetline( char s[], int lim ){
  int c, i;

  for( i=0; i < lim-1 && ( c = getchar() ) != EOF && c != '\n'; ++i )
    s[i] = c;

  if( c == '\n' ){
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}

void spc2tab( char line[], char tabline[], int width ){
  int iline, itabline, spaces;
  char c;

  iline = itabline = spaces = 0;
  while( ( c = line[ iline ] ) != '\0' ){
    if( c == ' ' && line[ iline + 1 ] == ' ' ){
      spaces++;
    } else if( c == ' ' && line[ iline + 1 ] != ' ' ){
      if( ++spaces < width )
        while( spaces-- ) tabline[ itabline++ ] = ' ';
    } else tabline[ itabline++ ] = c;

    if( spaces == width ){
      tabline[ itabline++ ] = '\t';
      spaces = 0;
    }

    iline++;
  }

  tabline[ itabline ] = '\0';
}

/*output
               15spc
	       15spc
		 2\t1spc
		 2\t1spc
		               2\t15spc
			       2\t15spc
        8spc
	8spc

*/
