/**
 * @file utils.h
 * @author Diego Pablo Matias Baltar <diego.baltar@est.fi.uncoma.edu.ar>
 * @brief Funciones de soporte
 * @version 0.1
 * @date 2024-04-18
 *
 * El puerto B de un atmega328p tiene los bits 0-5 mapeados a los pines 8-13 de
 * arduino.
 */

#ifndef UTILS_H
#define UTILS_H


/** PIN B */
#define PINB  (*(volatile unsigned char*)(0x23))
#define PINB0 0
#define PINB1 1
#define PINB2 2
#define PINB3 3
#define PINB4 4
#define PINB5 5
#define PINB6 6
#define PINB7 7

/** DDR B */
#define DDRB (*(volatile unsigned char*)(0x24))
#define DDB0 0
#define DDB1 1
#define DDB2 2
#define DDB3 3
#define DDB4 4
#define DDB5 5
#define DDB6 6
#define DDB7 7

/** Puerto B */
#define PORTB  (*(volatile unsigned char*)(0x25))
#define PORTB0 0
#define PORTB1 1
#define PORTB2 2
#define PORTB3 3
#define PORTB4 4
#define PORTB5 5
#define PORTB6 6
#define PORTB7 7

/** PIN C */
#define PINC (*(volatile unsigned char*)(0x26))
#define PINC0 0
#define PINC1 1
#define PINC2 2
#define PINC3 3
#define PINC4 4
#define PINC5 5
#define PINC6 6

/** DDR C */
#define DDRC (*(volatile unsigned char*)(0x27))
#define DDC0 0
#define DDC1 1
#define DDC2 2
#define DDC3 3
#define DDC4 4
#define DDC5 5
#define DDC6 6

/** PORT C */
#define PORTC (*(volatile unsigned char*)(0x28))
#define PORTC0 0
#define PORTC1 1
#define PORTC2 2
#define PORTC3 3
#define PORTC4 4
#define PORTC5 5
#define PORTC6 6


/*
 * Función que puede realizar una demora de aproximadamente de 1 microsegundo,
 * utilizando instrucciones nop en ensamblador.
 */
inline void delay_1us(void)
{
//  asm volatile ("nop" "\n\t"
//                "nop" "\n\t"
//                "nop" "\n\t"
//                "nop" "\n\t"
//                "nop" "\n\t"
//                "nop" "\n\t"
//                "nop" "\n\t"
//                "nop" "\n\t"
//                "nop" "\n\t"
//                "nop" "\n\t");
}

void delay_us(long n);
void delay_ms(long n);
void led_init(void);
void led_on(void);
void led_off(void);


#endif /* UTILS_H */
