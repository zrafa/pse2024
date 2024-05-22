/**
 * @file main.c
 * @author Diego Pablo Matías Baltar <diego.baltar@est.fi.uncoma.edu.ar>
 * @brief Prueba para el driver serial
 * @date 2024-05-19
 *
 * Programa de prueba para el driver de ADC.
 */

#include <stdint.h>

#include "adc.h"
#include "serial.h"
#include "utils.h"

int main(void)
{
  uint16_t adc_value = 0;

  adc_init();
  serial_init();

  while (1) {
    adc_value = adc_read(PORTC0);
    serial_put_int(adc_value, 4);
    serial_put_str("\r\n");

    delay_ms(2000);
  }

  return 0;
}
