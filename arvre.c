
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

struct NO{
 int info;
 NO *esq;
 NO *dir;
};

arvbin *cria_Arvbin(){
    arvbin *raiz = (arvbin) malloc(sizeof(arvbin));
    if(arvbin == NULL){
       *raiz = NULL;
    }
    return raiz;
}
int vazia_Arvbin(arvbin *raiz){
 if(raiz == NULL){
    return 1;
 }if(*raiz== NULL){
  return 1;
 }
 return 0;
}

int altura_arvBin(Arvbin *raiz){
    if(raiz==NULL){
      return 0;
    }if( *raiz== NULL){
     return 0;
    }
  int alt_esq = altura_arvBin(&((*raiz)->esq));
  int alt_dir = altura_arvBin(&((*raiz)->dir));
   if(alt_esq> alt_dir){
     return(alt_esq + 1);
   }else{
    return(alt_dir + 1);
   }
}

int totalNO_ArvBin(Arvbin *raiz){
 if(raiz==NULL){
    return 0;
 }if(*raiz==NULL){
     return 0;
 }
 int alt_esq = totalNO_ArvBin(&((*raiz)->esq)));
 int alt_dir = totalNO_ArvBin(&((*raiz)->dir)));
}

void libera_Arvbin(arvbin *raiz){
 if(raiz== NULL){
    return;
 }
  libera_NO(*raiz);
  free(raiz);
}
void libera_NO(struct NO *no){
if(no == NULL){
    return;
}
libera_NO(no->esq);
libera_NO(no->dir);
free(no);
no = NULL:
}
