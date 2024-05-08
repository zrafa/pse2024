
/* utils.c - funciones de soporte al programa principal */

/* puertos de E/S */

/* direccion de PORTB (registro de datos) */
volatile unsigned char * puerto_b = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_b = (unsigned char *) 0x24;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * pin_b = (unsigned char *) 0x23;


void esperar() 
{
        volatile unsigned long i;
	for (i=0; i<450000; i++);
} 

void init()
{
//Trigger está en el bit 1 y echo en el bit 0 del puerto B
//Trigger se setea como salida y echo como entrada
        *(puerto_b) &= 0b0;
        *(ddr_b) |= 0b00000010;
}

void trig_on()
{
        *(puerto_b) = 0b00000010;
}

void trig_off()
{
        *(puerto_b) = 0b00000000;
}

void echo_on()
{
        *(puerto_b) = 0b00000001;
}

void echo_off()
{
        *(puerto_b) = 0b00000000;
}

int leer_echo()
{
        return (*pin_b & 0b00000001);
}