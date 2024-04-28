
/* utils.c - funciones de soporte al programa principal */

/* Enciende y apaga un led conectado al puerto B bit 5 de un atmega328p
 * El puerto B de un atmega328p tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */


/* puertos de E/S */

/* direccion de PORTB (registro de datos) */
volatile unsigned char * PORTB = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * DDRB = (unsigned char *) 0x24;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * pin_b = (unsigned char *) 0x23;
#define LED_ROJO (0x20) /* 0b00100000 */

void esperar() {
	volatile unsigned long i;
	/* delay de aprox. 1 segundo */
	for (i=0; i<225000; i++);
}

/* led_init: configura el puerto b bit 5 como salida */
void led_init() {
	*PORTB = *PORTB & ~(LED_ROJO);
    *(DDRB) = *(DDRB) | (LED_ROJO);
}

/* led_on: enciende el led conectado al puerto b bit 5 */
void led_on() {
	*PORTB = LED_ROJO;
}

/* led_off: apaga el led conectado al puerto b bit 5 */
void led_off() {
	*PORTB = 0;
}




