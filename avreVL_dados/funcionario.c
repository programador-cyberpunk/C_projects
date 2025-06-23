#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funcionario.h"

void imprimeFuncionario(const Funcionario *f){
 printf("ID: %d\n", f->id);
 printf("Nome: %s\n", f->nome);
 printf("Idade: %d\n", f->idade);
 printf("Departamento: %s\n", f->dpto);
 printf("Salario: %.2f\n", f->sal);
}

//isso vai pra arvore
int comparaFuncionario(const Funcionario *f1, const Funcionario *f2){
 if(fi->id < f2->id){
    return -1;
 }else if(f1->id > f2->id){
   return 1;
 }
 return 0;
}
