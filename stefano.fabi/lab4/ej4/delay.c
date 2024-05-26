
/**********************************************************************
 *
 * delay.c 
 *
 **********************************************************************/

/* delay_us: espera n microsegundos */
void delay_us(long n)
{
  volatile unsigned long i = n / 2.2; // Ajuste con osciloscopio

  while (i > 0) {
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