
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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INT_DIGITS 5
#define MAX_LONG_DIGITS 10


/* Completar la estructura de datos para que se superponga a los registros
   del periferico de hardware del USART del atmega328, segun sugerido
   en el apunte */

typedef struct
{
    uint8_t status_control_a;    /* ucsr0a USART Control and Status A */
    uint8_t status_control_b;    /* ucsr0a USART Control and Status B */
    uint8_t status_control_c;    /* ucsr0a USART Control and Status C */
    uint8_t reserved;
    uint8_t baud_rate_l; /*ubrr0l USART baud rate register low*/
    uint8_t baud_rate_h; /*ubrr0h USART baud rate register high*/
    uint8_t data_es;    /* udr0 i/o data */

} volatile uart_t;

/* puntero a la estructura de los registros del periferico */
uart_t *puerto_serial = (uart_t *) (0xc0);

#define F_CPU 16000000UL
#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU/(USART_BAUDRATE*16UL)))-1)

//Máscara de bits
#define RECEIVER_ENABLE 0x10 /* RXEN0 Habilitar la recepcion 0b0001 0000*/
#define TRANSMITTER_ENABLE 0x08 /* TXEN0 Habilitar la transmicion 0b0000 1000*/
#define CHARACTER_SIZE_0 0x02 /* UCSZ00 Numero de bits del dato de e/s 0b0000 0010*/
#define CHARACTER_SIZE_1 0x04 /* UCSZ01 Numero de bits del dato de e/s 0b0000 0100*/
#define READY_TO_READ 0x80 /* RXC0 Dato listo para leer 0b1000 0000*/
#define READY_TO_WRITE 0x20 /* UDRE0 Buffer vacio listo para escribir 0b0010 0000*/


void serial_init() 
{
    /* Configurar los registros High y Low con BAUD_PRESCALE */
    puerto_serial->baud_rate_h = (unsigned char) (BAUD_PRESCALE>>8);
    puerto_serial->baud_rate_l = (unsigned char) BAUD_PRESCALE;

    /* Configurar un frame de 8bits, con un bit de paridad y bit de stop 0b00  0110 */
    puerto_serial->status_control_c = (unsigned char) (CHARACTER_SIZE_0 | CHARACTER_SIZE_1); 

    /* Activar la recepcion y transmicion */
    puerto_serial->status_control_b = (unsigned char) (RECEIVER_ENABLE | TRANSMITTER_ENABLE);
}


/* enviar un byte a traves del del dispositivo inicializado */
void serial_put_char (char c)
{
    while (!((puerto_serial->status_control_a) & READY_TO_WRITE));

    puerto_serial->data_es = c;
}


char serial_get_char(void)
{
    while (!((puerto_serial->status_control_a) & READY_TO_READ));

    return (puerto_serial->data_es);
}

void serial_put_str (char *str)
{
    while (*str != '\0') {
        serial_put_char(*str);
        str++;
    }   
}

void serial_put_int (int valor, int cant_digitos)
{
    int i;
    char numero [cant_digitos+1];
    itoa(valor,numero,10);
    
    int len = strlen(numero);
    int n = cant_digitos - len;

    for (int i = 0; i < n; i++) {
        memmove(numero + i + 1, numero + i, len); 
        numero[i] = '0';
        len++; 
    }

    numero[len] = '\0';
    serial_put_str(numero);
}

void serial_put_long_int (long int value, int num_digits)
{
	char buffer[MAX_LONG_DIGITS] = {0};
	int i = 0;

	if (value == 0) {
		return serial_put_char('0');
	} else if (value < 0) {
		serial_put_char('-');
		value = -value; // Usar valor absoluto
	}

	while (value != 0) {
		buffer[i] = value % 10;
		value /= 10;
		i++;
	}

	if (num_digits < 1 || num_digits > MAX_LONG_DIGITS)
		num_digits = i;

	for (int j = num_digits - 1; j > -1; j--)
		serial_put_char(48 + buffer[j]);
}