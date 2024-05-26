
mayday (codename) : quality styled drivers version zero. pse2024.

Este lab contiene una versión depurada inicial de los siguientes drivers 
básicos para el desarrollo de sistemas embebidos con un microcontrolador 
AVR atmega328p:

  - serial
  - adc
  - gpio
  - delay (biblioteca)

Dos cualidades son requeridas:
- correctitud: cada driver funciona apropiadamente para todos los casos
  de entrada.
- el código utiliza una norma de estilo general unificada lo que brinda
  legibilidad, fácil manutención, etc.

Informalmente, el objetivo es poder contar con drivers de "confianza". 
Por ejemplo, si se requiere activar bits individuales gpio, entonces que
estos drivers realicen la funcionalidad y lo hagan bien (que el usuario 
no deba verificar o "dudar" de si se realizó la operación, y que se realizó
correctamente).

La calidad de estos drivers básicos de bajo nivel es importante, ya que,
probablemente, sean muy utilizados por diferentes controladores de 
mayor nivel, o demás capas de software de una aplicación embebida final.

Verificación
------------

Se agrega una aplicación de testing, la cual utiliza un pequeño software
que obtiene una lectura de distancia desde el ultrasonido, y una lectura
del adc. Ambos valores son reportados via serial.

 
