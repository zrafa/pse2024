
/* Enciende y apaga un led conectado al puerto B bit 5 de un atmega328 */

/* 
 * El puerto B de un atmega328 tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */

#include "utils.h"
#define LED_0 0x1
#define LED_1 0x2
#define LED_2 0x4
#define LED_3 0x8
#define LED_4 0x10


inline void esperar_1us(void);
inline void esperar_10us(void);

int main(void)
{	
    while (1) {
		led_on(LED_0);
        //esperar_1us();
		delay_us(500);
		led_off(LED_0);
		//esperar_1us();
		delay_us(500);
    }
}

inline void delay_us(volatile int us){
   //PARA 16MHZ 
	while(us--){
         asm volatile (
            "nop" "\n\t"
			);
    }

    
}

inline void esperar_10us(void)
{// Para 4MHZ

  	    asm volatile (
            "nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			);
}

inline void esperar_1us(void)
{//PARA 16MHZ

  	    asm volatile (
            "nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			);
}

