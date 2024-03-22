#ifndef ALUNOS_H
#define ALUNOS_H

typedef struct Aluno Aluno;

struct Aluno* criaLista(int numAlunos);
void listarAlunos(Aluno *lista);
void adicionarAluno(Aluno *lista, Aluno aluno);
int buscarAluno(Aluno *lista, int matricula);
void removerAluno(Aluno *lista, int matricula);

#endif