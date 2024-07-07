#include <stdint.h>
#include "gpio.h"

#define led 13
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


#define TIMER1_CS 0b00011010
#define TIMER1_CTC 0b10000010

#define SYSTEM_TICKS 4000000
#define PRESCALAR 8
#define FREQ_OUT 50
//#define PWM_TOP (SYSTEM_TICKS/FREQ_OUT/PRESCALAR - 1)   //20mseg
//#define SERVO_MIN (1/1000*SYSTEM_TICKS/PRESCALAR - 1)   //1mseg
//#define SERVO_MAX (2/1000*SYSTEM_TICKS/PRESCALAR - 1)   //2mseg
#define PWM_TOP 9999
#define SERVO_MIN 549
#define SERVO_MAX 999

void pwm_init(void)
{
    timer1->tccr1a = TIMER1_CTC;
    timer1->tccr1b = TIMER1_CS;    
    timer1->icr1h = (PWM_TOP >> 8);    
    timer1->icr1l = (PWM_TOP & 0x00FF);
}

void update_pwm(int val)
{
    timer1->ocr1ah = (val >> 8); 
    timer1->ocr1al = (val & 0x00FF);   
}

void servo_set(int grados, int max_grados)
{
    float prop = (float)grados / (float)max_grados;
    int set = ((float)SERVO_MAX - (float)SERVO_MIN)*prop + (float)SERVO_MIN;   
    update_pwm(set);
}
