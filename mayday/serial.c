/**********************************************************************
 *
 * serial.c - Driver del UART del atmega328p
 *
 * Configuracion: 9600bps, 8bits data, 1bit stop, sin bit de paridad
 *
 **********************************************************************/

#include <stdint.h>

#define USART_BAUDRATE 9600
#define BAUD_PRESCALE  (((F_CPU/(USART_BAUDRATE*16UL)))-1)

/* Estructura de datos del USART del atmega328 */
typedef struct {
  uint8_t status_control_a; /* ucsr0a USART Control and Status A */
  uint8_t status_control_b; /* ucsr0b USART Control and Status B */
  uint8_t status_control_c; /* ucsr0c USART Control and Status C */
  uint8_t _reserved;        /* reserved */
  uint8_t baud_rate_l;      /* ubrr0l baud rate low */;
  uint8_t baud_rate_h;      /* ubrr0h baud rate high */
  uint8_t data_io;          /* udr0 I/O data */
} volatile uart_t;

/* Puntero a la estructura de los registros del periférico */
uart_t *serial_port = (uart_t*)(0xc0);


void serial_init(void)
{
	/* COMPLETAR */
}

void serial_put_char(char outputChar)
{
	/* COMPLETAR */
}

char serial_get_char(void)
{
	/* COMPLETAR */
}

void serial_put_str(char * outputStr)
{
	/* COMPLETAR */
}

char* serial_get_str(void)
{
	/* COMPLETAR */
}

void serial_put_int (int valor, int cant_digitos)
{
	/* COMPLETAR */
}

void serial_put_long_int (long int valor, int cant_digitos)
{
	/* COMPLETAR */
}

void serial_put_double (double valor, char digitos_enteros, char digitos_fraccionarios)
{
	/* COMPLETAR */
}

char serial_recibido(void)
{
	/* COMPLETAR */
}

