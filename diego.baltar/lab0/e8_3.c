#include <stdio.h>

#define BIT3 3

int main (int argc, char **argv)
{
  unsigned char status;

  status = 0b00110101;
  status = status | 0xFA; // 0b00110101 | 0b11111010 = 0b11111111
  status = status & 20;   // 0b11111111 & 0b00010100 = 0b00010100
  status |= (1 << 6);     // 0b00010100 | 0b01000000 = 0b01010100
  status &= ~(1 << BIT3); // 0b01010100 & 0b11110111 = 0b01010100
  status |= (1 << BIT3);  // 0b01010100 | 0b00001000 = 0b01011100

  printf ("Bits de status = %08b \n", status);
  printf ("Valor decimal de status = %i \n", status);
  printf ("Valor hexadecimal de status = %x \n", status);

  return 0;
}
