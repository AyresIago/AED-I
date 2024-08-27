/*1397 - beecrowd - Jogo do Maior*/
#include <stdio.h>
 
int main() {
    int f1, f2, p1, p2, rodada;
    
    while(1){
        p1 = 0;
        p2 = 0;
        
        scanf("%d", &rodada);
        if(rodada == 0)break;
        
        for(int i = 0; i < rodada; i++){
            scanf("%d %d", &f1, &f2);
            
            if(f1 > f2){
                p1++;
            }else if(f1 < f2){
                p2++;
            }
        }
        
        printf("%d %d\n", p1, p2);
    }
 
    return 0;
}