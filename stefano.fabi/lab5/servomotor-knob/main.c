#include <stdint.h>
#include "serial.h"
#include "delay.h"
#include "timer.h"
#include "adc.h"

#define F_OSC 4000000
#define F_CK 50
#define PRESCALER 8
#define TOP_VALUE ((F_OSC / (PRESCALER * F_CK)) - 1)

#define MAX_SERVOMETRO 1200
#define ADC_TO_POS(value) (MAX_SERVOMETRO * (value / 4096.0))

uint16_t adc_val = 0;
uint16_t prev_val = 0;

int main()
{
    serial_init();
    adc_init();
    timer1_init(TOP_VALUE);
    
    while (1) {
        // Cambiar el valor de OCR1A para controlar el ángulo del servomotor
        // OCR1A = 500; // 1 ms (ángulo mínimo)
        // OCR1A = 750; // 1.5 ms (posición media)
        // OCR1A = 1000; // 2 ms (ángulo máximo)

        adc_val = adc_get(MUX0, REF_5V);
        uint16_t diff = (prev_val * 10) / 100; // 10% del valor anterior

        if (adc_val > prev_val + diff || adc_val < prev_val - diff) {
            prev_val = adc_val;
            uint16_t new_pulse = ADC_TO_POS(adc_val);

			serial_put_int(new_pulse, 4);
            serial_put_str("\n \r");

            timer1_pulse(new_pulse);
        }
    }

    return 0;
}