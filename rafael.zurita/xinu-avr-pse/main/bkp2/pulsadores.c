
#include <xinu.h>
#include "gpio.h"
#include "serial.h"
#include "globals.h"


void pulsadores(void) {

	int distancia_izq = 0;
        int distancia_der = 0;
        gpio_input(12);
        gpio_pin(12, ON);
        gpio_input(11);
        gpio_pin(11, ON);

	/* pines de motores, motor stop */
        gpio_pin(MOTOR_DER_PIN, OFF);
        gpio_output(MOTOR_DER_PIN);
        gpio_pin(MOTOR_IZQ_PIN, OFF);
        gpio_output(MOTOR_IZQ_PIN);

        int izq = 0;
        int der = 0;
        while(1) {
                sleep(1);

		/* pulsador izquierdo */
                if (!gpio_pin(12, GET)) {
                        izq = 1;
                        der = 0;
                        motor_izq();
			/*
			if (distancia_izq > 3) {
                                motor_izq();
                        } else {
				motor_stop();
		        }
			*/

		/* pulsador derecho */
                } else if (!gpio_pin(11, GET)) {
                        izq = 0;
                        der = 1;
			motor_der();
			/*
                        if (distancia_der > 3) {
                                motor_der();
                        } else {
				motor_stop();
                        }
			*/

		/* sin pulsar pero moviendo */
                } else if (der || izq) {	/* se estaban moviendo */
                        izq = 0;
                        der = 0;
			motor_stop();
                }
		/*
                serial_put_int(distancia_izq, 4);
                serial_put_str("  ");
                serial_put_int(distancia_der, 4);
                serial_put_str("  \n\r");
		*/
        }

}
