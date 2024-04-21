
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

/* direccion de PORTC (registro de datos) */
volatile unsigned char * PORTC = (unsigned char *) 0x28;

/* direccion de DDR C (registro de control) */
volatile unsigned char * DDRC = (unsigned char *) 0x27;

/* direccion PIN C (registro de datos de entrada) */
volatile unsigned char * pin_c = (unsigned char *) 0x26;

#define L0 (0x01) //PB0 - D8
#define L1 (0x02) //PB1 - D9
#define L2 (0x04) //PB2 - D10
#define L3 (0x08) //PB3 - D11
#define L4 (0x10) //PB4 - D12
#define boton (0x01) //PC0 - A0

unsigned char cont = 0x00;
unsigned char hab = 0xFF;

void esperar() {
	volatile unsigned long i;
	for (i=0; i<112500; i++);
}

/* init: configura PB0 a PB4 como salida y PC0 como entrada */
void init() {
	*PORTB = *PORTB & ~(L0|L1|L2|L3|L4);
    *(DDRB) = *(DDRB) | (L0|L1|L2|L3|L4);
    *(DDRC) = *(DDRC) & ~(boton);
    *PORTC = *PORTC | boton; //Activo resistencia de pull up
}

void pulsador(){
    unsigned char valor = *pin_c & boton;
    if(valor==0){
        hab = ~(hab);
        esperar(); //anti rebote
        }
}

void led_on(){
    if(hab==0xFF){
        *PORTB = cont;
        cont++;
        if (cont==64){
            cont=0;
        }
        esperar();
    }
}





