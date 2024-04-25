/**
 * @file main.c
 * @author Diego Pablo Matias Baltar <diego.baltar@est.fi.uncoma.edu.ar>
 * @brief Controlar un piezo speaker utilizando un pin digital
 * @version 0.1
 * @date 2024-04-22
 *
 * Controlar un piezo speaker utilizando un pin digital.
 * Buscar la frecuencias de las notas musicales para una octava.
 *
 * Implementar la reproducción de una nota utilizando el control de la
 * frecuencia de períodos de una señal digital sobre un pin.
 * Utilice el delay_us(n) y un pin del arduino para generar una señal digital
 * con la frecuencia necesaria.
 *
 * Por ejemplo, el DO en escala 7ma tiene una frecuencia de 2093hz.
 * Para lograr esa frecuencia, habría que:
 *
 * ```
 * poner_en_alto la señal
 * esperar 248 microsegundos
 * poner_en_bajo la señal
 * esperar 248 microsegundos
 * ```
 *
 * Eso genera un período que dura 476 microsegundos.
 * En un segundo, con períodos de esa duración, habrán sucedido 2093 períodos
 * (2093hz, que se la frecuencia buscada y se escucharía el DO en séptima).
 *
 * Buscar una melodia sencilla.
 * Colocar las notas y duración en una estructura de datos (por ej. un arreglo).
 * Desarrollar un reproductor elegante para la melodia.
 */

#include "utils.h"
#include "melody.h"
#include "songs/nokia.h"
#include "songs/pacman.h"
#include "songs/takeonme.h"
#include "songs/starwars.h"
#include "songs/gameofthrones.h"

/** Pin del speaker */
#define SPEAKER_PIN (1 << PORTB5)
/** Determina que tan lenta o rápida se reproduce la melodía */
#define TEMPO       (140)

/** Arreglo de notas de la melodía, de pares frecuencia, duración, ... */
int melody[] = GAMESOFTHRONES_MELODY;

int main()
{
  melody_init(SPEAKER_PIN);
  delay_ms(2000);

  while (1) {
    melody_play(melody, MELODY_NOTES(melody), TEMPO);
    delay_ms(4000);
  }
}
