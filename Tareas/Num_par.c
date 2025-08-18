#include <math.h>
#include<stdio.h>

int main (){
  int val;
  int residuo=0;
  printf("Ingresa un número para combrobar si es o no par: ");
  scanf("%d",&val);

residuo=val%2;
if(residuo!=0){
  printf("No es par ");
}else printf("ES PAR");
}