/* gcc main.c getop.c stack.c getch.c */
#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP   100  /* máx tamaño de operando u operador */

/* calculadora polaca inversa */
main()
{
  int type;
  double op2;
  char s[MAXOP];
  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: divisor cero\n");
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: comando desconocido %s\n", s);
      break;
    }
  }
  return 0;
}
