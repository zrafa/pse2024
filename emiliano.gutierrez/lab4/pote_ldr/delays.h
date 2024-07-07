/*inline void esperar_1us(int n)
{       
    for (volatile unsigned int j = 0;j<n;j++){    
        for (unsigned char i = 0;i<=1;i++){
  	        asm volatile ("nop" "\n\t");
		}
	}
}*/

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

inline void delay_ms(float n)
{
    float aux = n;
    int ms = aux;
    aux = 10*(aux - ms);
    int c_us = aux;
    aux = 10*(aux - c_us);
    int d_us = aux;
    /*aux = 10*(aux - d_us);
    int u_us = aux;
    
    
    esperar_1us(u_us);*/
    esperar_10us(d_us);
    esperar_100us(c_us);
    esperar_1ms(ms);
}
