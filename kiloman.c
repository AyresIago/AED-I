/*1250 - beecrowd - KiloMan*/
#include <stdio.h>
#include <stdlib.h>

int main(){
  int n, i, j, t, *tiros, cont;
  char *pulos;

/*Número de casos de teste*/
  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &t);
    
    /*alocação dinâmica de memória para o vetor tiros e a string pulos*/
    tiros = (int*)malloc(t*sizeof(int));

    pulos = (char*)malloc(t*sizeof(char));

    cont = 0;

    for(j = 0; j < t; j++){
      scanf("%d", &tiros[j]);
    }

    for(j = 0; j < t; j++){
      scanf(" %c", &pulos[j]);

/*cont é incrementado caso em que o tiro é numa altura menor que 2 e a ação do personagem é permanecer parado 
ou se o tiro for maior que 2 e o personagem pular*/
      if((tiros[j] <= 2 && pulos[j] == 'S') || tiros[j] > 2 && pulos[j] == 'J')cont++;
    }

    printf("%d\n", cont);

/*liberação de memória alocaada para tiros e pulos*/
    free(tiros);
    free(pulos);
  }

  return 0;
}