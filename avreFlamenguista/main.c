#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(){

 struct NO{
  int info;
  struct NO *esq;
  struct NO *dir;
 };

 x = insere_avreLLRB(raiz, 150);
 x = insere_avreLLRB(raiz, 110);
 x = insere_avreLLRB(raiz, 100);
 x = insere_avreLLRB(raiz, 130);
 x = insere_avreLLRB(raiz, 120);
 x = insere_avreLLRB(raiz, 140);
 x = insere_avreLLRB(raiz, 160);
 remove_avreLLRB(raiz, 100);
}
