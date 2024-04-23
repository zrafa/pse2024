#include "delay.h"

volatile unsigned char *puerto_b = (unsigned char *)0x25;
volatile unsigned char *ddr_b = (unsigned char *)0x24;

void init();

int main(void) {
    unsigned char counter_max_value = 31;
  init();

  while (1) {
    for (char i = 0; i <= counter_max_value; i++) {
      *(puerto_b) = i;
      delay_ms(300);
    }
  }
}

void init() {
  *(puerto_b) &= 0;
  *(ddr_b) |= 0b00011111;
}
