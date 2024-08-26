/*1245 - beecrowd - Botas Perdidas*/
#include <stdio.h>
#include <stdlib.h>

/*Struct para armazenar o tamanho e o lado da bota*/
typedef struct botas{
  int num;
  char pe;
}bota;

/*Implementação de uma lista encadeada*/
typedef struct cel{
  bota par;
  struct cel *seg;
}celula;

/*função de inserção na lista*/
void insere(int n, char p, celula **lista){
  celula *nova = malloc(sizeof(celula));
  nova->par.num = n;
  nova->par.pe = p;
  nova->seg = *lista;
  *lista = nova;
}

/*A função compara os parâmetros com as botas já inseridas na lista e,
caso encontre o par correspondente esse é retirado da lista e a função retorna 1, caso contrário, retorna 0*/
int compara(int n, char par, celula **lista){
  if(lista==NULL)return 0;
  else{
    celula *descarta, *p = *lista, *q = NULL;

    while(p!=NULL){
      if(p->par.num == n){
        if(p->par.pe != par){
          descarta = p;
          p = p->seg;
          if(q == NULL){
            *lista = p;
          }else{
            q->seg = p;
          }
          free(descarta);
          return 1;
        }
      }
      q = p;
      p = p->seg;
    }
  }
  return 0;
}

int main(){
  int n, i, numero, par, cont, verifica;
  celula *lista = NULL;

  while(scanf("%d", &n)!=EOF){
    cont = 0;
    for(i = 0; i < n; i++){
      scanf("%d %c", &numero, &par);
      
      /*A entrada é inserida na lista apenas se não houver o par, verificado pela função compara, se houver, cont é incrementado*/
      verifica = compara(numero, par, &lista);

      if(verifica == 1){
        cont++;
      }else{
        insere(numero, par, &lista);
      }
    }

    printf("%d\n", cont);

    celula *aux;
    while(lista!=NULL){
      aux = lista;
      lista = lista->seg;
      free(aux);
    }
  }

  return 0;
}