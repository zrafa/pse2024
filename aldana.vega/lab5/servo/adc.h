/**********************************************************************
 *
 * Filename:    adc.h
 * 
 * API para la aplicacion embebida 
 **********************************************************************/

#ifndef _ADC_H

#define CHANNEL_MASK 0b00000111

#define REF_5V 1
#define REF_1_1V 2
#define REF_EXTERNAL 3

// CONTROL AND STATUS
#define ADEN 7
#define ADSC 6
#define ADATE 5
#define ADIF 4
#define ADIE 3
#define ADPS2 2
#define ADPS1 1
#define ADPS0 0

// MULTIPLEXER SELECTION
#define REFS1 7
#define REFS0 6
#define ADLAR 5
#define A3 3
#define A2 2
#define A1 1
#define A0 0

// CONFIGS
#define ENABLE (1 << ADEN)
#define PRESCALER_128 (0b111 << ADPS0)
#define START_CONVERSION (1 << ADSC)
#define EXTERNAL_REF (0b00 << REFS0)
#define INTERNAL_VCC (0b01 << REFS0)
#define INTERNAL_1_1V (0b11 << REFS0)

void adc_init(void);

int adc_get(char channel, char ref);

#endif /* _SERIAL_H */
