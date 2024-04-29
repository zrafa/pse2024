

#include "utils.h"
inline void delay_1us();
inline void delay_1xus(unsigned char n);
inline void delay_10us();
inline void delay_10xus(unsigned char n);
inline void delay_100us();
inline void delay_100xus(unsigned char n);
inline void delay_ms(unsigned char n);

int main(void)
{	
	led_init();

	while (1) {
		delay_10xus(3);
		led_on();

		delay_10us();
		led_off();
    	}
}

inline void delay_ms(unsigned char n){
  while(n>0){
    delay_100xus(10);
    n--;
  }
}

inline void delay_1us(){ //1.15 us
  asm volatile ("nop" "\n\t");
}

inline void delay_1xus(unsigned char n){ // 0.97 + 0.76*n
  while(n>0){
    delay_1us();
    asm volatile ("nop" "\n\t"
                "nop" "\n\t"
                "nop" "\n\t"
                "nop" "\n\t"
                "nop" "\n\t"
                "nop" "\n\t"
                "nop" "\n\t"
		);
    n--;
  }
}

inline void delay_10us(){ // 10 us
  for(unsigned char n = 0; n<35; n++){
    asm volatile ("nop" "\n\t"
		);
  }
  asm volatile ("nop" "\n\t"
                "nop" "\n\t"
		);
}

inline void delay_10xus(unsigned char n){ // 0.91 + 9.87*n
  while(n>0){
    delay_10us();
    asm volatile ("nop" "\n\t"
                "nop" "\n\t"
                "nop" "\n\t"
                "nop" "\n\t"
                "nop" "\n\t"
                "nop" "\n\t"
                "nop" "\n\t"
                "nop" "\n\t"
                "nop" "\n\t"
                "nop" "\n\t"
                "nop" "\n\t"
                "nop" "\n\t"
		);
    n--;
  }
}


inline void delay_100us(){ // 100 us
  for(unsigned char n = 0; n<10; n++){
    delay_10us();
    asm volatile ("nop" "\n\t"
                "nop" "\n\t"
                "nop" "\n\t"
                "nop" "\n\t"
                "nop" "\n\t"
                "nop" "\n\t"
                "nop" "\n\t"
                "nop" "\n\t"
                "nop" "\n\t"
                "nop" "\n\t"
                "nop" "\n\t"
                "nop" "\n\t"
                "nop" "\n\t"
		);
  }
  
}

inline void delay_100xus(unsigned char n){ // 1.1 + 98.9*n
  while(n>0){
    delay_100us();
    n--;
  }
}

