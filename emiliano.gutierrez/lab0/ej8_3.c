#include <stdio.h>

void
main ()
{
  #define BIT3 3
  unsigned char status;
  unsigned char aux1, aux2;
  status = 0b00110101;
  //Variable status original
  printf("%x\n",status);
  status = status | 0xFA;
  /*0xFA = 0b11111010. Al hacer operacion OR con 0xFA pongo en 1 todos los bits de status que
  están en las pocisiones de los 1's de 0xFA. En las posiciones de los 0's de 0xFA se mantiene
  sin cambios el valor que estaba en status. En este caso, el último y antepenúltimo bit en status
  permanecen sin cambios, el resto pasan a ser 1's (si es que no lo eran antes).
  Quedaría que status = 0b11111111 = 0xFF*/
  printf("%x\n",status);
  status = status & 20;
  /*20 = 0x14 = 0b00010100. Al hacer operación AND con 0x14, todos los bits en status ubicados en la
  posición de un 0 en 0x14 pasan a ser 0. Los bits restantes (correpondientes a donde hay 1's en 0x14)
  se mantienen sin cambio.
  Quedaría que status = 0b00010100 = 0x14*/
  printf("%x\n",status);
  status |= (1 << 6);
  /*(1<<6) = 0b01000000 = 0x40 = 64 decimal. Estoy haciendo una OR entre status y 0x40
  Quedaría que status = 0b01010100 = 0x54*/
  printf("%x\n",status);
  status &= ~(1 << BIT3);
  /*(1<<3) = 0b00001000 = 0x08 = 8 decimal. Al negarlo tengo 0b11110111 = 0xF7 = 247.
  Estoy haciendo operación AND entre 0xF7 y status.
  Quedaría que status = 0b01010100 = 0x54*/
  printf("%x\n",status);
  status |= (1 << BIT3);
  /* (1<<3) = 0b00001000. Hago operación OR con status.
  Quedaría status = 0b01011100 = 0x5C*/
  printf("%x\n",status);
  
  // Verificamos el estado del 2do bit. Debería ser un 1.
  aux1 = 0b01000000;
  aux2 = aux1&status;
  printf("%x\n",aux2); //Debería ver 0b01000000 = 0x40
  
  // Nos quedamos con los primeros 5 bits. AND con 0b11111000 = 0xF8
  aux1 = 0b11111000;
  aux2 = aux1&status;
  printf("%x\n",aux2); //Debería ver 0b01011000 = 0x58  
}
