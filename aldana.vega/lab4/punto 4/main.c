#include "adc.h"
#include "serial.h"
#include "utils.h"

int main()
{
	int val;

	adc_init();
	serial_init();

	while (1) {
 		val = adc_get(2);

		val = (int)map(val,0,1023,1,9);
		serial_put_int(val,1);
		delay_ms(1000);
	}

	for(;;);
}
