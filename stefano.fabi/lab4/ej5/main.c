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
	int val;
	
	speaker_init();

	serial_init();

	adc_init();

	while (1) {
		/* obtener una conversión ADC desde el pin de entrada ADC 2 */
 		//val = adc_read(2);

		/* realizar alguna acción con val */
		//serial_put_int(val);

		speaker_play(melody, MELODY_NOTES(melody), TEMPO);
    	delay_ms(4000);
	}

	return 0;
}
