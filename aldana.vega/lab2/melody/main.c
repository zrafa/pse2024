
/* Enciende y apaga un led conectado al puerto B bit 5 de un atmega328 */

/* 
 * El puerto B de un atmega328 tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */

#include "utils.h"
#include "frecuencias.h"



inline void esperar_1us(void);
inline void esperar_10us(void);
inline void delay_us(volatile int us);
inline void tone(int frecuencia, int duracion);
inline void delay_ms(volatile int ms);
inline void tono(int frecuencia);

int melody[] = {
   NOTE_A4, 0, NOTE_A4, 0, NOTE_A4, 0, NOTE_F4, NOTE_C5, NOTE_A4, 0, NOTE_F4, NOTE_C5, NOTE_A4, 0, NOTE_E5, 0, NOTE_E5, 0, NOTE_E5, 0, NOTE_F5, NOTE_C5, NOTE_GS4, NOTE_F4, NOTE_C5, NOTE_A4, 0};
   
int duracion_notas[] = {
500, 500, 500, 500, 500, 500, 350, 150, 500, 500, 350, 150, 650, 500,
  500, 500, 500, 500, 500, 350, 150, 500, 500, 350, 150, 650, 500
};




int main(void)
{	
	init();
	int tam = sizeof(melody);
    while (1) {
		/*for (int i = 0; i <tam; i++)
		{
			int duracion = 1000/duracion_notas[i];//ms
			tone(melody[i],duracion);
			delay_ms(duracion);	
		}*/
		tono(2093);
		delay_ms(100);


    }
}


inline void tone(int frecuencia, int duracion){//duracion en ms
	unsigned int periodo = 1000000/frecuencia;//Obtiene cuantos us equivale la frecuencia
	unsigned int ciclos = frecuencia*duracion/1000;

	for(int i=0;i<ciclos;i++){
		on();
	    delay_us(periodo/2);
		off();
		delay_us(periodo/2);
	}

}

inline void tono(int frecuencia){//duracion en ms
	int periodo = 1000000/frecuencia;//Obtiene cuantos us equivale la frecuencia 
		on();
	    delay_us(periodo/2);
		off();
		delay_us(periodo/2);


}


inline void delay_us(volatile int us){
   //PARA 16MHZ 
	while(us--){
         asm volatile (
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

