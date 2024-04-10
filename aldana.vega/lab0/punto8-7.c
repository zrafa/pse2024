#include <stdio.h>
#include <math.h>
void imprimir_binario(char a);

void main(){
        unsigned char x=5;
       
        printf("Bits originales\n");
        imprimir_binario(x);

        printf("\nBits luego de operar\n");
        x |= 0xC0;
        imprimir_binario(x);
}

void imprimir_binario(char a){
        unsigned char aux;
        for(int i = 7; i >= 0; i--){
                aux = a<<(7-i);
                aux= fabs (aux>>(7));
                printf("Bit %d: %d\n",i,aux);
              }
}        

