
/* utils.h - funciones de soporte al programa principal */

/* 
 * El puerto B de un atmega328 tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */

#ifndef _UTILS_H
#define _UTILS_H


void config();
void digitalWrite(unsigned char pin,unsigned char state);
void update(unsigned char cont);
unsigned char digitalRead(unsigned char i);


#endif	/* _UTILS_H */
