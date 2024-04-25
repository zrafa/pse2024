#include "utils.h"

#define NUM_STATES 14
#define NUM_LEDS 6

unsigned char led_state;

unsigned char state[NUM_STATES][NUM_LEDS] = {
    {1, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 0, 0},
    {1, 1, 1, 0, 0, 0},
    {0, 1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 0},
    {0, 0, 0, 1, 1, 1},
    {0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, 1},
    {0, 0, 0, 1, 1, 1},
    {0, 0, 1, 1, 1, 0},
    {0, 1, 1, 1, 0, 0},
    {1, 1, 1, 0, 0, 0},
    {1, 1, 0, 0, 0, 0}};

int main(void)
{

  led_init();

  while (1)
  {
    for (unsigned char s = 0; s < NUM_STATES; s++)
    {
      for (unsigned char l = 0; l < NUM_LEDS; l++)
      {
        led_state = state[s][l];
        if (led_state == 1)
        {
          led_on(l);
        }
        else
        {
          led_off(l);
        }
      }
      esperar();
    }
  }
}
