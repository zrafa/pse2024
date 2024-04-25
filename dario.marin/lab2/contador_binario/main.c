#include "delay.h"
#include "utils.h"

#define button 5

volatile unsigned char *puerto_b = (unsigned char *)0x25;
volatile unsigned char *ddr_b = (unsigned char *)0x24;
volatile unsigned char *pin_b = (unsigned char *)0x23;

void init();
void count(unsigned char counter_max_value);
void test_button();

int main(void) {
  init();
  unsigned char counter_max_value = 31;

  while (1) {
    count(counter_max_value);
  }
}

void init() {
  *(puerto_b) &= 0;
  *(ddr_b) |= 0b00011111;
}

void count(unsigned char counter_max_value) {
  for (char i = 0; i <= counter_max_value; i++) {
    *(puerto_b) = i;
    delay_ms(150);
    test_button();
    delay_ms(150);
    test_button;
  }
}

void test_button() {
  if (is_on(button, *(pin_b))) {
    delay_ms(100);
    while (is_on(button, *(pin_b))) {
    }
    delay_ms(100);
    while (is_on(button, *pin_b) == 0) {
    }
    delay_ms(100);
  }
}