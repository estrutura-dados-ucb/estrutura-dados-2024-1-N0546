#include <stdio.h>
#include <stdlib.h>

// [2]
//  |
//  \/
// [1] 
//  |
//  \/
// NULL 
typedef struct Node {
    int value;
    struct Node* prox;
} Node;


Node* top = NULL;

int stackIsEmpty(){
    return top == NULL;
}

Node* createNode(int value){
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;
    return node;
}

void push(int value){
    Node* node = createNode(value);
    if(stackIsEmpty()){
        node->prox = NULL;
    } else {
        node->prox = top;
    }
    top = node;
}

int pop(){
    // salvando endereço do elemento do topo
    Node* temp = top;

    int topValue = temp->value;
    top = top->prox;
    free(temp);

    return topValue;
}


void showStack(){
    Node* current = top;
    while(current != NULL){
        printf("|  %d  |\n", current->value);
        current = current->prox;
    }
}


int main(){
    push(1);
    push(2);
    push(3);
    showStack();
    int value;
    value = pop();
    printf("elemento removido: %d\n", value);
    showStack();

    return 0;
}