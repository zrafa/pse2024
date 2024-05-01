# ultrasound.c

Este archivo contiene funciones para controlar el sensor de ultrasonido HC-SR04.

## Macros

- `TRIGGER_PIN`: Define el número de pin utilizado como el pin de activación (Trigger).
- `ECHO_PIN`: Define el número de pin utilizado como el pin de eco (Echo).
- `TRIGGER_PULSE_WIDE_US`: Define la duración del pulso de activación en microsegundos.
- `TIME_OUT_US`: Define el tiempo de espera máximo en microsegundos para recibir un eco válido.

## Variables globales

- `puerto_b`: Puntero al registro de puertos B.
- `ddr_b`: Puntero al registro de dirección de datos B.
- `pin_b`: Puntero al registro de entrada de puertos B.

## Funciones

### `void ports_init()`

Inicializa los puertos utilizados para la comunicación con el sensor de ultrasonido.

### `void start_ranging()`

Inicia el proceso de medición de distancia enviando un pulso al pin de activación (Trigger) del sensor.

### `int listening_echo()`

Escucha el eco (Echo) del sensor para medir la distancia.

- Retorna el tiempo transcurrido en microsegundos desde que se envió el pulso de activación hasta que se recibió el eco.
