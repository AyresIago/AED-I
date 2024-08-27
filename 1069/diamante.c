/*1069 - beecrowd - Diamantes e Areia*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel{
  char diamante;
  struct cel *seg;
}celula;

void insere(char d, celula **lst){
  celula *nova;
  nova = malloc(sizeof(celula));
  nova->diamante = d;
  nova->seg = *lst;
  *lst = nova;
}

void remover(celula **lst){
  celula *descarta;
  descarta = *lst;
  *lst = descarta->seg;
  free (descarta);
}

int main(){
  int n, i, j, tam, cont;
  char minerio[1002];
  celula *lista;

  scanf("%d", &n);

  for(i=1; i<=n; i++){
    fgets(minerio, sizeof(minerio), stdin);
    
    tam = strlen(minerio);
    cont = 0;
    j=0;
    lista = NULL;

    for(j=0; j<tam; j++){
      if(minerio[j] == '<'){
        insere(minerio[j], &lista);
      }
      else if(minerio[j] == '>'){
        if(lista!=NULL && lista->diamante == '<'){
        remover(&lista);
        cont++;
        }
      }
    }
    printf("%d\n", cont);
  }

  while(lista!=NULL){
    celula *aux = lista;
    lista = lista->seg;
    free(aux);
  }

  return 0;
}