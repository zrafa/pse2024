
/* Enciende y apaga un led conectado al puerto B bit 5 de un atmega328 */

#include "utils.h"
#include "math.h"
#include "frecuencias.h"


inline void delay_us(volatile int us);
inline void tone(int frecuencia,long int duracion);
inline void delay_ms(volatile int ms);

int melody[] = ALL_TOO_WELL;

int tempo = 100;


int main(void){	
	
	init();
	int notes = sizeof(melody) / sizeof(melody[0]) / 2;
	
    while (1) {
  		long int duracion = 0;
  		unsigned int wholenote = (60000 * 4) / tempo;

  		for (int i = 0; i < notes * 2; i = i + 2) {
   			if (melody[i+1] > 0) {
      			duracion = wholenote / melody[i+1];
    		} else  {
     			duracion = wholenote / abs(melody[i+1]);
               duracion *= 1.5;
    		}

    		tone(melody[i], duracion);
			delay_us(duracion);
    	}
		delay_ms(1000);
	}
}


inline void tone(int frecuencia,long int duracion){//duracion en ms
	if (frecuencia <= 0) {
    	delay_us(duracion);
  	}else{
		long double us = 1000000.0 / frecuencia;
    	duracion *= 1000L;

		for(unsigned long i=0;i<duracion;i+=us){
			on();
	    	delay_us(us/2);
			off();
			delay_us(us/2);
		}
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
         delay_us(1000);
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

