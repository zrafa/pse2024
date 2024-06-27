
/* utils.h - funciones de soporte al programa principal */
#ifndef _UTILS_H
#define _UTILS_H


void esperar();
void init();
char leer_pin0();
char leer_pin1();
void pulsadores_on();
void led_on();
void led_off(); 
inline void delay_ms(volatile int ms);
inline void delay_us(volatile int us)
#endif	/* _UTILS_H */