

#ifndef _TIMER_H
#define _TIMER_H
#include <stdint.h>
void timer_init();

extern volatile uint8_t hundredths;
extern volatile uint8_t seconds;
extern volatile uint8_t minutes;

#endif