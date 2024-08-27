/*1242 - beecrowd - Ácido Ribonucleico Alienígina*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel{
  char base;
  struct cel *seg;
}celula;

void push(char b, celula *p){
  celula *nova = malloc(sizeof(celula));
  nova->base = b;
  nova->seg = p->seg;
  p->seg = nova;
}

void pop(celula *p){
  if(p->seg!=NULL){ 
    celula *q = p->seg;
    p->seg = q->seg;
    free(q);
  }
}

int ligacoes(char *r){
  celula cabeca;
  cabeca.seg = NULL;
  celula *rna = &cabeca; 
  int i, cont=0;

  for(i=0; i<strlen(r); i++){
    if(rna->seg==NULL){
      push(r[i], rna);
      continue;
    }
    switch (r[i])
    {
    case 'B':
      if(rna->seg->base=='S'){
        pop(rna);
        cont++;
      }else{
        push(r[i], rna);
      }
      break;
    
    case 'S':
      if(rna->seg->base=='B'){
        pop(rna);
        cont++;
      }else{
        push(r[i], rna);
      }
      break;
    
    case 'F':
      if(rna->seg->base=='C'){
        pop(rna);
        cont++;
      }else{
        push(r[i], rna);
      }
      break;
    
    case 'C':
      if(rna->seg->base=='F'){
        pop(rna);
        cont++;
      }else{
        push(r[i], rna);
      }
      break;
    }
  }
  
  celula *aux;
  while(rna->seg!=NULL){
    aux = rna->seg;
    rna->seg = rna->seg->seg;
    free(aux);
  }
  return cont;
}

int main(){
  char rnaa[300];
  int lig;

  while(scanf("%s", rnaa)!=EOF){
    lig = ligacoes(rnaa);
    printf("%d\n", lig);
  }
  return 0;
}