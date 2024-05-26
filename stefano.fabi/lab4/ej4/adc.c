/**********************************************************************
 *
 * adc.c - Driver del ADC del atmega328p
 * PAGINA 205 DEL ATMEGA328P DATASHEET
 * 
 * META : ocultar el hardware a la aplicacion 
 *
 **********************************************************************/

#include <stdint.h> /* para los tipos de datos. Ej.: uint8_t */
#include "adc.h"

/* ADCSRA - ADC Control and Status Register A */
#define ADPS0       (1 << 0)           /* Bit 0 - ADPS0: ADC Prescaler Select Bits */
#define ADPS1       (1 << 1)           /* Bit 1 - ADPS1: ADC Prescaler Select Bits */
#define ADPS2       (1 << 2)           /* Bit 2 - ADPS2: ADC Prescaler Select Bits */
#define ADIE        (1 << 3)           /* Bit 3 - ADIE: ADC Interrupt Enable */
#define ADIF        (1 << 4)           /* Bit 4 - ADIF: ADC Interrupt Flag */
#define ADATE       (1 << 5)           /* Bit 5 - ADATE: ADC Auto Trigger Enable */
#define ADSC        (1 << 6)           /* Bit 6 - ADSC: ADC Start Conversion */
#define ADEN        (1 << 7)           /* Bit 7 - ADEN: ADC Enable */

/* ADMUX - ADC Multiplexer Selection Register */
#define MUX0        (1 << 0)           /* Bit 0 - MUX0: Analog Channel Selection Bits */
#define MUX1        (1 << 1)           /* Bit 1 - MUX1: Analog Channel Selection Bits */
#define MUX2        (1 << 2)           /* Bit 2 - MUX2: Analog Channel Selection Bits */
#define MUX3        (1 << 3)           /* Bit 3 - MUX3: Analog Channel Selection Bits */
#define RES0_       (1 << 4)           /* Bit 4 - Res: Reserved Bit */
#define ADLAR       (1 << 5)           /* Bit 5 - ADLAR: ADC Left Adjust Result */
#define REFS0       (1 << 6)           /* Bit 6 - REFS0: Reference Selection Bits */
#define REFS1       (1 << 7)           /* Bit 7 - REFS1: Reference Selection Bits */

#define AREF_WITH_INTERNAL_VREF_TURNED_OFF              ((REFS0 & ~REFS0) | (REFS1 & ~REFS1))
#define AVCC_WITH_EXTERNAL_CAPACITATOR                  (REFS0 | (REFS1 & ~REFS1))
#define INTERNAL_1_1V_WITH_EXTERNAL_CAPACITATOR         (REFS0 | REFS1) 

/* ADC Prescaler Selections */
#define ADC_PS_2    ((ADPS0 & ~ADPS0) | (ADPS1 & ~ADPS1) | (ADPS2 & ~ADPS2))
#define ADC_PS_4    ((ADPS0 & ~ADPS0) | ADPS1 | (ADPS2 & ~ADPS2))
#define ADC_PS_8    (ADPS0 | ADPS1 | (ADPS2 & ~ADPS2))
#define ADC_PS_16   ((ADPS0 & ~ADPS0) | (ADPS1 & ~ADPS1) | ADPS2)
#define ADC_PS_32   (ADPS0 | (ADPS1 & ~ADPS1) | ADPS2)
#define ADC_PS_64   ((ADPS0 & ~ADPS0) | ADPS1 | ADPS2)
#define ADC_PS_128  (ADPS0 | ADPS1 | ADPS2)

/* Input Channel Selections */
#define ADC0   0x00
#define ADC1   0x01
#define ADC2   0x02
#define ADC3   0x03
#define ADC4   0x04
#define ADC5   0x05
#define ADC6   0x06
#define ADC7   0x07
#define ADC8   0x08     /* For temperature sensor */
/* 0x09:0x0D Reserved */
#define ADCVBG 0x0E
#define ADCGND 0x0F

#define START_CONVERSION (ADSC)


/* Estructura de datos del driver ADC 
 * PAGINA 217 DEL ATMEGA328P DATASHEET
 */

typedef struct
{
        uint8_t adcl;                   /* ADC Data Register Low */
	uint8_t adch;                   /* ADC Data Register High */
        uint8_t adcsra;                 /* ADCSRA – ADC Control and Status Register A */
        uint8_t adcsrb;                 /* ADCSRB – ADC Control and Status Register B */
        uint8_t admux;                  /* ADMUX – ADC Multiplexer Selection Register */

        uint8_t _reserved;              /* espacio sin utilizar */

        uint8_t didr0;                  /* DIDR0 – Digital Input Disable Register 0 */
        //uint8_t didr1;                /* ADMUX – ADC Multiplexer Selection Register */

} volatile adc_t;

volatile adc_t *adc = (adc_t *) (0x78);         /* direccion del primer registro */

void adc_init()
{
        /* Configurar los registros ADMUX y ADCSRA para utilizar el voltaje
        de vcc con capacitor externo y encender (habilitar) el periferico */
        adc->admux = AVCC_WITH_EXTERNAL_CAPACITATOR | ADLAR;

        // habilitar el ADC
        adc->adcsra |= ADEN;
        
        /* Establecer tambien el prescalar para lograr un valor acorde (divisor) */
        adc->adcsra |= ADC_PS_32;
}

int adc_read(char channel)
{
        /* 1. Selects which analog input is connected to the ADC */
        adc->admux |= channel;

        /* 2. Write this bit to one to start each conversion */
        adc->adcsra |= START_CONVERSION;         // Este bit se borrará cuando se complete la conversión.

        /* 3. When conversion is complete, it returns to zero */
        while (adc->adcsra & START_CONVERSION);

        /* 4. When conversion is complete, read the data register */
        /* IMPORTANT: ADCL must be read first, then ADCH */
        //int read_value = adc->adcl;
        //read_value |= adc->adch << 8;

        int read_value = adc->adch;
        
	/* return the value */
        return read_value;
}
