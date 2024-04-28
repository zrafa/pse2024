
/* utils.c - funciones de soporte al programa principal */

/* Efecto knight rider en los puertos b0-4 de un atmega328p
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

#define LED_0 (0x01) /* 0b00000001 */
#define LED_1 (0x02) /* 0b00000010 */
#define LED_2 (0x04) /* 0b00000100 */
#define LED_3 (0x08) /* 0b00001000 */
#define LED_4 (0x10) /* 0b00010000 */

#define POS_INI 0
#define NUM_LEDS 5
volatile unsigned char *TIRA_LED[NUM_LEDS] = {0};

#define VIPER_LENGHT 3

void esperar() {
	volatile unsigned long i;
	for (i=0; i<20000; i++);
}

/* knight_init: configura el puerto b bit 5 como salida */
void knight_init() {
	
	/* apagar el voltaje del pin gpio del puerto pb0-4
	*/
	*(PUERTO_B) = *(PUERTO_B) & (~ LED_0);
	*(PUERTO_B) = *(PUERTO_B) & (~ LED_1);
	*(PUERTO_B) = *(PUERTO_B) & (~ LED_2);
	*(PUERTO_B) = *(PUERTO_B) & (~ LED_3);
	*(PUERTO_B) = *(PUERTO_B) & (~ LED_4);
	//*(PUERTO_B) = *(PUERTO_B) & ( 0xE0);		//	0b11100000

	/* configurar el pin como salida = 1 en el puerto ddrb*/
	*(DDR_B) = *(DDR_B) | (LED_0);	
	*(DDR_B) = *(DDR_B) | (LED_1);	
	*(DDR_B) = *(DDR_B) | (LED_2);	
	*(DDR_B) = *(DDR_B) | (LED_3);	
	*(DDR_B) = *(DDR_B) | (LED_4);	
	//*(DDR_B) = *(DDR_B) | (0x1F);			// 0b00011111
}

/* void toRight: enciende los led desde pb0-4 */
void toRight() 
{
	for (int i = 0; i<NUM_LEDS; i++) 
	{
		//	prender el proximo led hasta cumplir la longitud de la vibora
		for (int j = 0; j<VIPER_LENGHT; j++) 
		{
			// estoy llegando al extremo derecho
			if (i+j >= NUM_LEDS) continue;

			unsigned char valor_b;
			valor_b = *(PUERTO_B);

			// el led ya esta prendido
			if (valor_b & (1 << (i+j))) continue;

			valor_b |= (1 << (j + i));
			*(PUERTO_B) = valor_b;
			esperar();
		}

		// apagar el primer led que se prendio
		unsigned char valor_b;
		valor_b = *(PUERTO_B);
		valor_b ^= (1 << i);
		*(PUERTO_B) = valor_b;

		esperar();
	}
}
/* void toLeft: enciende los led desde pb4-0 */
void toLeft() 
{
	for (int i = NUM_LEDS - 1; i>=0; i--) 
	{
		//	prender el proximo led hasta cumplir la longitud de la vibora
		for (int j = 0; j<VIPER_LENGHT; j++) 
		{
			// estoy llegando al extremo izquierdo
			if (i-j < 0) continue;
			
			unsigned char valor_b;
			valor_b = *(PUERTO_B);

			if (valor_b & (1 << (i+j))) continue;

			valor_b |= (1 << (i - j));
			*(PUERTO_B) = valor_b;

			esperar();
		}

		// apagar el primer led que se prendio
		unsigned char valor_b;
		valor_b = *(PUERTO_B);
		valor_b ^= (1 << i);
		*(PUERTO_B) = valor_b;

		esperar();
	}
}


/*
// Otro estilo mas sencillo de hacer el efecto knight rider
void loadAndConsumer() 
{
	// charging
	for (int i = 0; i<NUM_LEDS; i++) {
		unsigned char valor_b;
		valor_b = *(PUERTO_B);
		valor_b |= (1 << i);

		*(PUERTO_B) = valor_b;
		esperar();
	}

	// consuming
	for (int i = 0; i<NUM_LEDS; i++) {
		unsigned char valor_b;
		valor_b = *(PUERTO_B);
		valor_b &= (0 << i);

		*(PUERTO_B) = valor_b;
		esperar();
	}
}
*/