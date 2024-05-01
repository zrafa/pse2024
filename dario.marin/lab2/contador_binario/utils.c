
/* utils.c - funciones de soporte al programa principal */

unsigned char is_on(char bit, char word) {
  unsigned char aux = word & (1 << bit);
  return aux == (1 << bit);
}