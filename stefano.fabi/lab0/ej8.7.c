#include <stdio.h>

int main() {
    unsigned char x = 0b00001011;

    // Establecer los bits 7 y 6 de x
    x |= (0b11000000);

    // Mostrar el valor binario modificado de x
    printf("Valor binario modificado de x: %d%d%d%d%d%d%d%d\n", 
           (x & 0b10000000) ? 1 : 0,
           (x & 0b01000000) ? 1 : 0,
           (x & 0b00100000) ? 1 : 0,
           (x & 0b00010000) ? 1 : 0,
           (x & 0b00001000) ? 1 : 0,
           (x & 0b00000100) ? 1 : 0,
           (x & 0b00000010) ? 1 : 0,
           (x & 0b00000001) ? 1 : 0);

    return 0;
}
