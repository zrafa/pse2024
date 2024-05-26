/*
 * driver gpio: permite operar bits de los puertos gpios individualmente,
 * o en forma paralela (con los 8 bits del puerto).
 */

#ifndef GPIO_H
#define GPIO_H

#define OFF 	0x0
#define ON 	0x1
#define TOGGLE	0x2
#define GET	0x3
#define PORT_B	0x4
#define PORT_C	0x5
#define PORT_D	0x6

int gpio_pin(int pin, int op);
void gpio_input(int pin);
void gpio_output(int pin);
void gpio_read(int port);
void gpio_write(int port, unsigned char n);

#endif /* GPIO_H */
