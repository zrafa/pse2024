
/* simula el efecto knight rider */

/* 
 * El puerto B de un atmega328 tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */

#include "utils.h"

int main(void)
{	
	knight_init();

	while (1) 
	{
        toRight();
        esperar();

        toLeft();
        esperar();
    }
}


