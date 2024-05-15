#include "delay_us.h"
#include "utils.h"

// MACROS
#define TRIGGER_PIN 0
#define ECHO_PIN 1
#define TRIGGER_PULSE_WIDE_US 10
#define TIME_OUT_US 36000

// VARIABLES GLOBALES
volatile unsigned char *puerto_b = (unsigned char *)0x25;
volatile unsigned char *ddr_b = (unsigned char *)0x24;
volatile unsigned char *pin_b = (unsigned char *)0x23;

// FUNCIONES
void ports_init() {
  *(puerto_b) &= 0;
  *(ddr_b) |= 0b00000001;
}

void start_ranging() {
  set_bit(TRIGGER_PIN, puerto_b);
  delay_us(TRIGGER_PULSE_WIDE_US);
  clear_bit(TRIGGER_PIN, puerto_b);
}

int listening_echo() {
  unsigned int echo_time_us = 0;

  while (!is_on(ECHO_PIN, *pin_b)) {
  }

  while (is_on(ECHO_PIN, *pin_b)) {
    delay_us(10);
    echo_time_us += 10;

    if (echo_time_us >= TIME_OUT_US) {
      break;
    }
  }

  return echo_time_us;
}
