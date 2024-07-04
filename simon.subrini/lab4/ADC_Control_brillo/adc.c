/**********************************************************************
 *
 * adc.c - Driver del ADC del atmega328p
 *
 * META : ocultar el hardware a la aplicacion 
 *
 **********************************************************************/

#include <stdint.h> /* para los tipos de datos. Ej.: uint8_t */
#include "adc.h"

/* ADMUX – ADC Multiplexer Selection Register */
#define ADMUX_REFS1    7
#define ADMUX_REFS0    6
#define ADMUX_ADLAR    5
#define ADMUX_MUX3     3
#define ADMUX_MUX2     2
#define ADMUX_MUX1     1
#define ADMUX_MUX0     0

/* ADCSRA – ADC Control and Status Register A */
#define ADCSRA_ADEN    7
#define ADCSRA_ADSC    6
#define ADCSRA_ADATE   5
#define ADCSRA_ADIF    4
#define ADCSRA_ADIE    3
#define ADCSRA_ADPS2   2
#define ADCSRA_ADPS1   1
#define ADCSRA_ADPS0   0

/* ADCSRB – ADC Control and Status Register B */
#define ADCSRB_ACME    6
#define ADCSRB_ADTS2   2
#define ADCSRB_ADTS1   1
#define ADCSRB_ADTS0   0

/* ADCH – The ADC Data Register */
#define ADCH_ADC9     7
#define ADCH_ADC8     6
#define ADCH_ADC7     5
#define ADCH_ADC6     4
#define ADCH_ADC5     3
#define ADCH_ADC4     2
#define ADCH_ADC3     1
#define ADCH_ADC2     0

/* ADCL – The ADC Data Register */
#define ADCL_ADC1     7
#define ADCL_ADC0     6

#define REFS        (1 << ADMUX_REFS0)   /* Vref VCC */
#define ADLAR       (1 << ADMUX_ADLAR)   /* Justificado a la izq */
#define ADEN        (1 << ADCSRA_ADEN)   /* ADC Enable */
#define ADSC        (1 << ADCSRA_ADSC)   /* Start conversion */
#define ADPS        (7 << ADCSRA_ADPS0)  /* Prescaler selections */

typedef struct
{
        uint8_t adcl;                
        uint8_t adch;
        uint8_t adcsra;
        uint8_t adcsrb;
        uint8_t admux;
        uint8_t _reserved;
        uint8_t didr0;
        uint8_t didr1;

} volatile adc_t;

volatile adc_t *adc = (adc_t *) (0x78);/* direccion del primer registro */


void adc_init()
{
        adc->admux |= REFS | ADLAR;
        adc->adcsra |= ADEN | ADPS;
    
}

int adc_read(char input, char precision)
{
        if (input>8)
                return 0;
        adc->admux |= input;
        adc->adcsra |= ADSC;
        while(adc->adcsra & ADSC);
        
        if (precision == 8){
                return adc->adch;
        }else if (precision == 10){
                char lectura = (adc->adcl)>>6;
                return (((adc->adch)<<2)+lectura);
        }else{
                return 0;
        }
}
