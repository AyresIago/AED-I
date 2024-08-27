/*1387 - beecrowd - Og*/
#include <stdio.h>
 
int main() {
    int h, m, filhos;
    
    while(1){
        scanf("%d %d", &h, &m);
        
        if(h == 0 && m == 0){
            break;
        }
        
        filhos = h + m;
        
        printf("%d\n", filhos);
    }
 
    return 0;
}