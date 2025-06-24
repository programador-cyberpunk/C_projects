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


void rotacao LL(avreVL *){
  struct NO *B;
 B = (*A)->esq;
 (*A)->esq = B->dir;
 B->dir = (*A);

 //atualizar as alturas
 (*A)->alt = maior(alt_no(*A)->esq),alt_no((*A)->dir)) + 1;
 B->alt = maior(alt_no(B->esq), (*A)->alt) + 1;
 *A = B;
}
void rotacao RL(avreVL){
 rotacaoLL(&(*A)->dir);
 rotacaoRR(A);
}

void rotacao LR(avreVL){
 rotacaoRR(&(*A)->esq);
 rotacaoLL(A);
}
//bagulhos principais

avreVL* cria_avreVL(){
 avreVL *raiz = (avreVL*) malloc(sizeof(avreVL));
  if(raiz !=NULL){
    *raiz = NULL;
  }
  return raiz;
}

void liberaNO(struct NO *no){
 if(no == NULL){
    liberaNO(no->esq);
    liberaNO(no->dir);
    free(no);
 }
}

void liberaAvreVL(avreVL *raiz){
 if(raiz == NULL){
 return;
 liberaNO(*raiz);
 free(raiz);
}
}

//inserir os funcionarios
int insere_avreVL(avreVL *raiz, Funcionario f){
 int res;
 if(*raiz == NULL){
    struct NO *novo = (struct NO*)malloc(sizeof(struct NO));
 if( novo == NULL) {
    return 0; //quer dizer que deu bosta
 }
 }
 memcpy(&(novo->info), &f, sizeof(Funcionario));
 novo->alt = 0;
 novo->esq = NULL;
 novo->dir = NULL;
 *raiz = novo;
 return 1; //deu bom
}
struct NO *atual = *raiz;
if(f.id <atual->info.id){
    if((res = insere_avreVL(&(atual->esq), f)) == 1){
        if(balanceamento(atual) >= 2){
            if(f.id < (*raiz)->esq->info.id){
                rotacaoLL(raiz);
            }else{
             rotacaoLR(raiz);
            }
        }
    }
}else if (f.id >atual->info.id){
     if((res = insere_avreVL(&(atual->dir), f)) == 1){
        if(balanceamento(atual) >= 2){
            if(f.id < (*raiz)->dir->info.id){
                rotacaoLL(raiz);
            }else{
             rotacaoLR(raiz);
            }
        }
    }
}else{
 printf("Esse elemento %d ja existe,a insercao foi duplicada... \n\n", f.id);
 return 0;
}

atual->alt = maior(alt_no(atual->esq), alt_no(atual->dir)) + 1;
return res;

// funcao pra encontrar o no menor na subavre
struct NO* procuraMenor(struct NO* atual){
 struct NO *no1 = atual;
 struct NO *no2 = atual->esq;
 while (no2 != NULL){
    no1 = no2;
    no2 = no2->esq;
 }
 return no1;
}

// pra remover o funcionario da arvore pelo id
int remove_avreVL(avreVL *raiz, int id_remove){
 if(*raiz == NULL){
    return 0;
 }
 int res;
  if(id_remove <(*raiz)->info.id){
    if((res = remove_avreVL(&(*raiz)) >=2){
        if(alt_no((*raiz)->dir->esq) <=alt_no((*raiz)->dir->dir)){
        rotacaoRR(raiz);
       }else{
       rotacaoRL(raiz);
       }
       }
  }
}else if(id_remove >(*raiz)->info.id_remove){
     if((res = remove_avreVL(&(*raiz)) >=2){
        if(alt_no((*raiz)->esq->dir) <=alt_no((*raiz)->esq->esq)){
        rotacaoLL(raiz);
       }else{
       rotacaoLR(raiz);
       }
       }
}else{ //encontrou o no que tem que ser removido
 if((*raiz)->esq == NULL || (*raiz)->dir == NULL){
    struct NO *oldNode = *raiz;
 if((*raiz)->esq !=NULL){
    *raiz = (*raiz)->esq;
 }else{
  *raiz = (*raiz)->dir;
 }
 free(oldNode);
 }else{
  struct NO *temp = procuraMenor((*raiz)->dir);
  memcpy(&((*raiz)->info), &(temp->info), sizeof(Funcionario));
  remove_avreVL(&(*raiz)->dir, temp->info.id);
   if(balanceamento(*raiz) >=2){
    if(alt_no((*raiz->dir->esq)<=alt_no(*raiz)->dir->dir)){
        rotacaoRR(raiz);
    }else{
     rotacaoRL(raiz);
    }
   }
 }
 return 1; //deu bom
}
if(*raiz 1= NULL){
    (*raiz)->alt = maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir)) + 1;
}
return res;

int consulta_avreVL(avreVL *raiz, int id_busca){
 if(*raiz == NULL){
    return 0;
 }
    if((*raiz)->info.id == id_busca){
        imprimeFuncionario(&(*raiz)->info);
        return 1;
    }else if(id_busca < (*raiz)->info.id){
     return consulta_avreVL(&(*raiz)->esq, id_busca);
    }else{
     return consulta_avreVL(&(*raiz)->dir, id_busca);
    }
}

void OrdemAvreVL(avreVL *raiz){
 if(*raiz !=NULL){
    OrdemAvreVL(&(*raiz)->esq);
    imprimeFuncionario(&(*raiz)->info);
    OrdemAvreVL(&(*raiz)->dir);
 }
}
