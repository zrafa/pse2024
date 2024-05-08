/**********************************************************************
 *
 * main.c - the main program test file for the serial driver
 *
 **********************************************************************/

#include "serial.h"


int main(void)
{
    char rcvChar = 0;
    int n=5;

    /* Configure the UART for the serial driver */
    serial_init();

    serial_put_char('s');
    serial_put_char('t');
    serial_put_char('a');
    serial_put_char('r');
    serial_put_char('t');
    serial_put_char('\r');
    serial_put_char('\n');

    while (rcvChar != 'q'){
        /* Wait for an incoming character */
        rcvChar = serial_get_char();

        /* Echo the character back along with a carriage return and line feed */
        serial_put_char(rcvChar);
        serial_put_char('\r');
        serial_put_char('\n');
        serial_put_str("Fuera de rango\r\n");
        serial_put_int(n,4);
    }

    for (;;);

    return 0;
}

