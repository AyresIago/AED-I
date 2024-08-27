/*3467 - beecrowd - Esse é o meu lugar!*/
#include <stdio.h>
#include <string.h>

int main(){
  char sofa[4];
  int i;

/*A entrada se encerra com o fim de arquivo*/
  while(scanf(" %c", &sofa[0])!=EOF){ 
    for(i = 1; i < 3; i++){
      scanf(" %c", &sofa[i]);
    }
/*adição do carácter nulo na string*/
    sofa[3] = '\0';
/*Se o lado esquerdo do sofá estiver ocupado, ou seja, sofa[2]=='l' é impresso "Esse eh meu lugar", caso contrário, é impresso "Oi, Leonard"*/
    if(sofa[2] == 'L'){
      printf("Esse eh meu lugar\n");
    }else if(sofa[2]=='x'){
      printf("Oi, Leonard\n");
    }
  }

  return 0;
}