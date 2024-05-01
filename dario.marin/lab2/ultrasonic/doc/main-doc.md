# main.c

Este archivo contiene el programa principal que utiliza el sensor de ultrasonido HC-SR04 para medir la distancia y enviar los resultados a través de la comunicación serial.

## Macros

- `TIME_DISTANCE_RELATION`: Define la relación entre el tiempo de eco medido en microsegundos y la distancia medida en centímetros.
- `TIME_BETWEEN_SCANS_MS`: Define el tiempo de espera entre cada escaneo del sensor en milisegundos.

## Funciones

### `int main(void)`

La función principal del programa. Inicializa los puertos y la comunicación serial, luego inicia un bucle infinito donde realiza las siguientes acciones:

1. Inicia una medición de distancia utilizando el sensor de ultrasonido.
2. Escucha el eco del sensor para medir el tiempo transcurrido.
3. Calcula la distancia en centímetros utilizando la relación de tiempo establecida.
4. Envía la distancia medida a través de la comunicación serial.
5. Espera un tiempo definido antes de realizar el siguiente escaneo del sensor.
