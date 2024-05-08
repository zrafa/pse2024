
/* utils.c - funciones de soporte al programa principal */


#define PIN  0b00000100

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

void init() 
{
    *(puerto_b) &= PIN;
    *(ddr_b) |= PIN;
}

void on() 
{
    *(puerto_b) |= PIN;
}

void off() 
{
    *(puerto_b) &= ~PIN;
}
