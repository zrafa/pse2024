
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

/* direccion de PORTC (registro de datos) */
volatile unsigned char * puerto_c = (unsigned char *) 0x28;

/* direccion de DDR C (registro de control) */
volatile unsigned char * ddr_c = (unsigned char *) 0x27;

/* direccion PIN C (registro de datos de entrada) */
volatile unsigned char * pin_c = (unsigned char *) 0x26;


void esperar() {
	volatile unsigned long i;
	for (i=0; i<100000; i++);
}

void init() {
    volatile unsigned char *DDR_B = (unsigned char *) 0x24;
    volatile unsigned char *PUERTO_B = (unsigned char *) 0x25;

    volatile unsigned char *DDR_C = (unsigned char *) 0x27;
    volatile unsigned char *PUERTO_C = (unsigned char *) 0x28;
    
	
    //Configuracion de leds, bits 0 a 4 del puerto B
    *(PUERTO_B) &= 0;
    *(DDR_B) |= 0b00011111;

    //Configuracion del pulsador, bit 0 del puerto C
    *(PUERTO_C) &= 0;
    *(DDR_C) |= 0;
}

/* led_on: enciende los leds conectados en el puerto B */
void led_on(char led) {
    volatile unsigned char *PUERTO_B = (unsigned char *) 0x25;
    *(PUERTO_B) = led;
}

/*Enciende el pulsador para leer la entrada*/
void pulsador_on() {
    volatile unsigned char *PUERTO_C = (unsigned char *) 0x25;
    *(PUERTO_C) = 0b00000001;
}


//Lee el bit o del puerto C
char leer_pin() {
    char aux = *pin_c;
   return (aux & 0x1);
}

