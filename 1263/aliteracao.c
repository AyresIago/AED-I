/*1263 - beecrowd - Aliteração*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*A função recebe a sequência de palavras e imprime a quantidade de aliterações presente nela*/
void aliteracao(char v[]){
  int i, cont = 0, seguidas = 0, aliteracao=0;
  char *palavra, letras[5000];

  palavra = strtok(v, " ");
  if(palavra == NULL)return;
  letras[cont++] = tolower(palavra[0]);

  while(palavra!=NULL){  
    palavra = strtok(NULL, " ");
    if(palavra != NULL)letras[cont++] = tolower(palavra[0]);
  }
  
  for(i = 0; i < cont-1; i++){
    if(letras[i]==letras[i+1]){
      if(seguidas==0){
        seguidas = 1;
        aliteracao++;
      }
    }else{
      seguidas = 0;
    }
  }

  printf("%d\n", aliteracao);
}

int main(){
  char string[5000];

  while(1){
    if(fgets(string, sizeof(string), stdin)==NULL)break;
    if(string[0] == '\n')break;
    string[strcspn(string, "\n")] = '\0';
    aliteracao(string);
  }
  return 0;
}