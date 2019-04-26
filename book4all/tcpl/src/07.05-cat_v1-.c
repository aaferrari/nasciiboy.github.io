#include <stdio.h>

/* cat: concatena archivos, version 1 */
int main( int argc, char *argv[] ){
  FILE *fp;
  void filecopy( FILE *, FILE * );

  if( argc == 1 )   /* sin args; copia la entrada estandar */
    filecopy( stdin, stdout );
  else
    while( --argc > 0 )
      if( (fp = fopen( *++argv, "r" )) == NULL ){
        printf( "cat: no se puede abrir %s\n", *argv );
        return 1;
      } else {
        filecopy( fp, stdout );
        fclose( fp );
      }

  return 0;
}

/* filecopy: copia el achivo ifp al archivo ofp */
void filecopy( FILE *ifp, FILE *ofp ){
  int c;
  while( (c = getc( ifp )) != EOF )
    putc( c, ofp );
}

// output  $ ./a.out 07.05-cat_v1-.c
// #include <stdio.h>
//
// /* cat: concatena archivos, version 1 */
// int main( int argc, char *argv[] ){
//   FILE *fp;
//   void filecopy( FILE *, FILE * );
//
//   if( argc == 1 )   /* sin args; copia la entrada estandar */
//     filecopy( stdin, stdout );
//   else
//     while( --argc > 0 )
//       if( (fp = fopen( *++argv, "r" )) == NULL ){
//         printf( "cat: no se puede abrir %s\n", *argv );
//         return 1;
//       } else {
//         filecopy( fp, stdout );
//         fclose( fp );
//       }
//
//   return 0;
// }
//
// /* filecopy: copia el achivo ifp al archivo ofp */
// void filecopy( FILE *ifp, FILE *ofp ){
//   int c;
//   while( (c = getc( ifp )) != EOF )
//     putc( c, ofp );
// }


/* output  $ ./a.out
linea uno
linea uno
lenea dos
lenea dos
*/
