#include <xinu.h>
#include "serial.h"
#include "globals.h"

int encendido;
int dia;

void main(void) {

	encendido = 0;
	dia = 0;

	serial_init();

	resume(create(pulsador_global, 256, 20, "pul", 0));
	resume(create(led, 256, 20, "led", 0));

	int d;
	for(;;) {
		d = ultrasound_get(9, 9);
		// serial_put_str("distancia : ");
		// serial_put_int(d, 4);
		// serial_put_str("\n\r");

		sleepms(100);
		
	}


}

