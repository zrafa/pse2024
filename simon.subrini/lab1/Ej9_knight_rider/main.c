
/* Enciende y apaga un led conectado al puerto B bit 5 de un atmega328 */

/* 
 * El puerto B de un atmega328 tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */

#include "utils.h"

#define NUM_STATES 14
#define NUM_LEDS 6

unsigned char led_state;

unsigned char state[NUM_STATES][NUM_LEDS] = {
    {1,0,0,0,0,0},
    {1,1,0,0,0,0},
    {1,1,1,0,0,0},
    {0,1,1,1,0,0},
    {0,0,1,1,1,0},
    {0,0,0,1,1,1},
    {0,0,0,0,1,1},
    {0,0,0,0,0,1},
    {0,0,0,0,1,1},
    {0,0,0,1,1,1},
    {0,0,1,1,1,0},
    {0,1,1,1,0,0},
    {1,1,1,0,0,0},
    {1,1,0,0,0,0}
};
unsigned char led_state;
int main(void){	
    led_init();
    while (1) {
      for(unsigned char s = 0; s < NUM_STATES; s++){
        for(unsigned char l = 0; l < NUM_LEDS; l++){
          led_state = state[s][l];
          if(led_state==1){
            led_on(l);
          }else{
            led_off(l);
          }
        }
      esperar();
      }
    }
}


