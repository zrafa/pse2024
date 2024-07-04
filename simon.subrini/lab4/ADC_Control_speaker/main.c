
#include "serial.h"
#include "adc.h"
#include "delay_ms.h"
#include "melody.h"
#include "e_s.h"

void main()
{
	adc_init();
	serial_init();
	pinMode(12,INPUT);
	
	
	unsigned int lectura;
	unsigned int freq;
	unsigned int per;

	while (1) {
 		/*lectura = adc_read(2,10);
 		freq = 500+20*lectura; // freq = f(lectura)
 		serial_put_str("Freq: ");
 		serial_put_int(freq,5);
 		per = (1000000/freq);
 		serial_put_str(" Hz --- Periodo: ");
 		serial_put_int(per,5);
 		serial_put_str(" uS\n\r");*/
 		for (unsigned int i=30;i<=10000;i+=100){
 		        play_note(i, 1000, 12);
 		}
 		
	}

}
