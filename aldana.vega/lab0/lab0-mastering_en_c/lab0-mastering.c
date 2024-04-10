/* 
 * Dibuja un texto con caracteres ASCII usando un font intercambiable
 * Copyright 2020 - COMPLETE AQUI CON SU NOMBRE 
 *
 */


#include <string.h>
#include <stdio.h>

#include "font.h"

#define ANCHO 80
#define ALTO 24

unsigned char buffer[ANCHO * ALTO];
unsigned char addr;


void render_buffer(void)
{
	int i = 0;
	char linea[81];
	char *text =  "hola";

	for (i=0; i<ALTO; i++) {
		strncpy(&linea[0], &buffer[i*80], 80);
		linea[80] = 0;
		printf("%s\n", linea);	
	}
}


void draw_pixel_on_buffer(unsigned char x, unsigned char y, int color)
{
	switch(color) {
	case 0:
		buffer[y*80+x] = ' ';
		break;
	case 1:
		buffer[y*80+x] = 'X';
		break;
	default:		
		break;
	}

}

/* Dibuja una letra en el buffer, comenzando con la columna [x,y]
 * para el primer pixel de la letra 
 */

//VERSION CON PUNTEROS
/*void draw_char_on_buffer(unsigned char x, unsigned char y, char c,
                            unsigned char color)
{

	int i; // para recorrer el font por columnas 
	int j; // para recorrer el font por filas 
	char col; // para almacenar cada columna de pixeles del font 

	unsigned char aux;
    unsigned char byte;
    for(j=7;j>=0;j--){
        for (i=0;i<=4;i++){
            byte=*(font+5*c+i);
            aux=byte<<(7-j);
            aux=aux>>7;
			draw_pixel_on_buffer(x+i,j+y,aux); 
        } 
		
        
    }
}*/

//VERSION CON ARREGLOS
void draw_char_on_buffer(unsigned char x, unsigned char y, char c,
                            unsigned char color)
{

	int i; /* para recorrer el font por columnas */
	int j; /* para recorrer el font por filas */
	char col; /* para almacenar cada columna de pixeles del font */

	unsigned char aux;
    unsigned char byte;
    for(j=7;j>=0;j--){
        for (i=0;i<=4;i++){
            byte=font[5*c+i];
            aux=byte<<(7-j);
            aux=aux>>7;
			draw_pixel_on_buffer(x+i,j+y,aux); 
        } 
		
        
    }
}


void clear_buffer(void)
{
	memset(buffer, ' ', (ANCHO * ALTO) * sizeof(unsigned char));
	/*La función memset(void *s, int c, size_t n) completa los primeros n bytes a partir 
	de s con el valor c.
	En este caso completa con el caracter ' ' todos los bytes del buffer inicializado anteriormente*/
}

/* Muestra un texto en pantalla
 * x e y son coordenadas a resolución de pixel
 * Cada letra es de 6 columnas y 8 filas (1 columna es espacio)
 */


//VERSION CON PUNTEROS
/*void print_text_on_buffer(unsigned char x, unsigned char y, char *text)
{
	int i = 0;	
	char *c = text;
	while (*c != '\0') {
		draw_char_on_buffer(x,y,*c,0);
		x+=6;
		c++;
	}
}*/

//VERSION CON ARREGLOS
void print_text_on_buffer(unsigned char x, unsigned char y, char *text)
{
	int i = 0;	
	while (text[i] != '\0') {
		draw_char_on_buffer(x,y,text[i],0);
		x+=6;
		i++;
	}
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Error: se necesita al menos un argumento. \n");
		return -1;
	}

	printf("Programa: %s, y el argumento 1 es: %s \n", argv[0], argv[1]);
	
	
	clear_buffer();
	


	if (argc == 2)
		print_text_on_buffer(3, 5, argv[1]);
	else { 
		print_text_on_buffer(3, 5, argv[1]);
		print_text_on_buffer(3, 15, argv[2]);
	}
		
	render_buffer();

	return 0;


}
