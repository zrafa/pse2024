/*
reloj del sistema = 4000000 ticks/s / 64 (prescalar) = 62500 ticks/s

62500 ticks/s / 100 ticks = 625
*/

#include <avr/io.h>
#include <avr/interrupt.h>

volatile int ticks = 0;
volatile unsigned char flag_c = 0;
volatile unsigned char flag_s = 0;

typedef struct
{
    uint8_t tccr1a; // registro de control A del timer1
    uint8_t tccr1b; // registro de control B del timer1
    uint8_t tccr1c; // registro de control C del timer1
    uint8_t reserved;
    uint8_t tcnt1l; // registro timer1/contador low
    uint8_t tcnt1h; // registro timer1/contador high
    uint8_t icr1l;   // Input capture register low 
    uint8_t icr1h;   // Input capture register high 
    uint8_t ocr1al;  // registro comparador A low
    uint8_t ocr1ah;  // registro comparador A high
    uint8_t ocr1bl;  // registro comparador B low
    uint8_t ocr1bh;  // registro comparador B high
    
} volatile timer1_t;

volatile timer1_t *timer1 = (timer1_t *)(0x80);

// registro mascara de interrupciones timer1 
volatile unsigned char *timer1_timsk1 = (unsigned char *)(0x6F);

#define TIMER1_CS 0b00001011
#define TIMER1_CTC 0x00

#define SYSTEM_TICKS 4000000
#define PRESCALAR 64
#define TICKS_INT 100

#define TIMER1_OCR1AL (SYSTEM_TICKS/PRESCALAR/TICKS_INT)
#define TIMER1_OCR1AH ((SYSTEM_TICKS/PRESCALAR/TICKS_INT) >> 8)


void timer1_init( void )
{
    timer1->tccr1a |= TIMER1_CTC;
    timer1->tccr1b |= TIMER1_CS;
    timer1->ocr1al |= TIMER1_OCR1AL;
    timer1->ocr1ah |= TIMER1_OCR1AH;
    (*timer1_timsk1) |= 0x02;
}

ISR(TIMER1_COMPA_vect)
{
    ticks++;
    if (ticks == 625){
        ticks = 0;
        flag_s = 1;
    }
    flag_c = 1;
}
