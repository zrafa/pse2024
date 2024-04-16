#include <stdio.h>
#include <math.h>


void main(){
        unsigned char x=11;
        for(int i = 7; i >= 0; i--){
	        unsigned char aux = x<<(7-i);
        	aux= aux>>(7);
        	printf("Bit %d: %d\n",i,aux);
              }

	if( ((x<<4)>>7)==1 ){
	   printf("El bit3 de la variable registro es 1\n");
	}
}

