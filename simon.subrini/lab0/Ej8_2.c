#include <stdio.h>

void main(){
  char a = 0b00000001;
  
  b = ~(a << 5); // 0b11011111
  
  printf("a: %i",a);
  printf("\nb: %i",b);
  
}
