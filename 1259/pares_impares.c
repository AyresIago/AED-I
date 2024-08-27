/*1259 - beecrowd - Pares e Ímpares*/
#include <stdio.h>
#include <stdlib.h>

/*A função ordena o vetor v de forma decrescente*/
void insercao_decrescente(int n, int v[]){
  int i, j, x;

  for(j = 1; j < n; j++){
    x = v[j];
    for(i = j-1; i >= 0 && v[i]<x; i--){
      v[i+1] = v[i];
    }
    v[i+1] = x;
  }
}

/*A função intercala dois vetores crescentes em outro*/
void intercala(int p, int q, int r, int v[]){
  int i, j, k, *w;
  w = malloc((r-p)*sizeof(int));
  i = p;
  j = q;
  k = 0;

  while(i < q && j < r){
    if(v[i] <= v[j])w[k++] = v[i++];
    else w[k++] = v[j++];
  }
  while (i < q) w[k++] = v[i++];
  while(j < r) w[k++] = v[j++];
  for(i = p; i < r; i++)v[i] = w[i-p];
  free(w);
}

/*A função recursiva contém a função intercala para formar um vetor crescente*/
void mergesort_crescente(int p, int r, int v[]){
  if(p < r-1){
    int q = (p + r)/2;
    mergesort_crescente(p, q, v);
    mergesort_crescente(q, r, v);
    intercala(p, q, r, v);
  }
}

int main(){
  int i, n, num, cont_1 = 0, cont_2 = 0;
  int *v_par, *v_impar;

  scanf("%d", &n);

  v_par = malloc(n*sizeof(int));

  v_impar = malloc(n*sizeof(int));

/*loop para receber as entrada e a partir dela formar os vetores de numeros pares e ímpares*/
  for(i = 0; i < n; i++){
    scanf("%d", &num);
    if(num%2==0){
      v_par[cont_1] = num;
      cont_1++;
    }else{
      v_impar[cont_2] = num;
      cont_2++;
    }
  }

  mergesort_crescente(0, cont_1, v_par);
  insercao_decrescente(cont_2, v_impar);

  for(i = 0; i < cont_1; i++){
    printf("%d\n", v_par[i]);
  }

  for(i = 0; i < cont_2; i++){
    printf("%d\n", v_impar[i]);
  }

  free(v_par);
  free(v_impar);

  return 0;
}