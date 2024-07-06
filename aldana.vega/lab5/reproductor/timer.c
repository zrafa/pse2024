
#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

extern volatile unsigned char valor_escalado = 0;


/* direccion de PORTB (registro de datos) */
volatile unsigned char * puerto_b = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_b = (unsigned char *) 0x24;

typedef struct
{
    uint8_t tccr0a;
    uint8_t tccr0b;
    uint16_t tcnt0;
    uint16_t ocr0a;
    uint16_t ocr0b;  
}volatile timer0_t;

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

volatile timer0_t *timer0 = (timer0_t*) 0x44;

volatile unsigned char *timer0_timsk0 = (unsigned char) (0x6E);

#define TIMER0_CS 0x03
#define TIMER0_CTC 0x02

volatile timer1_t *timer1 = (timer1_t*) 0x80;

volatile unsigned char *timer1_timsk1 = (unsigned char) (0x6F);

#define TIMER1_CS 0x03
#define TIMER1_COM1A 128

#define SYSTEM_TICKS 16000000
#define PRESCALAR 64
#define TICKS_PER_SECOND 1000

#define TIMER1_OCR1A (SYSTEM_TICKS / PRESCALAR / TICKS_PER_SECOND)
#define TIMER0_OCR0A SYSTEM_TICKS / (PRESCALAR * 11025) - 1 

void timer0_init(void)
{ 
    //Setea modo CTC
    timer0->tccr0b |= TIMER0_CTC; //bit 3
    //Setea el reloj
    timer0->tccr0b |= TIMER1_CS; //bits 0 y 1
    //valor con el cual comparar, compara con el registro ocr1a
    timer0->ocr0a = TIMER0_OCR0A;
    //Comparar con ocr1a y genera una interrupcion si hay match
    (*timer0_timsk0) |= 0x02;
    //Activar las interrupciones globales
    sei();
}

void timer1_init(void)
{ 
    //Setea modo PWM
    timer1->tccr1b |= (11<<3);
    timer1->tccr1a |= (1<<1);
    //Setea el reloj
    timer1->tccr1b |= TIMER1_CS; 
    //Clear on match
    timer1->tccr1a |= TIMER1_COM1A; 

    timer1->ocr1b = 255;
    
    //Configurar PB1 como salida
    *(puerto_b) &= 0b10;
    *(ddr_b) |= 0b10;
} 


ISR(TIMER1_COMPA_vect){
    timer1->ocr1a=valor_escalado;
}