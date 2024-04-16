#include <string.h>
#include <stdio.h>

#include "font.h"
#include <stdlib.h>

#define ANCHO 80
#define ALTO 24

unsigned char buffer[ANCHO * ALTO];
unsigned char addr;


int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Error: se necesita al menos un argumento. \n");
		return -1;
	}

	printf("Programa: %s, y el argumento 1 es: %s \n", argv[0],argv[1]);
    
    unsigned char aux;
    unsigned char byte;

    char *c=argv[1];
    //unsigned char m = (*c<<24)>>24;
    unsigned char m = (*c & 0xFF);

    for(int j=7;j>=0;j--){
        for (int i=0;i<=4;i++){
            byte=font[5*m+i];
            aux=byte<<j;
            aux=aux>>7;
            printf("%d ",aux);
        } 
        printf("\n");
    }
	return 0;


}