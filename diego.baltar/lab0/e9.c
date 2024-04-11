#include <stdio.h>

int main (int argc, char **argv)
{
  unsigned char RES;
  unsigned char var;
  var = 190;
  RES = (unsigned char)(var * 500) / 190;

  printf ("RES = %i \n", RES);
  printf ("RES = %c \n", RES);
  printf ("RES = %08b \n", RES);

  return 0;
}
