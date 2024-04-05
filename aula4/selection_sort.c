#include <stdio.h>


int main(){
    int vetor[] = {10, 42, 100, 150, 8, 9, 1, 0, 3, 7};
    int tmp;
    int maior = -1;
    int posMaior = -1;

    for(int j = 9;j >= 0;j--){
        maior = -1;
        // for para achar o maior valor:
        for(int i = 0;i <= j;i++){
            if(vetor[i] > maior){
                posMaior = i;
                maior = vetor[i];
            }
        }
        // troco último elemento pelo maior valor encontrado
        tmp = vetor[posMaior];
        vetor[posMaior] = vetor[j];
        vetor[j] = tmp;
    }

    for(int i = 0;i<10;i++){
        printf("%d ", vetor[i]);
    }

}