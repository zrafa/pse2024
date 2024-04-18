/**
 * @file main.c
 * @author Diego Pablo Matias Baltar <diego.baltar@est.fi.uncoma.edu.ar>
 * @brief Contador binario de 5 bits
 * @version 0.1
 * @date 2024-04-18
 *
 * Enciende y apaga un led conectado al puerto B, bit 5 de un ATmega328.
 * El puerto B de un atmega328p tiene los bits 0-5 mapeados a los pines 8-13 de
 * arduino.
 */

#include "utils.h"

/** Máscara de bits para los pines GPIO que controlan los leds */
#define COUNTER_LEDS  (0x1F) /* 0b00011111 */
/** Máximo del contador binario de 5 bits (2^5 = 32) */
#define COUNTER_LIMIT (0x20)

void init_counter()
{
  PORTB = PORTB & ~COUNTER_LEDS; // Apagar los bits de los LEDS
  DDRB = DDRB | COUNTER_LEDS;    // Configurar los pines como SALIDA
}

void incr_counter()
{
  volatile unsigned char count;

  count = ((PORTB & COUNTER_LEDS) + 1) % COUNTER_LIMIT;
  PORTB = (PORTB & ~COUNTER_LEDS) | count;
}

int main()
{
  init_counter();

  while (1) {
    delay_ms(1000);
    incr_counter();
  }
}


