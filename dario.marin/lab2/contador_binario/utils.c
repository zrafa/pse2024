
/* utils.c - funciones de soporte al programa principal */

void esperar() {
  volatile unsigned long i;
  /* delay de aprox. 1 segundo */
  for (i = 0; i < 50000; i++)
    ;
}