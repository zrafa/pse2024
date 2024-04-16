#include <stdio.h>

int main (int argc, char **argv)
{
  char i = 'a';
  char j = 77;
  char k = 0x4D;
  unsigned char m = 'a';
  unsigned char n = 0x4d;
  unsigned char p = 'A';

  printf ("i = %c (%i) \n", i, i);
  printf ("j = %c (%i) \n", j, j);
  printf ("k = %c (%i) \n", k, k);

  printf ("m = %c (%i) \n", m, m);
  printf ("n = %c (%i) \n", n, n);
  printf ("p = %c (%i) \n", p, p);

  return 0;
}
