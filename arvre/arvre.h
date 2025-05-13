#ifndef ARVORE_H
#define ARVORE_H

typedef struct NO *Arvbin;

Arvbin *cria_Arvbin();
int consulta_Arvbin(Arvbin *raiz, int valor);
int vazia_Arvbin(Arvbin *raiz);
int insere_Arvbin(Arvbin *raiz, int valor);
int altura_arvBin(Arvbin *raiz);
void preOrdem_Arvbin(Arvbin *raiz);
void emOrdem_Arvbin(Arvbin *raiz);
void posOrdem_Arvbin(Arvbin *raiz);
int totalNO_ArvBin(Arvbin *raiz);
int remove_Arvbin(Arvbin *raiz, int valor);
void libera_Arvbin(Arvbin *raiz);
void libera_NO(struct NO *no);

#endif
