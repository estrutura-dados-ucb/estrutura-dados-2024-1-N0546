#include <stdio.h>

int main() {
    const char *filename = "exemplo.txt";

    if (remove(filename) == 0) {
        printf("Arquivo '%s' removido com sucesso.\n", filename);
    } else {
        printf("Erro ao remover o arquivo '%s'.\n", filename);
    }

    return 0;
}
