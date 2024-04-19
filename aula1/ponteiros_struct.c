#include <stdio.h>
#include <string.h>

struct Carro {
    char placa[10];
    char marca[30];
    int ano;
};



int main(){
    struct Carro *ponteiroParaOUno;
    struct Carro uno;

    ponteiroParaOUno = &uno;

    strcpy(uno.placa, "JJJ-9999");
    strcpy(uno.marca, "Fiat");
    uno.ano = 2010;


    printf("marca: %s\n", uno.marca);
    printf("placa: %s\n", uno.placa);
    printf("ano: %d\n", uno.ano);

    // imprimir endereco de uno

    printf("endereco de 'uno': %p\n", ponteiroParaOUno);

    // imprimir o que está salvo em uno
    printf("marca do 'uno': %s\n", (*ponteiroParaOUno).marca);
    printf("marca do 'uno': %s\n", ponteiroParaOUno->marca);

    return 0;
}