/**
 * @file main.c
 * @author Diego Pablo Matías Baltar <diego.baltar@est.fi.uncoma.edu.ar>
 * @brief Prueba para el driver serial
 * @date 2024-05-01
 *
 * Programa de prueba para el driver del UART.
 */

#include <string.h>
#include "serial.h"

#define BUFF_SIZE 256

int main(void)
{
  char recv_str[BUFF_SIZE];
  char recv_chr = 0;

  // Inicializar driver
  serial_init();
  serial_put_str("start\r\n");

  while (recv_chr != 's') {
    // Recibir texto (hasta BUFF_SIZE bytes - 1 para el final de string NULL)
    serial_put_str("Texto:\r\n");
    memset(&recv_str[0], 0, BUFF_SIZE-1);
    serial_get_str(&recv_str[0], BUFF_SIZE-1);
    serial_put_str(recv_str);
    serial_put_str("\r\n");

    // Recibir dato
    serial_put_str("Finalizar? s/N:\r\n");
    recv_chr = serial_get_char();

    // Hacer eco del dato con un salto de línea
    serial_put_char(recv_chr);
    serial_put_str("\r\n");
  }

  for (;;);

  return 0;
}
