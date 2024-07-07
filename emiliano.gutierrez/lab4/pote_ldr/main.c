
#include "adc.h"
#include "delays.h"
#include "serial.h"
#include "gpio.h"

#define pin_pote 18 //ADC4
#define ADC_pote 4 //ADC4
#define pin_ldr 16 //ADC2
#define ADC_ldr 2 //ADC2

int main()
{
	float pote = 0.0;
	float ldr = 0.0;

    gpio_mode(pin_pote,"INPUT");
    gpio_mode(pin_ldr,"INPUT");
    
    serial_init();
	adc_init();
	adc_disable_dig(ADC_pote);
	adc_disable_dig(ADC_ldr);
    
	while (1) {
	
	    ldr = (float) adc_get(ADC_ldr)*5/4095;   
        serial_put_str("Medición de foto resistencia: ");
        serial_put_float(ldr,2,3);
        serial_put_str(" V\n\r");
               
 		pote = (float) adc_get(ADC_pote)*5/4095;
 		serial_put_str("Medición de potenciómetro: ");
        serial_put_float(pote,2,3);    
        serial_put_str(" V\n\r"); 
    
        serial_put_str("\n\r");  
		delay_ms(1000); 
	}
}     
