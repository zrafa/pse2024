
/* utils.c - funciones de soporte al programa principal */

/* En los puertos b0-4 de un atmega328p
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

#define START (0x00)		// 0
#define END (0x1F)			// 31

void esperar() 
{
	volatile unsigned long i;
	/* delay de aprox. 1 segundo */
	for (i=0; i<450000; i++);
}

/* init: configura el puerto b bit 5 como salida */
void init() 
{
	/* apagar el voltaje del pin gpio del puerto pb0-4
	*/
	*(PUERTO_B) = *(PUERTO_B) & ( 0xE0);

	/* configurar el pin como salida = 1 en el puerto ddrb*/
	*(DDR_B) = *(DDR_B) | (0x1F);
}

/* void nextNumber: inicia la secuencia*/
void startSecuence() 
{
    for (unsigned int i = START; i <= END; i++) 
	{
        unsigned char valor_b;
		valor_b = *(PUERTO_B);
		valor_b = i;
		*(PUERTO_B) = valor_b;
		
		esperar();
    }
}