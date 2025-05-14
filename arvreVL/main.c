#include <stdio.h>
#include <stdlib.h>
#include <string>
#include  <math.h>
#include "arvreVL.h"

int main()
{
   int x;
   arvVL *raiz;

   confirmaInsercao(insere_arVL(raiz, 160));
   confirmaInsercao(insere_arVL(raiz, 150));
   confirmaInsercao(insere_arVL(raiz, 100));
   confirmaInsercao(insere_arVL(raiz, 110));
   confirmaInsercao(insere_arVL(raiz, 130));
   confirmaInsercao(insere_arVL(raiz, 140));
   confirmaInsercao(insere_arVL(raiz, 120));
   confirmaInsercao(insere_arVL(raiz, 170));
   confirmaInsercao(insere_arVL(raiz, 180));
   confirmaInsercao(insere_arVL(raiz, 190));
   confirmaInsercao(insere_arVL(raiz, 200));
   confirmaInsercao(insere_arVL(raiz, 200));
}
