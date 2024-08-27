/*1253 - beecrowd - Cifra de César*/
#include <stdio.h>
#include <string.h>

int main(){
  int n, posicoes, i, j, numascii, decodificada;
  char string[50];

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    
    scanf("%s", string);
    scanf("%d", &posicoes);
    
    for(j = 0; j < strlen(string); j++){
      /*Armazenar o numero da letra na tabela ascii*/
      numascii = (int)string[j];
      /*verificação se o deslocamento é abaixo da posição de 'A' na tabela, caso sim, a contagem retorna ao fim do alfabeto*/
      if((numascii - posicoes) < 65){
        decodificada = 91 - (65 - (numascii - posicoes));
      }else decodificada = numascii - posicoes;
      
      string[j] = (char)decodificada;
    }
    printf("%s\n", string);
  }

  return 0;
}