/*2136 - beecrowd - Amigos do Habay*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct cel{
  char nome[20];
  struct cel *seg;
}celula;

void insere(char n[20], celula **lista){
  celula *nova = malloc(sizeof(celula));
  strncpy(nova->nome, n, sizeof(nova->nome) - 1);
  nova->nome[sizeof(nova->nome)-1] = '\0';

  if(*lista == NULL || strcmp(n, (*lista)->nome)<0){
    nova->seg = *lista;
    *lista = nova;
  } else {
    celula *p = *lista;
    while(p->seg != NULL && strcmp(n, p->seg->nome)>=0){
      p = p->seg;
    }
    nova->seg = p->seg;
    p->seg = nova;
  }
}

int verifica_repeticao(char n[20], celula *lista){
  celula *p = lista;
  while(p != NULL){
    if(strcmp(n, p->nome) == 0){
      return 1;
    }
    p = p->seg;
  }
  return 0;
}

void imprime(celula *lista){
  celula *p = lista;

  while(p != NULL){
    printf("%s\n", p->nome);
    p = p->seg;
  }
}

int main(){
  char nome[20], confirma[4], vencedor[20] = "";
  int verifica, tam;
  celula *lista_habay = NULL, *recusa = NULL, *aux;

  scanf("%s", nome);
  
  while(strcmp(nome, "FIM") != 0){
    
    scanf("%s", confirma);

    if(strcmp(confirma, "YES") == 0){
      verifica = verifica_repeticao(nome, lista_habay);
      if(verifica == 0){
          tam = strlen(nome);
          if(strlen(vencedor) == 0 || tam > strlen(vencedor)){
            strcpy(vencedor, nome);
          }
        insere(nome, &lista_habay);
      }
    }else{
      insere(nome, &recusa);
    }
    scanf("%s", nome);
  }

  imprime(lista_habay);
  imprime(recusa);
  printf("\n");
  printf("Amigo do Habay:\n%s\n", vencedor);
  
  while(lista_habay != NULL){
    aux = lista_habay;
    lista_habay = lista_habay->seg;
    free(aux);
  }

  while(recusa != NULL){
    aux = recusa;
    recusa = recusa->seg;
    free(aux);
  }

  return 0;
}