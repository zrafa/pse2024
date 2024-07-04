#include "serial.h"
#include <time.h>
#include "timer.h"
#include "adc.h"


inline double map(int val, int minInp, int maxInp,int minOut, int maxOut);
inline void delay_us(volatile int us);
inline void delay_ms(volatile int ms);

void main(){
   int adc,valor;
   
   timer_init();
   serial_init();
   adc_init();

   while (1)
   {
      adc = adc_get(A0,REF_5V);
      valor = map(adc,0,1023,500,2500);
      servo_angulo(valor);
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

inline double map(int val, int minInp, int maxInp,int minOut, int maxOut){
	double res;
	res = (double) val/maxInp;
	res = res*(maxOut-minOut);
	res= minOut+res;
	return res;
}