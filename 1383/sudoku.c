/*1383 - beecrowd - Sudoku*/
#include <stdio.h>

/*A função abaixo recebe uma matriz linhas[9][9] e verifica repetições em suas linhas, retorna 0 se houver ou 1 se não existir*/
int verifica_linha(int linhas[9][9]){
  int i, j, x;

  for(i=0; i<9; i++){
    for(j=0; j<9; j++){
      for(x=j+1; x<9; x++){
        if(linhas[i][j]==linhas[i][x]){
          return 0;
        }
      }
    }
  }
  return 1;
}
/*A função abaixo recebe uma matriz colunas[9][9] verifica repetições em suas colunas e devolve 0 se houver ou 1 se não existir*/ 
int verifica_coluna(int colunas[9][9]){
  int i, j, x;

  for (i = 0; i < 9; i++){
    for (j = 0; j < 9; j++){
      for (x = j + 1; x < 9; x++) {
        if (colunas[j][i] == colunas[x][i]){
          return 0;
        }
      }
    }
  }
  return 1;
}
/*A função abaixo recebe uma matriz[9][9] e verifica se existe repetições em suas submatrizes 3x3, retorna 0 se houver ou 1 se não existir*/
int verifica_3x3(int matriz[9][9]){
  int i, j, m, n, x, y; 
  int submatriz[3][3],atual, cont;

  for(x=0; x<9; x+=3){ 
    for(y=0;y<9; y+=3){ 
      for(i=0; i<3;i++){
        for(j=0; j<3; j++){
          submatriz[i][j] = matriz[x+i][y+j];
        }
      } 
    
      for(i=0; i<3; i++){
      for(j=0; j<3; j++){ 
          atual = submatriz[i][j];

          for(m=0; m<3; m++){
            for(n=0; n<3; n++){
              if(m!=i || n !=j){
                if(atual == submatriz[m][n]){
                  return 0;
                }
              }
            }
          }
        }
      }
    }
  }
  return 1;
}

int main(){
  int instancia, x, i, j;
  int matriz[9][9];
  int verifica_1, verifica_2, verifica_3;

  scanf("%d", &instancia);
/*o laço de repetição abaixo inicia do x=0 até o tamanho de 'instancia-1' para receber os elementos da matriz[9][9] 
e executar as funções verifica_linha, verifica_coluna e verifica_3x3*/
  for(x=0; x<instancia; x++){ 
    for(i=0; i<9; i++){
      for(j=0; j<9; j++){
        scanf("%d", &matriz[i][j]);
    }
  }
  printf("Instancia %d", x+1); 
  verifica_1 = verifica_linha(matriz);
  if(verifica_1==0){
    printf("\nNAO\n\n");
  }else{
    verifica_2=verifica_coluna(matriz);
    if(verifica_2==0){
      printf("\nNAO\n\n");
    }else{
      verifica_3=verifica_3x3(matriz);
      if(verifica_3==0){
        printf("\nNAO\n\n");
      }else{
        printf("\nSIM\n\n");
     }
    }
  } 
}
return 0;
}