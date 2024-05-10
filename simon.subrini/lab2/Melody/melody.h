#ifndef _MELODY_H
#define _MELODY_H

#define MELODY_LEN(m) (sizeof(m) / sizeof(m[0]) / 2)

void play_melody(unsigned char pin, unsigned char tempo, int *melody, unsigned int melody_len);
void play_note(unsigned int freq, unsigned int note_duration_ms, unsigned char pin);


#endif	/* _MELODY_H */
