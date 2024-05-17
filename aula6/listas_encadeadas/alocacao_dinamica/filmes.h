#ifndef FILMES_H
#define FILMES_H

typedef struct NoFilme NoFilme;

void criarLista(NoFilme** filme);
void adicionarFilme(NoFilme** filme);
void listarFilmes();
int removerFilme(char* nomeFilme);
int buscarFilme(char* nomeFilme);

#endif
