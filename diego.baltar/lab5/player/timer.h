/**
 * @file timer.h
 * @author Diego Pablo Matías Baltar <diego.baltar@gmail.com>
 * @brief Servo utility functions
 * @date 2024-06-13
 * @version 0.1
 */

#ifndef _TIMER_H_
#define _TIMER_H_


#include <stdint.h>


typedef void (*timer0_compa_fn_t)(void);


void timer0_init(timer0_compa_fn_t func);
void timer1_init(uint16_t top_value);
void timer1_pulse(uint16_t width);


#endif /* _TIMER_H_ */

