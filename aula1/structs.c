#include <stdio.h>
#include <string.h>

typedef struct Pessoa {
    int idade;
    char nome[30];
    float altura;
} Pessoa;


int main(){
    Pessoa pessoa1;

    pessoa1.idade = 20;
    pessoa1.altura = 1.8;
    strcpy(pessoa1.nome, "amfkfma");

    return 0;
}