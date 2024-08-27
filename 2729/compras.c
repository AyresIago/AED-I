/*2729 - beecrowd - Lista de Compras*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
    char item[21];
    struct lista *seg;
}celula;

/*inserção na lista*/
void insere(char c[21], celula *p){
    celula *novo, *aux;
    novo = (celula*)malloc(sizeof(celula));
    strncpy(novo->item, c, sizeof(novo->item));
    novo->item[sizeof(novo->item)-1] = '\0';
    aux = p;
    while(aux->seg!=NULL && strcmp(novo->item, aux->seg->item)>=0){
        aux = aux->seg;
    }
    novo->seg = aux->seg;
    aux->seg = novo;
}

/*a função percorre a lista e compara c com cada item, caso seja igual retorna 0, ao contrário retorna 1*/
int compara(char c[21], celula *lista){
    celula *aux = lista->seg;
    while(aux!=NULL){
        if(strcmp(c, aux->item)==0){
            return 0;
        }
        aux = aux->seg;
    }
    return 1;
}

/*função de impressão da lista*/
void imprime(celula *lista){
    celula *a;
    for(a=lista->seg; a->seg!=NULL; a=a->seg){
        printf("%s ", a->item);
    }
    printf("%s\n", a->item);
}

int main(){
    int n, i;
    char compras[21000], *palavra;
    celula *lista= (celula*)malloc(sizeof(celula)), *aux;

    lista->seg=NULL;

    scanf("%d", &n);
    getchar();

    /*o laço recebe a string e a divide em palavras separadas por espaço, e insere na lista apenas os não repetidos, ou seja, quando compara=1*/
    for(i=0; i<n;i++){
        fgets(compras, sizeof(compras), stdin);
        palavra=strtok(compras, " \n");
        while(palavra!=NULL){
            if(compara(palavra, lista)==1){ 
                insere(palavra, lista);
            }
            palavra = strtok(NULL, " \n"); 
        }
        imprime(lista);

        while(lista->seg!=NULL){
            aux = lista->seg;
            lista->seg = aux->seg;
            free(aux);
        }
    }
    free(lista);
    return 0;
}
