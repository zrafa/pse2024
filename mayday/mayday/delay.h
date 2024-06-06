
#define MODE_4MHZ	4000000UL
#define MODE_16MHZ	16000000UL
/*
 * delay_us: realiza una espera de n microsegundos.
 */
inline void delay_us(void)
{

	#if F_CPU == MODE_4MHZ
        
        //for (int i = 0; i < n; i++) {

  	        asm volatile ("nop" "\n\t"
			      "nop" "\n\t"
			    );
        //}

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
