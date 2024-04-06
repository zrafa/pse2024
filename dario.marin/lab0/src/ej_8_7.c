#include <stdio.h>

void activate_bits_67(char* word) {
  char mask = 0b11000000;
  *word |= mask;
}

int main() {
  unsigned char word = 0;
  activate_bits_67(&word);
  printf("\n%d", word);
  return 0;
}