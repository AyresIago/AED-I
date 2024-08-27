/*1028 - beecrowd - Figurinhas*/
#include <stdio.h>
/*A função calcula o máximo divisor comum dos valores n1 e n2*/
int mdc(int n1, int n2){
  int resto;
  while(n2!=0){
    resto = n1%n2;
    n1 = n2;
    n2 = resto;
  }
  return n1;
}

int main(){
  int n, i, figurinha1, figurinha2, trocas_max;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d %d", &figurinha1, &figurinha2);
    trocas_max = mdc(figurinha1, figurinha2);
    printf("%d\n", trocas_max);
  }
  return 0;
}