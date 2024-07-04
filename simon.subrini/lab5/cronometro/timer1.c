/**********************************************************************
 *
 * timer1.c - Driver del TIMER1 del atmega328p
 *
 **********************************************************************/

#include "timer1.h"
#include <stdint.h> 
#include <avr/interrupt.h>

typedef struct
{
  uint8_t tccr1a;
  uint8_t tccr1b;
  uint8_t tccr1c;
  uint8_t reserved;
  uint8_t tcnt1l;
  uint8_t tcnt1h;
  uint8_t icr1l;
  uint8_t icr1h;
  uint8_t ocr1al;
  uint8_t ocr1ah;
  uint8_t ocr1bl;
  uint8_t ocr1bh;
} volatile timer1_t;

volatile timer1_t *timer1 = (timer1_t *) 0x80;
volatile unsigned  char *timer1_timsk1 = (unsigned char *) 0x6F;
volatile unsigned int ticks = 0;

#define TIMER1_CS 0xB /* 0b1011 -> Prescaler de 64  y modo CTC*/
#define SYSTEM_TICKS 16000000
#define PRESCALER 64
#define TICKS_PER_SECOND 100
#define OCR1A_L (SYSTEM_TICKS/PRESCALER/TICKS_PER_SECOND) * 0xFF;
#define OCR1A_H ((SYSTEM_TICKS/PRESCALER/TICKS_PER_SECOND)>>8)


void timer1_init ()
{
  timer1->tccr1a = 0; // Modo normal
  timer1->tccr1b |= TIMER1_CS;
  timer1->ocr1ah = OCR1A_H;
  timer1->ocr1al = OCR1A_L;
  (*timer1_timsk1) |= 0x02;
}

unsigned int timer1_get_counter()
{
  return ticks;
}

ISR(TIMER1_COMPA_vect)
{
  ticks++;
}
