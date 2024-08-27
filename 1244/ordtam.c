/*1244 - beecrowd - Ordenação por Tamanho*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Implementação de uma lista encadeada para inserção das strings*/
typedef struct cel{
  char palavra[50];
  struct cel *seg;
}celula;

/*A função abaixo insere a string p em uma lista encadeada sem cabeça e coloca na posição ordenada de acordo com o tamanho de p.*/
void insere(char p[50], celula **lista){
  celula *nova = malloc(sizeof(celula));
  strncpy(nova->palavra, p, sizeof(nova->palavra));
  nova->palavra[sizeof(nova->palavra)-1] = '\0';
  nova->seg = NULL;
  if(*lista == NULL||strlen((*lista)->palavra) < strlen(nova->palavra)){
    nova->seg = *lista;
    *lista = nova;
  }else{ 
    celula *aux = *lista;
    while(aux->seg!=NULL && strlen(aux->seg->palavra)>=strlen(nova->palavra)){
      aux = aux->seg;
    }
    nova->seg = aux->seg;
    aux->seg = nova;
  }
}

/*A função abaixo recebe o vetor v, o qual contém as palavras, e divide a fim de inserir separadamente cada palavra na lista e imprimi-la*/
void ordenacao(char v[2500]){ 
  celula *lista = NULL, *aux, *f;
  char *p;
  
  p = strtok(v, " ");
  while(p!=NULL){
    insere(p, &lista);
    p = strtok(NULL, " "); 
  }

  aux = lista;
  while(aux!=NULL){
    printf("%s", aux->palavra);
    aux = aux->seg;
    if(aux!=NULL){
      printf(" ");
    }
  }
  while(lista!=NULL){
    f = lista;
    lista = lista->seg;
    free(f);
  }
}

int main(){
  int tam, n, i;
  char entrada[2500];

  scanf("%d", &n); 
  getchar();

  for(i=0; i<n; i++){
    fgets(entrada, sizeof(entrada), stdin);
    size_t tam = strlen(entrada);
    if(tam>0 && entrada[tam-1]=='\n'){
      entrada[tam-1]='\0';
    }
    ordenacao(entrada);
    printf("\n");
  }
  return 0;
}