/**
 * @file main.c
 * @author Diego Pablo Matias Baltar <diego.baltar@est.fi.uncoma.edu.ar>
 * @brief Enciende y apaga un led
 * @version 0.1
 * @date 2024-04-18
 *
 * Enciende y apaga un led conectado al puerto B, bit 5 de un ATmega328.
 * El puerto B de un atmega328p tiene los bits 0-5 mapeados a los pines 8-13 de
 * arduino.
 */

#include "utils.h"

int main(void)
{
  led_init();

  while (1) {
    delay_ms(1000);
    led_on();

    delay_us(1000000);
    led_off();
  }
}


