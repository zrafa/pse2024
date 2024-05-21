
/**********************************************************************
 *
 * serial.c - Driver del UART del atmega328p
 *
 * META : ocultar el hardware a la aplicacion 
 *
 * Confiiguracion: 9600bps, 8bits data, 1bit stop, sin bit de paridad
 *
 **********************************************************************/

#include <stdint.h> /* para los tipos de datos. Ej.: uint8_t */

unsigned char INIT = 0b00000110;
unsigned char EN_RX_TX = 0b00011000;
unsigned char UDRE = 0b00100000;
unsigned char RXC = 0b10000000;

typedef struct
{
    uint8_t status_control_a;    /* ucsr0a USART Control and Status A */
    uint8_t status_control_b;    /* ucsr0b USART Control and Status B */
    uint8_t status_control_c;    /* ucsr0c USART Control and Status C */
    uint8_t reserved;    /* espacio sin utilizar */
    uint8_t baud_rate_l; /* ubrr0l baud rate low */
    uint8_t baud_rate_h; /* ubrr0h baud rate high */

    uint8_t data_es;    /* udr0 i/o data */

} volatile uart_t;

/* puntero a la estructura de los registros del periferico */
uart_t *puerto_serial = (uart_t *) (0xc0);


#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU/(USART_BAUDRATE*16UL)))-1)


void serial_init() {  
    puerto_serial->baud_rate_l = (unsigned char) (BAUD_PRESCALE);
    puerto_serial->baud_rate_h = (unsigned char) (BAUD_PRESCALE>>8);
    /* Activar la recepcion y transmision */
    puerto_serial->status_control_b = (unsigned char) (EN_RX_TX);
    /* Configurar un frame de 8bits, con un bit de paridad y bit de stop */
    puerto_serial->status_control_c = (unsigned char) (INIT);
}

void serial_put_char (char c)
{
    while (!((puerto_serial->status_control_a) & UDRE));   
    puerto_serial->data_es = c;    
}

char serial_get_char(void)
{
    while ((!(puerto_serial->status_control_a) & RXC));       
    return puerto_serial->data_es;
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
