
#include "adc.h"
#include "delays.h"
#include "serial.h"
#include "gpio.h"

#define pin_pote 16 //ADC2
#define ADC_pote 2 //ADC2

int main()
{
	char pote = 0;

    gpio_mode(pin_pote,"INPUT");
    
    serial_init();
	adc_init();
	adc_disable_dig(ADC_pote);
    
	while (1) {
               
 		pote = adc_get(ADC_pote)*9/4095 + 0x30;
        serial_put_char(pote);    
    
		delay_ms(1000); 
	}
}      
