/*2958 - beecrowd - O Rolê Bad Vibes*/
#include <stdio.h>
#include <stdlib.h>
/*Função ordena decrescente, em que recebe os parâmetros n e v*/
void insercao_decrescente(int n, int v[]){
  int i, j, x;

  for(j = 1; j < n; j++){
    x = v[j];
    for(i = j-1; i >= 0 && v[i]<x; i--){
      v[i+1] = v[i];
    }
    v[i+1] = x;
  }
}

int main(){
  int n, m, i, total, cont1 = 0, cont2 = 0, *v1, *v2, num;
  char problema;

  scanf("%d %d", &n, &m);

  total = m*n;
  v1 = malloc(total*sizeof(int));
  v2 = malloc(total*sizeof(int));

  /*Os vetores são construídos conforme as entradas, portanto, se problema = 'v' é inserido no vetor v1, se é 'D', no vetor v2.*/
  for(i = 0; i < total; i++){
    scanf("%d%c", &num, &problema);
    if(problema == 'V'){
      v1[cont1] = num;
      cont1++;
    }
    if(problema == 'D'){
      v2[cont2] = num;
      cont2++;
    }
  }

  insercao_decrescente(cont1, v1);
  insercao_decrescente(cont2, v2);

  for(i = 0; i<cont1; i++){
    printf("%dV\n", v1[i]);
  }

  for(i = 0; i<cont2; i++){
    printf("%dD\n", v2[i]);
  }

  return 0;
}