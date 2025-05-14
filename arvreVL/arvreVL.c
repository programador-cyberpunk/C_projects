#include <stdio.h>
#include <stdlib.h>
#include <string>
#include  <math.h>
#include "arvreVL.h"

struct NO{
 int info;
 int alt;
 struct NO *esq;
  struct NO *dir;
};


void confirmaInsercao(int x){
 if(x){
    printf("Deu certo e o elemento foi inserido...\n");
 }else{
  print("Deu bosta, arruma ai");
 }
}
//calcula a porra da altura do no
int alt_no(struct NO *no){
    if(no == NULL){
        return -1;
    }else{
     return no->alt;
    }
}


//devolve o maior entre dois bagulho
int maior(int x, int y){
 if(x >y){
    return (x);
 }else{
  return (y);
 }
}

//balançeamento dos bagulho
int balanca_NO(struct NO *no){
 return abs(alt_no(no->esq) - alt_no(no->dir));
}

void rotacaoRR(arvVL *A){
 struct NO *B;
 B = (*A)->dir;
 B->esq = (*A);
 (*A)->alt = maior(alt_no(*A->esq), alt_no(*A->dir)) + 1;
 B->alt = maior(alt_no(alt_no(B->dir)),(*A)->alt) + 1;
 (*A) = B;
}

void rotacaoLr(arvVL *A){
rotacaoRR(&(*A)->dir);
rotacaoLL(A);
}


void rotacaoRL(arvVL *A){
rotacaoLL(&(*A)->dir);
rotacaoRR(A);
}
