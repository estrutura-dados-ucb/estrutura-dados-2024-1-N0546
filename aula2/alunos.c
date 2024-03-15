#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alunos.h"

struct Aluno {
    int idade;
    char nome[30];
    float nota;
};

int ultimaPosLivre = 0;

struct Aluno* criaLista(int numAlunos){
    // Usando alocação estática
    // struct Aluno alunos[numAlunos];

    // Usando alocação dinâmica
    struct Aluno *alunos = (struct Aluno*) malloc(numAlunos*sizeof(Aluno));

    return alunos;
}

void adicionarAluno(struct Aluno **lista, struct Aluno aluno){
    strcpy((*lista)[ultimaPosLivre].nome, aluno.nome);
    (*lista)[ultimaPosLivre].idade = aluno.idade;
    (*lista)[ultimaPosLivre].nota = aluno.nota;
    ultimaPosLivre++;
    printf("ultima posicao livre: %d\n", ultimaPosLivre);
}

void listarAlunos(struct Aluno *lista){
    for(int i = 0; i < ultimaPosLivre;i++){
        printf("Aluno %d\n", i + 1);
        printf("nome: %s\n", lista[i].nome);
        printf("idade: %d\n", lista[i].idade);
        printf("nota: %f\n", lista[i].nota);
    }
}

int main(){
    struct Aluno *alunos;
    alunos = criaLista(10);

    struct Aluno aluno1, aluno2;
    strcpy(aluno1.nome, "joao");
    aluno1.idade = 20;
    aluno1.nota = 9.9;

    strcpy(aluno2.nome, "eduarda");
    aluno2.idade = 22;
    aluno2.nota = 10;

    adicionarAluno(&alunos, aluno1);
    adicionarAluno(&alunos, aluno2);
    adicionarAluno(&alunos, aluno2);

    listarAlunos(alunos);
    return 0;
}