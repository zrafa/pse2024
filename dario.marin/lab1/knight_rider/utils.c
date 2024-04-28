
/* utils.c - funciones de soporte al programa principal */


/* puertos de E/S */

/* direccion de PORTB (registro de datos) */
volatile unsigned char * puerto_b = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_b = (unsigned char *) 0x24;

void esperar() {
	volatile unsigned long i;
	/* delay de aprox. 1 segundo */
	for (i=0; i<50000; i++);
}

void knight_rider_init() {
    *(puerto_b) &= 0;
    *(ddr_b) |= 0b00011111;
}