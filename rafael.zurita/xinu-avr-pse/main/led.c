#include <xinu.h>
#include "globals.h"
#include "gpio.h"

#define LED 13

void led(void) {
	int i;
	
	gpio_output(LED);
	gpio_pin(LED, OFF);
	
	while (1) {

		for (i=0; i<dia; i++) {
			gpio_pin(LED, ON);
			sleepms(500);
			gpio_pin(LED, OFF);
			sleepms(500);
		}

		sleep(2);
	}
}
