/**
 * Ejercicio knight_rider: Conecte 5 leds a 5 pines controlados por el puerto B.
 * Desarrollar un programa que genere el efecto del knight_rider.
 *
 * El puerto B de un atmega328 tiene los bits 0-5 mapeados a los pines 8-13 de
 * arduino.
 */

/* Número de ciclos de decremento y prueba */
#define CYCLES_PER_MS (450)

/* Máscara de bits para los pines GPIO que controlan los leds */
#define LEDS (0x3F) /* 0b00111111 */

/* Tiempo entre cada efecto (ms) */
#define EFFECTS_DELAY (60)

/* Cantidad de efectos */
#define NUM_EFFECTS (8)

/* Datos del efecto knight_rider */
unsigned char effects[] = {
  0b00000001,
  0b00000011,
  0b00000111,
  0b00001110,
  0b00011100,
  0b00111000,
  0b00110000,
  0b00100000
};

/* Dirección de PORTB (registro de datos) */
volatile unsigned char *port_b = (unsigned char*) 0x25;

/* Dirección de DDRB (registro de control) */
volatile unsigned char *ddr_b = (unsigned char*) 0x24;

/* Dirección PINB (registro de datos de entrada) */
volatile unsigned char *pin_b = (unsigned char*) 0x23;

void delay_ms(int milliseconds)
{
  volatile unsigned long cycles = (milliseconds * CYCLES_PER_MS);

  while (cycles != 0)
    cycles--;
  /*volatile unsigned long i;
  for (i=0; i<450000; i++);*/
}

void init_leds()
{
  *port_b = *port_b & ~LEDS; //Apagar los bits de los LEDS
  *ddr_b = *ddr_b | LEDS; //Configurar los pines como SALIDA
}

int main(void)
{
  init_leds();

  while (1) {
    for (int i = 0; i < NUM_EFFECTS; i++) {
      *port_b = (*port_b & ~LEDS) | effects[i];
      delay_ms(EFFECTS_DELAY);
    }

    for (int i = NUM_EFFECTS-1; i >= 0; i--) {
      *port_b = (*port_b & ~LEDS) | effects[i];
      delay_ms(EFFECTS_DELAY);
    }
  }
}


