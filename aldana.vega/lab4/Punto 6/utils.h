
/* utils.h - funciones de soporte al programa principal */

#ifndef _UTILS_H
#define _UTILS_H


void esperar();
void init();
double map(int val, int minInp, int maxInp,int minOut, int maxOut);
inline void delay_ms(volatile int ms);
inline void delay_us(volatile int us);
inline void tone2(int frecuencia);
inline void tone(int frecuencia,long int duracion);

#endif	/* _UTILS_H */
