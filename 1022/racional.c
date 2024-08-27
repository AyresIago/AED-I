/*Exercício 1022 - beecrowd - TDA Racional*/
#include <stdio.h>

/*A estrutura registra o numerador e o denominador da fração*/
typedef struct racional{
  int numerador;
  char p;
  int denomindador;
}fracao;

/*A função abaixo calcula o máximo divisor comum entre o numerador e o denominador*/
int mdc(int num, int den){
  int resto;
  while(den!=0){
    resto = num%den;
    num = den;
    den = resto;
  }
  return num;
}

int main (){
  int testes, i, r_num, r_denom, simp_num, simp_den, d;
  char  operador;
  fracao f1, f2;

/*Entrada para o número de casos de testes*/
  scanf("%d", &testes);

  for(i = 0; i < testes; i++){
    scanf("%d %c %d", &f1.numerador, &f1.p, &f1.denomindador);
    scanf(" %c", &operador);
    scanf("%d %c %d", &f2.numerador, &f2.p, &f2.denomindador);

    switch (operador)
    {
    case '+':
      r_num = (f1.numerador * f2.denomindador) + (f1.denomindador * f2.numerador);
      r_denom = f1.denomindador * f2.denomindador;

      break;
    case '-':
      r_num = (f1.numerador * f2.denomindador) - (f1.denomindador * f2.numerador);
      r_denom = (f1.denomindador * f2.denomindador);
    
      break;
    case '*':
      r_num = (f1.numerador*f2.numerador);
      r_denom = (f1.denomindador * f2.denomindador);

      break;
    case '/':
      r_num = (f1.numerador * f2.denomindador);
      r_denom = (f2.numerador * f1.denomindador);

      break;
    }

    d = mdc(r_num, r_denom);

    simp_num = r_num/d;
    simp_den = r_denom/d;
/*Caso a simplificação do denomindor seja negativa inverte-se o valor do numerador e denominador da fração*/
    if(simp_den < 0){
      simp_den = simp_den*(-1);
      simp_num = simp_num*(-1);
    }

    printf("%d/%d = %d/%d\n", r_num, r_denom, simp_num, simp_den);
  }

  return 0;
}