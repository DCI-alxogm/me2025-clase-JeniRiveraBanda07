#include <stdio.h>
#include <math.h>

int main()
{
 double X_0=0 , f_0=1.2;
 double X_1=0.5, f_1=0.925;
 double X_2=1, f_2=0.2;
 double dif_adel=(f_2-f_1)/(X_2-X_1);
 double dif_atras=(f_1-f_0)/(X_1-X_0);
 double dif_centr=(f_2-f_0)/(X_2-X_0);
 double Er=-0.9125;
 double Er_adel=((Er-dif_adel)/Er)*100;
  double Er_atras=((Er-dif_atras)/Er)*100;
   double Er_centr=((Er-dif_centr)/Er)*100;
 printf("La primera derivada hacia adeltante:%.5f\n",dif_adel);
printf("La primera derivada hacia atras:%.5f\n",dif_atras);
 printf("La primera derivada centrada:%.5f\n",dif_centr);
printf("Error relativo adeltante:%.5f%%\n", Er_adel);
printf("Error relativo atras:%.5f%%\n", Er_atras);
printf("Error relativo centrada:%.5f%%\n", Er_centr);
}