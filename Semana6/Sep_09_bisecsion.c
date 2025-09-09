#include <stdio.h>
#include <math.h>

int main (){
float f(float c){
  return (9.81*68.1)/c*(1-exp(-(c/68.1)*10))-40;
}
float a, b, K, Err_max, Err, K_old;
K=(a+b)/2;
K_old=K;
}