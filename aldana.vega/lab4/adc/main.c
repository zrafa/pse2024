
#include "adc.h"
#include "serial.h"

inline void delay_ms(volatile int ms);
inline void delay_us(volatile int us);

int main()
{
	int val;

	adc_init();
	serial_init();

	serial_put_str("Inicia\r\n");

	while (1) {
		/* obtener una conversión ADC desde el pin de entrada ADC 2 */
 		val = adc_get(2);

		/* realizar alguna acción con val */
		serial_put_int(val,4);
		serial_put_str("\r\n");
		
		delay_ms(1000);
	}

	for(;;);
}

inline void delay_us(volatile int us){
   //PARA 16MHZ  
	while(us--){
         asm volatile (
            "nop" "\n\t"
            "nop" "\n\t"
            "nop" "\n\t"
			); 
    }  
}

inline void delay_ms(volatile int ms){
   //PARA 16MHZ 
	while(ms--){
         delay_us(100);
    }  
}