/*3357 - beecrowd - Rico do Mate*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel{
  char nome[21];
  struct cel *seg;
}celula;

void insere(char nome[21], celula **lista, celula **ultimo){
  celula *nova = malloc(sizeof(celula));
  strncpy(nova->nome, nome, sizeof(nova->nome));
  nova->nome[sizeof(nova->nome)-1] = '\0';
  nova->seg = *lista;
  if(*lista==NULL){
    *lista = nova;
    *ultimo = nova;
  }else{
    (*ultimo)->seg = nova;
    *ultimo = nova;
  }
}

void rico(float litros, float cuia, celula *circulo){
  celula *p = circulo;
  while(litros>cuia){
    litros -=cuia;
    p = p->seg;
  }
  printf("%s %.1f\n", p->nome, litros);
}

int main(){
  int n, i;
  float l, q;
  char participante[21];
  celula *roda = NULL, *fim = NULL;

  scanf("%d", &n);
  scanf("%f", &l);
  scanf("%f", &q);

  for(i=0; i<n; i++){
    scanf("%s", &participante);
    insere(participante, &roda, &fim);
  }

  if(fim!=NULL){
    fim->seg = roda;
  }

  rico(l, q, roda);

  celula *aux, *p=roda;
  do{
    aux = p;
    p = p->seg;
    free(aux);
  }while(p!=roda);
  
  return 0;
}