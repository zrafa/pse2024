/**********************************************************************
 *
 * adc.c - Driver del ADC del atmega328p
 *
 * META : ocultar el hardware a la aplicacion 
 *
 **********************************************************************/

#include <stdint.h> /* para los tipos de datos. Ej.: uint8_t */
#include "adc.h"

/* Estructura de datos del driver ADC */

typedef struct
{
        uint8_t adcl;               /* ADC Data Register Low */
	/* COMPLETAR */

} volatile adc_t;

volatile adc_t *adc = (adc_t *) (0x78); /* direccion del primer registro */


void adc_init()
{
        /* Configurar los registros ADMUX y ADCSRA para utilizar el voltaje
        de vcc con capacitor externo y encender (habilitar) el periferico */

        /* Establecer tambien el prescalar para lograr un valor acorde (divisor) */
}

int adc_get(char input)
{
        /* 1. Selects which analog input is connected to the ADC */

        /* 2. Write this bit to one to start each conversion */

        /* 3. When conversion is complete, it returns to zero */

        /* 4. When conversion is complete, read the data register */
        /* IMPORTANT: ADCL must be read first, then ADCH */

	/* return the value */
}
