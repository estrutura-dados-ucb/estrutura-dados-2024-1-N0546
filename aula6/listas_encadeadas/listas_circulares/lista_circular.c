#include <stdio.h>
#include <stdlib.h>

typedef struct item {
    int valor;
    struct item* prox;
} Item;

Item* inicio;
Item* fim;

Item* inicializaLista(int valor){
    Item* elem = (Item*) malloc(sizeof(Item));

    if(elem == NULL){
        printf("Erro ao alocar item!!!\n");
    }

    elem->valor = valor;
    elem->prox = NULL;
    inicio = elem;
    fim = elem;
    return elem;
}

void exibeLista(Item* itemInicial){

		Item* itemAtual = inicio;

		while(1){
				printf("%d\n", itemAtual->valor);
				itemAtual = itemAtual->prox;
				if(itemAtual == inicio){
					break;
				}
		}
}

// adiciona elemento ao fim da lista
void adicionaElemento(int valor){
    Item* elem = (Item*) malloc(sizeof(Item));

    if(elem == NULL){
        printf("Erro ao alocar item!!!\n");
    }

    elem->valor = valor;
    elem->prox = inicio; // ponteiro para prox. do último elemento aponta pro começo da lista
		fim->prox = elem;
    fim = elem;
}

int buscaPorElemento(int valor){
    Item* itemAtual = inicio;
    int ix = 0;
    while(1){
        if(itemAtual->valor == valor){
            printf("Elemento com valor %d encontrado!\n", valor);
            return ix;
        }
        itemAtual = itemAtual->prox;
        if(itemAtual == inicio){
            break;
        }
        ix++;
    }
    return -1;
}



int removeElemento(int valor){
    Item* itemAtual = inicio;
    Item* itemAnterior = NULL;
    while(1){
        if(itemAtual->valor == valor){
            printf("Elemento com valor %d encontrado! Removendo elemento...\n", valor);
            if(itemAtual == inicio){ // removendo primeiro elemento
                inicio = itemAtual->prox; // atualizar ponteiro para início da lista
								fim->prox = inicio;
            } else if(itemAtual == fim){ // removendo último elemento
                itemAnterior->prox = inicio; // atualizar ponteiro para fim da lista
                fim = itemAnterior;
            } else { // se for elemento do "meio"
                itemAnterior->prox = itemAtual->prox;
            }
            free(itemAtual);
            break;
        }
        itemAnterior = itemAtual;
        itemAtual = itemAtual->prox;

				// se deu a volta na lista e ainda não encontrou...
        if(itemAtual == inicio){
            break;
        }
    }
}


int tamanhoLista(){
    int tam = 0;
    Item* itemAtual = inicio;

    if(itemAtual == NULL){
        return 0;
    }
		
		do{
        tam++;
        itemAtual = itemAtual->prox;
		}
    while(itemAtual != inicio);

    return tam;
}


int main(){

    printf("Tamanho da lista inicialmente: %d\n", tamanhoLista());

    inicializaLista(0);
    adicionaElemento(1);
    adicionaElemento(1);
    adicionaElemento(2);
    adicionaElemento(3);
    adicionaElemento(5);
    printf("Exibindo lista na ordem de insercao:\n");
    exibeLista(inicio);
    printf("Tamanho da lista apos as adicoes: %d\n", tamanhoLista());

    removeElemento(2);

    exibeLista(inicio);
    printf("Tamanho da lista apos remocao: %d\n", tamanhoLista());

    int ixElem = buscaPorElemento(5);
    printf("Indice do elemento 5: %d\n", ixElem);
    
    return 0;
}
