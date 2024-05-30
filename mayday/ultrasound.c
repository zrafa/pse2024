/*
 * ultrasound: driver de ultrasonido
 */

/* 
 * get_distance: devuelve la distancia (en cm) del objeto enfrente.
 */
#include "gpio.h"
#include "delay.h"

#define TIME_OUT_US 36000
#define TRIGGER_PULSE_WIDE_US 10
#define TIME_DISTANCE_RELATION 58
#define TIME_BETWEEN_SCANS_US 5


int ultrasound_get(int trig, int echo)
{
	int cm;
    int tiempo;

	gpio_input(echo);
    gpio_output(trig);

    //Pulso de 10us para la señal de trigger
    gpio(trig,ON);
    delay_us(TRIGGER_PULSE_WIDE_US);
    gpio(trig,OFF); 

    //Echo lee la señal
    tiempo = 0;
    while (gpio(echo,GET) == 0);
    while((gpio(echo,GET) != 0) && (tiempo < TIME_OUT_US)){//Espera a que el pin cambie de estado
        delay_us(TIME_BETWEEN_SCANS_US);
        tiempo += TIME_BETWEEN_SCANS_US;
    }
        
    //Calculo de la distancia
    if(tiempo >= TIME_OUT_US){
        cm = -1;
    }else{
        cm = tiempo / TIME_DISTANCE_RELATION;
    }   

	return cm;
}

