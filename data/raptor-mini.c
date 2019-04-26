#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int automata( const char *txt, const char *re );

char leerPrimerCaracter( void ){
  int ch;

  ch = getchar();
  while( getchar() != '\n' ) continue;
  return ch;
}

char menu( void ){
  int ch;

  printf( "\n===== MENU AuToMaTa =======\n"
          "   q => Salir\n"
          "   x => Nueva exprecion\n"
          "   e => Evaluar\n"
          "   l => Nueva linea de entrada\n"
          " ? " );
  ch = leerPrimerCaracter();
  while(  ch != 'q' && ch != 'e' && ch != 'x' && ch != 'l' ){
    printf( "Responde por favor con 'e', 'l', 'x' o 'q' ? " );
    ch = leerPrimerCaracter();
  }

  return ch;
}

int main( int argc, char *argv[] ){
  char line[1024] = { 0 }, exp[1024] = { 0 };

  while(1){
    switch( menu() ){
    case 'e': break;
    case 'x':
      printf( "Ingrese expresión regular y presione Enter : " );
      gets(  exp );
      continue;
    case 'l':
      printf( "Ingrese cadena a reconocer y presione Enter: " );
      gets( line );
      continue;
    default : return 0;
    }

    printf( "\n   Cadena => \"%s\"\n"
            "Expresion => \"%s\"\n"
            "   Cadena => %s.. \n",
            line, exp, automata( line, exp ) ? "valida" : "invalida" );
  }

  return 0;
}


#define TRUE           1
#define FALSE          0
#define INF   1073741824 // 2^30

struct TEXT {
  const char *ptr;
  int   pos;
  int   len;
} static text;

enum TIPO { ALTERNATIVA, AGRUPACION, CARACTERES };

struct RE {
  const    char *ptr;
  int            len;
  enum     TIPO  tipo;
  unsigned int   loopsMin, loopsMax;
};

static int  ruta            ( struct RE  exp );
static int  recorrido       ( struct RE *exp );
static int  bucleCaracter   ( struct RE *exp );
static int  bucleAgrupacion ( struct RE *exp );
static int  seccionador     ( struct RE *exp, struct RE *seccion );
static void cortarCaracteres( struct RE *exp, struct RE *seccion );
static int  cortarXtipo     ( struct RE *exp, struct RE *seccion, const int tipo );
static void cortarXlongitud ( struct RE *exp, struct RE *seccion, const int len, const int tipo );
static void cortarExp       ( struct RE *exp, const int len );
static void obtenerBucles   ( struct RE *exp, struct RE *seccion );
static int  cmpCaracteres   ( struct RE *exp );

int automata( const char *txt, const char *re ){
  struct RE     exp;
  int resultado = 0;
  text.len      = strlen( txt );
  exp.ptr       = re;
  exp.tipo      = ALTERNATIVA;
  exp.len       = strlen( re );

  if( text.len == 0 || exp.len == 0 ) return 0;

  for( int avance, i = 0, loops = text.len; i < loops; i += avance ){
    avance   = 1;
    text.pos = 0;
    text.ptr = txt   + i;
    text.len = loops - i;

    if( ruta( exp ) ){
      if( text.pos > 0 ) avance = text.pos;
      resultado++;
    }
  }

  return resultado;
}

static int ruta( struct RE exp ){
  struct RE seccion;
  for( const int oTpos = text.pos;
       cortarXtipo( &exp, &seccion, ALTERNATIVA );
       text.pos = oTpos )
    if( recorrido( &seccion ) ) return TRUE;

  return FALSE;
}

static int recorrido( struct RE *exp ){
  struct RE seccion;
  for( int resultado = FALSE; seccionador( exp, &seccion ); ){
    resultado = (seccion.tipo == AGRUPACION)
      ? bucleAgrupacion( &seccion )
      : bucleCaracter( &seccion );

    if( resultado == FALSE ) return FALSE;
  }

  return TRUE;
}

static int bucleCaracter( struct RE *exp ){
  int avance, loops = 0;
  while( loops < exp->loopsMax && text.pos < text.len && (avance = cmpCaracteres( exp )) ){
    text.pos += avance;
    loops++;
  }

  return loops < exp->loopsMin ? FALSE : TRUE;
}

static int bucleAgrupacion( struct RE *exp ){
  int loops = 0;
  while( loops < exp->loopsMax && ruta( *exp ) ) loops++;

  return loops < exp->loopsMin ? FALSE : TRUE;
}

static int seccionador( struct RE *exp, struct RE *seccion ){
  if( exp->len == 0 ) return FALSE;

  switch( *exp->ptr ){
  case '(': cortarXtipo( exp, seccion,  AGRUPACION ); break;
  default : cortarCaracteres( exp, seccion ); break;
  }

  obtenerBucles( exp, seccion );
  return TRUE;
}

static void cortarCaracteres( struct RE *exp, struct RE *seccion ){
  for( int i = 1; i < exp->len; i++ )
    switch( exp->ptr[ i ] ){
    case '(':
      cortarXlongitud( exp, seccion, i, CARACTERES  ); return;
    case '?': case '+': case '*': case '{':
      if( i == 1 ) cortarXlongitud( exp, seccion,     1, CARACTERES  );
      else         cortarXlongitud( exp, seccion, i - 1, CARACTERES  );
      return;
    }

  cortarXlongitud( exp, seccion, exp->len, CARACTERES  );
}

static void cortarXlongitud( struct RE *exp, struct RE *seccion, const int len, const int tipo ){
  *seccion       = *exp;
  seccion->tipo  = tipo;
  seccion->len   = len;
  cortarExp( exp, len );
}

static int cortarXtipo( struct RE *exp, struct RE *seccion, const int tipo ){
  if( exp->len == 0 ) return FALSE;

  *seccion = *exp;
  seccion->tipo = tipo;
  for( int cut, i = 0, profundidad = 0; i < exp->len; i++ ){
    switch( exp->ptr[ i ] ){
    case '(': profundidad++; break;
    case ')': profundidad--; break;
    }

    switch( tipo ){
    case AGRUPACION : cut = profundidad == 0; break;
    case ALTERNATIVA: cut = profundidad == 0 && exp->ptr[i] == '|'; break;
    }

    if( cut ){
      seccion->len  = i;
      cortarExp( exp, i + 1 );
      if( tipo != ALTERNATIVA ) cortarExp( seccion, 1 );
      return TRUE;
    }
  }

  cortarExp( exp, exp->len );
  return TRUE;
}

static void cortarExp( struct RE *exp, const int len ){
  exp->ptr += len; exp->len -= len;
}

static int contarDigitos( const char *str ){
  for( int digits = 0; ; digits++ )
    if( isdigit( *str++ ) == 0 ) return digits;
}

static void obtenerBucles( struct RE *exp, struct RE *seccion ){
  seccion->loopsMin = 1; seccion->loopsMax = 1;

  if( exp->len )
    switch( *exp->ptr ){
    case '?' : cortarExp( exp, 1 ); seccion->loopsMin = 0; seccion->loopsMax =   1; return;
    case '+' : cortarExp( exp, 1 ); seccion->loopsMin = 1; seccion->loopsMax = INF; return;
    case '*' : cortarExp( exp, 1 ); seccion->loopsMin = 0; seccion->loopsMax = INF; return;
    case '{' : cortarExp( exp, 1 );
      seccion->loopsMin = atoi( exp->ptr );
      cortarExp( exp, contarDigitos( exp->ptr ) );
      if( *exp->ptr == ',' ){
        cortarExp( exp, 1 );
        if( *exp->ptr == '}' )
          seccion->loopsMax = INF;
        else {
          seccion->loopsMax = atoi( exp->ptr );
          cortarExp( exp, contarDigitos( exp->ptr  ) );
        }
      } else seccion->loopsMax = seccion->loopsMin;

      cortarExp( exp, 1 );
    }
}

static int cmpCaracteres( struct RE *exp ){
  return strncmp( text.ptr + text.pos, exp->ptr, exp->len ) == 0 ? exp->len : 0;
}
