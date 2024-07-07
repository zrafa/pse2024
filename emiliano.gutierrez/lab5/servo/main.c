#include "gpio.h"
#include "pwm.h"
#include "adc.h"
#include "delay.h"

#define OC1A 9
#define POTE 16 //ADC4

unsigned int adc_value;
 
void main()
{
    pwm_init();
    adc_init();
    gpio_input(POTE);
    gpio_output(OC1A);    
    servo_set(0, 180);
    
    while(1) {   
        adc_value = (float) adc_get(4, REF_5V)*180/4095;
        servo_set(adc_value, 180);
        delay_ms(500);
    }
}
