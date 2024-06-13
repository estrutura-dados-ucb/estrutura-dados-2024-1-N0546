#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ALUNOS 50

typedef struct Aluno {
    int matricula;
    char nome[50];
    float nota;
} Aluno;

int gerarHash(int valor){
    return (valor*41)%MAX_ALUNOS;
}

void inicializar(Aluno* alunos){
    for(int i = 0;i < MAX_ALUNOS;i++){
        alunos[i].matricula = -1;
    }
}

void inserir(Aluno* alunos, int matricula, char* nome, float nota){
    int index = gerarHash(matricula);

    // se tiver matrícula no index
    while(alunos[index].matricula != -1){
        matricula = (matricula + 1)%MAX_ALUNOS;
        index = gerarHash(matricula);
    }

    alunos[index].matricula = matricula;
    alunos[index].nota = nota;
    strcpy(alunos[index].nome, nome);
}

int buscar(Aluno* alunos, int matricula){
    int index = gerarHash(matricula);
    printf("matricula buscada: %d\n", matricula);
    while(alunos[index].matricula != -1){
        if(alunos[index].matricula == matricula){
            printf("Aluno encontrado!\nNome: %s\nNota: %f\n", 
            alunos[index].nome, alunos[index].nota);
            return 1;
        }
        matricula++;
        index = gerarHash(matricula);
    }
    printf("Aluno nao encontrado!!!\n");
    return 0;
}

void remover(Aluno* alunos, int matricula){
    int index = buscar(alunos, matricula);
    if(index){
        alunos[index].matricula = -1;
        alunos[index].nota = 0;
        strcpy(alunos[index].nome, "");
    }
}

 

int main(){

    Aluno* alunos = (Aluno*) malloc(sizeof(Aluno)*MAX_ALUNOS);
    //Aluno alunos[MAX_ALUNOS];
    inicializar(alunos);

    inserir(alunos, 1234, "joao", 8.9);
    inserir(alunos, 2323, "maria", 10);
    inserir(alunos, 4242, "pedro", 8.1);

    buscar(alunos, 23231);
    buscar(alunos, 1234);

    return 0;

}