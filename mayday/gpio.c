
/*
 * driver gpio: permite operar bits de los puertos gpios individualmente,
 * o en forma paralela (con los 8 bits del puerto).
 */


/*
 * Ejemplos de uso:
 *
 * // salida
 * gpio_output(13);
 * gpio_pin(13, ON);
 * gpio_pin(13, OFF);
 * gpio_pin(13, TOGGLE);
 *
 * // entrada
 * unsigned char v;
 * gpio_input(13);
 * v = gpio_pin(13, GET);
 *
 * // activar pull up
 * gpio_input(13);
 * gpio_pin(13, ON);
 *
 * // leer todo el registro de datos del puerto C (entrada)
 * gpio_input(PORT_C);
 * v = gpio_read(PORT_C);
 *
 * // escribir todo el registro de datos del puerto B (salida)
 * gpio_output(PORT_B);
 * v = 0x43;
 * gpio_write(PORT_B, v);
 */


/* gpio_pin(): opera sobre un pin individual (en salida, activar pull-up, o 
 * leyendo su valor de entrada).
 *
 * Argumentos:
 * pin: etiqueta del pin en la placa (ejemplo: 13)
 * op es la operación: ON, OFF, TOGGLE o GET
 *
 */
int gpio_pin(int pin, int op) 
{
	/* COMPLETAR */
}


/* establece el pin como entrada */
void gpio_input(int pin)
{
	/* COMPLETAR */
}

/* establece el pin como salida */
void gpio_output(int pin)
{
	/* COMPLETAR */
}

/* leer los 8 bits del puerto port */
void gpio_read(int port)
{
	/* COMPLETAR */
}

/* escribir los 8 bits del puerto port con el valor n */
void gpio_write(int port, unsigned char n)
{
	/* COMPLETAR */
}

