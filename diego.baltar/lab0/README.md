# Programación de Sistemas Embebidos - Repaso del lenguaje C - LAB 0
================================================================================

Bibliografía:
  Brian Kernighan y Dennis Ritchie, El lenguaje de programación C (título
  original en inglés: The C Programming Language)

  Eduardo Grosclaude, Taller de Lenguaje en C
  http://se.fi.uncoma.edu.ar/pse2020/taller-c/index.html

0. Escriba un programa `hello world`. Compilar y ejecutar. Por ejemplo:
   ```bash
   vi hello.c   # edicion. Usar vi u otro editor preferido
   make hello   # compilacion
   ./hello      # ejecucion
   ```

1. Enumerar los tipos de datos básicos en C.
   Escriba una definición de una variable por cada tipo. Por ej.: `int a;`

   ```c
   char c = -64;
   short s = -256;
   int i = -1024;
   long l = -4096;
   long long ll = -8182;
   float f = 2.7183;
   double d = 3.1416;
   long double ld = 1.41;

   unsigned char uc = 64;
   unsigned short us = 256;
   unsigned int ui = 1014;
   unsigned long ul = 4096;
   unsigned long long ull = 8182;

   void *p = 0;
   ```

2. Explique qué significa la palabra word cuando el contexto es la Arquitectura
   de una Computadora.

   En el contexto de la Arquitectura de una Computadora, `word` se refiere al
   tamaño de un registro del procesador. También se puede referir al tamaño de
   una instrucción del procesador o de un puntero, ya que depende de la
   arquitectura de la CPU. En los casos más comunes, en una arquitectura de 32
   bits, la palabra o word será de 32 bits, y en el caso de una arquitectura de
   64 bits, será por lo tanto de 64 bits.

3. ¿Cuántos bits puede almacenar una variable declarada como int (ej. int var;)
   en 3 computadoras de arquitecturas diferentes: arquitecturas de 8bits, 32bits
   y 64bits?.

   NOTA: la respuesta no es tan trivial como parece. Deberá buscar información
   sobre el lenguaje de programación C. Use wikipedia u otros recursos.

   Por lo general, los bits que se pueden almacenar en una variable tipo int
   varían según la arquitectura, aunque también el propósito del procesador.
   En el caso de microcontrolador de 8bits, puede almacenar 16bits, ya que
   tiene sentido realizar adición y sustracción en 16bits, incluso división y
   multiplicación. Esto se realiza talvez duplicando o aumentando el número de
   instrucciones de 8bits para llevar a cabo estas operaciones de 16bits.
   Por otra parte, cómo la mayoria de los microcontroladores de 8bits tienen
   limitaciones en cuanto al tamaño de memoria, no tendría sentido extender a
   enteros de 32bits, ya que también incrementaría la cantidad de instrucciones
   para operar con valores de este tamaño, y requerir mayor cantidad de memoria.
   Para el caso de 32bits y 64 bits, el tamaño de tipo int es ambos de 32bits,
   ya que tenemos una mayor capacidad de direccionamiento de memoria. Además,
   en la mayoría de aplicaciones de computadoras de 32 y 64 bits basta con tener
   enteros de 32bits, y son raros los casos donde se requiere utilizar 64bits.

4. Explique la diferencia en la salida de las siguientes instrucciones:
   ```c
   char a = 'M';
   printf ("a = %i \n", a);
   printf ("La letra %c \n", a);
   ```

   La diferencia es que la primera salida muestra el valor numérico del carécter
   'M' y la segunda muestra el carécter en sí.

   ¿Cuál es el valor numérico de a?

   El valor numérico de a es 77.

5. ¿Cuál es el rango numérico de i y j?
   ```c
   char i;
   unsigned char j;
   ```

   El tamaño de `char` es de 1 byte, y el rango de valores es [-128, 127].
   El tamaño de `unsigned char` es de 1 byte, y el rango de valores es [0, 255].
   La principal característica que nos importa es lo que representa este byte,
   y que en términos de bits, podremos representar entre 0x00 y 0xFF para ambos
   casos. Sin embargo, según sea con o sin signo, el significado es diferente.

6. ¿Cuál es el valor en base 2 (binario) de i, j, k, m, n, p?
   ```c
   char i = 'a';
   char j = 77;
   char k = 0x4D;
   unsigned char m = 'a';
   unsigned char n = 0x4d;
   unsigned char p = 'A';
   ```

   Explique el por qué de su repuesta. Contestar: Las variables anteriores,
   ¿fueron declaradas e inicializadas con valores diferente?

   Las variables j, k y n tienen el mismo valor y representan la letra 'M'.
   Las variables i y m tienen el mismo valor y representan la letra 'a'.
   La variable p representa la letra 'A'.
   Debido a que todas las variables mantienen valores entre 0 y 127, aunque las
   variables m, n y p son `unsigned` y las variables i, j y k son `signed`,
   todas representan un varacter ASCII.

7. Arreglos, Punteros y Operaciones.
   1. Comprender las siguientes definiciones y operaciones
      ```c
      main ()
      {
        int x[3];
        int *ptr;

        char a;
        char *b;

        x[0] = 1024;
        x[1] = 32;
        x[2] = -1;
        ptr = &x[0];
        ptr++;
        ptr++;

        a = 5;
        b = &a;
        printf ("a=%i, "
                "lo apuntado por b=%i, "
                "el contenido de b=%X, "
                "y la direccion de b=%X \n",
                a, *b, b, &b);

        *b = 21;
      }
      ```

      Si al comenzar el programa el sistema asignó la dirección 0xFFA00004 al
      arreglo x[], ¿Cuál es el valor final del contenido de ptr al finalizar la
      ejecución del programa?

      Si la dirección inicial de ptr es 0xffa00004, entonces la dirección final
      es 0xffa0000c, si el tamaño de un entero es de 4 bytes, entonces
      incrementar en 1 a ptr significa incrementar el puntero en 4 bytes.

      ¿Cuál es el valor final del contenido de la variable `a` al finalizar el
      programa?

      El valor de la variable `a` al final del programa es `21`.

      ¿Cuál es la dirección de la variable `x[2]`?

      Si la dirección inicial de ptr es 0xffa00004, entonces la dirección de
      `x[2]` es 0xffa0000C.

   2. Arreglos y punteros: Comprender el siguiente código.
      ```c
      unsigned int array[5];
      array[2] = 99;

      unsigned int *pointer;
      pointer = &array[0];
      *(pointer+2) = 99;

      pointer = array;
      ```

      Se declara una variable `array` como arreglo de 5 enteros sin signo.
      Se inicializa el tercer elemento con valor `99`.
      Se declara una variable `pointer` como puntero a un entero sin signo.
      Se incializa apuntando al primer elemento del arreglo `array`.
      Se establece el valor al que apunta `pointer` con valor `99`.
      En resumen, la segunda línea hace lo mismo que en la quinta, y la última
      línea hace lo mismo que la cuarta línea.

8. Operaciones sobre bits particulares.
   En la programación de sistemas embebidos es muy común leer y escribir
   registros del hardware. En particular, se requiere poder modificar ciertos
   bits y otros no. O conocer el valor de un bit particular.

   1. Comprender una operación shift. Por ejemplo: (1 << 5)
      Escriba un programa que defina una variable de tipo char.
      Asigne la operacion shift mencionada arriba a esa variable.
      Indique cual es el valor en base 2 de la variable de tipo char.
      Indique cual es el valor en decimal.

      El valor final es de 00100000 en base 2 y 32 en base 10.
      En este caso, (1 << 5) es hacer la operación 2^5 = 32 (base 10).

   2. Comprender una operación shift que luego se niega. Por ejemplo: ~(1 << 5)
      Escriba un programa que defina una variable de tipo char.
      Asigne a la variable la operacion shift mencionada arriba.
      Indique cual es el valor en base 2 de la variable de tipo char.
      Indique cual es el valor en decimal.

      El valor final es de 11011111 en base 2 y 223 en base 10.
      En este caso, ~(1 << 5) es como mover los bits en 0 hacia la izquierda, ya
      que hacemos la misma operación anterior, y luego negamos los bits.

   3. Comprender los operadores AND y OR (& y |).
      ```c
      #define BIT3 3
      unsigned char status;

      status = 0b00110101;
      status = status | 0xFA;
      status = status & 20;
      status |= (1 << 6);
      status &= ~(1 << BIT3);
      status |= (1 << BIT3);
      ```
      - Poder verificar el estado de un bit.
      - Poder obtener sólo una parte de los bits. Por ejemplo: & 0xF0

      El resultado de las operaciones paso a paso es el siguiente:
      ```
      status = 0b00110101
      status = 0b00110101 | 0b11111010 = 0b11111111
      status = 0b11111111 & 0b00010100 = 0b00010100
      status = 0b00010100 | 0b01000000 = 0b01010100
      status = 0b01010100 & 0b11110111 = 0b01010100
      status = 0b01010100 | 0b00001000 = 0b01011100
      ```
      Por lo tanto, el resultado final es 01011100 en base 2, 92 en base 10.

   4. Para la siguiente definición:
      ```c
      unsigned char x = 11;
      ```

      Indique el valor binario de cada bit de la variable x
      (bit7 bit6 bit5 bit4 bit3 bit2 bit1 bit0)

      El valor binario de cada bin de x es:
      (0 0 0 0 1 0 1 1)

   5. Se desea ejecutar un bloque de código en C si el bit 3 de la variable
      x anterior está en 1. Complete la siguiente sentencia condicional if

      if (  COMPLETAR  ) printf ("el bit3 de la variable registro es 1 \n");

      Para saber si el bit 3 está en 1, usamos una "máscara" para el bit 3:
      ```c
      if (x & 0x08)
        printf ("el bit3 de la variable registro es 1 \n");
      ```

   6. Escriba una sentencia en C para eliminar los bits2, bit1 y bit0
      (ponerlos en cero), sin modificar el resto de los bits.
      ```c
      x &= ~0x07; // ~0x07 = 0xf8 = 0b11111000
      ```

   7. Escriba una sentencia en C para poner asertar los bits7 y bit6
      (ponerlos en uno), sin modificar el resto de los bits.
      ```c
      x |= 0xc0; // 0xc0 = 0b11000000
      ```

9. Registros de 8 bits, aritmética de 16 a 32 bits.
   En ocasiones queremos realizar un cómputo, cuyo resultado debe ser almacenado
   en un registro de 8 bits.
   ¿Qué sucede con el resultado de la siguiente operación?
   ```c
   unsigned char RES;
   unsigned char var;
   var = 190;
   RES = (unsigned char)(var * 500) / 190;
   ```

   Analizando por parte, cuando se computa `(unsigned char)(var * 500)`, cómo el
   resultado de 190 * 500 = 95000, se genera un overflow, ya que el valor máximo
   de `unsigned char` es de 255. Luego, el resultado de esa operación resulta
   ser el módulo 255+1, es decir, el máximo más 1: `(190 * 500) % (255 + 1)`.
   Por lo tanto, `(unsigned char)(var * 500) = 24`, y la división entera de
   `24 / 190` da como resultado `0`. Finalmente, el resultado de RES es cero.

10. Desarrollar el programa que se detalle en archivo aparte.
