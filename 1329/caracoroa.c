/*1329 - beecrowd - Cara ou Coroa*/
#include <stdio.h>

int main(){
  int n, joao, maria, i, r;

  while(1){
    scanf("%d", &n);
    
    if(n == 0)break;
    
    maria = 0;
    joao = 0;
    
    for(i = 0; i < n; i++){ 
      scanf("%d", &r);
      if(r == 0){
        maria++;
      }else if(r == 1){
        joao++;
      }
    }
   
   printf("Mary won %d times and John won %d times\n", maria, joao);
  }
  return 0;
}