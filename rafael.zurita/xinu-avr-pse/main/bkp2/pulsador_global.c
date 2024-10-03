
#include <xinu.h>
#include "globals.h"
#include "gpio.h"
#include "serial.h"

#define PULSADOR 10

void serial_put_str(const char *str);
int pulsado (int pin) {
	int pul = -1;

	pul = (!gpio_pin(pin, GET));

	if (pul) {
		serial_put_str("pulsado\n\r");
	}

	return pul;
}

void pulsador_global(void) {
	int n; 
	pid32 pid_brazo; 

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
				// kill(pid_brazo);
				motor_stop();
				

				break;

			} else if (n == 5) {
				serial_put_str("ENCENDIDO\n\r");

				/* encender */
				dia = 1;
				encendido = 1;
				// pid_brazo = create(brazo, 256, 20, "bra", 0);
				// resume(pid_brazo);
				break;
			}

			sleep(1);
			n++;
		}
	}

}
