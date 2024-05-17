#include <stdio.h>
#include <string.h>
#include "filmes.h"

typedef struct NoFilme {
    char nome[50];
    int anoLancamento;
    char diretor[50];
    NoFilme* proxFilme;
} NoFilme;

NoFilme *head = NULL;

void criarLista(NoFilme* filme){
    head = filme;
    filme->proxFilme = NULL;
}

void adicionarFilme(NoFilme *filme){
    if(head == NULL){
        criarLista(filme);
    } else {
        filme->proxFilme = head;
        head = filme;
    }
}

void listarFilmes(){
    printf("Listando filmes...\n");
    NoFilme* filmeAtual = head;
    
    // head armazena o endereço do primeiro elemento
    // head = &filme
    // *head -> filme

    // enquanto próximo filme existe
    while(filmeAtual != NULL){
				printf("==================================================\n");
        printf("nome do filme: %s\n", filmeAtual->nome);
        printf("diretor(a) do filme: %s\n", filmeAtual->diretor);
        printf("ano de lancamento do filme: %d\n",filmeAtual->anoLancamento);

        filmeAtual = filmeAtual->proxFilme;
    }
		printf("==================================================\n\n\n");
}

int removerFilme(char* nomeFilme){
		printf("Removendo %s...\n\n\n", nomeFilme);
    // se filme que é pra ser removido é o primeiro
    if(strcmp(head->nome, nomeFilme) == 0){
        head = head->proxFilme;
        return 1;
    }
    else {

        NoFilme* filmeAtual = head;
        NoFilme* filmeAposFilmeAtual = head->proxFilme;
				
        while(filmeAposFilmeAtual != NULL){
            // head -> filme1 -> filme2 -> filme3 ...

            if(strcmp(filmeAposFilmeAtual->nome, nomeFilme) == 0){
                NoFilme* proxFilme = filmeAposFilmeAtual->proxFilme;
                filmeAtual->proxFilme = proxFilme;
                return 1;

            }

            filmeAtual = filmeAtual->proxFilme;
            filmeAposFilmeAtual = filmeAposFilmeAtual->proxFilme;
        }
    }
    return 0;
}

int buscarFilme(char* nomeFilme){
    NoFilme* filmeAtual = head;
    printf("Buscando por \"%s\"...\n", nomeFilme);
    while(filmeAtual != NULL){
        if(strcmp(filmeAtual->nome, nomeFilme) == 0){
          printf("Filme encontrado!\n");
          printf("Informacoes:\n");
          printf("nome do filme: %s\n", filmeAtual->nome);
          printf("diretor(a) do filme: %s\n", filmeAtual->diretor);
          printf("ano de lancamento do filme: %d\n\n\n",filmeAtual->anoLancamento);
          return 1;
        }
        filmeAtual = filmeAtual->proxFilme;
    }
  
    printf("\"%s\" nao encontrado!\n\n\n", nomeFilme);
    return 0;
}

int main(){

    NoFilme filme1, filme2, filme3;
    strcpy(filme1.nome, "Senhor dos Anéis");
    filme1.anoLancamento = 2002;
    strcpy(filme1.diretor, "Peter Jackson");
    adicionarFilme(&filme1);


    strcpy(filme2.nome, "As branquelas");
    filme2.anoLancamento = 2004;
    strcpy(filme2.diretor, "Keenen Ivory Wayans");
    adicionarFilme(&filme2);

    
    strcpy(filme3.nome, "Carros");
    filme3.anoLancamento = 2005;
    strcpy(filme3.diretor, "......");
    adicionarFilme(&filme3);

    listarFilmes();
    removerFilme("Senhor dos Anéis");
    listarFilmes();

    buscarFilme("2001");
    buscarFilme("As branquelas");
 

    return 0;
}
