avreLLRB *raiz;
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
