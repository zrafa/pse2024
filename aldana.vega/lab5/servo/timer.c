
#include <stdint.h>
#include "gpio.h"
#include <avr/io.h>
#include <avr/interrupt.h>

extern volatile unsigned long ticks = 0;


/* direccion de PORTB (registro de datos) */
volatile unsigned char * puerto_b = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_b = (unsigned char *) 0x24;

typedef struct
{
    uint8_t tccr1a;
    uint8_t tccr1b;
    uint8_t tccr1c;
    uint8_t reserved;
    uint16_t tcnt1;
    uint16_t icr1;
    uint16_t ocr1a;
    uint16_t ocr1b;
    
}volatile timer1_t;

volatile timer1_t *timer1 = (timer1_t*) 0x80;

volatile unsigned char *timer1_timsk1 = (unsigned char) (0x6F);

#define TIMER1_CS 0x02
#define TIMER1_COM1A 128

#define SYSTEM_TICKS 16000000
#define PRESCALAR 8
#define TICKS_PER_SECOND 1000

#define TIMER1_OCR1A (SYSTEM_TICKS/PRESCALAR)*0.01
#define TIMER1_ICR (SYSTEM_TICKS/PRESCALAR)*0.02-1;

void timer_init(void)
{ 
    //Setea modo PWM
    timer1->tccr1b |= (11<<3);
    timer1->tccr1a |= (1<<1);
    //Setea el reloj
    timer1->tccr1b |= TIMER1_CS;
    //Clear on match
    timer1->tccr1a |= TIMER1_COM1A;
    //ICR como tope
    timer1->icr1 = TIMER1_ICR;

    //Configurar PB1 como salida
    gpio_output(9);
} 


void servo_angulo(int ang){
    timer1->ocr1a = (uint16_t) ang;
}

