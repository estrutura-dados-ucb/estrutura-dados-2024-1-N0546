#include <stdio.h>

int main(){
    FILE* arq = fopen("exemplo.txt", "w+");

    if(arq == NULL){
        printf("Erro ao abrir arquivo!!!");
        return 1;
    }

    return 0;
}