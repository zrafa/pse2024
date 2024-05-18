/**********************************************************************
 *
 * main.c - the main program test file for the serial driver
 *
 **********************************************************************/

#include "serial.h"
#include "gamepad.h"

int main(void)
{
    char rcvChar = 0;
    
    /* Configure the UART for the serial driver */
    serial_init();

    /* Configure the gamepad */
    gamepad_init();

    while (1)
    {
        if (pressed_button_left()) 
		{
			delay_ms(25);

			if (pressed_button_left()) 
				serial_put_char('a');

            delay_ms(25);

			if (pressed_button_left()) 
				serial_put_char('a');
		}

        if (pressed_button_right()) 
		{
			delay_ms(25);

			if (pressed_button_right()) 
				serial_put_char('d');

            delay_ms(25);

			if (pressed_button_right()) 
				serial_put_char('d');
		}
    }

    return 0;
}

