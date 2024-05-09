/**
 * @file main.c
 * @author Diego Pablo Matías Baltar <diego.baltar@est.fi.uncoma.edu.ar>
 * @brief Prueba para el driver serial
 * @date 2024-05-01
 *
 * Programa de prueba para el driver del UART.
 */

#include "serial.h"


int main(void)
{
  char recv_char = 0;

  // Inicializar driver
  serial_init();

  serial_put_char('s');
  serial_put_char('t');
  serial_put_char('a');
  serial_put_char('r');
  serial_put_char('t');
  serial_put_char('\r');
  serial_put_char('\n');

  while (recv_char != 'q') {
    // Recibir dato
    recv_char = serial_get_char();

    // Hacer eco del dato con un salto de línea
    serial_put_char(recv_char);
    serial_put_char('\r');
    serial_put_char('\n');
  }

  for (;;);

  return 0;
}
