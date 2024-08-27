/*2633 - beecrowd - Churras no Yuri*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct churras{
  char nome[20];
  int validade;
}carne;

/*O algoritmo de inserção ordena o vetor em ordem crescente*/
void insercao_crescente(int n, carne v[]){
  int i, j; 
  carne x;

  for(j = 1; j < n; j++){
    x = v[j];
    for(i = j-1; i >= 0 && v[i].validade>x.validade; i--){
      v[i+1] = v[i];
    }
    v[i+1] = x;
  }
}

int main(){
  int n, i, valido_ate;
  char nome[20];
  carne *v;

  while(scanf("%d", &n)!=EOF){
    v = malloc(n*sizeof(carne));
    for(i = 0; i < n; i++){
      scanf("%s %d", &v[i].nome, &v[i].validade);
    }

    insercao_crescente(n, v);

    for(i = 0; i < n-1; i++){
      printf("%s ", v[i].nome);
    }
    printf("%s\n", v[n-1].nome);

    free(v);
  }
}


