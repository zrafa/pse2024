/**********************************************************************
 *
 * Filename:    adc.h
 * 
 * API para la aplicacion embebida 
 **********************************************************************/

#ifndef _ADC_H
#define _ADC_H

void adc_init(void);
int adc_get (char channel, char ref);

#endif /* _SERIAL_H */
