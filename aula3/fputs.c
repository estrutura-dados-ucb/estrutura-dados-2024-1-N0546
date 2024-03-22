#include <stdio.h>

int main() {
    FILE *arquivo = fopen("exemplo.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char *mensagem = "\nhello, world!\n";
    char nome[30];
    
    scanf("%s", nome);
    fputs(nome, arquivo);

    fputs(mensagem, arquivo);
    fputs("segunda linha", arquivo);


    fclose(arquivo);

    return 0;
}
