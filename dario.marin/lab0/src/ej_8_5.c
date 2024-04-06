#include <stdio.h>

char validation(char word) {
  char aux = word & (1 << 3);
  return aux == (1 << 3);
}

int main() {
  char word = 0b00000111;
  if (validation(word)) {
    printf("el bit3 de la variable registro es 1 \n");
  }

  return 0;
}