/*1103 - beecrowd - Alarme Despertador*/
#include <stdio.h>
#include <stdlib.h>

int main(){
  int h1, m1, h2, m2, soneca;
  
  while(1){
    
    scanf("%d %d", &h1, &m1);
    scanf("%d %d", &h2, &m2);

    if(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0){
      break;
    }
    if(h2 == 0){
      h2 = 24;
    }

    if(h1 == 0){
      h1 = 24;
    }

    if(h1 >= h2){
      soneca = (1440 - ((h1*60)+m1)) + ((h2*60) + m2);
    }else{
      soneca = ((h2*60 )+ m2) - ((h1*60 )+ m1);
    }
    
    if(h1 == h2 && m1 < m2)soneca = ((h2*60 )+ m2) - ((h1*60 )+ m1);

    printf("%d\n", soneca);
  }
}