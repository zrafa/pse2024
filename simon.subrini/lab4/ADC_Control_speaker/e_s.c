#include "e_s.h"

volatile unsigned char *PINB  = (unsigned char *) 0x23;
volatile unsigned char *DDRB  = (unsigned char *) 0x24;
volatile unsigned char *PORTB = (unsigned char *) 0x25;
volatile unsigned char *PINC  = (unsigned char *) 0x26;
volatile unsigned char *DDRC  = (unsigned char *) 0x27;
volatile unsigned char *PORTC = (unsigned char *) 0x28;
volatile unsigned char *PIND  = (unsigned char *) 0x29;
volatile unsigned char *DDRD  = (unsigned char *) 0x2A;
volatile unsigned char *PORTD = (unsigned char *) 0x2B;
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

void pinMode(unsigned char pin, unsigned char mode) // Mode -> 0: Entrada, 1: Salida
{ 
        unsigned char reg = pin < 8? 0 : pin < 14? 1 : 2;
    
        switch(reg){
        case 0:
	        *PORTD &= ~(1<<pin); 
	        if (mode==1)
	                *DDRD |=  (1<<pin); 
                else
                        *DDRD &= ~(1<<pin);
                break;
        case 1:
	        *PORTB &= ~(1<<(pin-8)); 
	        if (mode==1)
	                *DDRB |=  (1<<(pin-8)); 
                else
                        *DDRB &= ~(1<<(pin-8));
                break;
        default:
	        *PORTC &= ~(1<<(pin-14)); 
	        if (mode==1)
	                *DDRC |=  (1<<(pin-14)); 
                else
                        *DDRC &= ~(1<<(pin-14));
                break;
        }
}

void digitalWrite(unsigned char pin, unsigned char state)
{
        unsigned char reg = pin < 8? 0 : pin < 14? 1 : 2;
    
        switch(reg){
        case 0:
	        if (state)
	                *PORTD |= (1<<pin);
                else
                        *PORTD &= ~(1<<pin);
                break;
        case 1:
	        if (state)
	                *PORTB |= (1<<(pin-8));
                else
                        *PORTB &= ~(1<<(pin-8));
                break;
        default:
	        if (state)
	                *PORTC |= (1<<(pin-14));
                else
                        *PORTC &= ~(1<<(pin-14));
                break;
        }
        
        
}

unsigned char digitalRead(unsigned char pin)
{ 
        unsigned char reg = pin < 8? 0 : pin < 14? 1 : 2;
        unsigned char lectura;
        
        switch(reg){
        case 0:
            lectura = (*PIND >> pin) & 0x01; // Desplaza el bit al LSB y realiza una verificación lógica
            break;
        case 1:
            lectura = (*PINB >> (pin-8)) & 0x01;
            break;
        default:
            lectura = (*PINC >> (pin-14)) & 0x01;
            break;
    }
        return lectura;
}

