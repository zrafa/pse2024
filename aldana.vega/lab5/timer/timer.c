
#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

extern volatile unsigned long ticks = 0;

//Aumenta en 10?
ISR(TIMER1_COMPA_vect)
{
  ticks++;
}

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
    
}volatile timer1_t;

volatile timer1_t *timer1 = (timer1_t*) 0x80;

volatile unsigned char *timer1_timsk1 = (unsigned char) (0x6F);

#define TIMER1_CS 0x03
#define TIMER1_CTC 0x08

#define SYSTEM_TICKS 16000000
#define PRESCALAR 64
#define TICKS_PER_SECOND 1000

#define TIMER1_OCR1A (SYSTEM_TICKS/PRESCALAR)*0.01


void timer_init(void)
{ 
    //Setea modo CTC
    timer1->tccr1b |= TIMER1_CTC;
    //Setea el reloj
    timer1->tccr1b |= TIMER1_CS;
    //valor con el cual comparar, compara con el registro ocr1a
    timer1->ocr1al = TIMER1_OCR1A;
    //Comparar con ocr1a y genera una interrupcion si hay match
    (*timer1_timsk1) |= 0x02;
    //Activar las interrupciones globales
    sei();
}

