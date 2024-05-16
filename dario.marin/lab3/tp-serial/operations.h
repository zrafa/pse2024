
/* utils.h - funciones de soporte al programa principal */

#ifndef _UTILS_H
#define _UTILS_H

unsigned char get_bit(unsigned char *reg, unsigned char n);
void set_bit(unsigned char *reg, char n);
void clear_bit(unsigned char *reg, char n);
void toggle_bit(unsigned char *reg, unsigned char n);
void write_bits(unsigned char *reg, unsigned char n);
#endif /* _UTILS_H */
