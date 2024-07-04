#include "melody.h"
#include "e_s.h"
#include "delay_us.h"
#include "delay_10us.h"
#include "delay_100us.h"

void play_melody(unsigned char pin, unsigned char tempo, int *melody, unsigned int melody_len)
{
        int note_duration_ms;
    
        for(unsigned int i=0; i<melody_len * 2; i+=2){
                unsigned int freq = melody[i];
                int divider = melody[i + 1];
                
                // Calcular la duración de la nota
                note_duration_ms = (60000 * 4) / tempo / divider;
                
                if (divider < 0)
                        note_duration_ms *= -1.5;
                
                play_note(freq,note_duration_ms,pin);
                
        }
}

void play_note(unsigned int freq, unsigned int note_duration_ms, unsigned char pin){

        unsigned int n_ciclos = (freq * note_duration_ms)/1000; 
        unsigned int pause = (500000/freq); // medio periodo en uS.0
        
        for (unsigned int i = 0; i<n_ciclos; i++){
                if (pause<10){
                        digitalWrite(pin, 1);
                        delay_us(pause);
                        digitalWrite(pin, 0);
                        delay_us(pause);
                }else if(pause<100){
                        digitalWrite(pin, 1);
                        delay_10us(pause/10);
                        digitalWrite(pin, 0);
                        delay_10us(pause/10);
                }else{
                        digitalWrite(pin, 1);
                        delay_100us(pause/100);
                        digitalWrite(pin, 0);
                        delay_100us(pause/100);
                }
        }
}

