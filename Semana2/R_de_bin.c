#include<stdio.h>
#include<math.h>
int main(){
  float a,b,c,x1,x2,discr;
  printf("Ingresa el valor de A:\n");
  scanf("%f",&a);
  printf("Ingresa el valor de B:\n");
  scanf("%f",&b);
  printf("Ingresa el valor de C:\n");
  scanf("%f",&c);
  if(a==0){
    if(b==0){
      printf("solución trivial");
    }else{
      x1=-c/b;
    }
  }else{discr= (b*b)-(4*a*c);}
  if(discr>0)
}