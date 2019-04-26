unsigned long int next = 1;

/* rand: regresa un entero pseudoaleatorio en 0..32767 */
int rand( void ){
  next = next * 1103515245 + 123768;
  return (unsigned int)(next / 65536) % 32768;
}
/* srand: fija la semilla para rando() */
void srand( unsigned int seed ){
  next = seed;
}
