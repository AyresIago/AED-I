/*1168 - beecrowwd - LED*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct valor{
  char num;
  int led;
}valor;

typedef struct cel{
  valor item;
  struct cel *seg; 
}celula;

void insere(char l, int c, celula **lista){
  celula *nova = malloc(sizeof(celula));
  nova->item.num = l;
  nova->item.led = c;
  nova->seg = *lista;
  *lista = nova;
}


/*A função busca l na lista e retorna o número de leds necessário*/
int busca(char l, celula *lista){
  celula *p = lista;
  while(p != NULL && p->item.num != l){
    p = p->seg;
  }
  if(p == NULL)return 0;

  return p->item.led;
}

int main(){
  int n, i, j, tam, leds;
  char string[10000];
  celula *lista = NULL, *aux;

  insere('1', 2, &lista);
  insere('2', 5, &lista);
  insere('3', 5, &lista);
  insere('4', 4, &lista);
  insere('5', 5, &lista);
  insere('6', 6, &lista);
  insere('7', 3, &lista);
  insere('8', 7, &lista);
  insere('9', 6, &lista);
  insere('0', 6, &lista);

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%s", string);
    leds = 0;
    tam = strlen(string);
    
    /*O laço percorre a string e incrementa a variável leds de acordo com o número da posição j*/
    for(j = 0; j < tam; j++){
      leds += busca(string[j], lista);
    }
    printf("%d leds\n", leds);
  }

  while(lista!=NULL){
    aux = lista;
    lista = lista->seg;
    free(aux);
  }
  return 0;
}