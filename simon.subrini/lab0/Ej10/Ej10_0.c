#include <math.h>
#include <stdio.h>
#include "font.h"
void mostrar_fila(unsigned char b1,unsigned char b2,unsigned char b3,unsigned char b4,unsigned char b5,unsigned char f);
void mostrar_caracter(unsigned char x);
unsigned char caracter;

void main() {
  caracter='S';
  mostrar_caracter(caracter);
}
  

void mostrar_caracter(unsigned char x){
  unsigned char byte0 = font[5*x];
  unsigned char byte1 = font[(5*x)+1];
  unsigned char byte2 = font[(5*x)+2];
  unsigned char byte3 = font[(5*x)+3];
  unsigned char byte4 = font[(5*x)+4];
  
  
  for (unsigned char i = 0;i<8;i++){ //Itero para cada fila
    mostrar_fila(byte0,byte1,byte2,byte3,byte4,i);
  }
  
  
}

void mostrar_fila(unsigned char b0,unsigned char b1,unsigned char b2,unsigned char b3,unsigned char b4,unsigned char f){
  //printf("Mostrar fila\n");
  char txt[6];
  if ((b0 & (1<<f))>>f){
    txt[0]='X';
  }else{
    txt[0]=' ';
  }
  
  if ((b1 & (1<<f))>>f){
    txt[1]='X';
  }else{
    txt[1]=' ';
  }
  
  if ((b2 & (1<<f))>>f){
    txt[2]='X';
  }else{
    txt[2]=' ';
  }
  
  if ((b3 & (1<<f))>>f){
    txt[3]='X';
  }else{
    txt[3]=' ';
  }
  
  if ((b4 & (1<<f))>>f){
    txt[4]='X';
  }else{
    txt[4]=' ';
  }
  
  txt[5]='\0';
  
  printf("%s\n",txt);
  
}

