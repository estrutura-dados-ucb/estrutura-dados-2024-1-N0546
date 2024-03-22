#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alunos.h"

struct Aluno {
    int idade;
    char nome[30];
    float nota;
    int matricula;
};

int ultimaPosLivre = 0;

struct Aluno* criaLista(int numAlunos){
    // Usando alocação estática
    // struct Aluno alunos[numAlunos];

    // Usando alocação dinâmica
    struct Aluno *alunos = (struct Aluno*) malloc(numAlunos*sizeof(Aluno));

    return alunos;
}

void adicionarAluno(struct Aluno *lista, struct Aluno aluno){
    // posso fazer a atribuição "variável" por "variável"
/*     strcpy(lista[ultimaPosLivre].nome, aluno.nome);
    lista[ultimaPosLivre].idade = aluno.idade;
    lista[ultimaPosLivre].nota = aluno.nota; */

    // ou assim:
    lista[ultimaPosLivre] = aluno;

    ultimaPosLivre++;
    printf("ultima posicao livre: %d\n", ultimaPosLivre);
}

void listarAlunos(struct Aluno *lista){
    for(int i = 0; i < ultimaPosLivre;i++){
        printf("Aluno %d\n", i + 1);
        printf("nome: %s\n", lista[i].nome);
        printf("idade: %d\n", lista[i].idade);
        printf("matricula: %d\n", lista[i].matricula);
        printf("nota: %f\n", lista[i].nota);
    }
}

int buscarAluno(Aluno *lista, int matricula){
    for(int i = 0; i < ultimaPosLivre;i++){
        if(lista[i].matricula == matricula){
            return i;
        }
    }
    return -1;
}


void removerAluno(struct Aluno* lista, int matricula){
    int indiceAluno = buscarAluno(lista, matricula);

    if(indiceAluno != -1){
        lista[indiceAluno] = lista[indiceAluno + 1];
        lista[indiceAluno + 1].idade = -1;
        lista[indiceAluno + 1].nota = -1;
        lista[indiceAluno + 1].matricula = -1;
        strcpy(lista[indiceAluno + 1].nome, "");

        ultimaPosLivre--;
    }
}

int main(){
    struct Aluno *alunos;
    alunos = criaLista(10);

    struct Aluno aluno1, aluno2;
    strcpy(aluno1.nome, "joao");
    aluno1.idade = 20;
    aluno1.nota = 9.9;
    aluno1.matricula = 101010;

    strcpy(aluno2.nome, "eduarda");
    aluno2.idade = 22;
    aluno2.nota = 10;
    aluno2.matricula = 222222;

    adicionarAluno(alunos, aluno1);
    adicionarAluno(alunos, aluno2);

    listarAlunos(alunos);
    return 0;
}