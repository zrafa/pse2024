/*
 * ultrasound: programa que controla el HC-SR04 para medir distancias en cm
 */

#include "serial.h"
#include "utils.h"

#define TRIG_PIN 4
#define ECHO_PIN 5


inline void delay_1us();
inline void delay_1xus(unsigned char n);
inline void delay_10us();
inline void delay_10xus(unsigned char n);
inline void delay_100us();
inline void delay_100xus(unsigned char n);
inline void delay_ms(unsigned char n);

float distancia_cm;
unsigned int echo_pulse_cont;
unsigned int cont; // Lo uso para volver a enviar un pulso al trig en caso de que haya algún error

int main(void){
  ultrasound_init(TRIG_PIN, ECHO_PIN);
  serial_init();
  
  while (1) {
    echo_pulse_cont=0;
    cont=0;
    led_on(TRIG_PIN);
    delay_10us();
    led_off(TRIG_PIN);
    delay_1xus(2);
    
    while (echo_pulse_cont<360) {
      delay_100us();
      cont++; 
      if (cont>=20000) break;
      if (read_pin(ECHO_PIN)) {
        echo_pulse_cont++;
      }else if(echo_pulse_cont > 0){
        break;
      }
    }
    if (echo_pulse_cont<360){ // Si no esta fuera de rango 
      distancia_cm = (100 * echo_pulse_cont)/58.0; // Escalo los valores según datasheet
      serial_put_str("Distancia:  ");
      serial_put_int(distancia_cm, 3);
      serial_put_str(" cm\r\n"); 
    }else{
      serial_put_str("Fuera de rango\r\n");
    } 
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



