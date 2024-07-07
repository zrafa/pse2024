#include "timer1.h"
#include "serial.h"
#include "delay_ms.h"
#include <avr/interrupt.h>


void main()
{
  timer1_init();
  serial_init();
  sei();

  while (1) {
    unsigned int counter = timer1_get_counter(); //Tiempo en centesimas de segundo
    int secs = (counter/100) % 60;
    int mins = (counter/6000) % 60;
    int cent = counter % 100;
    
    serial_put_str("\r");
    serial_put_int(mins,2);
    serial_put_str(":");
    serial_put_int(secs,2);
    serial_put_str(":");
    serial_put_int(cent,2);
    delay_ms(10);
  }
}
