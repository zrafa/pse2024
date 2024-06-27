#include "serial.h"
#include <time.h>
#include "timer.h"

extern volatile unsigned long ticks;

void main()
{
   timer_init();
   serial_init();

   while(1){
      unsigned long current_ticks = ticks;

      unsigned int seg = (current_ticks / 1000)%60;
      unsigned int min = (current_ticks / 60000)%60;
      unsigned int hora = (current_ticks / 360000);

      serial_put_int(hora,2);
      serial_put_char(':');
      serial_put_int(min,2);
      serial_put_char(':');
      serial_put_int(seg,2);
      serial_put_char('\r');

      delay_ms(500);
   }
}


inline void delay_us(volatile int us){
   //PARA 16MHZ  
	while(us--){
         asm volatile (
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
			); 
    }  
}

inline void delay_ms(volatile int ms){
   //PARA 16MHZ 
	while(ms--){
         delay_us(100);
    }  
}