
/* utils.h - funciones de soporte al programa principal */

#ifndef _UTILS_H
#define _UTILS_H

unsigned char is_on(char bit, unsigned char word);
void set_bit(char bit, volatile unsigned char *reg);
void set_bits(unsigned char bits, volatile unsigned char *reg);
void clear_bit(char bit, volatile unsigned char *reg);
void clear_bits(unsigned char bits, volatile unsigned char *reg);

#endif /* _UTILS_H */
