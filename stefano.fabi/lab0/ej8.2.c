#include <stdio.h>

int main() {
    char variable_char; 

    variable_char = ~(1 << 5); 

    // Mostrar el valor en base 2 de la variable de tipo char
    printf("Valor en base 2 de la variable de tipo char: %d\n", variable_char);

    // Mostrar el valor en decimal de la variable de tipo char
    printf("Valor en decimal de la variable de tipo char: %d\n", (int) variable_char);

    return 0;
}
