/**
 * @file main.c
 * @author Diego Pablo Matias Baltar <diego.baltar@est.fi.uncoma.edu.ar>
 * @brief Programa que controla el sensor HC-SR04 para medir distancias en cm
 * @version 0.1
 * @date 2024-04-24
 *
 * Utilizando lab2_delay.txt implementar delay_us(int n);
 *
 * Utilizar el hello world con delay_us(n) para obtener frecuencias de pruebas.
 * Verificar con el osciloscopio.
 *
 * Desarrollar el control de un sensor digital de ultrasonido HC-SR04
 * utilizando la informacion de referencia de la pagina web
 * (especificamente pagina 6:)
 *
 * En la carpeta ultrasound/ se encuentra el código esqueleto para este trabajo.
 * Viene con una biblioteca serial para poder enviar por el serial del arduino
 * (a nuestra notebook) información en texto plano (asciis).
 * El código esqueleto tiene un ejemplo.
 *
 * Este programa debe reportar a su notebook la distancia del objeto detectado
 * en cm. En el código esqueleto existe una biblioteca para utilizar el serial y
 * enviar información, con un ejemplo.
 */

#include "serial.h"
#include "usound.h"
#include "utils.h"

#define TRIG_PIN (1 << PORTC4)
#define ECHO_PIN (1 << PORTC5)

float distance = 0.0;

int main()
{
  serial_init();
  usound_init(TRIG_PIN, ECHO_PIN);

  while (1) {
    distance = usound_distance();

    serial_put_str("Distancia:\r\n");
    serial_put_double(distance, 4, 2);
    serial_put_str("cm \r\n");

    delay_ms(2000);
  }
}
