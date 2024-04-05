#include <stdio.h>


int main(){
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tmp;
    int temAlgumValorDesordenado = 0;

    for(int j = 0;j < 9;j++){
        for(int i = 0;i < 9 - j;i++){
            if(vetor[i] > vetor[i+1]){
                tmp = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = tmp;
                temAlgumValorDesordenado = 1;
            }
        }
        if(!temAlgumValorDesordenado){
            printf("o array ja ta ordenado!\n");
            break;
         }
    }

    for(int i = 0;i<10;i++){
        printf("%d ", vetor[i]);
    }

}