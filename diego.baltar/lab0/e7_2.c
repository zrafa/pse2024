#include <stdio.h>

int main (int argc, char **argv)
{
  unsigned int array[5];
  array[2] = 99;

  unsigned int *pointer;
  pointer = &array[0];
  *(pointer+2) = 99;

  pointer = array;

  return 0;
}
