
/* Enciende y apaga un led conectado al puerto B bit 5 de un atmega328 */

/* 
 * El puerto B de un atmega328 tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */

#include "utils.h"
#include "serial.h"
#define PIN_ECHO 0x6 
#define PIN_TRIG 0x7

inline void delay_us(volatile int us);
inline void delay_ms(volatile int ms);

int main(void)
{	
    int tiempo = 0;
    int t1,t2;
    int cm;
    int echo;
	init();
    serial_init();
    while (1) {
        t1=0;
        t2=0; 

        //Pulso de 10us para la señal de trigger
		trig_on();
		delay_us(10);
		trig_off(); 


        //Echo lee la señal
       
        while(leer_echo()==1 && tiempo<36000){//ESpera a que el pin cambie de estado
            delay_us(10);
            t2+=10;
        }
        echo_off();

        
        //Calculo de la distancia
        if(tiempo>=36000){
            serial_put_str("Fuera de rango\r\n");
        }else{
            cm = tiempo/58;
            serial_put_str("Tiempo:\r\n");
  	        serial_put_int(tiempo, 4);
            serial_put_str("\r\n");
            serial_put_str("Distancia:\r\n");
  	        serial_put_int(cm, 4);
            serial_put_str("\r\n");
        }
        

        //Espera de 10us hasta enviar la proxima señal de trigger
        delay_ms(10);
            
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

inline void delay_ms(volatile int ms){
   //PARA 16MHZ 
	while(ms--){
         delay_us(1000);
    }  
}



