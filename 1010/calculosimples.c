/*1010 - Cálculo Simples*/
#include <stdio.h>
 
int main() {
  int p1, n1, p2, n2;
  double v1, v2, t1, t2, total;
  
  scanf("%d %d %lf", &p1, &n1, &v1);
  scanf("%d %d %lf", &p2, &n2, &v2);
  
  t1 = (double)n1*v1;
  t2 = (double)n2*v2;
  
  total = t1 + t2;
  
  printf("VALOR A PAGAR: R$ %.2lf\n", total);
    
    
    return 0;
}