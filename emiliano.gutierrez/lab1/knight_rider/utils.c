
/* utils.c - funciones de soporte al programa principal */

/* Enciende y apaga un led conectado al puerto B bit 5 de un atmega328p
 * El puerto B de un atmega328p tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */


/* puertos de E/S */

/* direccion de PORTB (registro de datos) */
volatile unsigned char * PORTB = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * DDRB = (unsigned char *) 0x24;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * pin_b = (unsigned char *) 0x23;


#define L0 (0x01) //PB0 - D8
#define L1 (0x02) //PB1 - D9
#define L2 (0x04) //PB2 - D10
#define L3 (0x08) //PB3 - D11
#define L4 (0x10) //PB4 - D12

unsigned char array[] = {0b00010000,0b00001000,0b00000100,0b00000010,0b00000001};
char i = 0;
unsigned char subida = 0x01;
void esperar() {
	volatile unsigned long i;
	for (i=0; i<15000; i++);
}

/* init: configura PB0 a PB4 como salida y PC0 como entrada */
void init() {
	*PORTB = *PORTB & ~(L0|L1|L2|L3|L4);
    *(DDRB) = *(DDRB) | (L0|L1|L2|L3|L4);
}


void knight(){
    if(subida==1){
        *PORTB = array[i];
        esperar();
        i++;}
    else{
        *PORTB = array[i];
        esperar();
        i--;}
    if(i==5){
        subida=0;
        i=3;}
    else if(i==-1){
        subida=1;
        i=1;}
}





