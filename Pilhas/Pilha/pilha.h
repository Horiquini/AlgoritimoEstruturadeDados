#ifndef PILHA_H
#define PILHA_H

struct Nodo {
    int info;
    Nodo* prox;
};

typedef struct Nodo Nodo;

struct Pilha {
    Nodo* topo;
};

typedef struct Pilha Pilha;

// Protótipos
Pilha* criaPilha();
int vaziaPilha(Pilha* pilha);
Pilha* push(Pilha* pilha, int valor);
int pop(Pilha* pilha);
int top(Pilha* pilha);
void printPilha(Pilha* pilha);

bool buscaElemento(Pilha* pilha, int valor);
bool buscaRemove(Pilha* pilha, int valor);
void removePares(Pilha* pilha);
void removeDuplicados(Pilha* pilha);

#endif

