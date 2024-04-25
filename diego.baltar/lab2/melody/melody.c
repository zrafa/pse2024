#include "melody.h"

/** Valor absoluto */
#define ABS(x) ((x) < 0 ? (-x) : (x))

/** Máscara de bits para el speaker */
static unsigned char speaker_pin = 0;

void melody_init(const unsigned char spkr_pin)
{
  speaker_pin = spkr_pin;

  MELODY_PORT &= ~speaker_pin;
  MELODY_DDR |= speaker_pin; // Operar como SALIDA
}

void melody_note(unsigned int frequency, unsigned int duration)
{
  if (frequency <= 0) {
    delay_us(duration);
    return;
  }

  long double seconds = 1.0 / frequency / 2;
  long int micros = seconds * 1000000L;
  long int duration_us = duration * 1000L;

  for (long i = 0; i <= duration_us; i += micros * 2) {
    PORTB |= speaker_pin;
    delay_us(micros);
    PORTB &= ~speaker_pin;
    delay_us(micros);
  }
}

void melody_play(int *melody, unsigned int notes, unsigned int tempo)
{
  int divider = 0;
  unsigned int duration = 0;
  unsigned int wholenote = (60000 * 4) / tempo;

  for (int n = 0; n < notes * 2; n = n + 2) {
    divider = melody[n + 1];
    if (divider > 0) {
      duration = wholenote / divider;
    } else if (divider < 0) {
      duration = wholenote / ABS(divider);
      duration *= 1.5;
    }

    melody_note(melody[n], duration);
    //delay_ms(duration * 0.1);
  }
}
