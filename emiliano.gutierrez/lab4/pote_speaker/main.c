
#include "adc.h"
#include "delays.h"
#include "serial.h"
#include "gpio.h"
#include "speaker.h"

#define pin_pote 16 //A2
#define ADC_pote 2 //ADC2
#define BUZZER 3 //D3

int f_max = 10000;
int f_min = 30;

int main()
{
	int freq = 0;
    gpio_mode(BUZZER,"OUTPUT");
    gpio_mode(pin_pote,"INPUT");
    
    serial_init();
	adc_init();
	adc_disable_dig(ADC_pote);
    
	while (1) {           
 		freq = (float) adc_get(ADC_pote)*f_max/4095;
        if (freq <= f_min)
            gpio_pin(BUZZER,"OFF");
        else
            tone_on(BUZZER,freq);
	}
}     
