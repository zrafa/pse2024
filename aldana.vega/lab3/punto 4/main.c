/**********************************************************************
 *
 * main.c - the main program test file for the serial driver
 *
 **********************************************************************/

#include "serial.h"
#include "utils.h"


int main(void)
{
    char rcvChar = 0;
    unsigned char on = 0;

    serial_init();
    inicializar();

    while (rcvChar != 'q'){
        
        rcvChar = serial_get_char();
        while (serial_is_empty()) {
            if(rcvChar =='k'){
                on = ~on;
            }else if (rcvChar == 'u') {
                ultrasonido();
            }
            
            if(on != 0){
                knight_rider();
            }else{
                knight_rider_apagar();
            }

            rcvChar = 0;
        }
    }

    for (;;);

    return 0;

}

