
/* utils.c - funciones de soporte al programa principal */


/* puertos de E/S */

/* direccion de PORTB (registro de datos) */
volatile unsigned char * puerto_b = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_b = (unsigned char *) 0x24;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * pin_b = (unsigned char *) 0x23;


void esperar() 
{
	volatile unsigned long i;
	/* delay de aprox. 1 segundo */
	for (i=0; i<30000; i++);
}

void knight_rider_init()
{
    *(puerto_b) &= 0;//Apaga los bits de los leds
    *(ddr_b) |= 0b00011111;//Configura los pines conectados a los bits 0-5 como salida
}

/* led_on: enciende los leds conectado al puerto b*/
void led_on(char led)
{
    *(puerto_b) = led;
}

