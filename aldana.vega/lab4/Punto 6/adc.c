/**********************************************************************
 *
 * adc.c - Driver del ADC del atmega328p
 *
 * META : ocultar el hardware a la aplicacion 
 *
 **********************************************************************/

#include <stdint.h> /* para los tipos de datos. Ej.: uint8_t */
#include "adc.h"

#define REFS2 0b01000000
#define ADEN 0b10000000 /*Habilita el ADC*/
#define PRESCALER 0b00000111 /*128*/
#define INICIAR_CONVERSION 0b01000000

/* Estructura de datos del driver ADC */

typedef struct
{
        uint8_t adcl;               /* ADC Data Register Low */
	uint8_t adch;
        uint8_t adcsra;
        uint8_t adcsrb;
        uint8_t admux;
        uint8_t reserved;
        uint8_t didr0; 

} volatile adc_t;

volatile adc_t *adc = (adc_t *) 0x78;/*direccion del primer registro */


void adc_init()
{
        adc->admux |= (unsigned char) (REFS2);
        adc->adcsra = (unsigned char)  ADEN ;

        adc->adcsra |=  PRESCALER;
}

int adc_get(char input)
{
        adc->admux |= input;

        adc->adcsra |= INICIAR_CONVERSION; 

        while (!((adc->adcsra)&(INICIAR_CONVERSION)));
        
        int aux = adc->adcl;
        aux |= (adc->adch<<8);

        return aux;
}
