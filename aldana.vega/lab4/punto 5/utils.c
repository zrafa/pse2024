
/* utils.c - funciones de soporte al programa principal */


#define PIN  0b00000100

/* puertos de E/S */

/* direccion de PORTB (registro de datos) */
volatile unsigned char * puerto_b = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_b = (unsigned char *) 0x24;


void init() 
{
    *(puerto_b) &= PIN;
    *(ddr_b) |= PIN;
}

void on() 
{
    *(puerto_b) |= PIN;
}

void off() 
{
    *(puerto_b) &= ~PIN;
}

inline void tone(int frecuencia,long int duracion)
{//duracion en ms	
	long double us = 1000000.0 / frecuencia;
	duracion *= 1000L;
	unsigned long i;
	if (frecuencia <= 0) {
    	delay_us(duracion);
  	}else{
		for(i = 0; i < duracion; i += us){
			on();
			delay_us(us / 2);
			off();
			delay_us(us / 2);
		}
  	}
}

inline void tone2(int frecuencia)
{	
	long double periodo = 1000000.0 / frecuencia;
	on();
	delay_us(periodo / 2);
	off();
	delay_us(periodo / 2);
}

inline double map(int val, int minInp, int maxInp,int minOut, int maxOut)
{
	double res;
	res = (double) val / maxInp;
	res = res * (maxOut - minOut);
	res = minOut + res;
	
	return res;
}

inline void delay_us(volatile int us)
{
   //PARA 16MHZ 
	while(us--){
        asm volatile (
            "nop" "\n\t"
			"nop" "\n\t"
			"nop" "\n\t"
		);
    }
}

inline void delay_ms(volatile int ms)
{
   //PARA 16MHZ 
	while(ms--){
         delay_us(1000);
    }  
}