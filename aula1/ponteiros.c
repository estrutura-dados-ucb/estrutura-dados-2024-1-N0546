#include <stdio.h>

void func(int **ponteiro){
    
    printf("dentro de func:\n");

    printf("endereco apontado pelo ponteiro: %p\n", *ponteiro);
    printf("endereco do ponteiro: %p\n", ponteiro);
    printf("valor salvo no endereco apontado por ponteiro: %d\n", *(*ponteiro));

    int novoValor = 42;
    *ponteiro = &novoValor;

}


int main(){
    int numero = 1;
    int *ponteiro; // vai armazenar endereço de "numero"
    int valores[2];

    ponteiro = &numero;
    printf("na main:\n");
    printf("endereco apontado pelo ponteiro: %p\n", ponteiro);
    printf("endereco do ponteiro: %p\n", &ponteiro);
    printf("valor salvo no endereco apontado por ponteiro: %d\n\n\n", *ponteiro);
    func(&ponteiro);

    printf("valor da var apontada por ponteiro depois de chamar func: %d\n", *ponteiro);





    /* printf("endereco de numero: %p\n", &numero); // & -> diz o endereço da variável na memória
    printf("valor de ponteiro: %p\n", ponteiro);
    printf("valor de numero por meio da variavel ponteiro: %d\n", *ponteiro);
    printf("valor de numero: %d", numero); // valor da variável na memória
 */
    return 0;
}