
#include "adc.h"
#include "delay_ms.h"
#include "serial.h"

void main()
{
	serial_init();
	adc_init();
	
	int lectura;
	char val;

	while (1) {
 		lectura = adc_read(2,8);
 		val = (lectura/100);
 		if (val>9)
 		        val = 9;
 		val += 48;
 		serial_put_char(val);
		delay_ms(500);
	}

}
