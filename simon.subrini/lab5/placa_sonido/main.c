#include "timer1.h"
#include "serial.h"
#include "gpio.h"
#include <avr/io.h>

#define MAX_VOLTAGE 255
#define V_REF 5
#define OUTPUT_VOLTAGE 1
#define SCALE_FACTOR (OUTPUT_VOLTAGE * MAX_VOLTAGE / V_REF)

volatile uint8_t current_sample = 0;

int main()
{
  serial_init();
  timer1_init();
    
  // Configurar OC1A (PB1) como salida
  gpio_output(9);

  while (1) {
    // Recibir dato del serial
    unsigned char dato = serial_get_char();

    // Escalar el dato para ajustar la tensión media a 1V
    current_sample = (dato * SCALE_FACTOR) / MAX_VOLTAGE;
  }

  return 0;
}

