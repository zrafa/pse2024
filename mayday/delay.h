
/*
 * delay_us: realiza una espera de n microsegundos.
 */

inline void delay_us(int n)
{
	/* COMPLETAR */
  	    asm volatile ("nop" "\n\t"
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

inline void delay_ms(int n)
{
	/* COMPLETAR */
}
