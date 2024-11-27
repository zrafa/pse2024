
#include <xinu.h>
#include "globals.h"
// #include "serial.h"

#define DIAS 18
#define IZQ 0
#define DER 1
#define CENTRO 2

// #define MEDIA_HORA 1800  	/* media hora son 1800 segundos */
// #define UN_DIA 81000		/* un dia de 22.5 horas son 81000 segundos */

#define MEDIA_HORA 10		/* 10 segundos */
#define UN_DIA 10		/* 10 segundos */


int posicion;

void mover_init(void) {
	// serial_put_str("start\n\r");
	while (encendido && (!motor_izq()));

	posicion = IZQ;
}

void esperar(int duracion) {
	int n = 0;

	// serial_put_str("esperar\n\r");
	while (encendido && (n < duracion)) {
		sleep(1);
		n++;
	}

}

void mover(void) {
	int fin;

	// serial_put_str("mover\n\r");
	if (posicion == IZQ) {
		while (encendido) {
			fin = motor_der();
			if (fin) {
				posicion = DER;
				return;
			}

			sleepms(100);
		}
	} else {	// DER
		while (encendido) {
			fin = motor_izq();
			if (fin) {
				posicion = IZQ;
				return;
			}
			sleepms(100);
		}
	}
}

void brazo(void) {
	int i;

	while (1) {

	   if (encendido) {
		estado = START;
		//mover_init();
		posicion = DER;
		for (i=1; i<DIAS; i++) {
			dia = i;

			estado = MOVIENDO;
			mover();
			estado = ESPERANDO;
			esperar(MEDIA_HORA);

			estado = MOVIENDO;
			mover();
			estado = ESPERANDO;
			esperar(MEDIA_HORA);

			estado = MOVIENDO;
			mover();
			estado = ESPERANDO;
			esperar(MEDIA_HORA);
			
			estado = ESPERANDO_1_DIA;
			// serial_put_str("esperamos dia\n\r");
			esperar(UN_DIA);
		}
		estado = APAGADO;
	   }
	   serial_put_str("14");
	   sleepms(2000);
	 }
}

