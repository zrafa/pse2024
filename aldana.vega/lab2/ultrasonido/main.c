#include "utils.h"
#include "serial.h"

inline void delay_us(volatile int us);
inline void delay_ms(volatile int ms);

int main(void)
{	
    int tiempo;
    int cm;

    init();
    serial_init();
    
    while (1) {
        //Pulso de 10us para la señal de trigger
        trig_on();
        delay_us(10);
        trig_off(); 

        //Echo lee la señal
        tiempo = 0;
        while (leer_echo() == 0){}
        while((leer_echo() != 0) && (tiempo < 36000)){//Espera a que el pin cambie de estado
            delay_us(5);
            tiempo += 5;
        }
        
        //Calculo de la distancia
        if(tiempo >= 36000){
            serial_put_str("Fuera de rango\r\n");
        }else{
            cm = tiempo / 58;
            serial_put_str("Distancia:\r\n");
            serial_put_int(cm, 4);
            serial_put_str("\r\n");
        }       

        delay_ms(10);
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
         delay_us(100);
    }  
}



