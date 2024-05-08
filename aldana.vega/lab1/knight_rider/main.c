#include "utils.h"
#include "math.h"

char led [9] = {0b00000000,
				0b00000001, 
				0b00000011,
				0b00000110,
				0b00001100,
				0b00011000,
				0b00010000,
				0b00000000};



int main(void) 
{
	int i;
    knight_rider_init();

    while (1) {
		for(i=0; i<9; i++){
			led_on(led[i]);
			esperar();
		}
		
		for(i=8; i>=0; i--){
			led_on(led[i]);
			esperar();
		}
	}
}


