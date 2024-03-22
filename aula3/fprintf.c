#include <stdio.h>

int main() {
    FILE *arquivo = fopen("exemplo.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    char *nome = "joao";

    int idade = 26;

    fprintf(arquivo, "nome: %s\nidade: %d\n", nome, idade);
    
    fclose(arquivo);

    return 0;
}
