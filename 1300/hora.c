/*1300 - beecrowd - Horas e Minutos*/
#include <stdio.h>

/*A função recebe o angulo, calcula a diferença dos angulos dos ponteiros das horas e minutos e verifica se existe no relógio, caso sim imprime Y, ao contrário, N.*/
  void existe_angulo(int ang){
    int i, a, cont = 1, hora = 0, min = 0;

    while(a!=ang && hora < 360){
      a = min - hora;
      min += 6;
      cont++;
      if(cont == 12){
        hora += 6;
        cont = 0;
      }
    }
  
    if(a == ang){
      printf("Y\n");
    }else{
      printf("N\n");
    }
  }

int main(){
  int angulo;

  while(scanf("%d", &angulo)!=EOF){ 
    existe_angulo(angulo);
  }
  return 0;
}