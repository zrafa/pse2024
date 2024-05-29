#include "adc.h"
#include "serial.h"
#include "delay.h"

#include "speaker.h"
#include "songs/nokia.h"
#include "songs/pacman.h"
#include "songs/takeonme.h"
#include "songs/starwars.h"
#include "songs/gameofthrones.h"

/** Determina que tan lenta o rápida se reproduce la melodía */
#define TEMPO       (140)

//int melody[] = GAMESOFTHRONES_MELODY;
//int melody[] = NOKIA_MELODY;
int melody[] = PACMAN_MELODY;

int main()
{
	speaker_init();

	serial_init();

	adc_init();

	while (1) {
		speaker_play(melody, MELODY_NOTES(melody), TEMPO);
    	
		// esperar para la proxima cancion
		delay_ms(1000);
	}

	return 0;
}
