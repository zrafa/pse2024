
#include "gpio.h"
#include "delays.h"
#include "serial.h"
#include "ultrasound.h"
#include "knight.h"

unsigned char flag = 0x00;

int main(void)
{
    char rcvChar = 0;

    serial_init();
    init_ultra();
    knight_init();
    serial_put_str("Arrancamos");
    serial_put_str("\n\r");
        
    while (1) {   
        rcvChar = serial_get_char();
        while (serial_rcv_empty()) {
            if (flag == 0xFF) 
                knight();
            else
                knight_apagar();  
        
            if (rcvChar == 'u') {
                ultrasound();
            }
            else if (rcvChar == 'k') {
                flag = ~flag;
            }   
            rcvChar = 0; 
        }
    }
}

