#include "timer.h"
#include "delay.h"
#include "serial.h"

int main(void)
{
    timer_init();
    serial_init();

    for (;;) {
        serial_put_int(minutes,2);
        serial_put_char(':');
        serial_put_int(seconds,2);
        serial_put_char(':');
        serial_put_int(hundredths,2);
        serial_put_char('\r');
        delay_ms(1000);
    }
}
