/*3408 - beecrowd - Ignore as Letras*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*A função recebe a string s como parâmetro e retorna o valor formado pelos números presentes nela ao ignorar as letras*/
int ignore(char s[]){
  int i, tam = strlen(s);
  int valor = 0, n = 1;

  for(i = tam - 1; i >= 0; i--){
    if(isdigit(s[i])){
      valor += (s[i]-'0')*n;
      n *= 10;
    }
  }

  return valor;
}

int main(){
  int n, i, v = 0;
  char string[1000];

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%s", string);
    v += ignore(string);
  }

  printf("%d\n", v);

  return 0;
}