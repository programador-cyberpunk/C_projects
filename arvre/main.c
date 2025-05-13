#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main() {
    Arvbin *raiz = cria_Arvbin();
    if (raiz == NULL) {
        printf("Erro ao criar arvore\n");
        return 1;
    }

    printf("Inserindo elementos na arvore...\n");
    insere_Arvbin(raiz, 150);
    insere_Arvbin(raiz, 110);
    insere_Arvbin(raiz, 100);
    insere_Arvbin(raiz, 130);
    insere_Arvbin(raiz, 120);
    insere_Arvbin(raiz, 140);
    insere_Arvbin(raiz, 160);

    printf("\nArvore pre-ordem:\n");
    preOrdem_Arvbin(raiz);

    printf("\nArvore em ordem:\n");
    emOrdem_Arvbin(raiz);

    printf("\nArvore pos-ordem:\n");
    posOrdem_Arvbin(raiz);

    int altura = altura_arvBin(raiz);
    printf("\nAltura da arvore: %d\n", altura);

    int total = totalNO_ArvBin(raiz);
    printf("Total de nos na arvore: %d\n", total);

    int valorBusca = 140;
    printf("\nConsultando valor %d: %s\n", valorBusca, consulta_Arvbin(raiz, valorBusca) ? "Encontrado" : "Nao encontrado");

    printf("\nRemovendo o valor 100...\n");
    if (remove_Arvbin(raiz, 100)) {
        printf("Remocao bem sucedida.\n");
    } else {
        printf("Valor nao encontrado para remocao.\n");
    }

    printf("\nArvore em ordem apos remocao:\n");
    emOrdem_Arvbin(raiz);

    libera_Arvbin(raiz);
    return 0;
}

