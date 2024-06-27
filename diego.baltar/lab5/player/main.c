/**
 * @file main.c
 * @author Diego Pablo Matías Baltar <diego.baltar@est.fi.uncoma.edu.ar>
 * @brief Prueba para el driver serial
 * @date 2024-06-26
 *
 * Programa del reproductor de audio.
 */

#include <stdint.h>

#include "adc.h"
#include "serial.h"
#include "timer.h"




int main(void)
{
	uint8_t sample = 0;

	adc_init();
	serial_init();
	serial_put_str("Echo:\r\n");

	while (1) {
		sample = serial_get_char();
		serial_put_int(sample, 0);
		serial_put_str("\r\n");

		//TODO: reproducir los datos de audio
	}

	return 0;
}
