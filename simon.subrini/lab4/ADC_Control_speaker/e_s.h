/**********************************************************************
 *
 * Filename:    e_s.h
 * 
 * API para la aplicacion embebida 
 * META : ocultar el hardware a la aplicacion 
 *
 **********************************************************************/

#ifndef _ES_H
#define _ES_H

#define LOW 0
#define HIGH 1
#define INPUT 0
#define OUTPUT 1


void pinMode(unsigned char pin, unsigned char mode);
void digitalWrite(unsigned char pin, unsigned char state);
unsigned char digitalRead(unsigned char pin);

#endif /* _ES_H */
