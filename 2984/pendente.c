/*2984 - Beecrowd - Assuntos Pendentes*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*A função recebe a string e seu tamanho para calcular o número de pendências de acordo com os numeros de "(", e imprime as saídas conforme o enunciado.*/
void pendencias(int n, char v[]){
  int i, pendencias = 0;

  for(i = 0; i < n; i++){
    if(v[i] == ')'){
      if(pendencias > 0)pendencias--;
    }else{
      pendencias++;
    }
  }

  if(pendencias > 0){
    printf("Ainda temos %d assunto(s) pendente(s)!\n", pendencias);
  }else{
    printf("Partiu RU!\n");
  }
}

int main(){
  char string[100000];
  int i, n;

  scanf("%s", string);
  
  n = strlen(string);

  pendencias(n, string);

  return 0;
}