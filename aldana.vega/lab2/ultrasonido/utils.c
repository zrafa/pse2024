
/* utils.c - funciones de soporte al programa principal */

/* Enciende y apaga un led conectado al puerto B bit 5 de un atmega328p
 * El puerto B de un atmega328p tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */



/* puertos de E/S */

/* direccion de PORTB (registro de datos) */
volatile unsigned char * puerto_d = (unsigned char *) 0x28;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_d = (unsigned char *) 0x2A;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * pin_d = (unsigned char *) 0x29;


void esperar() {
	volatile unsigned long i;
	for (i=0; i<450000; i++);
}


void init() {
    volatile unsigned char *DDR_D = (unsigned char *) 0x2A;
    volatile unsigned char *PUERTO_D = (unsigned char *) 0x28;
//Trigger está en el bit 7 y echo en el bit 6 del puerto D
//Trigger se setea como salida y echo como entrada

    *(PUERTO_D) &= 0b0;
    *(DDR_D) |= 0b10000000;
}

void trig_on(){
        *(puerto_d) = 0b1000000 ;
}

void trig_off(){
        *(puerto_d) = 0b0000000 ;
}

void echo_on(){
        *(puerto_d) = 0b0100000 ;
}

void echo_off(){
        *(puerto_d) = 0b0000000 ;
}

int leer_echo(){
        return *pin_d;
}