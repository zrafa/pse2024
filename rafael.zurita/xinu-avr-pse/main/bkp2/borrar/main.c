#include <xinu.h>
#include "serial.h"
#include "globals.h"
#include "gpio.h"

#define LED 13

void serial_init(void);
void serial_put_str(const char *str);
void serial_put_int (int v, int cant_digitos);


int encendido;
int dia;

void esperar(int duracion);
void mover(void);
void mover_init(void);

#define DIAS 18
#define IZQ 0
#define DER 1
#define CENTRO 2

// #define MEDIA_HORA 1800  	/* media hora son 1800 segundos */
// #define UN_DIA 81000		/* un dia de 22.5 horas son 81000 segundos */

#define MEDIA_HORA 10		/* 10 segundos */
#define UN_DIA 10		/* 10 segundos */


int posicion;

void main(void) {

	encendido = 0;
	dia = 0;

	serial_init();

	//resume(create(brazo, 256, 20, "bra", 0, NULL));
	resume(create(pulsador_global, 128, 20, "pul", 0, NULL));
	// resume(create(pulsadores, 128, 20, "led", 0, NULL));
	// resume(create(brazo, 128, 20, "bra", 0, NULL));


	int i;

	while (1) {
		/*
	   if (encendido) {
		mover_init();
		for (i=1; i<DIAS; i++) {
			mover();
			esperar(MEDIA_HORA);

			mover();
			esperar(MEDIA_HORA);

			mover();
			esperar(MEDIA_HORA);
			
			dia = i;
			
			serial_put_str("esperamos dia\n\r");
			esperar(UN_DIA);
		}
	   }
	   */
	    serial_put_str("esperamos dia\n\r");
	   sleepms(100);
        }
}



/*
void mover_init(void) {
	while (encendido && (!motor_izq()));

	posicion = IZQ;
}

void esperar(int duracion) {
	int n = 0;

	while (encendido && (n < duracion)) {
		sleep(1);
		n++;
	}

}

void mover(void) {
	int fin;

	if (posicion == IZQ) {
		while (encendido) {
			fin = motor_der();
			if (fin) {
				posicion = DER;
			}

			sleepms(100);
		}
	} else {	// DER
		while (encendido) {
			fin = motor_izq();
			if (fin) {
				posicion = IZQ;
			}
			sleepms(100);
		}
	}
}
*/
