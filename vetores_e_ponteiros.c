#include <stdio.h>

int main(){

    int valores[2];

    valores[0] = 1;
    valores[1] = 2;

    printf("valores[0]: %d\n", valores[0]);
    printf("valores[1]: %d\n", valores[1]);

    printf("endereco de valores[0]: %p\n", valores);
    printf("endereco de valores[1]: %p\n", valores + 1);
    printf("valores[0]: %d\n", *valores);
    printf("valores[1]: %d\n", *valores + 1);

    return 0;
}