/*3454 - beecrowd - Alice no País do Jogo da Velha*/
#include <stdio.h>
#include <stdlib.h>

int main(){
  int verifica = 0, verifica_alice = 0, i = 0;
  char velha[4];

/*Entrada das jogadas*/
  for(i = 0; i < 3; i++){
    scanf("%c", &velha[i]);
    if(velha[i]=='O')verifica++;
    if(velha[i]=='X')verifica_alice++;
  }

/*Verifica se as jogadas de Bob e Alice estão conforme o exercício*/
  if(verifica > 1 || verifica_alice > 2){
    printf("?\n");
    return 0;
  }

/*Verificação em caso de vitória ou empate*/
  if(velha[1]=='X'){
    printf("Alice\n");
  }else{
    printf("*\n");
  }

  return 0;
}