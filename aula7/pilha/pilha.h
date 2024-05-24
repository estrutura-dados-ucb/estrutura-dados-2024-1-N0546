#ifndef PILHA_H
#define PILHA_H

typedef struct Node Node;

Node* createNode(int value);
void showStack();
void push(int value); // inserir
int pop(); // remover
int stackIsEmpty();

#endif