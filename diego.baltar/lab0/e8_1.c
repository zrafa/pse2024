#include <stdio.h>

int main (int argc, char **argv)
{
  unsigned char c = (1 << 5);

  printf ("Bits de c = %08b \n", c);
  printf ("Valor decimal de c = %i \n", c);
  printf ("Valor hexadecimal de c = %x \n", c);

  return 0;
}
