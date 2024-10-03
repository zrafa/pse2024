#include <xinu.h>
#include "serial.h"
#include "globals.h"
#include "gpio.h"

#define LED 13

void serial_init(void);
void serial_put_str(const char *str);
void serial_put_int (int v, int cant_digitos);


int encendido;
int dia;

void main(void) {

	encendido = 0;
	dia = 0;

	serial_init();

	//resume(create(brazo, 256, 20, "bra", 0, NULL));
	resume(create(pulsador_global, 128, 20, "pul", 0, NULL));
	// resume(create(pulsadores, 128, 20, "led", 0, NULL));
	resume(create(brazo, 128, 20, "bra", 0, NULL));

        int i;

        gpio_output(LED);
        gpio_pin(LED, OFF);

	for(;;) {

                for (i=0; i<dia; i++) {
                        gpio_pin(LED, ON);
                        sleepms(500);
                        gpio_pin(LED, OFF);
                        sleepms(500);
                }

                sleep(2);
        }
}

