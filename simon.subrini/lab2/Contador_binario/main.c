#include "utils.h"

inline void delay_1us();
inline void delay_1xus(unsigned char n);
inline void delay_10us();
inline void delay_10xus(unsigned char n);
inline void delay_100us();
inline void delay_100xus(unsigned char n);
inline void delay_ms(unsigned int n);

unsigned char cont = 0;
unsigned char state = 0; // 0: conteo, 1: pausa

#define pinPul 0

int main(void){	
  config();

  while (1) {    
    if (digitalRead(pinPul)==0){
        delay_ms(30);
        if (digitalRead(pinPul)==0){
          state = !state;
        }
    }   
    if (state){
        if (cont < 32){
          cont++;
        }else{
          cont=0;
        }
        update(cont);
    }else{
      cont=0;
    }
  delay_ms(300);
  }
}


inline void delay_ms(unsigned int n){
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




