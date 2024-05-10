#include "utils.h"

/*
ddr: 0: Entrada, 1: Salida
port: 
  si ddr = 0:
      0: Sin pullup
      1: Con pullup
  si ddr = 1:
      0: Estado bajo
      1: Estado alto
pin: Solo lectura -> estado pines
*/

volatile unsigned char *PORTB = (unsigned char *) 0x25;
volatile unsigned char *DDRB  = (unsigned char *) 0x24;
volatile unsigned char *PINB  = (unsigned char *) 0x23;

void config(unsigned char pin)
{
	*PORTB &= ~(1<<pin); 
	*DDRB  |=  (1<<pin); 
}

void digitalWrite(unsigned char pin, unsigned char state)
{
        if (state)
	        *PORTB |= (1<<pin);
        else
                *PORTB &= ~(1<<pin);
        
}

unsigned char digitalRead(unsigned char i)
{
        unsigned char lectura = * PINB & (1<<i);
        return lectura;
}

