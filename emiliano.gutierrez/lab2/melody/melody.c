#include "pin_rw.h"
#include "delays.h"
//#include "alors_on_danse_lead.h"
#include "takeonme.h"
//#include "nokia.h"

#define BUZZER 0x04 //(PD2 - D2)

/* puertos de E/S */

/* direccion de PORTD (registro de datos) */
volatile unsigned char * PORTD = (unsigned char *) 0x2B;

/* direccion de DDR D (registro de control) */
volatile unsigned char * DDRD = (unsigned char *) 0x2A;

/* direccion PIN D (registro de datos de entrada) */
volatile unsigned char * pin_d = (unsigned char *) 0x29;

float offset = 0; // este offset lo uso para aumentar la frecuencia de entrada 
// al buzzer. es algo que uso a oido nomas, no hace en si al codigo

void init_es(void){
    *DDRD = *DDRD | BUZZER; //BUZZER como salida
    *PORTD = 0;
}

void tone_on(unsigned char pinx,volatile unsigned char * dir_port, float freq, float dur)
{   
    // dur entra en cantidad de mseg
    float T = 1000/freq; // en mseg
    while (dur > 0){
        if (freq == offset){
            delay_ms(dur);
            break;
        }
            
        write_pin(1,pinx,dir_port);
        delay_ms(T/2);
        write_pin(0,pinx,dir_port);
        delay_ms(T/2);
        dur -= T;
    }
}

void main(void)
{
    init_es();
    int notes = sizeof(melody) / sizeof(melody[0]) / 2;
    float wholenote = 60000 * 4 / tempo; // en mseg
    int divider = 0;
    float noteDuration = 0;
    
    for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    
        divider = melody[thisNote + 1];
        if (divider > 0) {
            noteDuration = (wholenote) / divider;
        }
        else if (divider < 0) {
            noteDuration = -(wholenote) / (divider);
            noteDuration *= 1.5;
        }

        tone_on(BUZZER, PORTD, melody[thisNote] + offset, noteDuration * 0.9);
        delay_ms(noteDuration*0.1);
    }    
}
