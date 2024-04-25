
/* contador binario */

/* 
 * El puerto B de un atmega328 tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */

#include "utils.h"


int main(void)
{	
	init();

	while (1) 
	{
		startSecuence();
    }
}


