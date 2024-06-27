#include "math.h"
#include "utils.h"
#include "adc.h"
#include "serial.h"

int main(void)
{	
	int val;
	int frecuencia;	
	init();
	adc_init();
	serial_init();
	
	while (1) {
		val = adc_get(2);
		frecuencia = (int) map(val,0,1023,20,20000);
		tone2(frecuencia);
		delay_us(800);
	}
}


