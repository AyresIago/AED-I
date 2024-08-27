/*2460 - beecrowd - Fila*/
#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
  int id;
  struct cel *seg;
}celula;

void insere(int y, celula **ei, celula **ef){
  celula *nova, *p;
  nova = malloc(sizeof(celula));
  nova->id = y;
  nova->seg = NULL;

  if(*ei == NULL){
    *ei = nova;
  }else{
    (*ef)->seg = nova;
  }
  *ef = nova;
}

/*A função remove a célula cujo conteúdo é igual a y da fila*/
void remover(int y, celula **ei, celula **ef){
  celula *p, *q;
  p = *ei;
  q = NULL;

  while(p!=NULL && p->id!=y){
    q = p;
    p = p->seg;
  }
  if(p!=NULL){
    if(q==NULL){
      *ei = p->seg;
    }else{
      q->seg = p->seg;
    }
    if(p == *ef){
      *ef = q;
    }
    free(p);
  }
}

void imprimir(celula *lista){
  while(lista!=NULL){
    printf("%d ", lista->id);
    lista = lista->seg;
  }
}

int main(){
  int n, identificacao, m, i, retira;
  celula *fila = NULL, *ultimo = NULL;

  scanf("%d", &n);
  if(n<1 || n>50000){
    return 0;
  }

  for(i=0; i<n; i++){
    scanf("%d", &identificacao);
    insere(identificacao, &fila, &ultimo);
  }

  scanf("%d", &m);
  if(m<1 || m>50000 || m>n){
    return 0;
  }

  for(i=0; i<m; i++){
    scanf("%d", &retira);
    remover(retira, &fila, &ultimo);
  }

  imprimir(fila);
  
  celula *p;
  while(fila!=NULL){
    p = fila;
    fila = fila->seg;
    free(p);
  }
  return 0;
}