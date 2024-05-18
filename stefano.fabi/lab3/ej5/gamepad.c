/**********************************************************************
 *
 * gamepad.c 
 *
 * META : crear un gamepad con botones izquierda y derecha
 *
 **********************************************************************/

#include "gamepad.h"

/* direccion de PORTC (registro de datos) */
volatile unsigned char * PUERTO_C = (unsigned char *) 0x28;

/* direccion de DDR C (registro de control) */
volatile unsigned char * DDR_C = (unsigned char *) 0x27;

/* direccion PIN C (registro de datos de entrada) */
volatile unsigned char * PIN_C = (unsigned char *) 0x26;

#define BUTTON_LEFT (0x01)      /* PC0 0b00000001 */
#define BUTTON_RIGHT (0x02)     /* PC1 0b00000010 */

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
void gamepad_init() 
{
	/* configurar el pin como entrada = 0 en el puerto ddrc */
	*(DDR_C) = *(DDR_C) & (~ BUTTON_LEFT);	
	*(DDR_C) = *(DDR_C) & (~ BUTTON_RIGHT);	

	/* prender el voltaje del pin gpio del puerto pc0 del pulsador (1 sin pulsar - 0 pulsado)
	* al estar configurado el pin como entrada se activa la resistencia pull up
	*/
	*(PUERTO_C) = *(PUERTO_C) | (BUTTON_LEFT);
	*(PUERTO_C) = *(PUERTO_C) | (BUTTON_RIGHT);
}

/* char pressed_button_left(): devuelve verdadero si se presiono el boton o falso en caso contrario */
char pressed_button_left() 
{
	char read_state = *(PIN_C) & (BUTTON_LEFT);
	return ! (read_state);
}

/* char pressed_button_right(): devuelve verdadero si se presiono el boton o falso en caso contrario */
char pressed_button_right() 
{
	char read_state = *(PIN_C) & (BUTTON_RIGHT);
	return ! (read_state);
}


