#include "serial.h"
#include "timer1.h"
#include <avr/io.h>
#include <avr/interrupt.h>

int seg = 0;
int min = 0;
extern volatile int ticks;
extern volatile unsigned char flag_c;
extern volatile unsigned char flag_s;
volatile unsigned char flag_m = 0;

int main()
{
    serial_init();
    timer1_init();
    sei();
    
    while(1) {
        if (flag_s == 1) {
            flag_s = 0;
            seg++;
            if (seg == 60) {
                seg = 0;  
                flag_m = 1;
            }
        }
        
        if (flag_m == 1) {
            flag_m = 0;
            min++;
            if (min == 60) {
                min = 0;    
            }
        }
        
        if (flag_c == 1) {
            serial_put_str("\r");
            serial_put_int(min,2);
            serial_put_str(":");    
            serial_put_int(seg,2);
            serial_put_str(":");
            serial_put_int(ticks,2); 
            flag_c = 0;
        }
        
    }
}
