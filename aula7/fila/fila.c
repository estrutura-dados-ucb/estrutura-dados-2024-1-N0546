#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* prox;
} Node;


Node* front = NULL;
Node* rear = NULL;

int queueIsEmpty(){
    return front == NULL;
}

Node* createNode(int value){
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;
    return node;
}

void enqueue(int value){
    Node* node = createNode(value);
    if(queueIsEmpty()){
        front = node;
        rear = node;
    } else {
        // [1] -> [2] -> [3]
        // coloco novo elemento na próxima posição
        rear->prox = node;
        node->prox = NULL;
        rear = node;
    }
    

}

int dequeue(){
    // salvando endereço do elemento do topo
    Node* temp = front;
    int frontValue = temp->value;


    front = front->prox;
    free(temp);

    return frontValue;
}


void showQueue(){
    Node* current = front;
    while(current != NULL){
        printf("|  %d  |", current->value);
        current = current->prox;
    }
    printf("\n");
}


int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    showQueue();
    int value;
    value = dequeue();
    printf("elemento removido: %d\n", value);
    showQueue();

    return 0;
}