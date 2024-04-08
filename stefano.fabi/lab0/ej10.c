#include <stdio.h>

int main() {
    unsigned char RES;
    unsigned char var;
    var = 190;
    
    RES = (unsigned char)(var * 500) / 190;

    // Imprimir el resultado
    printf("El resultado de la operación es: %u\n", RES);

    return 0;
}
