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

void timer1_init(uint16_t top_value, timer1_compa_fn_t func);


#endif /* _TIMER_H */
