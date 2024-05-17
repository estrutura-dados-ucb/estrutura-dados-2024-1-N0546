#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

void preencheEMostraLista(int *lista, int tamanho){
    for(int i = 0;i < tamanho;i++){
        lista[i] = 10*i;
    }

    for(int i = 0;i < tamanho;i++){
       printf("lista[%d] = %d\n", i, lista[i]);
    }
}



int main(){
    int lista_estatica[MAX_SIZE];
    preencheEMostraLista(lista_estatica, MAX_SIZE);

    int* lista_dinamica;
    lista_dinamica = (int*) malloc(sizeof(int)*20);
    printf("com 20 itens:\n");
    preencheEMostraLista(lista_dinamica, 20);
    lista_dinamica = (int*) realloc(lista_dinamica, sizeof(int)*10);
    printf("com 10 itens:\n");
    preencheEMostraLista(lista_dinamica, 10);

    return 0;
}