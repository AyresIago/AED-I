/*1241 - beecrowd - Encaixa ou Não II*/
#include <stdio.h>
#include <string.h>

/* forma mais simples e objetiva utilizando aritmética de ponteiros*/
/*
void encaixa_ou_nao(char v1[], char v2[]){
  int i, t1, t2, diferenca;

  t1 = strlen(v1); t2 = strlen(v2);
  diferenca = t1 - t2;

  if(diferenca < 0){
    printf("nao encaixa\n");
  }else{ 
    if(strcmp(v1+diferenca, v2)==0)printf("encaixa\n");
    else printf("nao encaixa\n");
  }
}
*/

/*A função recebe as duas strings e compara a substring de v1 com v2 para verificar se encaixa no final da primeira.*/
void encaixa_ou_nao(char v1[], char v2[]){
  int i, t1, t2, diferenca, cont = 0;
  char  aux[1001];

  t1 = strlen(v1); t2 = strlen(v2);
  diferenca = t1 - t2;

  if(diferenca < 0){
    printf("nao encaixa\n");
  }else{ 
    for(i = diferenca; i < t1; i++){
      aux[cont] = v1[i];
      cont++;
    }
    aux[cont] = '\0';
    if(strcmp(aux, v2)==0)printf("encaixa\n");
    else printf("nao encaixa\n");
  }
}


int main(){
  int n, i;
  char a[1001], b[1001];

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%s", a);
    scanf("%s", b);
    encaixa_ou_nao(a, b);
  }
  return 0;
}