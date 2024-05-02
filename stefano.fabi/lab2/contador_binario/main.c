
/* contador binario */
// tutorial anti rebote del boton mecanico
// https://www.geekfactory.mx/tutoriales-arduino/boton-o-pulsador-con-arduino/

#include "utils.h"

int main(void)
{	
	init();

	while (1) 
	{
		if (pressed()) 
		{
			delay_ms(50);

			if (pressed()) 
				toggle_counter();
		}
		
		int expired = 1;

		while (is_counter_enable()) 
		{
			if (expired > 6) {
				next_number();
				expired = 0;
			} else {
				delay_ms(50);
				expired++;
			}

			if (pressed()) 
			{
				delay_ms(50);

				if (pressed()) 
					toggle_counter();
			}
		}
    }
}


