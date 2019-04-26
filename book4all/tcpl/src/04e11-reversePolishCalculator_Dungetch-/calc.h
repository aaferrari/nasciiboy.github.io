#define NUMBER  '0'  /* señal de que un número se encontró  */
#define STRING  '1'  /* señal de que una cadena se encontró */

void push( double );
double pop( void );
double top( void );
int getop( char [] );
int getch( void );
void ungetch( int );
void ungets( char s[] );
void clear( void );
void string_funct( char s[] );
