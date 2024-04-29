
/* utils.c - funciones de soporte al programa principal */

/* puertos de E/S */

/* direccion de PORTB (registro de datos) */
volatile unsigned char * puerto_b = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_b = (unsigned char *) 0x24;


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
    //Configuracion de leds, bits 0 a 4 del puerto B
    *(puerto_b) &= 0;
    *(ddr_b) |= 0b00011111;

    //Configuracion del pulsador, bit 0 del puerto C
    *(puerto_c) &= 0;
    *(ddr_c) |= 0;
}

/* led_on: enciende los leds conectados en el puerto B */
void led_on(char led) {
    *(puerto_b) = led;
}

/*Enciende el pulsador para leer la entrada*/
void pulsador_on() {
    *(puerto_c) = 0b00000001;
}

//Lee el bit o del puerto C
char leer_pin() {
    char aux = *pin_c;
   return (aux & 0x1);
}

