/**********************************************************************
 *
 * Filename:    speaker.h
 * 
 * API para la aplicacion embebida 
 * META : ocultar el hardware a la aplicacion 
 *
 **********************************************************************/

#ifndef _SPEAKER_H
#define _SPEAKER_H

/** Cantidad de notas */
#define MELODY_NOTES(m) (sizeof(m) / sizeof(m[0]) / 2)

void speaker_init(void);
void speaker_play(int *melody, unsigned int notes, unsigned int tempo);
void speaker_note(unsigned int frequency, unsigned int duration);


#endif /* _SERIAL_H */