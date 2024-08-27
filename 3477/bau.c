/*3477 - beecrowd - Baú Danificado*/
#include <stdio.h>

/*Função para calcular a área de um semicírculo e um triângulo retângulo, cujas áreas somadas são necessárias restaurar de acordo com o exercício*/
void area(int x, int y, int z){
  double triangulo, circulo, raio; 
  int restauracao;

  raio = (double)z/2;
  circulo = 3*(raio*raio);
  triangulo = (double)(y*z)/2;

  restauracao = (int)(triangulo + (circulo/2));

  printf("AREA = %d\n", restauracao);
  
}

int main(){
  int x, y, z;

  scanf("%d %d %d", &x, &y, &z);

/*Caso as entradas não resultem no teorema de pitágoras o triângulo não é retângulo*/
  if(((y*y)+(z*z))!=(x*x)){
    printf("Nao eh retangulo!\n");
    return 0;
  }

  area(x, y, z);

  return 0;

}