
/* utils.h - funciones de soporte al programa principal */

#ifndef _ULTRASOUND_H
#define _ULTRASOUND_H
#define TIME_OUT_US 36000

void ports_init();
void start_ranging();
int listening_echo();

#endif /* _ULTRASOUND_H */
