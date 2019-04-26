/* este programa imprime los valores de las constantes
   que definen los valores de las variables            */
#include <stdio.h>
#include <limits.h>

int main(){
  printf( "Number of bits in char               %22d\n",     CHAR_BIT     );
  printf( "Maximum value for signed char        %22d\n",     SCHAR_MAX    );
  printf( "Maximum value for char               %22d\n",     CHAR_MAX     );
  printf( "Minimum value for signed char        %22d\n",     SCHAR_MIN    );
  printf( "Minimum value for char               %22d\n",     CHAR_MIN     );
  printf( "Maximum value for unsigned char      %22d\n",     UCHAR_MAX    );
  printf( "Maximum value for short              %22d\n",     SHRT_MAX     );
  printf( "Minimum value for short              %22d\n",     SHRT_MIN     );
  printf( "Maximum value for unsigned short     %22d\n",     USHRT_MAX    );
  printf( "Maximum value for int                %22d\n",     INT_MAX      );
  printf( "Minimum value for int                %22d\n",     INT_MIN      );
  printf( "Maximum value for unsigned int       %22u\n",     UINT_MAX     );
  printf( "Maximum value for long               %22ld\n",    LONG_MAX     );
  printf( "Minimum value for long               %22ld\n",    LONG_MIN     );
  printf( "Maximum value for unsigned long      %22lu\n",    ULONG_MAX    );
  printf( "Maximum value for long long          %22lld\n",   LLONG_MAX    );
  printf( "Minimum value for long long          %22lld\n",   LLONG_MIN    );
  printf( "Maximum value for unsigned long long %22llu\n",   ULLONG_MAX   );

  return 0;
}


/* output
Number of bits in char                                    8
Maximum value for signed char                           127
Maximum value for char                                  127
Minimum value for signed char                          -128
Minimum value for char                                 -128
Maximum value for unsigned char                         255
Maximum value for short                               32767
Minimum value for short                              -32768
Maximum value for unsigned short                      65535
Maximum value for int                            2147483647
Minimum value for int                           -2147483648
Maximum value for unsigned int                   4294967295
Maximum value for long                  9223372036854775807
Minimum value for long                 -9223372036854775808
Maximum value for unsigned long        18446744073709551615
Maximum value for long long             9223372036854775807
Minimum value for long long            -9223372036854775808
Maximum value for unsigned long long   18446744073709551615
*/
