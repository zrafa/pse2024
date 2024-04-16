#include <stdio.h>

int main (int argc, char **argv)
{
  char i;
  unsigned char j;

  i = 0b10000000;
  j = 0b10000000;

  printf ("Valor numérico de i = %i\n", i);
  printf ("Valor numérico de j = %i\n", j);
  printf ("Bits de i = %08b\n", i);
  printf ("Bits de j = %08b\n", j);

  return 0;
}
