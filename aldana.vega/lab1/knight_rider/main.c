#include "utils.h"
#include "math.h"

int main(void) {

	char led [9] = {0b00000000,
					0b00000001, 
					0b00000011,
					0b00000110,
					0b00001100,
					0b00011000,
					0b00010000,
					0b00000000};

    knight_rider_init();

    while (1) {
		for(int i=0;i<9;i++){
			led_on(led[i]);
			esperar();
		}
		
		for(int i=8;i>=0;i--){
			
			led_on(led[i]);
			esperar();
		}


		}
}


