#include <stdint.h>
#include "serial.h"
#include "timer.h"

// pagina 100 atmega328p
// nro calculado con la formula del osc del reloj

// informacion
// 1 centesima = 1/100 segundos = 0,01 segundos = 10ms = 100 hz
// el timer1 es de 16 bits, es decir, puede contar hasta 65536

// si utilizamos un prescaler de 64
// f_ck = f_osc/prescaler = 62500 hz
// esto es t = 1/62500 = 16 us = 0,016ms
// esta frecuencia de interrupción generaría una interrupción aproximadamente cada 16us
// es mucho mas rapido que 10ms por lo tanto top_value = 10 / 0,016ms = 625 
// tenemos que contar con el timer hasta 625 y luego en la interrupcion aumentar una centesima

// otra forma vista desde f_ck
// para expresar 1/100 en terminos de frecuencia se hace 1/0,01 = 100 = f_ck
// el temporizador debe generar 100 interrupciones por segundo para cumplir con la solicitud de 
// una interrupción cada 10 milisegundos

// para conocer que prescaler usar hago prescaler = f_osc/f_ck = 40000
// necesitamos configurar el prescaler para que divida la frecuencia del oscilador a 40000
// Esto significa que para reducir la frecuencia del oscilador de 4 MHz a 100 Hz, se necesitaría un divisor o prescaler de 40000.
// no tenemos un prescaler de esta magnitud en el avr-atmega328p (1, 8, 64, 256, 1024)

#define F_OSC 4000000
#define F_CK 100
#define PRESCALER 64
#define TOP_VALUE ((F_OSC / (PRESCALER * F_CK)) - 1)

typedef struct
{
	uint8_t minutes;
	uint8_t seconds;
	uint8_t centiseconds;
} time_t;

volatile time_t time = {0, 0, 0};

void cronometro()
{
	time.centiseconds++;

	if (time.centiseconds >= 100) {
		time.centiseconds = 0;
		time.seconds++;

		if (time.seconds >= 60) {
			time.seconds = 0;
			time.minutes++;
				
			if (time.minutes >= 60) {
				time.minutes = 0;
			}
		}
	}
}

int main()
{
	serial_init();

	timer1_init(TOP_VALUE, cronometro);

	while (1) {
		serial_put_int(time.minutes, 2);
		serial_put_char(':');
		serial_put_int(time.seconds, 2);
		serial_put_char(':');
		serial_put_int(time.centiseconds, 2);
		serial_put_str("\r");
	}

	return 0;
}
