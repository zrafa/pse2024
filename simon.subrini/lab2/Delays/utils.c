
/* utils.c - funciones de soporte al programa principal */

/* Enciende y apaga un led conectado al puerto B bit 5 de un atmega328p
 * El puerto B de un atmega328p tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */


/* puertos de E/S */

/* direccion de PORTB (registro de datos) */
volatile unsigned char * puerto_b = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_b = (unsigned char *) 0x24;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * pin_b = (unsigned char *) 0x23;

/*
void esperar(unsigned int n) {
	volatile unsigned long i = n*1000;
	// delay de aprox. 1 segundo 
	for (i=0; i<n; i++){
	  delay_1us();
	}
}
*/

/* led_init: configura el puerto b bit 5 como salida */
void led_init() {
	* ddr_b |= 0b00100000; // Configuro el pin 0 (pin 13 fisico) del puerto B como salida
}

/* led_on: enciende el led conectado al puerto b bit 5 */
void led_on() {
	* puerto_b |= 0b00100000;
}

/* led_off: apaga el led conectado al puerto b bit 5 */
void led_off() {
	* puerto_b &= 0b11011111;
}
