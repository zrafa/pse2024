
/* utils.c - funciones de soporte al programa principal */

/* Enciende y apaga un led conectado al puerto B bit 5 de un atmega328p
 * El puerto B de un atmega328p tiene los bits 0-5 mapeados a los
 * pines 8-13 de arduino
 */

/* máscara de bits para el pin GPIO que controla el led rojo */
#define LED_ROJO (0x20) /* 0b00100000 */

/* puertos de E/S */

/* direccion de PORTB (registro de datos) */
volatile unsigned char * puerto_b = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_b = (unsigned char *) 0x24;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * pin_b = (unsigned char *) 0x23;


void esperar()
{
  volatile unsigned long i;
  /* delay de aprox. 1 segundo */
  for (i=0; i<450000; i++);
}

/* led_init: configura el puerto b bit 5 como salida */
void led_init()
{
  /* turn the GPIO pin voltage off
   * (this should be done before the pins are configured)
   */
  *(puerto_b) = *(puerto_b) & (~LED_ROJO);

  /* make sure the LED control pin is set to operate as OUTPUT */
  *(ddr_b) = *(ddr_b) | (LED_ROJO);
}

/* led_on: enciende el led conectado al puerto b bit 5 */
void led_on()
{
  unsigned char valor_b;

  valor_b = *(puerto_b);
  valor_b |= LED_ROJO;
  *(puerto_b) = valor_b;
}

/* led_off: apaga el led conectado al puerto b bit 5 */
void led_off()
{
  unsigned char valor_b;

  valor_b = *(puerto_b);
  valor_b &= (~LED_ROJO);
  *(puerto_b) = valor_b;
}
