/*
 * ultrasound: programa que controla el HC-SR04 para medir distancias en cm
 */

#include "serial.h"

int main(void)
{
	int distancia_cm = 8;

	serial_init();

	/* Ejemplo de uso de la biblioteca serial */
    	serial_put_str("HOLA MUNDO \r\n");
    	serial_put_int(distancia_cm, 4);	/* Mostrar distancia */
    
    for (;;) {
    	serial_put_str("HOLA MUNDO \r\n");
    	serial_put_int(distancia_cm, 4);	/* Mostrar distancia */
    	serial_put_str("\r\n");
    }

}

