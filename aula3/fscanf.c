#include <stdio.h>

int main() {
    FILE *arquivo = fopen("exemplo.txt", "r");
    char texto[30];
    int numero;

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fscanf(arquivo, "%s", texto);
    printf("%s\n", texto);

    fscanf(arquivo, "%s", texto);

    printf("%s\n", texto);

    fclose(arquivo);

    return 0;
}
