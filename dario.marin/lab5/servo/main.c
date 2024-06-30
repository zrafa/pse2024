#include "timer.h"
#include "adc.h"

#define MAX_KNOB 893
int main(void)
{
    int adc_value;
    float time_ms;
    timer_init();
    adc_init();

    for (;;) {
        adc_value = adc_get(A0, REF_5V);
        time_ms = (float) (1 + adc_value / MAX_KNOB);
        set_duty_cycle(time_ms);
    }
}
