#include "adc.h"
#include "serial.h"
#include "delay.h"

int main()
{
	int val;

	serial_init();

	adc_init();

	while (1) {
		/* obtener una conversión ADC desde el pin de entrada ADC 2 */
 		val = adc_read(2);

		/* escalar val entre 0 y 100 */
    	int nuevo_val = (val * 9) / 255;

		/* realizar alguna acción con val */
		serial_put_int(nuevo_val);


		//serial_put_string("\r\n");
		delay_ms(500);
	}

	for(;;);

	return 0;
}
