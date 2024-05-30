
#define MODE_4MHZ	4000000UL
#define MODE_16MHZ	16000000UL
/*
 * delay_us: realiza una espera de n microsegundos.
 */
inline void delay_us(int n)
{

	#if F_CPU == MODE_4MHZ

		/* COMPLETAR */
  	    asm volatile ("nop" "\n\t"
			  "nop" "\n\t"
			 );

	#elif F_CPU == MODE_16MHZ

		/* COMPLETAR */
  	    asm volatile ("nop" "\n\t"
			  "nop" "\n\t"
			 );

	#endif
}

inline void delay_ms(int n)
{
	/* COMPLETAR */
}