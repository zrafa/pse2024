#include "adc.h"
#include "serial.h"
#include "delay.h"

int main()
{
	int val;

	serial_init();

	serial_put_string("start");

	adc_init();

	while (1) {
		/* obtener una conversión ADC desde el pin de entrada ADC 2 */
 		val = adc_read(2);

		/* realizar alguna acción con val */
		serial_put_int(val);

		delay_ms(500);
	}

	for(;;);

	return 0;
}
