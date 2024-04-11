#include <stdio.h>

int main (int argc, char **argv)
{
  int x[3];
  int *ptr;

  char a;
  char *b;

  x[0] = 1024;
  x[1] = 32;
  x[2] = -1;
  ptr = &x[0];
  ptr++;
  ptr++;

  a = 5;
  b = &a;

  printf ("a=%i, lo apuntado por b=%i, el contenido de b=%p, y la direccion de "
          "b=%p \n",
          a, *b, b, &b);

  *b = 21;

  return 0;
}
