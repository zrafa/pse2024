#include <stdio.h>
#include <math.h>


void print_bin(char y);

void main() {
  unsigned char x = 0b00001011;
  printf("x: %i ->",x);
  print_bin(x);
  x = x<<4;
  printf("\nx: %i ->",x);
  print_bin(x);
  x = x>>7;
  printf("\nx: %i ->",x);
  print_bin(x);
  if (x==1) {
    printf("\nEl bit 3 de la variable registro es 1 \n");
  }else{
    printf("\nEl bit 3 de la variable registro es 0 \n");
  }
}

void print_bin(char y){
        unsigned char aux;
        for(int i = 0; i <= 7; i++){
                aux = y<<(i);
                aux = aux>>7;
                printf("%i ",aux);
              }
}        

