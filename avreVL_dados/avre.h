#ifndef AVRE_H
#endif  AVRE_H

#include "funcionario.h"
 typedef struct No{
  Funcionario info; //pra armazenar a struct funcionario
  int alt; // a altura do no
  struct NO *esq;
  struct NO *dir;
 }NO;

 typedef struct No *avreVL;

 //funçoes da arvre
 avreVL* cria_avreVL();
 void libera_avreVL(avreVL *raiz);
 int insere_avreVL(avreVL *raiz, Funcionario f);
 int remove_avreVL(avreVL *raiz, int id_remover);
 int consulta_avreVL(avreVL *raiz, int id_busca);
 void ordem_avreVL(avreVL *raiz);

 #endif
