/**
 * @file main.c
 * @author Diego Pablo Matías Baltar <diego.baltar@est.fi.uncoma.edu.ar>
 * @brief Prueba para el driver serial
 * @date 2024-06-17
 *
 * Programa de prueba para el timer.
 */

#include <stdint.h>

#include "adc.h"
#include "serial.h"
#include "timer.h"

/* Valor tope para el timer1 */
#define TIMER1_TOP 20000

/* Transforma un valor del ADC a una posición del servo en us [1000, 4000] */
#define ADC_TO_POS(v) ((v * 3.91) + 1000)

typedef struct
{
	uint8_t h;
	uint8_t m;
	uint8_t s;
} time_t;

volatile int ticks = 0;
volatile time_t time = {0, 0, 0};

void timer0_fun()
{
	ticks++;

	if (ticks == 1000) {
		time.s++;

		if (time.s > 59) {
			time.s = 0;
			time.m++;

			if (time.m > 59) {
				time.m = 0;
				time.h++;

				if (time.h > 23) {
					time.h = 0;
					time.m = 0;
					time.s = 0;
				}
			}
		}

		serial_put_int(time.h, 2);
		serial_put_char(':');
		serial_put_int(time.m, 2);
		serial_put_char(':');
		serial_put_int(time.s, 2);
		serial_put_str("\r");

		ticks = 0;
	}
}

void timer_servo_control()
{
	static uint16_t position = 1000;
	static uint16_t prev_val = 0;
	uint16_t next_val = adc_get(MUX0, REF_5V);

	if (next_val == prev_val)
		return;

	prev_val = next_val;
	position = ADC_TO_POS(next_val);

	timer1_pulse(position);
}

int main(void)
{
	adc_init();
	serial_init();
	timer1_init(TIMER1_TOP);
	timer0_init(timer0_fun);

	while (1) {
		timer_servo_control();
	}

	return 0;
}
