/* utils.c - funciones de soporte al programa principal */

/* puertos de E/S */


/* direccion de PORTC (registro de datos) */
volatile unsigned char * puerto_c = (unsigned char *) 0x28;

/* direccion de DDR C (registro de control) */
volatile unsigned char * ddr_c = (unsigned char *) 0x27;

/* direccion PIN C (registro de datos de entrada) */
volatile unsigned char * pin_c = (unsigned char *) 0x26;


/* direccion de PORTB (registro de datos) */
volatile unsigned char * puerto_b = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_b = (unsigned char *) 0x24;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * pin_b = (unsigned char *) 0x23;

void init() 
{
    //Configuracion del pulsador izquierdo en el bit 0 del puerto C
    //Configuracion del pulsador derecho en el bit 1 del puerto C
    *(puerto_c) &= 0;
    *(ddr_c) = 0;
}

/*Enciende el pulsador para leer la entrada*/
void pulsadores_on() 
{
    *(puerto_c) = 0b00000011;
}

//Lee el bit 0 del puerto C
char leer_pin0() 
{
    char aux = *pin_c;
    return (aux & 0b01);
}

//Lee el bit 1 del puerto C
char leer_pin1() 
{
    char aux = *pin_c;
    return (aux & 0b10);
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