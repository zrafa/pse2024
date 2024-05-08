inline void esperar_10us(int n)
{       
    for (volatile unsigned int j = 0;j<n;j++){    
        for (unsigned char i = 0;i<=1;i++){
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
	}
}

inline void esperar_100us(int n)
{
    for (volatile unsigned int j = 0;j<n;j++){
        for (volatile unsigned int i = 1; i<20;i++){
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
	}
}

inline void esperar_1ms(int n)
{       
    for (volatile unsigned int j = 0;j<n;j++){
        for (volatile unsigned int i = 1; i<200;i++){
  	        asm volatile ("nop" "\n\t"
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
	}
}
