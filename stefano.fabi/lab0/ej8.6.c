#include <stdio.h>

int main() {
    unsigned char x = 0b00001011;

    // Mostrar el valor binario original de x
    printf("Valor binario original de x: %d%d%d%d%d%d%d%d\n", 
           (x & 0b10000000) ? 1 : 0,
           (x & 0b01000000) ? 1 : 0,
           (x & 0b00100000) ? 1 : 0,
           (x & 0b00010000) ? 1 : 0,
           (x & 0b00001000) ? 1 : 0,
           (x & 0b00000100) ? 1 : 0,
           (x & 0b00000010) ? 1 : 0,
           (x & 0b00000001) ? 1 : 0);

    // Eliminar los bits 2, 1 y 0 de x
    x &= ~(0b00000111);

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
