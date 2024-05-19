/**
 * @file adc.h
 * @author Diego Pablo Matías Baltar <diego.baltar@est.fi.uncoma.edu.ar>
 * @brief Driver para ADC del atmega328p
 * @date 2024-05-19
 */

#ifndef _ADC_H
#define _ADC_H

#include <stdint.h>


void     adc_init(void);
uint16_t adc_read(uint8_t channel);


#endif /* _ADC_H */
