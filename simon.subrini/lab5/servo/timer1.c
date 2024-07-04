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

#define TIMER1_CS 0b00011011 /* Prescaler de 64  y modo fast PWM*/
#define TCCR1A_ 0b10000010 /* COM1A1 | WGM11 */

#define F_OSC 4000000
#define F_CK 50
#define T_PWM 20
#define PRESCALER 64
#define ICR1_VALUE ((F_OSC / (PRESCALER * F_CK)) - 1)


void timer1_init ()
{
  timer1->tccr1a |= TCCR1A_; // Modo fast PWM
  timer1->tccr1b |= TIMER1_CS;
  timer1->icr1h = (ICR1_VALUE >> 8);
  timer1->icr1l = ICR1_VALUE & 0x00FF;
}


void timer1_set_pwm_duty_cycle(float grados)
{
  //float aux = (grados * ICR1_VALUE)/(T_PWM*1000);
  float prop = (float)grados / 180.0;
  unsigned int ocr1a = (102 - 51)*prop + 51;
  timer1->ocr1ah = (ocr1a >> 8);
  timer1->ocr1al = ocr1a & 0x00FF;
}

/*

si 20ms son 1023
1 ms = 51
2 ms = 102

*/
