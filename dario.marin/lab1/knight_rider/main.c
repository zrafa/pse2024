#include "utils.h"

#define LED_0 0x1
#define LED_1 0x2
#define LED_2 0x4
#define LED_3 0x8
#define LED_4 0x10

int main(void) {
    knight_rider_init();

    while (1) {
        led_on(LED_0);
		esperar();
		led_off(LED_0);
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
        led_on(LED_3);
		esperar();
		led_off(LED_3);
		led_on(LED_2);
		esperar();
		led_off(LED_2);
		led_on(LED_1);
		esperar();
		led_off(LED_1);
		led_on(LED_0);
		esperar();
		led_off(LED_0);

    }
}


