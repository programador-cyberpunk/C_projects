#include<stdio.h>
#include<stdlib.h>
#include<math.h>

main(){

int mtx[5][5], v[10];
int i = 0, j = 0, soma = 0;

// formando a matriz eu acho, declarando na vdd

for(i = 0; i<5; i ++){
  for(j = 0; j<5; j++){
   printf("\n Digite os valores da matriz na posicao: %d e %d",i ,j );
   scanf("%d", &mtx);
  }
}
//soma das matrizes de i
printf("\n\n Total por linhas: \n\n");
 for(i = 0; i<5; i++){
  for(j = 0; j<5; j++){
   soma = soma + mtx[i][j];
  }
  printf("\n\n Linha %d: soma = %d ", i + 1, soma);
  v[i] = soma;
  soma = 0;
 }

 // soma das matrizes de j

  soma = 0;
 printf("\n\n Total por coluna: ");
  for(j = 0; j<5; j++){
    for(i = 0; i<5; i++){
    soma = soma + mtx[j][i];
   }
  printf("\n\n Coluna %d: soma = %d ", j + 1,soma);
  v[j + 5] = soma;
  soma = 0;
  }

  // total de linhas e colunas
  for(i = 0; i<5; i++){
   printf("\n\n Valores da soma da linha %d sao: %d\n", i + 1,v[i]);
   printf("\n\n Valores da soma da coluna %d sao: %d\n", j +1,v[i + 5]);
  }
  printf("\n\n\n");
system("pause");
return 0;
}
