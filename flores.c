/*1140 - beecrowd - Flores Florescem da França*/
#include <string.h>
#include <ctype.h>
#include <stdio.h>

/*A função verifica se a sentença s é ou não um tautograma e imprime "Y" caso seja ou "N" caso contrário*/
void tautograma_ou_nao(char s[1001]){
  char letras, *palavra, primeira;
  int verifica = 0;

  palavra = strtok(s, " ");
  if(palavra == NULL)return;
  primeira = tolower(palavra[0]);

  while(palavra!=NULL){
    palavra = strtok(NULL, " ");
    if(palavra != NULL){ 
      letras = tolower(palavra[0]);
      if(letras != primeira)verifica++;
    } 
  }

  if(verifica>0)printf("N\n");
  else printf("Y\n");

}

int main(){
  char sentenca[1001];

  while(1){
    fgets(sentenca, sizeof(sentenca), stdin);
    sentenca[strcspn(sentenca, "\n")] = '\0';

    if(strcmp(sentenca, "*")==0)break;
    
    tautograma_ou_nao(sentenca);

  }

  return 0;
}