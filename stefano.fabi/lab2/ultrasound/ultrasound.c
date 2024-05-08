/*
 * ultrasound: programa que controla el HC-SR04 para medir distancias en cm
 */

#include "serial.h"

/* direccion de PORTC (registro de datos) */
volatile unsigned char * PUERTO_C = (unsigned char *) 0x28;

/* direccion de DDR C (registro de control) */
volatile unsigned char * DDR_C = (unsigned char *) 0x27;

/* direccion PIN C (registro de datos de entrada) */
volatile unsigned char * PIN_C = (unsigned char *) 0x26;


#define ULTRASOUND_TRIGGER (0x01) 	/* PC0 0b00000001 */
#define ULTRASOUND_ECHO (0x02) 		/* PC1 0b00000010 */

/*
 * esperar_1us: funcion que puede realizar una demora de aproximadamente de 
 * 1 microsegundo, utilizando instrucciones nop en ensamblador
 *
 */
inline void esperar_1us(void)
{
  	    asm volatile (
			"nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			);
}

/* ultrasound_init(): configura el puerto pc1 como salida y pc2 como entrada */
void ultrasound_init() 
{
	/* apagar el voltaje del pin gpio del puerto pc1
	*/
	*(PUERTO_C) = *(PUERTO_C) & (~ ULTRASOUND_TRIGGER);


	/* configurar el pin como salida = 1 en el puerto ddrc*/
	*(DDR_C) = *(DDR_C) | (ULTRASOUND_TRIGGER);

	/* configurar el pin como entrada = 0 en el puerto ddrc */
	*(DDR_C) = *(DDR_C) & (~ ULTRASOUND_ECHO);	

	/* prender el voltaje del pin gpio del puerto pc1 del echo
	* al estar configurado el pin como entrada se activa la resistencia pull up
	*/
	//*(PUERTO_C) = *(PUERTO_C) | (ULTRASOUND_ECHO);

}

/* char trigger_enable(): prende la señal de trigger */
void trigger_enable() {
	*(PUERTO_C) = *(PUERTO_C) | (ULTRASOUND_TRIGGER);
}

/* char trigger_enable(): apaga la señal de trigger */
void trigger_disable() {
	*(PUERTO_C) = *(PUERTO_C) & (~ ULTRASOUND_TRIGGER);
}

/* char echo_enable(): devuelve verdadero si la señal echo esta en alto o falso en caso contrario */
char echo_enable() {
	return *(PIN_C) & (ULTRASOUND_ECHO);

	// probando con la resistencia pullup
	//char read_state = *(PIN_C) & (ULTRASOUND_ECHO);
	//return ! (read_state);
}

int main()
{
	ultrasound_init();

	serial_init();
   
    while (1) 
	{
		serial_put_str("ESPERANDO DATOS... \r\n");

		// levantar la señal del trigger
		trigger_enable();

		// espero 10us
		for (int i=0; i<10; i++) esperar_1us();

		// apago la senial del trigger
		trigger_disable();

		// esperamos que el dispositivo prenda el echo
		while (! echo_enable()) {
			serial_put_str("ECHO: ESPERANDO... \r\n");
		};

		int time_echo_us = 0;
		
		// calcular cuanto tiempo esta en alto la señal
		while (echo_enable()) {
			serial_put_str("ECHO: RECIBIDO... \r\n");

			esperar_1us();
			time_echo_us++;

			if (time_echo_us >= 36) break;
		}

		if (time_echo_us >= 36) {
			serial_put_str("FUERA DE RANGO\r\n");
		} else {
			int distancia_cm = time_echo_us / 58;

			serial_put_str("LA DISTANCIA ES ");
			serial_put_int(distancia_cm, 4);	/* Mostrar distancia */
			serial_put_str("\r\n");
		}

		// espero 10us para activar el proximo pulso
		for (int i=0; i<10; i++) esperar_1us();

		// fin del programa
		serial_put_str("FIN DEL PROGRAMA... \r\n");
		for (int i=0; i<5000; i++) esperar_1us();
    }
}

