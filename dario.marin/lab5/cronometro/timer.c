#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

// CONSTANTS
#define F_OSC 16000000
#define F_CK 100
#define PRESCALER 64
#define OCR1A_VALUE ((F_OSC / (PRESCALER * F_CK)) - 1)

// BITS
#define WGM12 3
#define CS11 1
#define CS10 0
#define OCIE1A 1

// CONF
#define CTC_MODE (1 << WGM12)
#define PRESCALER_64 ((1 << CS11) | (1 << CS10))
#define INTERRUPT_ENABLE (1 << OCIE1A)

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

timer1_t *timer1 = (timer1_t *)0x80;
volatile unsigned char *timsk1 = (unsigned char *)0x6F;

volatile uint8_t hundredths;
volatile uint8_t seconds;
volatile uint8_t minutes;

ISR(TIMER1_COMPA_vect)
{
    hundredths++;
    if (hundredths >= 100)
    {
        hundredths = 0;
        seconds++;
        if (seconds >= 60)
        {
            seconds = 0;
            minutes++;
        }
    }
}

void timer_init()
{
    hundredths = 0;
    seconds = 0;
    minutes = 0;

    timer1->tccr1b |= (CTC_MODE | PRESCALER_64);
    timer1->ocr1ah = (OCR1A_VALUE >> 8) & 0xFF;
    timer1->ocr1al = OCR1A_VALUE & 0xFF;
    *timsk1 |= INTERRUPT_ENABLE;
    sei();
}