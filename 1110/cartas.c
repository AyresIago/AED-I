/*1110 - beecrowd - Jogando Cartas fora*/
#include <stdio.h>
#include <stdlib.h>

/*implementação de uma lista encadeada dupla*/
typedef struct cel{
  int num;
  struct cel *seg;
  struct cel *ant;
}celula;

void insere(int y, celula **lista){
  celula *nova = malloc(sizeof(celula));
  nova->num = y;
  nova->seg = *lista;
  nova->ant = NULL;
  if(*lista!=NULL){
    (*lista)->ant = nova;
  }
  *lista = nova;
}

/*A função remove o item do topo da lista*/
int remover(celula **lista){
  celula *descarte = *lista;
  int n = descarte->num;
  *lista = descarte->seg;
  if(*lista!=NULL){
    (*lista)->ant = NULL;
  }
  free(descarte);
  return n;
}

/*A função insere y na base(final) da lista*/
void insere_base(int y, celula **lista){
  celula *nova = malloc(sizeof(celula)), *p = *lista;
  nova->num = y;
  nova->seg = NULL;
  if(p == NULL){
    nova->ant = NULL;
    *lista = nova;
    return;
  }
  while(p->seg!=NULL){
    p = p->seg;
  }
  p->seg = nova;
  nova->ant = p;
}

int main(){
  int n, i, base;
  celula *pilha = NULL;

  scanf("%d", &n);
  
  while(n!=0){
    int *descartada = malloc((n-1)*sizeof(int));
    for(i=n; i>0; i--){
      insere(i, &pilha);
    }
    for(i=0; i<n-1; i++){
      descartada[i]=remover(&pilha);
      base = remover(&pilha);
      insere_base(base, &pilha);
    }

    if(n>1){ 
      printf("Discarded cards:");
      for(i=0; i<n-2; i++){
        printf(" %d,", descartada[i]);
      }
      printf(" %d\n", descartada[n-2]);
    }else{
      printf("Discarded cards:\n");
    }
    printf("Remaining card: %d\n", pilha->num);

    celula *aux;
      while(pilha!=NULL){
        aux = pilha;
        pilha = pilha->seg;
        free(aux);
      }
      free(descartada);
      scanf("%d", &n);
  }
  return 0;
}