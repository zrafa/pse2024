#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

/* TCCR0A - Timer/Counter0 Control Register A bits */
#define COM0A1 7 /* Bits 7:6 - COM0A1:0: Compare Match Output A Mode */
#define COM0A0 6
#define COM0B1 5 /* Bits 5:4 - COM0B1:0: Compare Match Output B Mode */
#define COM0B0 4
#define WGM01  1 /* Bits 1:0 - WGM01:0: Waveform Generation Mode */
#define WGM00  0

/* TCCR0B - Timer/Counter0 Control Register B bits */
#define FOC0A 7 /* Bit 7 - FOC0A: Force Output Compare A */
#define FOC0B 6 /* Bit 6 - FOC0B: Force Output Compare B */
#define WGM02 3 /* Bit 3 - WGM02: Waveform Generation Mode */
#define CS02  2 /* Bits 2:0 - CS02:0: Clock Select */
#define CS01  1
#define CS00  0

/* TCCR1A - Timer/Counter1 Control Register A bits */
#define COM1A1 7 /* Bit 7:6 - COM1A1:0: Compare Output Mode for Channel A */
#define COM1A0 6
#define COM1B1 5 /* Bit 5:4 - COM1B1:0: Compare Output Mode for Channel B */
#define COM1B0 4
#define WGM11  1 /* Bit 1:0 - WGM11:0: Waveform Generation Mode */
#define WGM10  0

/* TCCR1A - Timer/Counter1 Control Register A bits */
#define ICNC1 7 /* Bit 7 - ICNC1: Input Capture Noise Canceler */
#define ICES1 6 /* Bit 6 - ICES1: Input Capture Edge Select */
#define WGM13 4 /* Bit 4:3 - WGM13:2: Waveform Generation Mode */
#define WGM12 3
#define CS12  2 /* Bit 2:0 - CS12:0: Clock Select */
#define CS11  1
#define CS10  0

#define TICKS 16000000UL
#define PRESCALER 64
#define TICKS_PER_SECOND 1000


/* Timer/Counter0 */
typedef struct
{
	uint8_t tccr0a; /* TCCR0A - Timer/Counter0 Control Register A */
	uint8_t tccr0b; /* TCCR0B - Timer/Counter0 Control Register B */
	uint8_t tcnt0;  /* TCNT0 - Timer/Counter0 Register */
	uint8_t ocr0a;  /* OCR0A - Output Compare Register A */
	uint8_t ocr0b;  /* OCR0B - Output Compare Register B */

} timer0_t;

/* Timer/Counter1 */
typedef struct
{
	uint8_t tccr1a; /* TCCR1A - Timer/Counter1 Control Register A */
	uint8_t tccr1b; /* TCCR1B - Timer/Counter1 Control Register B */
	uint8_t tccr1c; /* TCCR1C - Timer/Counter1 Control Register C */

	uint8_t _res;   /* Reserved */

	uint16_t tcnt1; /* Timer/Counter1 - Counter register low/high byte */
	uint16_t icr1;	/* Timer/Counter1 - Input capture register low/high byte */
	uint16_t ocr1a; /* Timer/Counter1 - Output compare register A low/high byte */
	uint16_t ocr1b; /* Timer/Counter1 - Output compare register B low/high byte */

} timer1_t;


static timer0_compa_fn_t timer0_compa_fn = (timer0_compa_fn_t)(0);

static volatile timer0_t *timer0 = (volatile timer0_t*)(0x44);
static volatile timer1_t *timer1 = (volatile timer1_t*)(0x80);

ISR(TIMER0_COMPA_vect) {
	if (timer0_compa_fn != 0)
		timer0_compa_fn();
}

void timer0_init(timer0_compa_fn_t fn)
{
	timer0_compa_fn = fn;

	timer0->tccr0a |= (1 << WGM01);
	timer0->tccr0b |= (1 << CS01) | (1 << CS00); // Preescalar 64
	timer0->ocr0a = TICKS/PRESCALER/TICKS_PER_SECOND;
	TIMSK0 = 0x02;

	sei();
}

void timer1_init(uint16_t top_value)
{
	timer1->tccr1a |= (1 << WGM11) | (1 << COM1A1);
	timer1->tccr1b |= (1 << WGM12) | (1 << WGM13) | (1 << CS11);
	timer1->icr1 = top_value; // Establecer el tope
	DDRB |= (1 << PB1); // Establecer OC1A (PB1) como salida
}

void timer1_pulse(uint16_t width)
{
	timer1->ocr1a = width;
}
