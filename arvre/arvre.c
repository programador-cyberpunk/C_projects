#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arvre.h"

struct NO {
    int info;
    struct NO *esq;
    struct NO *dir;
};

Arvbin *cria_Arvbin() {
    Arvbin *raiz = (Arvbin *)malloc(sizeof(Arvbin));
    if (raiz != NULL) {
        *raiz = NULL;
    }
    return raiz;
}

int vazia_Arvbin(Arvbin *raiz) {
    if (raiz == NULL || *raiz == NULL) {
        return 1;
    }
    return 0;
}

int consulta_Arvbin(Arvbin *raiz, int valor) {
    if (raiz == NULL || *raiz == NULL) {
        return 0;
    }
    struct NO *atual = *raiz;
    while (atual != NULL) {
        if (valor == atual->info) {
            return 1;
        }
        if (valor > atual->info) {
            atual = atual->dir;
        } else {
            atual = atual->esq;
        }
    }
    return 0;
}

int insere_Arvbin(Arvbin *raiz, int valor) {
    if (raiz == NULL) {
        return 0;
    }
    struct NO *novo = (struct NO *)malloc(sizeof(struct NO));
    if (novo == NULL) {
        return 0;
    }
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;
    if (*raiz == NULL) {
        *raiz = novo;
    } else {
        struct NO *atual = *raiz;
        struct NO *ant = NULL;
        while (atual != NULL) {
            ant = atual;
            if (valor == atual->info) {
                free(novo); // Evita vazamento de memória
                return 0; // Valor já existe
            }
            if (valor > atual->info) {
                atual = atual->dir;
            } else {
                atual = atual->esq;
            }
        }
        if (valor > ant->info) {
            ant->dir = novo;
        } else {
            ant->esq = novo;
        }
    }
    return 1;
}

int altura_arvBin(Arvbin *raiz) {
    if (raiz == NULL || *raiz == NULL) {
        return 0;
    }
    int alt_esq = altura_arvBin(&((*raiz)->esq));
    int alt_dir = altura_arvBin(&((*raiz)->dir));
    return (alt_esq > alt_dir ? alt_esq : alt_dir) + 1;
}

void preOrdem_Arvbin(Arvbin *raiz) {
    if (raiz == NULL || *raiz == NULL) {
        return;
    }
    printf("%d\n", (*raiz)->info);
    preOrdem_Arvbin(&((*raiz)->esq));
    preOrdem_Arvbin(&((*raiz)->dir));
}

void emOrdem_Arvbin(Arvbin *raiz) {
    if (raiz == NULL || *raiz == NULL) {
        return;
    }
    emOrdem_Arvbin(&((*raiz)->esq));
    printf("%d\n", (*raiz)->info);
    emOrdem_Arvbin(&((*raiz)->dir));
}

void posOrdem_Arvbin(Arvbin *raiz) {
    if (raiz == NULL || *raiz == NULL) {
        return;
    }
    posOrdem_Arvbin(&((*raiz)->esq));
    posOrdem_Arvbin(&((*raiz)->dir));
    printf("%d\n", (*raiz)->info);
}

int totalNO_ArvBin(Arvbin *raiz) {
    if (raiz == NULL || *raiz == NULL) {
        return 0;
    }
    return totalNO_ArvBin(&((*raiz)->esq)) + totalNO_ArvBin(&((*raiz)->dir)) + 1;
}

static struct NO *remove_atual(struct NO *atual) {
    struct NO *no1, *no2;
    if (atual->esq == NULL) {
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while (no2->dir != NULL) {
        no1 = no2;
        no2 = no2->dir;
    }
    if (no1 != atual) {
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

int remove_Arvbin(Arvbin *raiz, int valor) {
    if (raiz == NULL || *raiz == NULL) {
        return 0;
    }
    struct NO *ant = NULL;
    struct NO *atual = *raiz;
    while (atual != NULL) {
        if (valor == atual->info) {
            if (atual == *raiz) {
                *raiz = remove_atual(atual);
            } else if (ant->dir == atual) {
                ant->dir = remove_atual(atual);
            } else {
                ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if (valor > atual->info) {
            atual = atual->dir;
        } else {
            atual = atual->esq;
        }
    }
    return 0;
}

void libera_NO(struct NO *no) {
    if (no == NULL) {
        return;
    }
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
}

void libera_Arvbin(Arvbin *raiz) {
    if (raiz == NULL) {
        return;
    }
    libera_NO(*raiz);
    free(raiz);
}

