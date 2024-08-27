/*1008 - beecrowd - Salário*/
#include <stdio.h>
 
 void salario(int n, int h, double v){
     double salario = (double)h*v;
     
     printf("NUMBER = %d\n", n);
     printf("SALARY = U$ %.2lf\n", salario);
 }
 
int main() {
 int numero, horas;
 double v;
 
 scanf("%d", &numero);
 scanf("%d", &horas);
 scanf("%lf", &v);
 
 salario(numero, horas, v);
 
    return 0;
}