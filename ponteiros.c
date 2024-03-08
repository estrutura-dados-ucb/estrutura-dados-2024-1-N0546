#include <stdio.h>

int main(){
    int numero = 1;
    int *ponteiro; // vai armazenar endereço de "numero"
    int valores[2];

    ponteiro = &numero;

    printf("endereco de numero: %p\n", &numero); // & -> diz o endereço da variável na memória
    printf("valor de ponteiro: %p\n", ponteiro);
    printf("valor de numero por meio da variavel ponteiro: %d\n", *ponteiro);
    printf("valor de numero: %d", numero); // valor da variável na memória

    return 0;
}