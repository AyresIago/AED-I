/*1281 - beecrowd - Ida à Feira*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto{
  char nome[50];
  float preco;
}prod;

typedef struct cel{
  prod item;
  struct cel *seg;
}celula;

void insere(char n[50], float y, celula **lista){
   celula *nova = (celula*)malloc(sizeof(celula));
   strcpy(nova->item.nome, n);
   nova->item.preco = y;
   nova->seg = *lista;
   *lista = nova;
}

float busca(char e[50], celula *lista){
  celula *p = lista;
  float y;
  while(p!=NULL && strcmp(p->item.nome, e)!=0){
    p = p->seg;
  }
  y = p->item.preco;
  return y;
}

int main(){
  int n, m, p, quantidade, i, j;
  float preco, custo_unidade;
  char produto[50], escolha[50];
  celula *feira = NULL, *aux;

  scanf("%d", &n);

  float custo_total[n];

  for(i=0; i<n; i++){
    scanf("%d", &m);
    for(j=0; j<m; j++){
      scanf("%s", produto);
      scanf("%f", &preco);
      insere(produto, preco, &feira);
    }
    scanf("%d", &p);
    custo_total[i] = 0;
    for(j=0; j<p; j++){
      scanf("%s", escolha);
      scanf("%d", &quantidade);
      custo_unidade = busca(escolha, feira)*quantidade;
      custo_total[i] += custo_unidade;
    }
    feira = NULL;
  }
  for(i=0; i<n; i++){
    printf("R$ %.2f\n", custo_total[i]);
  }

  while(feira!=NULL){
    aux = feira;
    feira = feira->seg;
    free(aux);
  }
return 0;
}