
#include <xinu.h>
#include "globals.h"
#include "gpio.h"
#include "serial.h"

#define PULSADOR 10

int pulsado (int pin) {
	int pul = -1;

	pul = (!gpio_pin(pin, GET));

	if (pul)
		serial_put_str("pulsado\n\r");

	return pul;
}

void pulsador_global(void) {
	int n; 

	gpio_input(PULSADOR);
	gpio_pin(PULSADOR, ON);

	while (1) {

		n = 0;
		while (pulsado(PULSADOR)) {
			if ((n == 5) && (encendido)) {
				serial_put_str("APAGADO\n\r");

				/* apagar */
				dia = 0;
				encendido = 0;
				break;

			} else if (n == 5) {
				serial_put_str("ENCENDIDO\n\r");

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
