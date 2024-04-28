# Laboratorio 1

## Compilar

Para compilar y cargar y cargar el programa en el arduino, ya sea el ejercicio `led_blink` como `knight_rider`:

1. Sitúese en la carpeta del ejercicio.
2. Ejecute el comando `make`.
3. Conecte el arduino a la computadora.
4. Ejecute el comando `make flash`.

### Observaciones

- El archivo make original provisto en el repositorio fue modificado para hacer coincidir el baud rate con el de mi arduino.
- En el caso de `knight_rider`, la función `esperar()` del archivo `utils.c` fue modificada con el fin de reducir su tiempo de espera para que la animación se vea más fluida.
