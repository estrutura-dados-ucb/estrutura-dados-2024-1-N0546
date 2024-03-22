#include <stdio.h>

int main() {
    int caractere;
    FILE *arquivo = fopen("exemplo.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    printf("Conteudo do arquivo:\n");
    while (!feof(arquivo)) {
        caractere = fgetc(arquivo);
        printf("%c", caractere);
    }

    fclose(arquivo);

    return 0;
}
