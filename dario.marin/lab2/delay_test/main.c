#include "delay.h"

#define LED_0 0x2

volatile unsigned char *puerto_b = (unsigned char *)0x25;
volatile unsigned char *ddr_b = (unsigned char *)0x24;

void init();

int main(void) {
  while (1) {
    *(puerto_b) |= LED_0;
    delay_us(500);
    *(puerto_b) &= ~LED_0;
    delay_us(500);
  }
}

void init() {
  *(puerto_b) &= 0;
  *(ddr_b) |= 0b00000010;
}
