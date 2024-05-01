#include "delay_ms.h"
#include "serial.h"
#include "ultrasound.h"

#define TIME_DISTANCE_RELATION 58
#define TIME_BETWEEN_SCANS_MS 500

int main(void) {
  unsigned int echo_time_us;
  float distance_cm = 0;
  unsigned int integer_digits = 2;
  unsigned int decimal_digits = 3;

  ports_init();
  serial_init();
  serial_put_str("Iniciando \r\n");

  while (1) {
    start_ranging();
    echo_time_us = listening_echo();

    if (echo_time_us >= TIME_OUT_US) {
      serial_put_str("FUERA DE RANGO \r\n");
    } else {
      distance_cm = ((float)(echo_time_us)) / TIME_DISTANCE_RELATION;
      serial_put_str("Distancia en cm: \r\n");
      serial_put_double(distance_cm, integer_digits, decimal_digits);
      serial_put_str("\r\n");
    }
    delay_ms(TIME_BETWEEN_SCANS_MS);
  }
}