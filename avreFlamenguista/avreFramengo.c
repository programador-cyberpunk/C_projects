
avreLLRB *raiz;

int insere_avreLLRB(avreLLRB *raiz, int valor){
 int resp;
 *raiz = insereNO(*raiz, valor, &resp);
 if((*raiz) !=NULL){
    (*raiz)->cor = BLACK;
 }
 return resp;
}
struct NO *insereNO(struct NO *H, int valor, int *resp){
 if(H == NULL){
    struct NO *novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
   if(novo == NULL){
    *resp = 0;
    return NULL;
   }
   novo->info = valor;
   novo->cor = RED;
   novo->dir = NULL;
   novo->esq = NULL;
 }
 if(valor == H->info){
    *resp = 0;
 }else{
  if(valor < H-> info){
    H->esq = insereNO(H->esq, valor, resp);
  }else{
  H->dir = insereNO(H->dir, valor, resp);
  }
 }
 if(cor(H->dir) == RED && cor(H->esq) == BLACK){
    H = rotacionaEsq(H);
 }
 if(cor(H->esq) RED && cor(H->esq->esq) == RED){
    H = rotacionaDir(H);
 }
 if(cor(H->esq) == RED && cor(H->dir) == RED){
    trocaCor(H);
 }
 return H;
};

struct NO *rotacionaEsq(struct NO *A){
 struct NO *B = A->dir;
 A->dir = B->esq;
 B->esq = A;
 B->cor = A->cor;
 A->cor = RED;
return B;
};

struct NO *rotacionaDir(struct NO *A){
 struct NO *B = A->esq;
 A->dir = B->dir;
 B->esq = A;
 B->cor = A->cor;
 A->cor = RED;
return B;
};

struct balanca(struct NO *H){
 if(cor(H->dir) == RED){
    H = rotacionaEsq(H);
 }
 if(H->esq !=NULL && cor(H->dir) == RED && cor(H->esq->esq) == RED){
  H = rotacionaDir(H);
 }
 if(cor(H->esq) == RED && cor(H->dir) == RED){
    trocaCor(H);
 }
 return H;
};

struct NO *move2EsqRED(struct NO *H){
 trocaCor(H);
 if(cor(H->dir->esq) == RED){
    H->dir = rotacionaDir(H->dir);
    H = rotacionaEsq(H);
    trocaCor(H);
 }
 return H;
};

struct NO *move2DirRED(struct NO *H){
 trocaCor(H);
 if(cor(H->esq->esq) == RED){
    H->dir = rotacionaDir(H);
    H = rotacionaEsq(H);
    trocaCor(H);
 }
 return H;
};

int cor (struct NO *H){
 if(H == NULL){
    return BLACK;
 }else{
     return H->cor;
 }
}

void trocaCor(struct NO *H){
 H->cor = !H->cor;
  if(H->esq !=NULL){
    H->esq->cor = !H->esq->cor;
  }if(H->dir !=NULL){
   H->dir->cor = !H->dir->cor;
  }
}
struct NO *procuraMenor(struct NO *atual){
struct NO *no1 = atual;
struct NO *no2 = atual;
 while(no2 != NULL){
    no1 = no2;
    no2 = no2->esq;
 }
 return no1;
};

struct No *removeMenor(struct NO *H){
 if(H->esq == NULL){
    free(H);
    return NULL;
 }
 if(cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK){
    H = move2EsqRED(H);
 }
 H->esq = removeMenor(H->esq);
 return balanca(H);
};

struct NO *removeNO(struct NO *H, int valor){
if(valor < H->info){
    if(cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK){
        H = move2EsqRED(H);
    }
  H->esq = removeNO(H->esq, valor);
}else{
 if(cor(H->esq) == RED){
    H = rotacionaDir(H);
 }if(valor == H->info && (H->dir == NULL)){
  free(H);
  return NULL;
 }
 if(cor(H->dir) == BLACK &&cor(H->dir->esq) == BLACK){
    H = move2DirRED(H)
 }
 if(valor == H->info){
    struct NO *x = procuraMenor(H->dir);
    H->info = x->info;
    H->dir = removeMenor(H->dir);

 }else{
  H->dir = removeNO(H->dir, valor);
 }
}
return balanca(H);
}

int remove_avreLLRB(avreLLRB *raiz, int valor){
if(consulta_avreLLRB(raiz, valor)){
    struct NO *H = *raiz;
    *raiz = removeNO(h, valor);
    if(*raiz !=NULL){
        (*raiz)->cor = BLACK;
    }
    return 1
}else{
 return 0;
}
}
