
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

#define USART_BAUDRATE 9600
//#define BAUD_PRESCALE (((F_CPU/(USART_BAUDRATE*16UL)))-1)   // UBRR (Baud Rate Register) 
#define BAUD_PRESCALE 0b00011001        

#define INIT_C 0x06     // 0b00000110
#define INIT_B 0x18     // 0b00011000

#define TXEN0   0b01000000
#define RXCn    0b10000000
#define UDREn   0b00010000

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
    puerto_serial->baud_rate_l = (unsigned char) (BAUD_PRESCALE);
    puerto_serial->baud_rate_h = (unsigned char) (BAUD_PRESCALE >> 8);

    /* Configurar un frame de 8bits, con un bit de paridad y bit de stop */
    puerto_serial->status_control_c = (unsigned char) (INIT_C);

    /* Activar la recepcion y transmicion */
    puerto_serial->status_control_b = (unsigned char) (INIT_B);


    /* Configuracion: 9600bps, 8bits data, 1bit stop, sin bit de paridad
    8 bits de datos: b2:UCSZn2 = 0 en UCSRnB, b2:UCSZn1 = 1 y b1:UCSZn0 = 1 en UCSRnC
    1 bit de stop: b3:USBSn = 0 en UCSRnC
    sin bit de paridad: b5:UPMn1 = 0 y b4:UMPn0 = 0 en UCSRnC 
    */
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
    while (! (puerto_serial->status_control_a & UDREn));

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
    while (! (puerto_serial->status_control_a & RXCn));

    /* Get and return received data from buffer */
    return puerto_serial->data_es;

}



