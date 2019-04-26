/* itoa: convierte n a caracteres en s */
/* reverse: invierte la cadena s en el mismo lugar */
#include <stdio.h>
#include <string.h>
#include <limits.h>

void twobin( unsigned int x, char s[] ){
  int i = 0;
  while( x ){
    if( x & 1U ) s[ i++ ] = '1';
    else         s[ i++ ] = '0';
    x >>= 1;
  }

  s[ i ] = '\0';
}


void twooct( unsigned int x, char s[] ){
  int i = 0;
  unsigned int mask = ~(~0U << 3);
  while( x ){
    s[ i++ ] = ( x & mask ) + '0';
    x >>= 3;
  }

  s[ i ] = '\0';
}


void twohex( unsigned int x, char s[] ){
  int i = 0;
  unsigned int mask = ~(~0U << 4);
  while( x ){
    if( ( x & mask ) >= 10 ) s[ i++ ] = ( x & mask ) - 10 + 'A';
    else                     s[ i++ ] = ( x & mask )      + '0';
    x >>= 4;
  }

  s[ i ] = '\0';
}


void reverse( char s[] ){
  int c, i, j;
  for( i = 0, j = strlen( s ) - 1; i < j; i++, j-- ){
    c = s[ i ];
    s[ i ] = s[ j ];
    s[ j ] = c;
  }
}


void itob( unsigned int n, char s[], int b ){
  if( !n ){ s[ 0 ] = '0'; s[ 1 ] = '\0';
  } else {
    switch( b ){
    case  2: twobin( n, s ); break;
    case  8: twooct( n, s ); break;
    case 16: twohex( n, s ); break;
    default:
      printf( "itob - case %d no macth\n", b );
      break;
    }

    reverse( s );
  }
}


int main(){
  unsigned int i;
  char bin[ sizeof( char ) * CHAR_BIT + 1 ];
  char oct[ sizeof( char ) * CHAR_BIT + 1 ];
  char hex[ sizeof( char ) * CHAR_BIT + 1 ];

  for( i = 0; i < 100; i++ ){
    itob( i, bin,  2 );
    itob( i, oct,  8 );
    itob( i, hex, 16 );
    printf( "%3d - 0x%s o%s %s\n", i, hex, oct, bin );
  }

  return 0;
}

/* output
  0 - 0x0 o0 0
  1 - 0x1 o1 1
  2 - 0x2 o2 10
  3 - 0x3 o3 11
  4 - 0x4 o4 100
  5 - 0x5 o5 101
  6 - 0x6 o6 110
  7 - 0x7 o7 111
  8 - 0x8 o10 1000
  9 - 0x9 o11 1001
 10 - 0xA o12 1010
 11 - 0xB o13 1011
 12 - 0xC o14 1100
 13 - 0xD o15 1101
 14 - 0xE o16 1110
 15 - 0xF o17 1111
 16 - 0x10 o20 10000
 17 - 0x11 o21 10001
 18 - 0x12 o22 10010
 19 - 0x13 o23 10011
 20 - 0x14 o24 10100
 21 - 0x15 o25 10101
 22 - 0x16 o26 10110
 23 - 0x17 o27 10111
 24 - 0x18 o30 11000
 25 - 0x19 o31 11001
 26 - 0x1A o32 11010
 27 - 0x1B o33 11011
 28 - 0x1C o34 11100
 29 - 0x1D o35 11101
 30 - 0x1E o36 11110
 31 - 0x1F o37 11111
 32 - 0x20 o40 100000
 33 - 0x21 o41 100001
 34 - 0x22 o42 100010
 35 - 0x23 o43 100011
 36 - 0x24 o44 100100
 37 - 0x25 o45 100101
 38 - 0x26 o46 100110
 39 - 0x27 o47 100111
 40 - 0x28 o50 101000
 41 - 0x29 o51 101001
 42 - 0x2A o52 101010
 43 - 0x2B o53 101011
 44 - 0x2C o54 101100
 45 - 0x2D o55 101101
 46 - 0x2E o56 101110
 47 - 0x2F o57 101111
 48 - 0x30 o60 110000
 49 - 0x31 o61 110001
 50 - 0x32 o62 110010
 51 - 0x33 o63 110011
 52 - 0x34 o64 110100
 53 - 0x35 o65 110101
 54 - 0x36 o66 110110
 55 - 0x37 o67 110111
 56 - 0x38 o70 111000
 57 - 0x39 o71 111001
 58 - 0x3A o72 111010
 59 - 0x3B o73 111011
 60 - 0x3C o74 111100
 61 - 0x3D o75 111101
 62 - 0x3E o76 111110
 63 - 0x3F o77 111111
 64 - 0x40 o100 1000000
 65 - 0x41 o101 1000001
 66 - 0x42 o102 1000010
 67 - 0x43 o103 1000011
 68 - 0x44 o104 1000100
 69 - 0x45 o105 1000101
 70 - 0x46 o106 1000110
 71 - 0x47 o107 1000111
 72 - 0x48 o110 1001000
 73 - 0x49 o111 1001001
 74 - 0x4A o112 1001010
 75 - 0x4B o113 1001011
 76 - 0x4C o114 1001100
 77 - 0x4D o115 1001101
 78 - 0x4E o116 1001110
 79 - 0x4F o117 1001111
 80 - 0x50 o120 1010000
 81 - 0x51 o121 1010001
 82 - 0x52 o122 1010010
 83 - 0x53 o123 1010011
 84 - 0x54 o124 1010100
 85 - 0x55 o125 1010101
 86 - 0x56 o126 1010110
 87 - 0x57 o127 1010111
 88 - 0x58 o130 1011000
 89 - 0x59 o131 1011001
 90 - 0x5A o132 1011010
 91 - 0x5B o133 1011011
 92 - 0x5C o134 1011100
 93 - 0x5D o135 1011101
 94 - 0x5E o136 1011110
 95 - 0x5F o137 1011111
 96 - 0x60 o140 1100000
 97 - 0x61 o141 1100001
 98 - 0x62 o142 1100010
 99 - 0x63 o143 1100011
*/
