#include <stdio.h>
#include <math.h>


void main(){
	unsigned char x=11;
	unsigned char aux;
	for(int i = 7; i >= 0; i--){
		aux= x<<(7-i);
		aux= aux>>(7);
		printf("Bit %d: %d\n",i,aux);
    }
}
