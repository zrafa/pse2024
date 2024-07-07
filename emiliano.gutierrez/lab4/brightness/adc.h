/**********************************************************************
 *
 * Filename:    adc.h
 * 
 * API para la aplicacion embebida 
 * META : ocultar el hardware a la aplicacion 
 *
 **********************************************************************/

#ifndef _ADC_H
#define _ADC_H

void adc_init(void);
void adc_disable_dig(char);
char conv_state(void);
char adif_check(void);
int adc_get(char);

#endif /* _ADC_H */
