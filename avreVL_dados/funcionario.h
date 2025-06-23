#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
// como diria jack O estripador,vamos por partes

#define MAX_NOME 130
#define MAX_DPTO 50

typedef struct funcionario{
 int id;
 char *nome[MAX_NOME];
 int idade;
 char *dpto[MAX_DPTO];
 float sal;
}Funcionario;

void imprimeFuncionario(const Funcionario *f);

// essa porra é pra comparativo na arvre,tipo -1 se f1 < f2,0 se f1 == f2,1 se f1 > f2
int comparaFuncionario(const Funcionario *f1, const Funcionario *f2);

#endif
