
/* utils.h - funciones de soporte al programa principal */

/* 
 * El puerto B de un atmega328 tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */

#ifndef _UTILS_H
#define _UTILS_H


void esperar();
void led_init();
void knight_rider_init();
void led_on(char led);
void led_off(char led);


#endif	/* _UTILS_H */
