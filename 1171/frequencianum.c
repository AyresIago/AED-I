/*1171 - beecrowd - Frequência de Números*/
#include <stdio.h>
#include <stdlib.h>

typedef struct numero{
  int num, frequencia;
}numero;

typedef struct cel{
  numero n;
  struct cel *seg;
}celula;

int compara(int v, celula *lista){
    celula *aux = lista;
    while(aux!=NULL){
        if(v==aux->n.num){
          aux->n.frequencia++;
          return 0;
        }
        aux = aux->seg;
    }
    return 1;
}

void insere_cont(int v, celula **lista){
  celula *nova = malloc(sizeof(celula)), *p, *q;
  p = *lista;
  q = NULL;
  nova->n.num = v;
  nova->n.frequencia =1;
  while(p!=NULL && p->n.num<nova->n.num){
    q = p;
    p = p->seg;
  }
  nova->seg = p;
  if(q!=NULL){
    q->seg = nova;
  }else{
    *lista = nova;
  }
}

void imprimir(celula *lista){
  celula *p;
  for(p=lista; p!=NULL; p=p->seg){
    printf("%d aparece %d vez(es)\n", p->n.num, p->n.frequencia);
  }
}

int main(){
  int n, x, i, verifica;
  celula *numeros = NULL;

  scanf("%d", &n);
  
  for(i = 0; i<n; i++){
    scanf("%d", &x);
    verifica = compara(x, numeros);
    if(verifica==1){ 
      insere_cont(x, &numeros);
    }
  }

  imprimir(numeros);

  celula *aux;
  while(numeros!=NULL){
    aux = numeros;
    numeros = numeros->seg;
    free(aux);
  }

  return 0;
}