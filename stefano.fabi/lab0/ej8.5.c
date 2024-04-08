#include <stdio.h>

int main() {
    unsigned char x = 11;

    if (x & (1 << 3)) {
        printf("El bit 3 de la variable x es 1");
    }

    return 0;
}
