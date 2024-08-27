/*1192 - beecrowd - O Jogo Matemático de Paula*/
#include <stdio.h>
#include <ctype.h>

void matematica(char letra, int num_1, int num_2){
  int resultado;

  if(num_1 == num_2){
    resultado = num_1*num_2;
  }else{
    if(isupper(letra)){
      resultado = num_2 - num_1;
    }else{
      resultado = num_1 + num_2;
    }
  }

  printf("%d\n", resultado);
}

int main(){
  int n, i, numero_1, l, numero_2;

  scanf("%d", &n);
  
  /*Loop para realizar cada caso de teste*/
  for(i = 0; i < n; i++){ 
    scanf("%d%c%d", &numero_1, &l, &numero_2);
    matematica(l, numero_1, numero_2);
  }
  return 0;
}