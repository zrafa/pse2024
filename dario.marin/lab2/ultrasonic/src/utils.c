/**
 * @file utils.c
 * @brief Funciones útiles y de propósito general para la implementación de los
 * laboratorios.
 */

/**
 * @brief Comprueba si un bit específico está activado en una palabra.
 * @param bit El número de bit que se va a comprobar.
 * @param word La palabra en la que se va a comprobar el bit.
 * @return 1 si el bit está activado, 0 si está desactivado.
 */
unsigned char is_on(unsigned char bit, volatile unsigned char word) {
  return (word & (1 << bit)) ? 1 : 0;
}

/**
 * @brief Activa un bit específico en un registro.
 * @param bit El número de bit que se activará.
 * @param reg Puntero al registro en el que se activará el bit.
 */
void set_bit(char bit, volatile unsigned char *reg) { *reg |= (1 << bit); }

/**
 * @brief Activa múltiples bits en un registro.
 * @param bits La máscara de bits que indica qué bits se activarán.
 * @param reg Puntero al registro en el que se activarán los bits.
 */
void set_bits(unsigned char bits, volatile unsigned char *reg) {
  *(reg) |= bits;
}

/**
 * @brief Desactiva un bit específico en un registro.
 * @param bit El número de bit que se desactivará.
 * @param reg Puntero al registro en el que se desactivará el bit.
 */
void clear_bit(char bit, volatile unsigned char *reg) { *reg &= ~(1 << bit); }

/**
 * @brief Desactiva múltiples bits en un registro.
 * @param bits La máscara de bits que indica qué bits se desactivarán.
 * @param reg Puntero al registro en el que se desactivarán los bits.
 */
void clear_bits(unsigned char bits, volatile unsigned char *reg) {
  *(reg) &= ~bits;
}