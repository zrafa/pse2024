
/**********************************************************************
 *
 * timer.c - Driver del Timer del atmega328p
 * pagina 89 atmega328p
 *
 **********************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"
#include "gpio.h"

/* direccion de PORTB (registro de datos) */
volatile unsigned char * PUERTO_B = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * DDR_B = (unsigned char *) 0x24;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * PIN_B = (unsigned char *) 0x23;

/* TCCR1A – Timer/Counter1 Control Register A */
#define COM1A1 		(1 << 7) 		/* Bit 7:6 - COM1A1:0: Compare Output Mode for Channel A */
#define COM1A0 		(1 << 6)
#define COM1B1 		(1 << 5) 		/* Bit 5:4 - COM1B1:0: Compare Output Mode for Channel B */
#define COM1B0 		(1 << 4)
#define WGM11  		(1 << 1) 		/* Bit 1:0 - WGM11:0: Waveform Generation Mode */
#define WGM10  		(1 << 0)

/* TCCR1B – Timer/Counter1 Control Register B */
#define ICNC1 		(1 << 7) 		/* Bit 7 - ICNC1: Input Capture Noise Canceler */
#define ICES1 		(1 << 6) 		/* Bit 6 - ICES1: Input Capture Edge Select */
#define WGM13 		(1 << 4) 		/* Bit 4:3 - WGM13:2: Waveform Generation Mode */
#define WGM12 		(1 << 3)
#define CS12  		(1 << 2) 		/* Bit 2:0 - CS12:0: Clock Select */
#define CS11  		(1 << 1)
#define CS10  		(1 << 0)		

/* TIMSK1 – Timer/Counter1 Interrupt Mask Register */
#define ICIE1   	(1 << 5)		
#define OCIE1B  	(1 << 2)		
#define OCIE1A  	(1 << 1)		
#define TOIE1     	(1 << 5)		

#define SERVOMOTOR 9

// pagina 108 atmega328p
typedef struct
{
	uint8_t tccr1a; /* TCCR1A - Timer/Counter1 Control Register A */
	uint8_t tccr1b; /* TCCR1B - Timer/Counter1 Control Register B */
	uint8_t tccr1c; /* TCCR1C - Timer/Counter1 Control Register C */

	uint8_t _res;   /* Reserved */

	uint8_t tcnt1l;  /* Timer/Counter1 - Counter register low/high byte */
    uint8_t tcnt1h;

	uint8_t icr1l;	    /* Input capture register low/high byte */
    uint8_t icr1h;      /* Input capture register low/high byte */

	uint8_t ocr1al;     /* Output compare register A low/high byte */
    uint8_t ocr1ah;     /* Output compare register A low/high byte */

    uint8_t ocr1bl;     /* Output compare register B low/high byte */
    uint8_t ocr1bh;     /* Output compare register B low/high byte */
} timer1_t;

static volatile timer1_t *timer1 = (volatile timer1_t*) (0x80);

// Enable FAST PWM Mode: wgm13 = 1 , wgm12 = 1 , wgm11 = 1 , wgm10 = 0
#define INITIALIZE_MODE_IN_TCCRA  (((WGM10) & (~ WGM10)) | WGM11)			
#define INITIALIZE_MODE_IN_TCCRB  (WGM12 | WGM13)

// Clear OC1A/OC1B on compare match when up-counting. Set OC1A/OC1B on compare match when down counting.
#define PORT_OPERATION  (COM1A1 | ((COM1A0) & (~ COM1A0)))	

// Seleccionar prescaler (prescaling 8)
#define PRESCALER (((CS10) & (~ CS10)) | CS11 | ((CS12) & (~ CS12)))

// Habilitar las interrupciones
#define INTERRUPT_ENABLE (OCIE1A)

void timer1_init(uint16_t top_value)
{
    timer1->tccr1a = INITIALIZE_MODE_IN_TCCRA | PORT_OPERATION; 
	
	timer1->tccr1b = INITIALIZE_MODE_IN_TCCRB | PRESCALER;
	
	timer1->icr1h = (top_value >> 8) & 0xFF;
    timer1->icr1l = top_value & 0xFF;

	gpio_output(SERVOMOTOR);
}

void timer1_pulse(uint16_t width) 
{
	timer1->ocr1ah = (width >> 8) & 0xFF;
    timer1->ocr1al = width & 0xFF;
}