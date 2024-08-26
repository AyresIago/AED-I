/*2495 - beecrowd - Onde Está Minha Caneta?*/
#include <stdio.h>
#include <stdlib.h>

int main(){
  int n, i, devolvida, soma_conjunto, soma_devolvidas, *canetas, cont, faltante;

  while(scanf("%d", &n)!=EOF){ 

    canetas = malloc(n*sizeof(int)+1);
    cont = 0;
    soma_conjunto = 0;
    soma_devolvidas = 0;

/*através do laço é somado o numero de cada caneta do conjunto, e enquanto i < n é armazenado em um vetor os números das canetas devolvidas*/
    for(i = 1; i <= n; i++){
      if(i < n){ 
        scanf("%d", &devolvida);
        canetas[cont] = devolvida;
        cont++;
      }
      soma_conjunto += i;
    }

/*Nesse laço realiza-se a soma dos numeros das canetas devolvidas*/
    for(i = 0; i < cont; i++){
      soma_devolvidas += canetas[i];
    }

/*Para encontrar a faltante basta subtrair a soma das canetas devolvidas da soma do conjunto completo*/
    faltante = soma_conjunto - soma_devolvidas;

    printf("%d\n", faltante);
  }
  return 0;
}