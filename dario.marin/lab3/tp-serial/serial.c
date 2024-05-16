
/**********************************************************************
 *
 * serial.c - Driver del UART del atmega328p
 *
 * META : ocultar el hardware a la aplicacion
 *
 * Configuracion: 9600bps, 8bits data, 1bit stop, sin bit de paridad
 *
 **********************************************************************/

#include <stdint.h>

#include "operations.h"

#define USART_BAUDRATE 9600
#define BAUDRATE_PRESCALE 0b01100111
#define INIT 0b00000110
#define EN_RX_TX 0b00011000

typedef struct {
  uint8_t status_control_a;
  uint8_t status_control_b;
  uint8_t status_control_c;
  uint8_t reserved;
  uint8_t baud_rate_L;
  uint8_t baud_rate_H;
  uint8_t data_es;
} volatile uart_t;

uart_t *puerto_serial = (uart_t *)(0xc0);

void serial_init() {
  puerto_serial->baud_rate_L = (unsigned char)(BAUDRATE_PRESCALE);
  puerto_serial->baud_rate_H = (unsigned char)(BAUDRATE_PRESCALE >> 8);
  puerto_serial->status_control_c = INIT;
  puerto_serial->status_control_b = EN_RX_TX;
}

void serial_put_char(char c) {
  while (!get_bit(&(puerto_serial->status_control_a), 5))
    ;
  puerto_serial->data_es = c;
}

char serial_get_char(void) {
  while (!get_bit(&(puerto_serial->status_control_a), 7))
    ;
  return puerto_serial->data_es;
}
