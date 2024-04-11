# Programación de Sistemas Embebidos

## LAB 1: Cadena de herramientas y primer programa embebido
================================================================================

Bibliografía:
  Brian Kernighan y Dennis Ritchie, El lenguaje de programación C (título
  original en inglés: The C Programming Language)

  Eduardo Grosclaude, Taller de Lenguaje en C
  http://se.fi.uncoma.edu.ar/pse2020/taller-c/index.html

  Apuntes:
    - cadena de herramientas
    - primer programa embebido

0. Subir la resolucion del lab0 utilizando lo indicado en instrucciones.txt
   del repositorio https://github.com/zrafa/pse2024/
   (subir unicamente archivos de texto plano. No subir ejecutables, pdf
   u otro tipo de archivos).

1. Instalar un toochain para cross-compiling a AVR. Tambien avrdude.
   ¿Qué paquetes componen el toolchain para AVR en su sistema?

   Los paquetes del toolchain para AVR en mi sistema, al ejecutar el comando:
   ```bash
   ls /usr/bin/avr*
   ```

   Se obtiene lo siguiente:
   ```
   /usr/bin/avr-addr2line   /usr/bin/avr-gcc-ar         /usr/bin/avr-lto-dump
   /usr/bin/avr-ar          /usr/bin/avr-gcc-nm         /usr/bin/avr-man
   /usr/bin/avr-as          /usr/bin/avr-gcc-ranlib     /usr/bin/avr-nm
   /usr/bin/avr-c++         /usr/bin/avr-gcov           /usr/bin/avr-objcopy
   /usr/bin/avr-c++filt     /usr/bin/avr-gcov-dump      /usr/bin/avr-objdump
   /usr/bin/avr-cpp         /usr/bin/avr-gcov-tool      /usr/bin/avr-ranlib
   /usr/bin/avrdude         /usr/bin/avr-gdb            /usr/bin/avr-readelf
   /usr/bin/avr-elfedit     /usr/bin/avr-gdb-add-index  /usr/bin/avr-size
   /usr/bin/avr-g++         /usr/bin/avr-gprof          /usr/bin/avr-strings
   /usr/bin/avr-gcc         /usr/bin/avr-ld             /usr/bin/avr-strip
   /usr/bin/avr-gcc-13.2.0  /usr/bin/avr-ld.bfd
   ```

2. ;
   a. Completar el programa hello world en C que acompaña este lab
     (carpeta led_blink/).
   b. Compilar con:
      ```bash
      make clean
      make
      ```
   c. Transferir el firmware generado al MCU con:
      ```bash
      make flash
      ```
   d. Comprobar que el programa se ejecuta correctamente.

## Manejo de herramientas del toolchain

3. Utilice el comando file para verificar que el archivo elf ejecutable
   generado al compilar es de la arquitectura adecuada.

   Salida:
   ```
   led-test: ELF 32-bit LSB executable, Atmel AVR 8-bit, version 1 (SYSV), statically linked, with debug_info, not stripped
   ```

4. Verifique donde instaló, el sistema de paquetes de Linux, las binutils de
   avr.

   Los paquetes del toolchain para AVR están en `/usr/bin/`:
   ```
   /usr/bin/avr-addr2line   /usr/bin/avr-gcc-ar         /usr/bin/avr-lto-dump
   /usr/bin/avr-ar          /usr/bin/avr-gcc-nm         /usr/bin/avr-man
   /usr/bin/avr-as          /usr/bin/avr-gcc-ranlib     /usr/bin/avr-nm
   /usr/bin/avr-c++         /usr/bin/avr-gcov           /usr/bin/avr-objcopy
   /usr/bin/avr-c++filt     /usr/bin/avr-gcov-dump      /usr/bin/avr-objdump
   /usr/bin/avr-cpp         /usr/bin/avr-gcov-tool      /usr/bin/avr-ranlib
   /usr/bin/avrdude         /usr/bin/avr-gdb            /usr/bin/avr-readelf
   /usr/bin/avr-elfedit     /usr/bin/avr-gdb-add-index  /usr/bin/avr-size
   /usr/bin/avr-g++         /usr/bin/avr-gprof          /usr/bin/avr-strings
   /usr/bin/avr-gcc         /usr/bin/avr-ld             /usr/bin/avr-strip
   /usr/bin/avr-gcc-13.2.0  /usr/bin/avr-ld.bfd
   ```

5. ¿Dónde están los encabezados y las bibliotecas de C para avr?

   Los encabezados están en `/usr/avr/include/`;
   y las bibliotecas en `/usr/avr/lib/`.

6. ¿Dónde se instaló el compilador avr-gcc?

   La ubicación del compilador es igual al resto del toolchain; en `/usr/bin/`.

7. ;
   a. Utilice avr-objdump para realizar un decodificado del programa binario elf
      (obtener el código en lenguaje ensamblador AVR a partir del binario elf)
      ```
      ./led-test:     formato del fichero elf32-avr


      Desensamblado de la sección .text:

      00000000 <__vectors>:
        0:	0c 94 34 00 	jmp	0x68	; 0x68 <__ctors_end>
        4:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
        8:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
        c:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
        10:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
        14:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
        18:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
        1c:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
        20:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
        24:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
        28:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
        2c:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
        30:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
        34:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
        38:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
        3c:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
        40:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
        44:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
        48:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
        4c:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
        50:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
        54:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
        58:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
        5c:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
        60:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>
        64:	0c 94 49 00 	jmp	0x92	; 0x92 <__bad_interrupt>

      00000068 <__ctors_end>:
        68:	11 24       	eor	r1, r1
        6a:	1f be       	out	0x3f, r1	; 63
        6c:	cf ef       	ldi	r28, 0xFF	; 255
        6e:	d8 e0       	ldi	r29, 0x08	; 8
        70:	de bf       	out	0x3e, r29	; 62
        72:	cd bf       	out	0x3d, r28	; 61

      00000074 <__do_copy_data>:
        74:	11 e0       	ldi	r17, 0x01	; 1

      00000076 <.Loc.1>:
        76:	a0 e0       	ldi	r26, 0x00	; 0

      00000078 <.Loc.2>:
        78:	b1 e0       	ldi	r27, 0x01	; 1

      0000007a <.Loc.3>:
        7a:	ea e3       	ldi	r30, 0x3A	; 58

      0000007c <.Loc.4>:
        7c:	f1 e0       	ldi	r31, 0x01	; 1

      0000007e <.Loc.5>:
        7e:	02 c0       	rjmp	.+4      	; 0x84 <.L__do_copy_data_start>

      00000080 <.L__do_copy_data_loop>:
        80:	05 90       	lpm	r0, Z+

      00000082 <.Loc.7>:
        82:	0d 92       	st	X+, r0

      00000084 <.L__do_copy_data_start>:
        84:	a6 30       	cpi	r26, 0x06	; 6

      00000086 <.Loc.9>:
        86:	b1 07       	cpc	r27, r17

      00000088 <.Loc.10>:
        88:	d9 f7       	brne	.-10     	; 0x80 <.L__do_copy_data_loop>

      0000008a <L0^A>:
        8a:	0e 94 90 00 	call	0x120	; 0x120 <main>
        8e:	0c 94 9b 00 	jmp	0x136	; 0x136 <_exit>

      00000092 <__bad_interrupt>:
        92:	0c 94 00 00 	jmp	0	; 0x0 <__vectors>

      00000096 <esperar>:
        96:	cf 93       	push	r28
        98:	df 93       	push	r29
        9a:	00 d0       	rcall	.+0      	; 0x9c <L0^A>

      0000009c <L0^A>:
        9c:	00 d0       	rcall	.+0      	; 0x9e <L0^A>

      0000009e <L0^A>:
        9e:	cd b7       	in	r28, 0x3d	; 61
        a0:	de b7       	in	r29, 0x3e	; 62
        a2:	19 82       	std	Y+1, r1	; 0x01
        a4:	1a 82       	std	Y+2, r1	; 0x02
        a6:	1b 82       	std	Y+3, r1	; 0x03
        a8:	1c 82       	std	Y+4, r1	; 0x04

      000000aa <.L2>:
        aa:	89 81       	ldd	r24, Y+1	; 0x01
        ac:	9a 81       	ldd	r25, Y+2	; 0x02
        ae:	ab 81       	ldd	r26, Y+3	; 0x03
        b0:	bc 81       	ldd	r27, Y+4	; 0x04
        b2:	80 3d       	cpi	r24, 0xD0	; 208
        b4:	9d 4d       	sbci	r25, 0xDD	; 221
        b6:	a6 40       	sbci	r26, 0x06	; 6
        b8:	b1 05       	cpc	r27, r1
        ba:	38 f0       	brcs	.+14     	; 0xca <.L3>
        bc:	0f 90       	pop	r0
        be:	0f 90       	pop	r0
        c0:	0f 90       	pop	r0
        c2:	0f 90       	pop	r0
        c4:	df 91       	pop	r29
        c6:	cf 91       	pop	r28
        c8:	08 95       	ret

      000000ca <.L3>:
        ca:	89 81       	ldd	r24, Y+1	; 0x01
        cc:	9a 81       	ldd	r25, Y+2	; 0x02
        ce:	ab 81       	ldd	r26, Y+3	; 0x03
        d0:	bc 81       	ldd	r27, Y+4	; 0x04
        d2:	01 96       	adiw	r24, 0x01	; 1
        d4:	a1 1d       	adc	r26, r1
        d6:	b1 1d       	adc	r27, r1
        d8:	89 83       	std	Y+1, r24	; 0x01
        da:	9a 83       	std	Y+2, r25	; 0x02
        dc:	ab 83       	std	Y+3, r26	; 0x03
        de:	bc 83       	std	Y+4, r27	; 0x04
        e0:	e4 cf       	rjmp	.-56     	; 0xaa <.L2>

      000000e2 <led_init>:
        e2:	e0 91 04 01 	lds	r30, 0x0104	; 0x800104 <puerto_b>
        e6:	f0 91 05 01 	lds	r31, 0x0105	; 0x800105 <puerto_b+0x1>
        ea:	80 81       	ld	r24, Z
        ec:	8f 7d       	andi	r24, 0xDF	; 223
        ee:	80 83       	st	Z, r24
        f0:	e0 91 02 01 	lds	r30, 0x0102	; 0x800102 <ddr_b>
        f4:	f0 91 03 01 	lds	r31, 0x0103	; 0x800103 <ddr_b+0x1>
        f8:	80 81       	ld	r24, Z
        fa:	80 62       	ori	r24, 0x20	; 32
        fc:	80 83       	st	Z, r24
        fe:	08 95       	ret

      00000100 <led_on>:
      100:	e0 91 04 01 	lds	r30, 0x0104	; 0x800104 <puerto_b>
      104:	f0 91 05 01 	lds	r31, 0x0105	; 0x800105 <puerto_b+0x1>
      108:	80 81       	ld	r24, Z
      10a:	80 62       	ori	r24, 0x20	; 32
      10c:	80 83       	st	Z, r24
      10e:	08 95       	ret

      00000110 <led_off>:
      110:	e0 91 04 01 	lds	r30, 0x0104	; 0x800104 <puerto_b>
      114:	f0 91 05 01 	lds	r31, 0x0105	; 0x800105 <puerto_b+0x1>
      118:	80 81       	ld	r24, Z
      11a:	8f 7d       	andi	r24, 0xDF	; 223
      11c:	80 83       	st	Z, r24
      11e:	08 95       	ret

      00000120 <main>:
      120:	0e 94 71 00 	call	0xe2	; 0xe2 <led_init>

      00000124 <.L2>:
      124:	0e 94 4b 00 	call	0x96	; 0x96 <esperar>
      128:	0e 94 80 00 	call	0x100	; 0x100 <led_on>
      12c:	0e 94 4b 00 	call	0x96	; 0x96 <esperar>
      130:	0e 94 88 00 	call	0x110	; 0x110 <led_off>
      134:	f7 cf       	rjmp	.-18     	; 0x124 <.L2>

      00000136 <_exit>:
      136:	f8 94       	cli

      00000138 <__stop_program>:
      138:	ff cf       	rjmp	.-2      	; 0x138 <__stop_program>
      ```
   b. Utilice el comando avr-size para obtener el espacio que ocupará
      el programa en el sistema. ¿Cuántos bytes ocupa la sección de código?
      ¿Y la de datos?.

      ```
      text	   data	    bss	    dec	    hex	filename
      314	      6	      0	    320	    140	./led-test
      ```

      La sección del código ocupará 314 bytes y la de datos 6 bytes, 320 bytes
      en total.

8. Utilizando el programa decodificado por avr-objdump en 7. a.
   ¿Es el código de main() lo primero que se ejecuta en su program?
   ¿Puede encontrar la llamada a la función main? ¿En qué dirección comienza
   el código de la función main? ¿Qué son todas las instrucciones anteriores
   a main?

   El código del main no es lo primero que se ejecuta en el programa, ya que se
   puede observar que hay una llamada a `main()` y luego a `_exit()` en la
   sección:
   ```
   0000008a <L0^A>:
   8a:	0e 94 90 00 	call	0x120	; 0x120 <main>
   8e:	0c 94 9b 00 	jmp	0x136	; 0x136 <_exit>
   ```

   El código del main comienza en la dirección `0x120`:
   ```
   00000120 <main>:
   120:	0e 94 71 00 	call	0xe2	; 0xe2 <led_init>
   ```

9. Ejercicio knight_rider: Conecte 5 leds a 5 pines controlados por el puerto B
   Desarrollar un programa que genere el efecto del knight_rider:
   https://wallpapercave.com/wp/wp3292242.gif
   ayuda de programación: tal vez, se podría definir un arreglo de elementos
   unsigned char. Y cada elemento del arreglo puede contener un valor
   completo de la animacion, para el registro data del puerto b.
   De esta manera puede ir escribiendo, iterando, cada elemento del arreglo,
   al registro data del puerto b (con una pausa entre escritura y escritura).



