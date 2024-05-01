/**
 * @file usound.h
 * @author Diego Pablo Matias Baltar <diego.baltar@est.fi.uncoma.edu.ar>
 * @brief Funciones para controlar el sensor de ultrasonido
 * @version 0.1
 * @date 2024-04-24
 */

#ifndef USOUND_H
#define USOUND_H

#include "utils.h"

/** Usar Puerto C */
#define USOUND_PIN  PINC
#define USOUND_DDR  DDRC
#define USOUND_PORT PORTC


void  usound_init(const unsigned char trig_pin, const unsigned char echo_pin);
float usound_distance();


#endif /* USOUND_H */
