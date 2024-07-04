#include "timer1.h"
#include "delay_ms.h"
#include "gpio.h"
#include "adc.h"

#define MAX_KNOB 900.0

void main()
{
  timer1_init();
  adc_init();
  gpio_output(9); // pin OC1A
  int adc_value;
  float time_ms;

  while (1) {
    adc_value = adc_get(A0, REF_5V);
    time_ms = (float) (1 + adc_value / MAX_KNOB);
    timer1_set_pwm_duty_cycle(time_ms);
    delay_ms(300);
  }
}

