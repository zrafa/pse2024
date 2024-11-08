/*
 * ultrasound: driver de ultrasonido
 */

/* 
 * get_distance: devuelve la distancia (en cm) del objeto enfrente.
 */
#define __DELAY_BACKWARD_COMPATIBLE__
#define F_CPU   4000000UL
#include <util/delay.h>
#include "gpio.h"

// #define TIME_OUT_US 36000
#define TIME_OUT_US 32000
#define TRIGGER_PULSE_WIDE_US 10
#define TIME_DISTANCE_RELATION 58
#define TIME_BETWEEN_SCANS_US 5


int ultrasound_get(int trig, int echo)
{
    int cm;
    int tiempo; 

    gpio_output(trig);

    //Pulso de 10us para la señal de trigger
    gpio_pin(trig, ON);
    _delay_us(TRIGGER_PULSE_WIDE_US);
    gpio_pin(trig, OFF); 

    gpio_input(echo);
    //Echo lee la señal
    tiempo = 0;
    while (gpio_pin(echo, GET) == 0);
    while ((gpio_pin(echo, GET) != 0) && (tiempo < TIME_OUT_US)) {//Espera a que el pin cambie de estado
        _delay_us(TIME_BETWEEN_SCANS_US);
        tiempo += TIME_BETWEEN_SCANS_US;
    }
        
    //Calculo de la distancia
    if (tiempo >= TIME_OUT_US) {
        cm = -1;
    } else {
        cm = tiempo / TIME_DISTANCE_RELATION;
    }   
 

    return cm;
}

