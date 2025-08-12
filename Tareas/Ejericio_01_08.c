#include<stdio.h>
#include<math.h>

int main(){
  float num[5];
  num[0]=1.7;
  num[1]=2.7;
  num[2]=6.4;
  num[3]=8.4;
  num[4]=7.1;
  printf("%f %f %f %f %f\n",num[0],num[1],num[2],num[3],num[4]);
  printf(" X^2= %f %f %f %f %f\n",exp(num[0]),exp(num[1]),exp(num[2]),exp(num[3]),exp(num[4]));
  printf(" logaritmo= %f %f %f %f %f\n",log(num[0]),log(num[1]),log(num[2]),log(num[3]),log(num[4]));
  printf(" exp(x)+cos(x)= %f %f %f %f %f\n",((exp(num[0])+cos(num[0])),(exp(num[1])+cos(num[1])),(exp(num[2])+cos(num[2])),(exp(num[3])+cos(num[3])),(exp(num[4])+cos(num[4]))));
  

}