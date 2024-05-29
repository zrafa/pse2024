/**********************************************************************
 *
 * adc.c - Driver del ADC del atmega328p
 * PAGINA 205 DEL ATMEGA328P DATASHEET
 * 
 * META : ocultar el hardware a la aplicacion 
 *
 **********************************************************************/

#include "speaker.h"

/* puertos de E/S */

/* direccion de PORTB (registro de datos) */
volatile unsigned char * PUERTO_B = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * DDR_B = (unsigned char *) 0x24;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * PIN_B = (unsigned char *) 0x23;

#define SPEAKER (1 << 0)        /* 0b00000001 */

/** Valor absoluto */
#define ABS(x) ((x) < 0 ? (-x) : (x))

void speaker_init()
{
        // apagar el voltaje del pin
        *(PUERTO_B) &= ~ SPEAKER;

        // configurar puerto como salida
        *(DDR_B) |= SPEAKER;
}

void speaker_note(unsigned int frequency, unsigned int duration)
{
  if (frequency <= 0) {
    delay_us(duration);
    return;
  }

  long double seconds = 1.0 / frequency / 2;
  long int micros = seconds * 1000000L;
  long int duration_us = duration * 1000L;

  for (long i = 0; i <= duration_us; i += micros * 2) {
    *(PUERTO_B) |= SPEAKER;
    delay_us(micros);
    *(PUERTO_B) &= ~ SPEAKER;
    delay_us(micros);
  }
}

void speaker_play(int *melody, unsigned int notes, unsigned int tempo)
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

    speaker_note(melody[n], duration);
    //delay_ms(duration * 0.1);
  }
}