/**
 * @file serial.h
 * @author Diego Pablo Matías Baltar <diego.baltar@est.fi.uncoma.edu.ar>
 * @brief Driver del UART del atmega328p
 * @date 2024-05-01
 *
 * API para la aplicacion embebida.
 * META: ocultar el hardware a la aplicacion.
 */

#ifndef _SERIAL_H
#define _SERIAL_H


void serial_init(void);
void serial_put_char(char c);
char serial_get_char(void);


#endif /* _SERIAL_H */
