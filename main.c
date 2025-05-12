#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

raiz = cria_Arvbin();
libera_Arvbin(raiz);
int main(){
    int x;
    arvbin *raiz;

    if(vazia_Arvbin(raiz)){
        printf("A arvore esta vazia");
    }else{
     printf("A arvore possui elementos");
    }
    printf("\n\n");

    x = altura_arvBin(raiz);
    printf("Altura da arvore eh: %d", x);

    x =  totalNO_ArvBin(raiz);
    printf("O total da arvore eh: %d", x);
}
