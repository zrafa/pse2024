
#include "gpio.h"
#include "delays.h"

#define L0 2 // D2
#define L1 3 // D3
#define L2 4 // D4
#define L3 5 // D5
#define L4 6 // D6

char i = 0;
unsigned char subida = 1;

unsigned char array[] = {
    0b00010000,
    0b00011000,
    0b00001100,
    0b00000110,
    0b00000011,
    0b00000001
    };

void knight_init() {
    gpio_mode(L0,"OUTPUT");
    gpio_mode(L1,"OUTPUT");
    gpio_mode(L2,"OUTPUT");
    gpio_mode(L3,"OUTPUT");
    gpio_mode(L4,"OUTPUT");    
}

void knight(){
    if(subida==1){
        gpio_write("D", array[i]<<2);
        delay_ms(50);
        i++;
    }
    else{
        gpio_write("D", array[i]<<2);
        delay_ms(50);
        i--;
    }
    if(i==6){
        subida=0;
        i=4;
    }
    else if(i==-1){
        subida=1;
        i=1;
    }
}
