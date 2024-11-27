
#include <xinu.h>
#include "serial.h"
#include "globals.h"
#include "gpio.h"

#define PULSADOR 10
#define PULSADOR_IZQUIERDO 12
#define PULSADOR_DERECHO 11

int encendido;
int dia;
int estado;



int pulsado (int pin) {
	int pul = -1;

	pul = (!gpio_pin(pin, GET));

	return pul;
}

void main(void) {

	encendido = 0;
	dia = 0;

	serial_init();
	motor_init();

	resume(create((void *)led, 64, 20, "led", 0, NULL));
	resume(create((void *)brazo, 440, 20, "bra", 0, NULL));

	int n;	/* n veces pulsador global */ 
	int distancia_izq = 0;
        int distancia_der = 0;
        int izq = 0;
        int der = 0;
	estado = APAGADO;

	/* pulsadores init */
        gpio_input(PULSADOR_IZQUIERDO);
        gpio_pin(PULSADOR_IZQUIERDO, ON);
        gpio_input(PULSADOR_DERECHO);
        gpio_pin(PULSADOR_DERECHO, ON);
	gpio_input(PULSADOR);
	gpio_pin(PULSADOR, ON);


	while (1) {

		n = 0;
		while (pulsado(PULSADOR)) {
			serial_put_str("GLOBAL\n\r");
			if ((n == 5) && (encendido)) {

				/* apagar */
				dia = 0;
				encendido = 0;
				//motor_stop();
				estado = APAGADO;
				

				break;

			} else if (n == 5) {

				/* encender */
				dia = 1;
				encendido = 1;
				estado = START;
				break;
			}
			n++;
			sleepms(1000);
		}


		/* pulsador izquierdo */
                if (pulsado(PULSADOR_IZQUIERDO)) {
                        izq = 1;
                        der = 0;
                        motor_izq();

		/* pulsador derecho */
                } else if (pulsado(PULSADOR_DERECHO)) {
                        izq = 0;
                        der = 1;
			motor_der();

		/* sin pulsar pero moviendo */
                } else if (der || izq) {	/* se estaban moviendo */
                        izq = 0;
                        der = 0;
			motor_stop();
                }
		sleepms(1000);
		serial_put_int(estado, 4);
                serial_put_str("  \n\r");
	}

}







