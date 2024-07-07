/**********************************************************************
/ *
/ * timer.h: interfaz del driver timer
/ *
/ **********************************************************************/

/* para los tipos de datos. Ej.: uint8_t */
#include <stdint.h> 

#ifndef _TIMER_H
#define _TIMER_H

typedef void (* timer1_compa_fn_t) (void);

void timer1_init(uint16_t top_value);
void timer1_pulse(uint16_t width);

#endif /* _TIMER_H */
