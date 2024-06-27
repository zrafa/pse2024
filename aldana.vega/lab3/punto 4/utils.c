
/* utils.c - funciones de soporte al programa principal */
#include "serial.h"
#include "stdio.h"

void esperar();
inline void delay_us(volatile int us);
inline void delay_ms(volatile int ms);

void init();
void trig_on();
void trig_off();
void echo_on();
void echo_off();
int leer_echo();

void knight_rider_init();
void led_on(char led);

/* puertos de E/S */

/* direccion de PORTB (registro de datos) */
volatile unsigned char * puerto_b = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_b = (unsigned char *) 0x24;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * pin_b = (unsigned char *) 0x23;

/* direccion de PORTC (registro de datos) */
volatile unsigned char * puerto_c = (unsigned char *) 0x28;

/* direccion de DDR C (registro de control) */
volatile unsigned char * ddr_c = (unsigned char *) 0x27;

/* direccion PIN C (registro de datos de entrada) */
volatile unsigned char * pin_c = (unsigned char *) 0x26;

char led [9] = {0b00000000, 0b00000001, 0b00000011, 0b00000110, 0b00001100, 0b00011000, 0b00010000, 0b00000000};

void inicializar()
{
    knight_rider_init();
    init();
}


void knight_rider_init() 
{
    *(puerto_b) &= 0;//Apaga los bits de los leds
    *(ddr_b) |= 0b00011111;//Configura los pines conectados a los bits 0-5 como salida
}

void knight_rider()
{
    for (int i = 0; i < 9; i++) {
        led_on(led[i]);
        esperar();
    }
		
    for (int i = 8;i >= 0; i--) {
        led_on(led[i]);
    	esperar();
    }
}

/* led_on: enciende los leds conectado al puerto b*/
void led_on(char led) 
{
    *(puerto_b) = led;
}

void knight_rider_apagar() 
{
    *(puerto_b) &= 0;//Apaga los bits de los leds
}

void init() 
{
    //Trigger está en el bit 5 del puerto B y echo en el bit 0 del puerto C
    //Trigger se setea como salida y echo como entrada

    *(puerto_c) &= 0b0;
    *(ddr_c) |= 0b00000000;
    *(ddr_b) |= 0b00100000;

}

void ultrasonido()
{
    int tiempo;
    int cm;

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

void trig_on()
{
    *(puerto_b) = 0b00100000;
}

void trig_off()
{
    *(puerto_b) = 0b00000000;
}

int leer_echo()
{
    return (*pin_c & 0b00000001);
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
