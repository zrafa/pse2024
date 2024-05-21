
#include "gpio.h"
#include "delays.h"
#include "serial.h"
#include "ultrasound.h"
#include "knight.h"

int main(void)
{
    char rcvChar = 0;

    serial_init();
    init_ultra();
    knight_init();
    serial_put_str("Presione 'k' o 'u' para encender 5 leds con efecto knight rider");
    serial_put_str("\n\ro mostrar mediciones de sensor ultrasónico, respectivamente");
    serial_put_str("\n\r");
        
    while (1) {
        rcvChar = serial_get_char();
        if (rcvChar == 'u')
            ultrasound();
        else if (rcvChar == 'k')
            knight();
    }
}

