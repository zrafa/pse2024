#include "utils.h"
#include "melody.h"
#include "delay_ms.h"
#include "takeonme.h"
#include "Harry Potter.h"

#define pinSpk 5

int melody[] = HP;
//int melody[] = TAKEONME_MELODY;

unsigned char tempo = 140;
unsigned int melody_len = MELODY_LEN(melody);

int main(void){	
        config(pinSpk);
        delay_ms(1000);

        while (1) {   
                play_melody(pinSpk, tempo, melody, melody_len);
                delay_ms(1000);
        }   
}



