/* getbits regresa el campo de n bits de x ajustado a la derecha que
   inicia en la posicion p. Se supone que la pasicion del bit 0 esta
   en el borde derecho y que n y p son valores adecuados */
unsigned getbits( unsigned x, int p, int n ){
  return ( x >> ( p + 1 - n ) ) & ~( ~0 << n );
}
