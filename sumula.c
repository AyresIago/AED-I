/*3422 - beecrowd - José e a Súmula*/
#include <stdio.h>

/*struct para armazenar o tempo decorrido na atual etapa da partida*/
typedef struct tempo{
  int tempo;
  int etapa;
}tempo;

int main(){
  int n, cont = 0, conversao, acrescimos;
  tempo decorrido;
  char c;

  scanf("%d", &n);

/*laço para realizar os casos de teste*/
  while(cont < n){
    scanf("%d %d%c", &decorrido.tempo, &decorrido.etapa, &c);

    if(decorrido.etapa == 2){
      if(decorrido.tempo > 45){
        acrescimos = decorrido.tempo - 45;
        printf("90+%d\n", acrescimos);
      }else{
        conversao = decorrido.tempo + 45;
        printf("%d\n", conversao);
      }
    }else{
      if(decorrido.tempo > 45){
        acrescimos = decorrido.tempo - 45;
        printf("45+%d\n", acrescimos);
      }else{
        printf("%d\n", decorrido.tempo);
      }
    }
    cont++;
  }

  return 0;
}