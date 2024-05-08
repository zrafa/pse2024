/*
 * ultrasound: programa que controla el HC-SR04 para medir distancias en cm
 */
#include "serial.h"
#include "pin_rw.h"
#include "delays.h"

/* puertos de E/S */

/* direccion de PORTB (registro de datos) */
volatile unsigned char * PORTB = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * DDRB = (unsigned char *) 0x24;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * pin_b = (unsigned char *) 0x23;

#define TRIG 0x01 //(PB0 - D8)
#define ECHO 0x02 //(PB1 - D9)

unsigned int cont = 0;
unsigned int distancia = 0;

void init_es(void){
    *(DDRB) = (*(DDRB) & ~ECHO) | TRIG; //ECHO como entrada y TRIG como salida
    *PORTB = (*PORTB & ~TRIG) | ECHO; //activo res de pull up para ECHO
}

void trig_pulse()
{
    write_pin(1,TRIG,PORTB);
    esperar_10us(1); 
    write_pin(0,TRIG,PORTB);
}

void medir(void)
{       
    while (read_pin(ECHO,pin_b)==0);
    
    cont = 0;
    while (read_pin(ECHO,pin_b)==1){
        esperar_100us(1);
        cont++;
    }
    
    if (cont < 360){
        distancia = cont*100/58;
        serial_put_str("Distancia: ");
        serial_put_int(distancia,3);
        serial_put_str(" cm\r\n");
    }
    else {
        serial_put_str("Fuera de rango\r\n");
    }    
}

int main(void)
{
	serial_init();
	init_es();
    
    while(1){
        trig_pulse();
        medir();
        esperar_1ms(1000);
    }
}

