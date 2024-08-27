/*3160 - beecrowd - Amigos*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel{
  char nome[21];
  struct cel *seg;
}celula;

void insere(char n[21], celula **lista){
  celula *nova = (celula*)malloc(sizeof(celula));
  strncpy(nova->nome, n, sizeof(nova->nome));
  nova->seg = NULL;
  if(*lista==NULL){
    *lista = nova;
  }else{
    celula *p = *lista;
    while(p->seg!=NULL){
      p = p->seg;
    }
    p->seg = nova;
  }
}

/*A funçao insere n antes da celula que contém indicacao na lista, caso não encontre, n é inserido no final*/
void insere_busca(char indicacao[21], char n[21], celula **lista){
  celula *nova=(celula*)malloc(sizeof(celula));
  celula *p, *q;
  strncpy(nova->nome, n, sizeof(nova->nome));
  p = *lista;
  q = NULL;
  while(p!=NULL && strcmp(p->nome, indicacao)!=0){
    q = p;
    p = p->seg;
  }
  nova->seg = p;
  if(q==NULL){
    *lista = nova;
  }else{
    q->seg = nova;
  }
}

void imprimir(celula *lista){
    celula *p;
    for(p=lista; p->seg!=NULL; p=p->seg){
        printf("%s ", p->nome);
    }
    printf("%s", p->nome);
}

int main(){
  char amigos[1000], novos_amigos[1000], *nome, indicado[20];
  celula *lista_amigos = NULL, *aux;

/*Ao receber a string amigos, cada nome é separado e inserido individualmente na lista_amigos*/
  fgets(amigos, sizeof(amigos), stdin);
  nome = strtok(amigos, " \n");
  while(nome!=NULL){
    insere(nome, &lista_amigos);
    nome = strtok(NULL, " \n"); 
  }

  fgets(novos_amigos, sizeof(novos_amigos), stdin);

  fgets(indicado, sizeof(indicado), stdin);
  indicado[strcspn(indicado, "\n")] = '\0';

/*Os nomes da string novos_amigos, para o caso em que não haja indicados, são inseridos no final da lista*/
  if(strcmp(indicado, "nao")==0){
    nome = strtok(novos_amigos, " \n");
    while(nome != NULL){
      insere(nome, &lista_amigos);
      nome = strtok(NULL, " \n");
    }
  }else{
    nome = strtok(novos_amigos, " \n");
    while(nome != NULL){
      insere_busca(indicado, nome, &lista_amigos);
      nome = strtok(NULL, " \n");
    }
  }
  imprimir(lista_amigos);

  while(lista_amigos!=NULL){
    aux = lista_amigos;
    lista_amigos = lista_amigos->seg;
    free(aux);
  }
  return 0;
  }
