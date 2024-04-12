#include <stdio.h>

int partition(int *vetor, int esq, int dir){
    int pivot = vetor[esq];

    // indicador de elementos a esquerda
    int i = esq - 1;

    // indicador de elementos a direita
    int j = dir + 1;
    printf("Sorting between indexes %d and %d...\n", i + 1, j - 1);
    printf("Pivot: %d\n", pivot);
    printf("Before sorting:\n");
    for(int i = 0; i<10;i++){
        printf("%d ", vetor[i]);
    }
    printf("\n\n");

    while(1){
        do{
            i += 1;
        } while(vetor[i] < pivot);

        do{
            j -= 1;
        }while(vetor[j] > pivot);
        

        if(i >= j){
            // retornando o pivô para a função quicksort
            return j;
        }

        printf("\nSwapping vetor[%d] and vetor[%d]...\n", i, j);

        int tmp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = tmp;
        printf("After swapping:\n");
        for(int i = 0; i<10;i++){
            printf("%d ", vetor[i]);
        }
        printf("\n\n");
    }
}


void quicksort(int* vetor, int esq, int dir){
    if(esq >= 0 && dir >= 0 && esq < dir){
        // selecionar um pivô
        int p = partition(vetor, esq, dir);
        printf("Returned pivot position: %d\n", p);
        printf("-----------------------------------------\n");
        for(int i = 0; i<10;i++){
            printf("%d ", vetor[i]);
        }
        printf("\n-----------------------------------------\n");

        // chamar o quicksort com elementos a direita do pivô
        quicksort(vetor, esq, pivot);
 
        // chamar o quicksirt com elementos a esquerda do pivô
        quicksort(vetor, pivot + 1, dir);
    }
}



int main(){
    int vetor[] = {5, 1, 2, 10, 8, 7, 6, 3, 9, 4};

    quicksort(vetor, 0, 9);
    for(int i = 0; i<10;i++){
        printf("%d ", vetor[i]);
    }

}