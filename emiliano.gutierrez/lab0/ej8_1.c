#include <stdio.h>

void
main ()
{
  unsigned char var1 = 0b10000000;
  printf ("%i\n", var1);
  var1 = var1 >> 2;
  printf ("%i\n", var1);
  /*
     Se define var1 como unsigned char con valor inicial 0b10000000 = 128 en decimal.
     Al aplicar el desplazamiento en dos unidades hacia la derecha, desplazaremos el 1,
     quedando 0b00100000 = 32 en decimal.
   */