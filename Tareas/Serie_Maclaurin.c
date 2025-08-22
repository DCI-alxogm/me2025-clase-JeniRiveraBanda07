#include <stdio.h>
#include <math.h>

int main(){
  float x,es;
  printf(" Ingresa el valor de x:\n");
  scanf("%f",&x);
  printf("Ingresa el valor de es:\n");
  scanf("%f",&es);

  float suma=1;
  float errapr=100;
  int n=1;
  while (errapr > es){
    int fact=1;
    for(int i=1;i<=n;i++){
      fact*=i;
    }
    float t=pow(x,n)/fact;
    suma += t;
    errapr=(t/suma)*100;
    printf("n=%d, e^%.1f=%f, error_aprox=%f%%\n",n,x,suma,errapr);
    n++;
    if(n>1000)break;
  }
}