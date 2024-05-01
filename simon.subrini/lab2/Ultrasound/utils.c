
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



void ultrasound_init(const unsigned char trig_pin, const unsigned char echo_pin) {
        * PORTB &= ~((1 << trig_pin) | (1 << echo_pin));
        * DDRB  &= ~(1 << echo_pin);   // Entrada
        * DDRB  |=  (1 << trig_pin);   // Salida
}


/* led_on: enciende el led conectado al puerto b bit i*/
void led_on(unsigned char i) {
	* PORTB |= (1 << i);
}

/* led_off: apaga el led conectado al puerto b bit i*/
void led_off(unsigned char i) {
	* PORTB &= ~(1 << i);
}

unsigned char read_pin(unsigned char i){
  unsigned char lectura = * PINB & (1 << i);
  if (lectura == 0){
    return 0;
  }else{
    return 1;
  }
}

