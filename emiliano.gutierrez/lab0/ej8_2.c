#include <stdio.h>

void
main ()
{
  unsigned char var2 = 0b10000000;
  printf ("%i\n", var2);
  var2 = ~(var2 >> 2);
  printf ("%i\n", var2);
  /*
     Se define var2 como unsigned char con valor inicial 0b10000000 = 128 en decimal.
     Al aplicar el desplazamiento en dos unidades hacia la derecha, desplazaremos el 1,
     quedando 0b00100000 = 32 en decimal. Luego, al negarlo, se obtiene 0b11011111 
     (todos los dígitos negados) que es igual a 255 - 32 = 223 en decimal.
    */
}
