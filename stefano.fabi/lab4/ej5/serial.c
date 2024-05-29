
/**********************************************************************
 *
 * serial.c - Driver del UART del atmega328p
 *
 * META : ocultar el hardware a la aplicacion 
 *
 * Configuracion: 9600bps, 8bits data, 1bit stop, sin bit de paridad
 *
 **********************************************************************/

#include <stdint.h> /* para los tipos de datos. Ej.: uint8_t */

/* Completar la estructura de datos para que se superponga a los registros
   del periferico de hardware del USART del atmega328, segun sugerido
   en el apunte */


/* UCSR0A - USART Control and Status Register A bits */
#define UCSR0A_MPCM0   1 << 0
#define UCSR0A_U2X0    1 << 1
#define UCSR0A_UPE0    1 << 2
#define UCSR0A_DOR0    1 << 3
#define UCSR0A_FE0     1 << 4
#define UCSR0A_UDRE0   1 << 5
#define UCSR0A_TXC0    1 << 6
#define UCSR0A_RXC0    1 << 7

/* UCSR0B - USART Control and Status Register B bits */
#define UCSR0B_TXB80   1 << 0
#define UCSR0B_RXB80   1 << 1
#define UCSR0B_UCSZ02  1 << 2
#define UCSR0B_TXEN0   1 << 3
#define UCSR0B_RXEN0   1 << 4
#define UCSR0B_UDRIE0  1 << 5
#define UCSR0B_TXCIE0  1 << 6
#define UCSR0B_RXCIE0  1 << 7

/* UCSR0C - USART Control and Status Register C bits */
#define UCSR0C_UCPOL0  1 << 0
#define UCSR0C_UCSZ00  1 << 1
#define UCSR0C_UCSZ01  1 << 2
#define UCSR0C_USBS0   1 << 3
#define UCSR0C_UPM00   1 << 4
#define UCSR0C_UPM01   1 << 5
#define UCSR0C_UMSEL00 1 << 6
#define UCSR0C_UMSEL01 1 << 7

#ifndef F_CPU
#define F_CPU 4000000UL
#endif

typedef struct
{
 uint8_t status_control_a;      /* ucsr0a USART Control and Status A */
 uint8_t status_control_b;      /* ucsr0b USART Control and Status B */
 uint8_t status_control_c;      /* ucsr0c USART Control and Status C */
 uint8_t _reserved;             /* espacio sin utilizar */
 uint8_t baud_rate_l;           /* ubrr0l baud rate low */
 uint8_t baud_rate_h;           /* ubrr0h baud rate high */
 uint8_t data_es;               /* udr0 i/o data */
} volatile uart_t;


/* puntero a la estructura de los registros del periferico */
uart_t *puerto_serial = (uart_t *) (0xc0);

#define USART_BAUDRATE              9600
#define BAUD_PRESCALE               (((F_CPU/(USART_BAUDRATE*16UL)))-1)   // UBRR (Baud Rate Register) 
#define DISABLE_PARITY_MODE         ((UCSR0C_UPM01 & ~UCSR0C_UPM01) | (UCSR0C_UPM00 & ~UCSR0C_UPM00))
#define ONE_STOP_BIT                (UCSR0C_USBS0 & ~UCSR0C_USBS0)
#define CHAR_SIZE_8_BITS            (UCSR0C_UCSZ01 | UCSR0C_UCSZ00)
#define ASYNCHRONOUS_MODE           ((UCSR0C_UMSEL01 & ~UCSR0C_UMSEL01) | (UCSR0C_UMSEL00 & ~UCSR0C_UMSEL00))

// configuracion del usart
#define USART_MODE      ASYNCHRONOUS_MODE           /* Habilitar la recepción */
#define RX_ENABLE       UCSR0B_RXEN0                /* Habilitar la recepción */
#define TX_ENABLE       UCSR0B_TXEN0                /* Habilitar la transmisión */
#define PARITY_MODE     DISABLE_PARITY_MODE         /* No usar bit de paridad */
#define STOP_BITS       ONE_STOP_BIT                /* Usar 1 bit de stop */
#define CHAR_SIZE       CHAR_SIZE_8_BITS            /* Usar 8 bits de dato de E/S */

// estados
#define READY_TO_READ   UCSR0A_RXC0                 /* Dato listo para leer */
#define READY_TO_WRITE  UCSR0A_UDRE0                /* Búfer listo para escribir */

#define MAX_INT_DIGITS  5
#define MAX_LONG_DIGITS 10

/* Máximo entre dos números */
#define MAX(a,b) ((a) < (b) ? (b) : (a))

/* Mínimo entre dos números */
#define MIN(a,b) ((a) < (b) ? (a) : (b))

// PAGINA 149 ATMEGA328 -- RUTINA INICIALIZACION
// PAGINA 159 ATMEGA328 -- REGISTROS DEL HARDWARE
void serial_init() {

	/* Escribir una rutina de inicializacion */

	/* El manual del atmega328p tiene un ejemplo. Adecuarla a C y
           la estructura de datos */

	/* Configurar los registros High y Low con BAUD_PRESCALE */
	/* Configurar un frame de 8bits, con un bit de paridad y bit de stop */
	/* Activar la recepcion y transmicion */

    /* Escribir una rutina de inicializacion */
    /* El manual del atmega328p tiene un ejemplo. Adecuarla a C y
    la estructura de datos */
    /* Configurar los registros High y Low con BAUD_PRESCALE */

    /* Configuracion: 9600bps, 8bits data, 1bit stop, sin bit de paridad
    8 bits de datos: b2:UCSZn2 = 0 en UCSRnB, b2:UCSZn1 = 1 y b1:UCSZn0 = 1 en UCSRnC
    1 bit de stop: b3:USBSn = 0 en UCSRnC
    sin bit de paridad: b5:UPMn1 = 0 y b4:UMPn0 = 0 en UCSRnC 
    */

    puerto_serial->baud_rate_l = (unsigned char) (BAUD_PRESCALE);
    puerto_serial->baud_rate_h = (unsigned char) (BAUD_PRESCALE >> 8);

    /* Configurar un frame de 8bits, con un bit de paridad y bit de stop */
    puerto_serial->status_control_c = (unsigned char) (USART_MODE | PARITY_MODE | STOP_BITS | CHAR_SIZE);

    /* Activar la recepcion y transmicion */
    puerto_serial->status_control_b = (unsigned char) (RX_ENABLE | TX_ENABLE | (UCSR0B_UCSZ02 & ~UCSR0B_UCSZ02));
}


/* enviar un byte a traves del del dispositivo inicializado */
void serial_put_char(char c)
{
    /* Wait until the transmitter is ready for the next character. */

    /* completar con E/S programada */
    /* Se debe esperar verificando el bit UDREn del registro UCSRnA,
       hasta que el buffer esté listo para recibir un dato a transmitir */

    // while ( /* completar con E/S programada */ )
    //     ;

    /* Send the character via the serial port. */
    /* (escribir el dato al registro de datos de E/S */


    /* Wait for empty transmit buffer */
    // el dispositivo esta listo para transmitir y
    // el buffer esta vacio
    while (! (puerto_serial->status_control_a & READY_TO_WRITE));

    /* Put data into buffer, sends the data */
    puerto_serial->data_es = c;
}


char serial_get_char(void)
{
    /* Wait for the next character to arrive. */
    /* Completar con E/S programada similar a serial_put_char pero 
       utilizando el bit correcto */
    
    // while ( /* completar con E/S programada */ )
    //     ;

    // return /* DEBE devolver el valor que se encuentra en el registro de datos de E/S */

    /* Wait for data to be received */
    while (! (puerto_serial->status_control_a & READY_TO_READ));

    /* Get and return received data from buffer */
    return puerto_serial->data_es;
}

void serial_put_string(const char* str) {
    while (*str) {
        serial_put_char(*str++);
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
