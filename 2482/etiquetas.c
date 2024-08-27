/*2482 - beecrowd - Etiquetas do Noel*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Registro para armazenar cada idioma e sua respectiva frase.*/
typedef struct feliznatal{
  char idioma[50];
  char frase[50];
}lingua;


typedef struct cel{
  lingua feliz_natal;
  struct cel *seg;
}celula;

/*A função insere o idioma e a frase em cada nó da lista duplamente encadeda*/
void insere(char i[50], char f[50], celula **lista){
  celula *nova = malloc(sizeof(celula));
  strncpy(nova->feliz_natal.idioma, i, sizeof(nova->feliz_natal.idioma)-1);
  nova->feliz_natal.idioma[sizeof(nova->feliz_natal.idioma)-1] = '\0';
  strncpy(nova->feliz_natal.frase, f, sizeof(nova->feliz_natal.frase)-1);
  nova->feliz_natal.frase[sizeof(nova->feliz_natal.frase)-1] = '\0';
  nova->seg = *lista;
  *lista = nova;
}

/*A função busca na lista o idioma i e imprime a frase*/
void busca(char i[50], celula *lista){
  celula *p = lista;
  while(p!=NULL && strcmp(p->feliz_natal.idioma, i)!=0){
    p = p->seg;
  }
  if(p!=NULL){
    printf("%s\n", p->feliz_natal.frase);
  }
}

int main(){
  int i, n, m;
  char lingua[20], frase[25], nome[20], l[20];
  celula *lista = NULL;

  scanf("%d", &n);
  getchar();

  /*laço para as entradas do idioma e a frase e inserção na lista*/
  for(i=0; i<n; i++){
    fgets(lingua, sizeof(lingua), stdin);
    lingua[strcspn(lingua, "\n")] = '\0';
    
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';
    
    insere(lingua, frase, &lista);
  }

  scanf("%d", &m);
  getchar();

  /*laço para as entradas dos nomes e nacionalidade e imprimir a saída*/
  for(i=0; i<m; i++){
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    
    scanf("%s", l);
    getchar();
    
    printf("%s\n", nome);
    
    busca(l, lista);
  }

  celula *aux;
  while(lista!=NULL){
    aux = lista;
    lista = lista->seg;
    free(aux);
  }

  return 0;
}