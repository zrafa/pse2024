/**
 * @file main.c
 * @author Diego Pablo Matías Baltar <diego.baltar@est.fi.uncoma.edu.ar>
 * @brief Prueba para el driver serial
 * @date 2024-05-19
 *
 * Programa para controlar el speaker.
 */

#include <stdint.h>

#include "adc.h"
#include "melody.h"
#include "utils.h"
#include "serial.h"

#define SCALE_MAX_VALUE (1023)
#define SCALE(v,m)      ((uint16_t)((v/(float)SCALE_MAX_VALUE)*(m)))

int main(void)
{
	uint16_t adc_value = 0;

	adc_init();
	serial_init();
	melody_init((1 << PORTB0));

	while (1) {
		adc_value = adc_get(MUX0, REF_5V);
		serial_put_int(adc_value, 0);
		serial_put_str("\r\n");
		melody_note(adc_value, 10);
		//delay_ms(2000);
	}

	return 0;
}
