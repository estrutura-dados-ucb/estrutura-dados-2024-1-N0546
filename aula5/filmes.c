#include <stdio.h>
#include <string.h>
#include "filmes.h"
#define MAX 50

typedef struct Filme {
    char nome[50];
    int anoLancamento;
    char diretor[50];
} Filme;

typedef struct ListaFilmes {
    Filme filmes[MAX];
    int numFilmes;
} ListaFilmes;

int partition(ListaFilmes *vetor, int esq, int dir){
    char pivot[50];

    // pivô vai ser elemento mais a esquerda
    strcpy(pivot, vetor->filmes[esq].nome);

    // indicador de elementos a esquerda
    int i = esq - 1;

    // indicador de elementos a direita
    int j = dir + 1;

    while(1){
        do{
            i += 1;
        } while(strcmp(vetor->filmes[i].nome, pivot) < 0);

        do{
            j -= 1;
        }while(strcmp(vetor->filmes[j].nome, pivot) > 0);

        if(i >= j){
            // retornando a posição
            // que divide vetor em duas partes
            // elementos da parte esquerda < pivô
            // elementos da parte direita >= pivô

            return j;
        }

        Filme tmp = vetor->filmes[i];
        vetor->filmes[i] = vetor->filmes[j];
        vetor->filmes[j] = tmp;
    }
}


void quicksort(ListaFilmes* vetor, int esq, int dir){
    if(esq >= 0 && dir >= 0 && esq < dir){
        // selecionar um novo valor para direita
        int p = partition(vetor, esq, dir);

        // chamar o quicksort com elementos a direita de p
        quicksort(vetor, esq, p);
 
        // chamar o quicksort com elementos a esquerda de p
        quicksort(vetor, p + 1, dir);
    }
}


void criaLista(ListaFilmes *lista){
    lista->numFilmes = 0;
}

void listarFilmes(ListaFilmes *lista){
    for(int i = 0; i < lista->numFilmes;i++){
        printf("nome: %s\n", lista->filmes[i].nome);
        printf("ano de lancamento: %d\n", lista->filmes[i].anoLancamento);
        printf("nome do diretor: %s\n", lista->filmes[i].diretor);
        printf("=====================================================\n");

    }
}

void adicionarFilme(ListaFilmes *lista, Filme filme){
    if(lista->numFilmes < MAX - 1){
        lista->filmes[lista->numFilmes] = filme;
        lista->numFilmes += 1;
    } else {
        printf("Lista ja esta cheia!!!");
    }
}

void ordenarFilmes(ListaFilmes *lista){
    quicksort(lista, 0, lista->numFilmes - 1);
}

int buscaBinaria(ListaFilmes *lista, char* nomeFilme, int esq, int dir){
    int m = (esq + dir)/2;

    while(esq <= dir){
        if(strcmp(nomeFilme, lista->filmes[m].nome) < 0){
            buscaBinaria(lista, nomeFilme, esq, m - 1);
        } else if(strcmp(nomeFilme, lista->filmes[m].nome) > 0){
            buscaBinaria(lista, nomeFilme, m + 1, dir);
        } else if(strcmp(nomeFilme, lista->filmes[m].nome) == 0){
            return m;
        }
    }
    return -1;
}


int main(){
    ListaFilmes lista;

    criaLista(&lista);
    Filme filme1, filme2, filme3, filme4;
    strcpy(filme1.nome, "duna 2");
    strcpy(filme1.diretor, "denis villenueve");
    filme1.anoLancamento = 2024;

    strcpy(filme2.nome, "avatar 2");
    strcpy(filme2.diretor, "james cameron");
    filme2.anoLancamento = 2023;

    strcpy(filme3.nome, "o menino e a garca");
    strcpy(filme3.diretor, "hayao miyazaki");
    filme3.anoLancamento = 2024;

    strcpy(filme4.nome, "questao de tempo");
    strcpy(filme4.diretor, "richard curtis");
    filme4.anoLancamento = 2013;


    adicionarFilme(&lista, filme1);
    adicionarFilme(&lista, filme2);
    adicionarFilme(&lista, filme3);
    adicionarFilme(&lista, filme4);

    printf("\n\nLista desordenada:\n");
    listarFilmes(&lista);
    ordenarFilmes(&lista);

    printf("\n\nLista ordenada:\n");
    listarFilmes(&lista);



}