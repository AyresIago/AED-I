/*2065 - beecrowd - Fila do Supermercado*/
#include <stdio.h>
#include <stdlib.h>
/*Registro para guardar as informações de cada funcionário, as variáveis v recebe a eficiência de atendimento e tempo recebe o tempo de atendimento gerado*/
typedef struct funcionario{
  int v;
  int tempo;
}funcionario;

/*Implementação de fila em uma lista encadeada*/
typedef struct fila{
  int c;
  struct fila *seg;
}celula;

/*A função de inserir recebe a variável y, para ser o novo elemento, e os ponteiros duplos para o início e fim da fila*/
void insere(int y, celula **finicio, celula **ffim){
  celula *nova;
  nova =(celula*)malloc(sizeof(celula));
  nova->c = y;
  nova->seg = NULL;
  if(*ffim==NULL){
    *ffim = *finicio = nova;
  }else{
    (*ffim)->seg = nova;
    *ffim = nova;
  }
}
/*A função de remover da fila recebe os ponteiros duplos do início e fim da fila e retorna a variável x retirada do início da fila*/
int remover(celula **finicio, celula **ffim){
  celula *p;
  int x;
  p = *finicio;
  x = p->c;
  *finicio = p->seg;
  free(p);
  if(*finicio==NULL){
    *ffim = NULL;
  }
  return x;
}

int main(){
  int f, m, v, itens, i, j, compra, total=0, menor, num_prox;
  funcionario *n;
  celula *inicio, *fim;
 /*Inicialização da fila*/
  inicio = fim = NULL;

  scanf("%d %d", &f, &m);
 
  n = malloc(f*sizeof(funcionario));
  
  for(i=0; i<f; i++){
    scanf("%d", &n[i].v);
    n[i].tempo = 0;
  }

  for(j=0; j<m; j++){
    scanf("%d", &itens);
    insere(itens, &inicio, &fim);
  }
/*Laço de repetição para retirar os elementos da fila e calcular o tempo de atendimento */
  while(inicio!=NULL){
    menor = n[0].tempo;
    num_prox = 0;
    for(i=1; i<f; i++){
      if(n[i].tempo < menor){
        menor = n[i].tempo;
        num_prox = i;
      }
    }

    compra = remover(&inicio, &fim);
    n[num_prox].tempo += n[num_prox].v*compra;
  }
  /*Laço de repetição para calcular o tempo total de atendimento de todos os clientes*/
  for(i=0; i<f; i++){
    if(n[i].tempo > total){
      total = n[i].tempo;
    }
  }

  printf("%d", total);

  free(n);
  return 0;
}