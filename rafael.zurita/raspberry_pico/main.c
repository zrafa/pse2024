#include <stdint.h>
#include "delaysw.h"

/* LED conectado a gpio 25 */

/* 
 * 0x40014000 es el registro para definir la funcion de cada gpio
 * 0x400140cc es el registro para definir la función del gpio 25
 */
volatile uint32_t * gpio_func = (uint32_t *) (0x40014000 + 0x0cc);

/* registros para operar los GPIO en funcion SIO */
volatile uint32_t * gpio_output_enable = (uint32_t *) (0xd0000000 + 0x024);
volatile uint32_t * gpio_set = (uint32_t *) (0xd0000000 + 0x014);
volatile uint32_t * gpio_clear = (uint32_t *) (0xd0000000 + 0x018);

int main( void ) {

	*gpio_func = 0x05; 	/* 0x05 es la funcion SIO para el gpio 25 */
	*gpio_output_enable |= (1 << 25); 
    
	while (1) {
		*gpio_set |= (1 << 25); 
                delay_sw(50000);
		*gpio_clear |= (1 << 25); 
                delay_sw(50000);
	}
}

