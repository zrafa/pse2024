
#include <xinu.h>

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
	while (encendido && (! izquierda())) {
		enceder_motor(IZQ);
		sleems(100);

		if (! encendido) {
			motor_stop();
			return;
		}
	}
}

void brazo(void) {

	while(1) {

	if (encendido) {
		mover_init();

		for (i=1; i<DIAS; i++) {
			mover();
			esperar(MEDIA_HORA);

			mover();
			esperar(MEDIA_HORA);

			mover();
			esperar(MEDIA_HORA);
			
			dias = i;
			
			esperar(UN_DIA);
		}
	}
	}


}

