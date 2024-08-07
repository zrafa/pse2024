/**********************************************************************
 *
 * Filename:    serial.h
 * 
 * API para la aplicacion embebida 
 * META : ocultar el hardware a la aplicacion 
 *
 **********************************************************************/

#ifndef _SERIAL_H
#define _SERIAL_H


void serial_init(void);
void serial_put_char(char c);
char serial_rcv_empty(void);
char serial_get_char(void);
void serial_put_str(char * str);
void serial_put_int (int valor, int cant_digitos);
void serial_put_float(float val, int dig, int dec);

#endif /* _SERIAL_H */
