
#include <xinu.h>
#include "gpio.h"
#include "serial.h"
#include "globals.h"
#include "ultrasound.h"

void motor_init(void)
{
        /* pines de motores, motor stop */
        gpio_pin(MOTOR_DER_PIN, OFF);
        gpio_output(MOTOR_DER_PIN);
        gpio_pin(MOTOR_IZQ_PIN, OFF);
        gpio_output(MOTOR_IZQ_PIN);

}

void motor_stop(void) 
{

        gpio_output(MOTOR_DER_PIN);
        gpio_output(MOTOR_IZQ_PIN);
	gpio_pin(MOTOR_DER_PIN, OFF);
	gpio_pin(MOTOR_IZQ_PIN, OFF);
	serial_put_str("stop\n\r");
}


void mostrar_distancias(int izq, int der)
{
                serial_put_int(izq, 4);
                serial_put_str("  ");
                serial_put_int(der, 4);
                serial_put_str("  \n\r");
}


int motor_izq(void) 
{
	int distancia_izq;
	int distancia_der;
	int res;

	// distancia_izq = ultrasound_get(9,9);
	// distancia_der = ultrasound_get(8,8);
	// distancia_izq = ultrasound_get(8,8);
	disable();
	distancia_izq = ultrasound_get(9,9);
	enable();

	distancia_der = 4;
	if ((distancia_izq > 3) || (distancia_izq == -1)) {
        	gpio_output(MOTOR_IZQ_PIN);
		gpio_pin(MOTOR_IZQ_PIN, ON);
		serial_put_str("izq\n\r");
		res = 0;
	} else {
		motor_stop();
		res = 1;
	}
	mostrar_distancias(distancia_izq, distancia_der);
	return res;
}

int motor_der(void) 
{
	int distancia_izq;
	int distancia_der;
	int res;

	// distancia_izq = ultrasound_get(9,9);
	// distancia_der = ultrasound_get(8,8);
	disable();
	distancia_der = ultrasound_get(6,6);
	enable();


	distancia_izq = 4;
	if ((distancia_der > 3) || (distancia_der == -1)) {
        	gpio_output(MOTOR_DER_PIN);
		gpio_pin(MOTOR_DER_PIN, ON);
		serial_put_str("der\n\r");
		res = 0;
	} else {
		motor_stop();
		res = 1;
	}
	mostrar_distancias(distancia_izq, distancia_der);
	return res;
}

