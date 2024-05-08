
#include "utils.h"

inline void delay_us(volatile int us);
inline void delay_ms(volatile int ms);

void main(void)
{	
	char n;
	char estado_actual = 1;
	char estado_anterior = 1;
	char estado = 1;

	init();
	pulsador_on();

    while (1) {
		estado_actual = leer_pin();
		delay_ms(5);//delay de 5 ms
		estado_actual = leer_pin();
		
		if((estado_actual == 0) && (estado_anterior == 1))//Se apretó el pulsador
			estado = 1 - estado;
		
		estado_anterior = estado_actual;

		if(estado == 1){
			led_on(n);
			n++;
			delay_ms(300);
		}
    }
}

inline void delay_us(volatile int us)
{
   //PARA 16MHZ 
	while(us--){
         asm volatile (
            "nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			);
    }    
}

inline void delay_ms(volatile int ms)
{
   //PARA 16MHZ 
	while(ms--){
         delay_us(1000);
    }  
}


