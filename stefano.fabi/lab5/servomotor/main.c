#include <stdint.h>
#include "serial.h"
#include "delay.h"
#include "timer.h"

// pagina 100 atmega328p
// nro calculado con la formula del osc del reloj

// informacion
// La frecuencia del PWM debe ser de 50 Hz
// El período de la señal PWM es 1/50 Hz = 20 ms 

// necesitamos configurar el temporizador para que alcance su valor máximo (TOP) cada 20 ms
// top = (f_osc / (prescaler * frec_pwm)) - 1 = (4MHz / (8 / 50Hz))  - 1 = (4000000 / (8 / 50Hz))  - 1 = 9999
// el valor de top es 9999 utilizando un prescaler de 8

#define F_OSC 4000000
#define F_CK 50
#define PRESCALER 8
#define TOP_VALUE ((F_OSC / (PRESCALER * F_CK)) - 1)

int main()
{
	serial_init();

	timer1_init(TOP_VALUE);

	while (1) {
		// Cambiar el valor de OCR1A para controlar el ángulo del servomotor
        // OCR1A = 500; // 1 ms (ángulo mínimo)
        // OCR1A = 750; // 1.5 ms (posición media)
        // OCR1A = 1000; // 2 ms (ángulo máximo)
		timer1_pulse(250);
		delay_ms(1000);

		//timer1_pulse(750);
		//delay_ms(1000);

		timer1_pulse(1500);
		delay_ms(1000);
	}

	return 0;
}
