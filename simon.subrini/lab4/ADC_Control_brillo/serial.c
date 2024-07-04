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


#define RX_E           (1 << UCSR0B_RXEN0)  /* Habilitar la recepción */
#define TX_E           (1 << UCSR0B_TXEN0)  /* Habilitar la transmisión */
#define PARITY_MODE    (0 << UCSR0C_UPM00)  /* No usar bit de paridad */
#define STOP_BITS      (0 << UCSR0C_USBS0)  /* Usar 1 bit de stop */
#define CHAR_SIZE      (3 << UCSR0C_UCSZ00) /* Usar 8 bits de dato de E/S */
#define READY_TO_READ  (1 << UCSR0A_RXC0)   /* Dato listo para leer */
#define READY_TO_WRITE (1 << UCSR0A_UDRE0)  /* Búfer listo para escribir */

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU/(USART_BAUDRATE*16UL)))-1)


typedef struct
{
        uint8_t status_control_a; /* ucsr0a USART Control and Status A */
        uint8_t status_control_b; /* ucsr0b USART Control and Status B */
        uint8_t status_control_c; /* ucsr0c USART Control and Status C */
        uint8_t _reserved; /* espacio sin utilizar */
        uint8_t baud_rate_l; /* ubrr0l baud rate low */;
        uint8_t baud_rate_h; /* ubrr0h baud rate high */
        uint8_t data_es; /* udr0 i/o data */


} volatile uart_t;

/* puntero a la estructura de los registros del periferico */
uart_t *puerto_serial = (uart_t *) (0xc0);

void serial_init() {
        puerto_serial->baud_rate_h = (uint8_t)(BAUD_PRESCALE >> 8);
        puerto_serial->baud_rate_l = (uint8_t)(BAUD_PRESCALE);
        
        puerto_serial->status_control_b = RX_E | TX_E;

        puerto_serial->status_control_c = CHAR_SIZE | STOP_BITS | PARITY_MODE;
}


void serial_put_char (char c)
{  
        while (!(puerto_serial->status_control_a & READY_TO_WRITE));
        puerto_serial->data_es = c;
}

void serial_put_str (char * str)
{
    char * string = str;    
    while (*string != 0) {
        serial_put_char(*string);  
        string++;
    }      
}

void serial_put_int (int val, int dig)
{
    char num[8];
    int i = 0;
    int resto = 0;
    int cifra = 0;
    int aux = 0;
    cifra = val;
    aux = val;
    
    for (i = 0; i <= dig - 1; i++) {
        resto = cifra % 10;
        cifra = 0x30 + resto; // 0x30 es el 0 en ascii
        num[i] = cifra;
        aux /= 10;
        cifra = aux;
    }
    
    for (i = dig - 1; i >= 0; i--) {
        serial_put_char(num[i]); 
    }
}

char serial_get_char(void)
{
        while (!(puerto_serial->status_control_a & READY_TO_READ));
        return puerto_serial->data_es;
}


