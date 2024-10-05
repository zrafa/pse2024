/**********************************************************************
 *
 * Filename:    serial.h
 * 
 * API para la aplicacion embebida 
 *
 * META : ocultar el hardware a la aplicacion 
 *
 **********************************************************************/

#ifndef _AVR_SERIAL_H
#define _AVR_SERIAL_H

void kserial_init(void);
void kserial_put_char(char outputChar);
char kserial_get_char(void);
void kserial_put_str(char * outputStr);
char* kserial_get_str(void);


#endif /* _AVR_SERIAL_H */
