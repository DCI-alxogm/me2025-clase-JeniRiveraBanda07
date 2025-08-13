// escribe un programa en donde se definan 4 números enteros
#include<stdio.h>
#include<math.h>
int main(){
float a=3;
float b=4;
float c=5;
float d=7;
printf("e=(a+b)* c/d = %f\n", (a+b)*c/d);
printf("e=((a+b)*c)/d=%f\n",((a+b)*c)/d);
printf("e=a+b*c/d=%f\n",a+b*c/d);
printf("e=a+(b*c)/d=%f\n",a+(b*c)/d);
}