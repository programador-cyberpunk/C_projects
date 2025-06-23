#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para memcpy
#include "avl.h"    // Inclui a definição da AVL e da Funcionario
#include <math.h>

int alt_no(struct NO *no){
 if(no == NULL){
    return -1;
 }else{
  return no->alt;
 }
}

int maior(int x, int y){
 return (x > y) ? x : y;
}

int balanceamento(struct NO *no){
 if(no == NULL){
    return 0;
 }
 return alt_no(no->esq) - alt_no(no->dir);
}

//rodation pra direita
void rotacao RR(avreVL *A){
 struct NO *B;
 B = (*A)->dir;
 (*A)->dir = B->esq;
 B->esq = (*A);

 (*A)->alt = maior(alt_no(*A)->esq, alt_no((*A)->dir) + 1;
 B->alt = maior(alt_no(B->dir), (*A)->alt) + 1;
 *A = B;
}
