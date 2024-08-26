/*2929 - beecrowd - Menor da Pilha*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void remover(celula **lista){
  if(*lista == NULL){
    printf("EMPTY\n");
    return;
  }
  celula *descarte = *lista;
  *lista = descarte->seg;
  if(*lista!=NULL){
    (*lista)->ant = NULL;
  }
  free(descarte);
}

/*Função para percorrer a pilha e verificar o valor mínimo presente, se a pilha estiver vazia é impresso "EMPTY" se não o valor mínimo*/
void minimo(celula *lista){
  if(lista==NULL){
    printf("EMPTY\n");
    return;
  };
  celula *p = lista;
  int min = lista->num;
  while(p!=NULL){
    if(min > p->num)min = p->num;
    p = p->seg;
  }
  printf("%d\n", min);
}

int main(){
  int operacoes, i, n;
  char op[10];
  celula *pilha = NULL, *p;

  scanf("%d", &operacoes);

/*Laço para realizar as operações de acordo com o a variável operacoes*/
  for(i = 0; i < operacoes; i++){
    scanf("%s", op);
    if(strcmp(op, "PUSH")==0){
      scanf("%d", &n);
      insere(n, &pilha);
    }else if (strcmp(op, "POP")==0){
      remover(&pilha);
    }else{
      minimo(pilha);
    }
  }

  while(pilha!=NULL){
    p = pilha;
    pilha = pilha->seg;
    free(p);
  }
  
  return 0;
}