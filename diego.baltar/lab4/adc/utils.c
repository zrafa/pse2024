#include "utils.h"

/** Máscara de bits para el pin GPIO que controla el led rojo */
#define RED_LED (0x20) /* 0b00100000 */

/* delay_us: espera n microsegundos */
void delay_us(long n)
{
  volatile unsigned long i = n / 2.2; // Ajuste con osciloscopio

  while (i > 0) {
    delay_1us();
    i--;
  }
}

/* delay_ms: espera n milisegundos */
void delay_ms(long n)
{
  volatile unsigned long i = n;

  while (i > 0) {
    delay_us(1000);
    i--;
  }
}

/* led_init: configura el puerto b bit 5 como salida */
void led_init()
{
  // apagar el voltage del pin GPIO
  // esto debe hacerse antes de configurar los pines
  PORTB = PORTB & ~RED_LED;

  // establecer el pin de control del LED para operar como salida
  DDRB = DDRB | RED_LED;
}

/* led_on: enciende el led conectado al puerto b bit 5 */
void led_on()
{
  PORTB |= RED_LED;
}

/* led_off: apaga el led conectado al puerto b bit 5 */
void led_off()
{
  PORTB &= ~RED_LED;
}
