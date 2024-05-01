
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
			delay_ms(100);

			if (pressed()) 
				toggle_counter();
		}
		
		if (is_counter_enable()) 
		{
			next_number();
			delay_ms(300);
		}
    }
}


