#include<stdio.h>
#include<stdlib.h>

main(){

int v1[5], v2[5];

int i = 0, j = 0;

//preenchendo

for(i = 0; i <5; i++){
 printf("Informe o valor do elemento %d do vetor 1: ", i + 1);
 scanf("%d", &v1[i]);
};

for(j = 0; j <5; j++){
 printf("Infome o valor do elemento %d do vetor 2: ", j + 1);
 scanf("%d", &v2[j]);
};

// mostrando os valores iguais na tabela
for(i = 0; i<5; i++){
 for(j = 0; j<5;j++){
 if(v1[i]==v2[j]){
  printf("\n Valores iguais nas posicoes: %d e %d ", i + 1,j + 1);
 }
 }
}
for(i = 0; i<5; i++){
   for(j = 0; j<5; j++){

   }
}
system("pause");
}
