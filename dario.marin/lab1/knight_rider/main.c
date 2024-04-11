#include "utils.h"

int main(void) {
    knigh_rider_init();

    while (1) {
        led_on(LED_1);
		esperar();
		led_off(LED_1);
        led_on(LED_2);
		esperar();
		led_off(LED_2);
        led_on(LED_3);
		esperar();
		led_off(LED_3);
        led_on(LED_4);
		esperar();
		led_off(LED_4);
        led_on(LED_5);
		esperar();
		led_off(LED_5);
    }
}


