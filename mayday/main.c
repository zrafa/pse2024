
/*
 * Aplicacion embebida que realiza un testing hello world de los drivers
 */

#include "adc.h"
#include "delay.h"
#include "gpio.h"
#include "serial.h"
#include "ultrasound.h"

void main()
{
	int val;

	adc_init();
	serial_init();
	gpio_output(13);

	while (1) {
		/* obtener una conversión ADC desde el pin de entrada ADC 2 */
 		val = adc_get(2);
		serial_put_str("    ADC : ");
		serial_put_int(val, 4);

		/* obtener una distancia del ultrasound */
 		val = ultrasound_get();
		serial_put_str("    Ultrasound : ");
		serial_put_int(val, 4);

		serial_put_str("\n\r");

		gpio_pin(13, TOGGLE);
		delay_ms(500);
	}
}
