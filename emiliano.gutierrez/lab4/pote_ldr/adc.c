/**********************************************************************
 *
 * adc.c - Driver del ADC del atmega328p
 *
 * META : ocultar el hardware a la aplicacion 
 *
 **********************************************************************/

#include <stdint.h> /* para los tipos de datos. Ej.: uint8_t */

unsigned char START_CONV = 0x40;
unsigned char ADIF = 0x10;
/* Estructura de datos del driver ADC */

typedef struct
{
    uint8_t adcl;
    uint8_t adch;
    uint8_t adcsra; /* ADC Control and Status Register A */
    uint8_t adcsrb;
    uint8_t admux;  /* ADC Multiplexer Selection Register */
    uint8_t reserved;
    uint8_t didr0;
}   volatile adc_t;

/* puntero a la estructura de los registros del periferico */
adc_t * adc = (adc_t *) (0x78);

void adc_init()
{
    /* Configurar los registros ADMUX y ADCSRA para utilizar el voltaje
    de vcc con capacitor externo y encender (habilitar) el periferico */
    adc->admux = (unsigned char) (0b01000000); // inicialmente conecto ADC0
    /* Establecer tambien el prescalar para lograr un valor acorde (divisor) */
    adc->adcsra = (unsigned char) (0b10000111); // 128 de preescaler (111), probar con 32 
    // si el micro tiene 4MHZ (es poner los ultimos 3 bits en 101)
    adc->didr0 = (unsigned char) (0b00000000); //no desactivo pin digital de ADCx
}

void adc_disable_dig(char input)
{ 
    input = 1 << input;
    adc->didr0 |= input;
}

char conv_state(void)
{
    //devuelvo un true cuando termino la conversion
    return !((adc->adcsra) & START_CONV);
}

char adif_check(void)
{
    //devuelvo un true cuando la bandera se levanta (termino la conversion)
    return (adc->adcsra) | ~ADIF;
} 

/* devuelve un valor de 10bits de la conversión ADC entrada input */
int adc_get(char input)
{
    int val;
    /* 1. establecer el multiplexor a la entrada input */
    adc->admux = (adc->admux & 0x40) | input;
    /* 2. iniciar una conversion ADC */
    adc->adcsra |= START_CONV;
    /* 3. completar con E/S programada */
    while(!conv_state());
    /* 4. devolver el valor del registro de datos del ADC (Low y High)*/
    /* IMPORTANTE: hay que leer el registro L antes del H !!! */
    val = adc->adcl;
    val |= (adc->adch) << 8;
    //adc->adcsra |= ADIF; CONSULTAR
    return val;
}
