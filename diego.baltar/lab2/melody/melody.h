/**
 * @file melody.h
 * @author Diego Pablo Matias Baltar <diego.baltar@est.fi.uncoma.edu.ar>
 * @brief Funciones para controlar un piezo speaker utilizando un pin digital
 * @version 0.1
 * @date 2024-04-24
 */

#ifndef MELODY_H
#define MELODY_H

#include "utils.h"

/** Usar Puerto B */
#define MELODY_PIN  PINB
#define MELODY_DDR  DDRB
#define MELODY_PORT PORTB

/** Cantidad de notas */
#define MELODY_NOTES(m) (sizeof(m) / sizeof(m[0]) / 2)


void melody_init(const unsigned char spkr_pin);
void melody_note(unsigned int frequency, unsigned int duration);
void melody_play(int *melody, unsigned int notes, unsigned int tempo);


#endif /* MELODY_H */
