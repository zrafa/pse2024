#include "gpio.h"
#include "delay.h"
/* Genera una señal digital de onda cuadrada con frecuencia frecuency,
 * y que dura ms milisegundos
 */
void square_wave(int frecuency, int ms, int pin)
{
        unsigned int n_ciclos = (frecuency * ms)/1000; 
        if (frecuency <= 100){
                unsigned int pause = 500/frecuency; // medio periodo en mS.0
                for (unsigned int i = 0; i<n_ciclos; i++){
                        gpio_pin(pin, ON);
                        delay_ms(pause);
                        gpio_pin(pin, OFF);
                        delay_ms(pause);
                }
        }else{
                unsigned int pause = 500000/frecuency; // medio periodo en uS.0
                for (unsigned int i = 0; i<n_ciclos; i++){
                        gpio_pin(pin, ON);
                        delay_us(pause);
                        gpio_pin(pin, OFF);
                        delay_us(pause);
                }
        }
}
