#include <xinu.h>
#include "serial.h"
#include "globals.h"
#include "gpio.h"

#define PULSADOR 10
int encendido;
int dia;


int pulsado (int pin) {
	int pul = -1;

	pul = (!gpio_pin(pin, GET));

//	if (pul) {
//		serial_put_str("pulsado\n\r");
//	}

	return pul;
}

void main(void) {

	encendido = 0;
	dia = 0;

	serial_init();

	// resume(create(pulsador_global, 256, 20, "pl", 0, NULL));
	resume(create(led, 64, 20, "led", 0, NULL));
	//resume(create(brazo, 64, 20, "bra", 0, NULL));
	resume(create(pulsadores, 128, 20, "pul", 0, NULL));

	int n; 
	pid32 pid_brazo; 

	gpio_input(PULSADOR);
	gpio_pin(PULSADOR, ON);

	while (1) {

		n = 0;
		while (pulsado(PULSADOR)) {
			if ((n == 5) && (encendido)) {
				// serial_put_str("OFF\n\r");

				/* apagar */
				dia = 0;
				encendido = 0;
				motor_stop();
				

				break;

			} else if (n == 5) {
				// serial_put_str("ON\n\r");

				/* encender */
				dia = 1;
				encendido = 1;
				break;
			}

			sleep(1);
			n++;
		}
	}

}


