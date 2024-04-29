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


volatile unsigned char * PORTB = (unsigned char *) 0x25;
volatile unsigned char * DDRB  = (unsigned char *) 0x24;
volatile unsigned char * PINB  = (unsigned char *) 0x23;


void config() {
	* PORTB = 0b00000001; // Pullup en la entrada PORTB0, salidas PORTB1 a PORTB5 en estado bajo
	* DDRB  = 0b00111110; // Entrada PORTB0, salidas PORTB1 a PORTB5
}

void digitalWrite(unsigned char pin,unsigned char state) {
    if (state){
	* PORTB |= (1<<pin);
    }else{
        * PORTB &= ~(1<<pin);
    }
}

unsigned char digitalRead(unsigned char i){
  unsigned char lectura = * PINB & (1 << i);
  if (lectura == 0){
    return 0;
  }else{
    return 1;
  }
}

void update(unsigned char cont){
  * PORTB = (cont << 1);
}
