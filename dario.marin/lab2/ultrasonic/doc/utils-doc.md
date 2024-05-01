# utils.c

Este archivo contiene funciones de propósito general independientemente del laboratorio.

## Funciones

### `unsigned char is_on(unsigned char bit, volatile unsigned char word)`

Comprueba si un bit específico está activado en una palabra.

- `bit`: El número de bit que se va a comprobar.
- `word`: La palabra en la que se va a comprobar el bit.
- Retorna `1` si el bit está activado, `0` si está desactivado.

### `void set_bit(char bit, volatile unsigned char *reg)`

Activa un bit específico en un registro.

- `bit`: El número de bit que se activará.
- `reg`: Puntero al registro en el que se activará el bit.

### `void set_bits(unsigned char bits, volatile unsigned char *reg)`

Activa múltiples bits en un registro.

- `bits`: La máscara de bits que indica qué bits se activarán.
- `reg`: Puntero al registro en el que se activarán los bits.

### `void clear_bit(char bit, volatile unsigned char *reg)`

Desactiva un bit específico en un registro.

- `bit`: El número de bit que se desactivará.
- `reg`: Puntero al registro en el que se desactivará el bit.

### `void clear_bits(unsigned char bits, volatile unsigned char *reg)`

Desactiva múltiples bits en un registro.

- `bits`: La máscara de bits que indica qué bits se desactivarán.
- `reg`: Puntero al registro en el que se desactivarán los bits.