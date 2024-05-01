
/* utils.c - funciones de soporte al programa principal */

/* En los puertos b0-4 de un atmega328p
 * El puerto B de un atmega328p tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */

#include "utils.h"

/* puertos de E/S */

/* direccion de PORTB (registro de datos) */
volatile unsigned char * PUERTO_B = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * DDR_B = (unsigned char *) 0x24;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * PIN_B = (unsigned char *) 0x23;

#define LED_0 (0x01) /* PB0 0b00000001 */
#define LED_1 (0x02) /* PB1 0b00000010 */
#define LED_2 (0x04) /* PB2 0b00000100 */
#define LED_3 (0x08) /* PB3 0b00001000 */
#define LED_4 (0x10) /* PB4 0b00010000 */

/* direccion de PORTC (registro de datos) */
volatile unsigned char * PUERTO_C = (unsigned char *) 0x28;

/* direccion de DDR C (registro de control) */
volatile unsigned char * DDR_C = (unsigned char *) 0x27;

/* direccion PIN C (registro de datos de entrada) */
volatile unsigned char * PIN_C = (unsigned char *) 0x26;

#define PULSADOR (0x01) /* PC0 0b00000001 */

#define COUNTER_LIMIT (0x20)			// 32

/** Determina si se detiene o no el contador 
 * true = prende el contador
 * false = detiene el contador
*/
char counter_enable = 0;

/* delay_us: espera n microsegundos */
void delay_us(long n)
{
  volatile unsigned long i = n / 2.2; // Ajuste con osciloscopio

  while (i > 0) {
    i--;
  }
}

/* delay_ms: espera n milisegundos */
void delay_ms(long n)
{
  volatile unsigned long i = n;

  while (i > 0) {
    delay_us(1000);
    i--;
  }
}

/* init: configura el puerto b bit 5 como salida */
void init() 
{
	/* apagar el voltaje del pin gpio del puerto pb0-4
	*/
	*(PUERTO_B) = *(PUERTO_B) & (~ LED_0);
	*(PUERTO_B) = *(PUERTO_B) & (~ LED_1);
	*(PUERTO_B) = *(PUERTO_B) & (~ LED_2);
	*(PUERTO_B) = *(PUERTO_B) & (~ LED_3);
	*(PUERTO_B) = *(PUERTO_B) & (~ LED_4);

	/* configurar el pin como salida = 1 en el puerto ddrb*/
	*(DDR_B) = *(DDR_B) | (LED_0);	
	*(DDR_B) = *(DDR_B) | (LED_1);	
	*(DDR_B) = *(DDR_B) | (LED_2);	
	*(DDR_B) = *(DDR_B) | (LED_3);	
	*(DDR_B) = *(DDR_B) | (LED_4);	

	/* configurar el pin como entrada = 0 en el puerto ddrc */
	*(DDR_C) = *(DDR_C) & (~ PULSADOR);	

	/* prender el voltaje del pin gpio del puerto pc0 del pulsador (1 sin pulsar - 0 pulsado)
	* al estar configurado el pin como entrada se activa la resistencia pull up
	*/
	*(PUERTO_C) = *(PUERTO_C) | (PULSADOR);

}

/* void next_number(): aumenta el contador */
void next_number() 
{
    unsigned char valor_b;
	valor_b = *(PUERTO_B);
	valor_b = (valor_b + 1) % COUNTER_LIMIT;
	*(PUERTO_B) = valor_b;
}

/* char pressed(): devuelve verdadero si se presiono el boton o falso en caso contrario */
char pressed() 
{
	char read_state = *(PIN_C) & (PULSADOR);
	return ! (read_state);
}

char is_counter_enable() 
{
	return counter_enable;
}

void toggle_counter()
{
	counter_enable = ! counter_enable;
}