/*1763 - beecrowd - Tradutor do Papai Noel*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct trad{
  char pais[20];
  char palavra[30];
}traducao;

typedef struct cel{
  traducao nacao;
  struct cel *seg;
}celula;

/*Inserção de cada país e sua respectiva tradução de "Feliz Natal!" na lista*/
void insere(char p[20], char t[30], celula **lista){
  celula *nova = malloc(sizeof(celula));

  strncpy(nova->nacao.pais, p, sizeof(nova->nacao.pais)-1);
  nova->nacao.pais[sizeof(nova->nacao.pais)-1] = '\0';
  strncpy(nova->nacao.palavra, t, sizeof(nova->nacao.palavra)-1);
  nova->nacao.palavra[sizeof(nova->nacao.palavra)-1] = '\0';

  nova->seg = *lista;
  *lista = nova;
}

/*Função de busca para encontrar e imprimir a frase de cada país, se não encontrar é impresso "--- NOT FOUND ---"*/
void busca(char n[20], celula *lista){
  celula *p = lista;

  while(p!=NULL && strcmp(n, p->nacao.pais)!=0){
    p = p->seg;
  }
  if(p!=NULL){
    printf("%s\n", p->nacao.palavra);
  }else{
    printf("--- NOT FOUND ---\n");
  }
}

int main(){
  char nome[20];
  celula *lista = NULL;

  insere("brasil","Feliz Natal!" , &lista);
  insere("alemanha","Frohliche Weihnachten!" , &lista);
  insere("austria", "Frohe Weihnacht!", &lista);
  insere("coreia", "Chuk Sung Tan!", &lista);
  insere("espanha", "Feliz Navidad!", &lista);
  insere("grecia", "Kala Christougena!", &lista);
  insere("estados-unidos", "Merry Christmas!", &lista);
  insere("inglaterra", "Merry Christmas!", &lista);
  insere("australia", "Merry Christmas!", &lista);
  insere("portugal", "Feliz Natal!", &lista);
  insere("suecia", "God Jul!", &lista);
  insere("turquia", "Mutlu Noeller", &lista);
  insere("argentina", "Feliz Navidad!", &lista);
  insere("chile", "Feliz Navidad!", &lista);
  insere("mexico", "Feliz Navidad!", &lista);
  insere("antardida", "Merry Christmas!", &lista);
  insere("canada", "Merry Christmas!", &lista);
  insere("irlanda", "Nollaig Shona Dhuit!", &lista);
  insere("belgica", "Zalig Kerstfeest!", &lista);
  insere("italia", "Buon Natale!", &lista);
  insere("libia", "Buon Natale!", &lista);
  insere("siria", "Milad Mubarak!", &lista);
  insere("marrocos", "Milad Mubarak!", &lista);
  insere("japao", "Merii Kurisumasu!", &lista);
  
  while(scanf("%19s", nome)!=EOF){
    busca(nome, lista);
  }

  celula *aux;
  while(lista!=NULL){
    aux = lista;
    lista = lista->seg;
    free(aux);
  }

  return 0;
}