/*
 * ultrasound: programa que controla el HC-SR04 para medir distancias en cm
 */
#include "gpio.h"
#include "delays.h"

#define TRIG 8 //(PB0 - D8)
#define ECHO 9 //(PB1 - D9)

unsigned int cont = 0;
unsigned int distancia = 0;

void init_ultra(void)
{
    gpio_mode(TRIG,"OUTPUT");
    gpio_mode(ECHO,"INPUT");
}

void trig_pulse(void)
{
    gpio_pin(TRIG,"ON");
    esperar_10us(1); 
    gpio_pin(TRIG,"OFF");
}

void medir(void)
{       
    while (gpio_pin(ECHO,"GET") == 0);
    
    cont = 0;
    while (gpio_pin(ECHO,"GET") == 1){
        delay_ms(0.1);
        cont++;
    }
    
    if (cont < 360){
        distancia = cont*100/58;
        serial_put_str("Distancia: ");
        serial_put_int(distancia,3);
        serial_put_str(" cm\r\n");
    }
    else {
        serial_put_str("Fuera de rango\r\n");
    }    
}

int ultrasound(void)
{
    trig_pulse();
    medir();
}

