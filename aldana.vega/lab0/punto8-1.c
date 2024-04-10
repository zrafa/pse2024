#include <stdio.h>
#include <math.h>

void imprimir_binario(char a);

//Ejercicios 8.1 y 8.2
void main(){
	char a=-20,b=2,aux;

	//Valor original	
	printf("Valor original: %d, valor en base 2: ",a);
	imprimir_binario(a);


	//Valor al aplicar shift
	char shift=a<<b;
	printf("\nValor al aplicar <<:\%i, valor en base 2:",shift);
	imprimir_binario(shift);



        //Valor al aplicar ~
        shift=~(shift);
        printf("\nValor al aplicar ~:\%i, valor en base 2:",shift);
        imprimir_binario(shift);

        printf("\n");
        



}


void imprimir_binario(char a){
        char aux;
        for(int i = 7; i >= 0; i--){
                aux = a<<(7-i);
                aux= fabs (aux>>(7));
                printf("%d ",aux);
              }
}        

