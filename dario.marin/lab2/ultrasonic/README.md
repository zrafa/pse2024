# EJ 2 - Ultrasonido

En este ejercicio se implementa el control de un sensor digital de ultrasonido HC-SR04 utilizando la información provista por el fabricante en la hoja de datos.

Este programa reporta la distancia de un objeto detectado por el sensor a la terminal.

## Documentación

El código fuente consiste en 3 archivos:

- [utils.c](doc/utils-doc.md): Funciones de propósito general.
- [ultrasound.c](doc/ultrasound-doc.md): Funciones para controlar el sensor.
- [main.c](doc/main-doc.md): El programa principal.

## Conexión al arduino

## Elementos necesarios

- Arduino Nano (x1).
- Sensor ultrasónico HC-SR04 (x1).

### Conexiones del Sensor de Ultrasonido HC-SR04

- **Trigger:** debe conectarse al pin digital 8 (D8) del Arduino (correspondiente al PB1).
- **Echo (Pin de eco):** debe conectarse al pin digital 9 (D9) del Arduino (correspondiente al PB2).
- **VCC:** debe conectarse al pin de 5V del Arduino Nano.
- **GND (Tierra):** debe conectarse a uno de los pines de tierra (GND) del Arduino Nano.

## Instalación y Configuración de Minicom

Minicom es una herramienta de terminal que te permite comunicarte con dispositivos serie. Será necesario para poder visualizar las mediciones del sensor.

### Instalación de Minicom

Para instalar, minicom, en el caso de que no lo tengamos previamente, debemos ejecutar el siguiente comando en la terminal.

```bash
sudo apt install minicom
```

### Configuración de Minicom

1. Ingresar a la configuración de minicom utilizando el comando `sudo minicom -s`.
2. En el menú, elegir la opción **Configuración del puerto serie**.
3. Presionar `a` para modificar el dispositivo serie. El argumento debe ser `/dev/ttyUSB0`. Presionar `enter` para confirmar la modificación.
4. Presionar `e` para acceder a la configuración *Bps/Paridad/Bits*. En el menú emergente, presionar `c` para establecer el baud rate en 9600. Presionar `enter` para salir.
5. Presionar `f` para establecer *Control de Flujo por Hardware* en `No`.
6. Presionar `esc` para salir de la configuración del puerto serie.

En este punto, minicom ya se encuentra configurado correctamente para establecer la comunicación. Sin embargo, si se cierra la terminal será necesario volverlo a configurar nuevamente. Podemos guardar la configuración para no tener que repetir los pasos anteriores cada vez que deseemos correr el programa eligiendo la opción **Guardar configuración como dfl**.

Una vez finalizado todo lo anterior elegimos la opción **Salir del minicom** para volver al entorno de la terminal.

## Compilación y Visualización de las mediciones

### Compilación

Para compilar, inicie una instancia de la terminal en la carpeta `src` del proyecto y ejecute el comando:

```bash
make
```

Luego, conecte el Ardunio a la computadora mediante el cable USB y ejecute el comando:

```bash
make flash
```

> ⚠️ **No ejecute `make flash` si hay una instancia de minicom abierta**.

### Visualización de las medidas

En una instancia de la terminal ejecute `minicom`. En este punto, el programa debería iniciar y mostrar los resultados de las mediciones en la terminal en un cada periodos de 500 ms.

Para salir de minicom presione la combinación de teclas `ctrl + a` y presione `x` a continuación. En las opciones emergentes presione elija `si` para confirmar la salida.
