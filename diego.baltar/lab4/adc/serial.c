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

/* UCSR0A - USART Control and Status Register A bits */
#define UCSR0A_MPCM0   0
#define UCSR0A_U2X0    1
#define UCSR0A_UPE0    2
#define UCSR0A_DOR0    3
#define UCSR0A_FE0     4
#define UCSR0A_UDRE0   5
#define UCSR0A_TXC0    6
#define UCSR0A_RXC0    7

/* UCSR0B - USART Control and Status Register B bits */
#define UCSR0B_TXB80   0
#define UCSR0B_RXB80   1
#define UCSR0B_UCSZ02  2
#define UCSR0B_TXEN0   3
#define UCSR0B_RXEN0   4
#define UCSR0B_UDRIE0  5
#define UCSR0B_TXCIE0  6
#define UCSR0B_RXCIE0  7

/* UCSR0C - USART Control and Status Register C bits */
#define UCSR0C_UCPOL0  0
#define UCSR0C_UCSZ00  1
#define UCSR0C_UCSZ01  2
#define UCSR0C_USBS0   3
#define UCSR0C_UPM00   4
#define UCSR0C_UPM01   5
#define UCSR0C_UMSEL00 6
#define UCSR0C_UMSEL01 7

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define USART_BAUDRATE 9600
#define BAUD_PRESCALE  (((F_CPU/(USART_BAUDRATE*16UL)))-1)

#define RX_ENABLE      (1 << UCSR0B_RXEN0)  /* Habilitar la recepción */
#define TX_ENABLE      (1 << UCSR0B_TXEN0)  /* Habilitar la transmisión */
#define PARITY_MODE    (0 << UCSR0C_UPM00)  /* No usar bit de paridad */
#define STOP_BITS      (0 << UCSR0C_USBS0)  /* Usar 1 bit de stop */
#define CHAR_SIZE      (3 << UCSR0C_UCSZ00) /* Usar 8 bits de dato de E/S */
#define READY_TO_READ  (1 << UCSR0A_RXC0)   /* Dato listo para leer */
#define READY_TO_WRITE (1 << UCSR0A_UDRE0)  /* Búfer listo para escribir */

#define MAX_INT_DIGITS  5
#define MAX_LONG_DIGITS 10

/* Máximo entre dos números */
#define MAX(a,b) ((a) < (b) ? (b) : (a))

/* Mínimo entre dos números */
#define MIN(a,b) ((a) < (b) ? (a) : (b))

/* Estructura de datos del USART del atmega328, según sugerido en el apunte */
typedef struct
{
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

void serial_init()
{
  // Establecer baud rate
  serial_port->baud_rate_h = (uint8_t)(BAUD_PRESCALE >> 8);
  serial_port->baud_rate_l = (uint8_t)(BAUD_PRESCALE);

  // Habilitar recepción y transmisión
  serial_port->status_control_b = RX_ENABLE | TX_ENABLE;

  // Establecer formato del frame
  serial_port->status_control_c = CHAR_SIZE | STOP_BITS | PARITY_MODE;
}

/* Enviar un byte a través del del dispositivo inicializado */
void serial_put_char(char data)
{
  // Se debe esperar verificando el bit UDREn del registro UCSRnA
  // hasta que el búfer esté listo para recibir un dato a transmitir
  while (!(serial_port->status_control_a & READY_TO_WRITE));

  // Colocar dato en el búfer para ser enviado
  serial_port->data_io = data;
}

/* Recibir un byte a través del del dispositivo inicializado */
char serial_get_char(void)
{
  // Esperar para recibir el dato
  while (!(serial_port->status_control_a & READY_TO_READ));

  // Devolver el valor que se encuentra en el registro de datos de E/S
  return serial_port->data_io;
}

void serial_put_str(char *str)
{
  char *c = str;

  while (*c != '\0') {
    serial_put_char(*c);
    c++;
  }
}

void serial_get_str(char *str, int len)
{
  char c = 0;
  char n = 0;

  while (c != '\n' && c != '\r' && n < len) {
    c = serial_get_char();
    *(str+n) = c;
    n++;
  }
}

void serial_put_int(int n, unsigned char digits)
{
  char len = MAX(MIN(MAX_INT_DIGITS, digits), 1);

  switch (len) {
    case 5:
      serial_put_char(n/10000 % 10 + 48);
    case 4:
      serial_put_char(n/1000 % 10 + 48);
    case 3:
      serial_put_char(n/100 % 10 + 48);
    case 2:
      serial_put_char(n/10 % 10 + 48);
    case 1:
      serial_put_char(n % 10 + 48);
    default:
      break;
  }
}

void serial_put_long_int(long int n, unsigned char digits)
{

}

void serial_put_double(double d, char int_digits, char frac_digits)
{

}
