/*1238 - beecrowd - Combinador*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*A função intercala as duas strings c1 e c2 em combina e a imprime*/
void combinador(char c1[], char c2[]){
  int n = strlen(c1), m = strlen(c2), i = 0, cont = 0;
  char *combina = malloc((n+m+1)*sizeof(char));

  while(i < n && i < m){
    combina[cont] = c1[i];
    cont++;
    combina[cont] = c2[i];
    cont++;
    i++;
  }

  if(n<m){
    while(i<m){
      combina[cont] = c2[i];
      cont++;
      i++;
    }
  }else if(n>m){
    while(i < n){ 
      combina[cont] = c1[i];
      cont++;
      i++;
    }
  }

  combina[cont] = '\0';

  printf("%s\n", combina);
  free(combina);
}

int main(){
  int i, n;
  char a[51], b[51];

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%s", a);
    scanf("%s", b);
    combinador(a, b);
  }

  return 0;
}