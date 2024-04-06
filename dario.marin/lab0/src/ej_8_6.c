#include <stdio.h>

void clear_bits(char* word) {
  char mask = 0b11111000;
  *word &= mask;
}

int main() {
  unsigned char word = 0xFF;
  clear_bits(&word);
  printf("\n%d", word);
  return 0;
}