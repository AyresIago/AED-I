/*1214 - beecrowd - Acima da Média*/
#include <stdio.h>
#include <stdlib.h>

int main(){
  int c, n, i, j, *v;
  float soma, cont, media, percentual;

  scanf("%d", &c);
  for(i = 0; i < c; i++){
    
    soma = 0;
    cont = 0;
    
    scanf("%d", &n);

    v = malloc(n * sizeof(int));
    
    for(j = 0; j < n; j++){
      scanf("%d", &v[j]);
      soma += v[j];
    }
    
    media = soma/n;
    
    for(j = 0; j < n; j++){
      if(v[j] > media)cont++;
    }
    percentual = cont/n*100;
    printf("%.3f%%\n", percentual);
    free(v);
  }
  return 0;
}