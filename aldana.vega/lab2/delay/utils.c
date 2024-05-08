
/* utils.c - funciones de soporte al programa principal */
#define LED  0x20

/* puertos de E/S */

/* direccion de PORTB (registro de datos) */
volatile unsigned char * puerto_b = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_b = (unsigned char *) 0x24;

void esperar() 
{
	volatile unsigned long i;
	/* delay de aprox. 1 segundo */
	for (i=0; i<450000; i++);
}

/* led_init: configura el puerto b bit 5 como salida */
void led_init() 
{
    *(puerto_b) &= LED;
    *(ddr_b) |= LED;
}

void knight_rider_init()
{
    *(puerto_b) &= 0;
    *(ddr_b) |= 0b00011111;
}

/* led_on: enciende el led conectado al puerto b bit 5 */
void led_on(char led) 
{
    *(puerto_b) |= led;
}

/* led_off: apaga el led conectado al puerto b bit 5 */
void led_off(char led) 
{
    *(puerto_b) &= ~led;
}
