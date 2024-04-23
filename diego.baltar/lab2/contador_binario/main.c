/**
 * @file main.c
 * @author Diego Pablo Matias Baltar <diego.baltar@est.fi.uncoma.edu.ar>
 * @brief Contador binario de 5 bits
 * @version 0.1
 * @date 2024-04-18
 *
 * Implementación del Control de pulsador. Configuración de pullpup.
 * Implementar con los leds un contadora binario de 5 bits.
 * Simplemente se debe contar dejando un delay de unos 300ms entre valores.
 * Si se presiona el pulsador (conectado a un pin del puerto C) se detiene el
 * conteo. Si se presiona nuevamente el pulsador entonces continua el conteo.
 */

#include "utils.h"

/** Máscara de bits para los pines GPIO que controlan los leds */
#define COUNTER_LEDS  (0x1F) /* 0b00011111 */
/** Máximo del contador binario de 5 bits (2^5 = 32) */
#define COUNTER_LIMIT (0x20)

/** Máscara de bits para el pull-up */
#define PULLUP_LED    (1 << PORTB5) /* 0b00100000 */
/** Máscara de bits para el led del pull-up */
#define PULLUP_BTN    (1 << PORTC0) /* 0b00000001 */

/** Valor del contador */
unsigned char counter = 0;

/** Determina si se detiene o no el contador */
unsigned char counter_stopped = 0;

void init_counter()
{
  PORTB &= ~COUNTER_LEDS; // Apagar los bits de los LEDS
  DDRB |= COUNTER_LEDS;   // Configurar los pines como SALIDA
}

void incr_counter()
{
  counter = ((PORTB & COUNTER_LEDS) + 1) % COUNTER_LIMIT;
  PORTB = (PORTB & ~COUNTER_LEDS) | counter;
}

void toggle_counter()
{
  PORTB ^= PULLUP_LED;
  counter_stopped = !counter_stopped;
}

void init_pullup()
{
  // Inicializar led del pull-up
  PORTB &= ~PULLUP_LED;
  DDRB |= PULLUP_LED;

  // Habilitar pull-up para los pines del puerto C
  // Establecer el pin del puerto C como entrada
  PORTC |= PULLUP_BTN;
  DDRC &= ~PULLUP_BTN;
}

int main()
{
  volatile unsigned char button_up = 0;

  init_pullup();
  init_counter();

  while (1) {
    button_up = PINC & PULLUP_BTN;

    // Se debe presionar el botón hasta que se prenda el led del contador
    // Esto es por los delays del botón y del contador
    if (!button_up) {
      toggle_counter();
      delay_ms(300);
    }

    if (!counter_stopped) {
      incr_counter();
      delay_ms(1000);
    }
  }
}


