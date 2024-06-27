
#include "adc.h"
#include "serial.h"
#include "utils.h"


int main()
{
	int val;
	int val2;
	char pulsador1;
	adc_init();
	serial_init();

	serial_put_str("Inicia\r\n");

	while (1) {
		//Potenciometro
 		val = adc_get(2);
		val = (int) map(val,0,1023,0,2);
		serial_put_int(val,1);
		serial_put_str("\r\n");

		//Pulsador
		pulsador1 = leer_pin0();
		delay_ms(5);//delay de 5 ms
		pulsador1 = leer_pin0();
		if (pulsador1 == 0){
			delay_us(10);
			serial_put_int(3,1);
			serial_put_str("\r\n");
        }

		delay_ms(1000);
	}

	for(;;);
}
