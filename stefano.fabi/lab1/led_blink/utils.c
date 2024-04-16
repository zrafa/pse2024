
/* utils.c - funciones de soporte al programa principal */

/* Enciende y apaga un led conectado al puerto B bit 5 de un atmega328p
 * El puerto B de un atmega328p tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */


/* puertos de E/S */

/* direccion de PORTB (registro de datos) */
volatile unsigned char * PUERTO_B = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * DDR_B = (unsigned char *) 0x24;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * PIN_B = (unsigned char *) 0x23;

#define LED_ROJO (0x20) /* 0b00100000 */

void esperar() {
	volatile unsigned long i;
	/* delay de aprox. 1 segundo */
	for (i=0; i<450000; i++);
}

/* led_init: configura el puerto b bit 5 como salida */
void led_init() {
	/* COMPLETAR */
	
	/* apagar el voltaje del pin gpio del puerto pb5
	*/
	*(PUERTO_B) = *(PUERTO_B) & (~ LED_ROJO);
	
	/* configurar el pin como salida = 1 en el puerto ddrb*/
	*(DDR_B) = *(DDR_B) | (LED_ROJO);	

}

/* void leg_toggle: alterna el voltaje del pb5 */
void led_toggle() {
	unsigned char valor_b;
        valor_b = *(PUERTO_B);
        valor_b ^= LED_ROJO;
        *(PUERTO_B) = valor_b;
}

/* led_on: enciende el led conectado al puerto b bit 5 */
void led_on() {
	/* COMPLETAR */

	led_toggle();
}

/* led_off: apaga el led conectado al puerto b bit 5 */
void led_off() {
	/* COMPLETAR */
	
	led_toggle();
}