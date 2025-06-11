#ifndef FILA_H
#define FILA_H

struct Node {
    int info;
    Node* prox;
};

typedef struct Node Node;

struct Fila {
    Node* inicio;
    Node* fim;
};

typedef struct Fila Fila;

Fila* criaFila();
int vaziaFila(Fila* fila);
void enqueue(Fila* fila, int valor);
int dequeue(Fila* fila);
int first(Fila* fila);
void printFila(Fila* fila);
bool buscaEditaElemento(Fila* fila, int antigo, int novoValor);
bool buscaRemoveElemento(Fila* fila, int valor);
void removeDuplicados(Fila* fila);
void removePares(Fila* fila);


#endif

