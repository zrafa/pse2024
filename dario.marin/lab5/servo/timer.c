#include <stdint.h>
#include "gpio.h"

// CONSTANTS
#define F_OSC 16000000
#define F_CK 50
#define T_PWM 20
#define PRESCALER 8
#define ICR1_VALUE ((F_OSC / (PRESCALER * F_CK)) - 1)

// BITS
#define WGM13 4
#define WGM12 3
#define WGM11 1
#define CS11 1
#define CS10 0
#define OCIE1A 1
#define COM1A1 7

// CONF
#define CTC_MODE (1 << WGM12)
#define CLEAR_ON_MATCH (1 << COM1A1)
#define FAST_PWM_MODE_B ((1 << WGM12) | (1 << WGM13))
#define FAST_PWM_MODE_A (1 << WGM11)
#define PRESCALER_64 ((1 << CS11) | (1 << CS10))
#define PRESCALER_8 (1 << CS11)
#define INTERRUPT_ENABLE (1 << OCIE1A)

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

timer1_t *timer1 = (timer1_t *) 0x80;

void timer_init() {
    timer1->tccr1a |= FAST_PWM_MODE_A | CLEAR_ON_MATCH;
    timer1->tccr1b |= FAST_PWM_MODE_B | PRESCALER_8;
    timer1->icr1l = ICR1_VALUE & 0xFF;
    timer1->icr1h = (ICR1_VALUE >> 8) & 0xFF;

    gpio_output(9);
}

void set_duty_cycle(float time_ms) {
    uint16_t ocr1a = (uint16_t)((time_ms / T_PWM) * (ICR1_VALUE + 1));
    timer1->ocr1al = ocr1a & 0xFF;
    timer1->ocr1ah = (ocr1a >> 8) & 0xFF;
}