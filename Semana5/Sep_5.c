#include <stdio.h>
float fx(float x); // con esto ya no se usa la libreria de math.h
int main()
{
    int i;
float a= -2, b=2, h=0.25;
int n=(int)((b-a)/h)+1;// son flotantes b y a, los convertimos en enteros 
float x[n], fpa[n];


for(i=0;i<n;i++){
    x[i]=a+i*h;

}
for(i=0;i<n;i++){
    fpa[i]=(fx(x[i+1])-fx(x[i]))/h;
  

}

}
float fx(float x){
    float f;
    f=x*x*x-2*x+4;
    return f;
}