#include "serial.h"
#include <time.h>
#include "timer.h"

extern volatile unsigned char valor_escalado = 0;

unsigned char escalar_dato(unsigned char dato);
inline void delay_us(volatile int us);
inline void delay_ms(volatile int ms);

void main(){
   unsigned char dato;

   timer_init();
   serial_init();

   while (1)
   {
      dato = serial_get_char();
      //Escalar dato
      escalar_dato(dato);
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

unsigned char escalar_dato(unsigned char dato){
	
}