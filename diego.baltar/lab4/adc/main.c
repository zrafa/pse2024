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

#define SCALE_MAX_VALUE (1023)
#define SCALE(v,m)      ((uint16_t)((v/(float)SCALE_MAX_VALUE)*(m)))

int main(void)
{
  uint16_t adc_value = 0;

  adc_init();
  serial_init();

  while (1) {
    adc_value = adc_read(ADC0);

    serial_put_str("ADC (0:1023): ");
    serial_put_int(adc_value, 0);
    serial_put_str("\r\n");

    serial_put_str("ADC int (-512:511): ");
    serial_put_int(adc_value - (1024/2), 0);
    serial_put_str("\r\n");

    serial_put_str("ADC int (-512:511) - 4: ");
    serial_put_int(adc_value - (1024/2), 4);
    serial_put_str("\r\n");

    serial_put_str("ADC long (*1000): ");
    serial_put_long_int(adc_value*1000, 0);
    serial_put_str("\r\n");

    serial_put_str("ADC long (*1000) - 10: ");
    serial_put_long_int(adc_value*1000L, 10);
    serial_put_str("\r\n");

    serial_put_str("ADC long (*-1000): ");
    serial_put_long_int(adc_value*-1000L, 0);
    serial_put_str("\r\n");

    serial_put_str("ADC double (0:1) - 4: ");
    serial_put_double(adc_value / 1023.0, 0, 4);
    serial_put_str("\r\n");

    serial_put_str("ADC double (0:100) - 2: ");
    serial_put_double(adc_value / 1023.0 * 100, 3, 2);
    serial_put_str("\r\n");

    //serial_put_str("ADC scaled value (0:9): ");
    //serial_put_int(SCALE(adc_value, 9), 0);
    serial_put_str("\r\n");

    delay_ms(2000);
  }

  return 0;
}
