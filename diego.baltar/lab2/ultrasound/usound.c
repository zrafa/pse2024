#include "usound.h"

#define TIMEOUT_US 36000
#define INTRVAL_US 80

/** El pin conectado al "trigger" del sensor */
static unsigned char trig_pin = 0;
/** El pin conectado al "echo" del sensor */
static unsigned char echo_pin = 0;

void usound_init(const unsigned char t_pin, const unsigned char e_pin)
{
  trig_pin = t_pin;
  echo_pin = e_pin;

  USOUND_PORT &= ~((1 << trig_pin) | (1 << echo_pin));
  USOUND_DDR &= ~(1 << echo_pin); // Operar como entrada
  USOUND_DDR |= (1 << trig_pin); // Operar como salida
}

static void usound_trigger()
{
  USOUND_PORT |= (1 << trig_pin);
  delay_us(10);
  USOUND_PORT &= ~(1 << trig_pin);
  delay_us(2);
}

float usound_distance()
{
  unsigned int duration = 0;
  unsigned int echo = 0;

  usound_trigger();
  while (duration <= TIMEOUT_US) {
    delay_us(INTRVAL_US);
    if (USOUND_PIN & echo_pin)
      echo += INTRVAL_US;
    else if (echo > 0) {
      break;
    }

    duration += INTRVAL_US;
  }

  return echo / 58.0;
}
