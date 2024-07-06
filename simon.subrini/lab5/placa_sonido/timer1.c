#include "timer1.h"
#include <avr/io.h>
#include <avr/interrupt.h>

typedef struct {
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

#define TIMER1_CS 0x03 // Prescaler = 64
#define TCCR1A_ (1 << COM1A1) | (1 << WGM11) // COM1A1 | WGM11
#define SYSTEM_TICKS 16000000
#define PRESCALER 64
#define FREQ_11025HZ 11025
#define OCR1A_VAL ((SYSTEM_TICKS / PRESCALER) / FREQ_11025HZ) // Para 11025 Hz

extern volatile uint8_t current_sample;

void timer1_init()
{
  // Modo CTC con OCR1A como TOP
  timer1->tccr1a |= (1 << WGM12);
  timer1->tccr1b |= TIMER1_CS;
  OCR1A = OCR1A_VAL;

  // Habilitar interrupción del comparador A del Timer 1
  TIMSK1 |= (1 << OCIE1A);

  // Configurar el Timer 1 en modo Fast PWM con ICR1 como TOP
  timer1->tccr1a = TCCR1A_;
  timer1->tccr1b |= (1 << WGM13) | (1 << WGM12) | TIMER1_CS;

  // Establecer TOP en ICR1 para 11025 Hz
  ICR1 = OCR1A_VAL;

  // Habilitar interrupciones globales
  sei();
}

void timer1_set_pwm_duty_cycle(uint8_t duty_cycle)
{
  // Escalar el duty cycle a 8 bits
  uint16_t pwm_value = (uint16_t)duty_cycle * ICR1 / 255;
  OCR1A = pwm_value;
}

ISR(TIMER1_COMPA_vect)
{
  // Actualizar el ciclo de trabajo del PWM con la muestra actual
  OCR1A = current_sample;
}
