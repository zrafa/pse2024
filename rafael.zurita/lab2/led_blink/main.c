
/* Enciende y apaga un led conectado al puerto B bit 5 de un atmega328 */

/* 
 * El puerto B de un atmega328 tiene los bits 0-5 mapeados a los pines 8-13 de
 * arduino 
 */

/* mascara para el led en el arduino pro mini */
#define LED_ROJO (0x20) /* 0b00100000 */
#define LED_OFF (0x20)  /* 0b11011111 */

void esperar2(void){
	volatile unsigned long int i;

	for (i=0;i<5000;i++);

}
inline void delayus(void) {

	asm volatile (	"nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
			);

}

int main(void)
{

    volatile unsigned char * puerto_b = (unsigned char *) 0x25;
    volatile unsigned char * ddr_b = (unsigned char *) 0x24; /* direccion de DDR B */

        *puerto_b = *puerto_b & (~LED_ROJO);
	*(ddr_b) = *(ddr_b) | (LED_ROJO);

    while (1) {

        *puerto_b = (*puerto_b) | LED_ROJO;
	delayus();
	//esperar2();
        *puerto_b = *puerto_b & (~LED_ROJO);
        //*puerto_b = (*puerto_b) & LED_OFF;
	delayus();
	//esperar2();
    }

}
