/**********************************************************************
 *
 * main.c - the main program test file for the serial driver
 *
 **********************************************************************/

#include "serial.h"
#include "utils.h"

inline void delay_us(volatile int us);
inline void delay_ms(volatile int ms);

int main(void)
{
    char pulsador1=1;
    char pulsador2=1;
    char rcvChar = 0;
    /* Configure the UART for the serial driver */
    serial_init();
    init();
    pulsadores_on();

    while (rcvChar != 'q'){
        /* Wait for an incoming character */

        pulsador1 = leer_pin0();
        pulsador2 = leer_pin1();
        delay_ms(5);
        pulsador1 = leer_pin0();
        pulsador2 = leer_pin1();
		
        if (pulsador1 == 0) {
            delay_us(10);
            serial_put_str("A\r\n");
        }else if (pulsador2 == 0) {
            delay_us(10);
            serial_put_str("D\r\n");
        }
        
        delay_ms(100);
    }

    for (;;);

    return 0;
}

