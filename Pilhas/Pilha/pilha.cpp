#include <iostream>
#include "pilha.h"
using namespace std;

Pilha* criaPilha() {
    Pilha* p = new Pilha;
    p->topo = NULL;
    return p;
}

int vaziaPilha(Pilha* pilha) {
    return (pilha->topo == NULL);
}

Pilha* push(Pilha* pilha, int valor) {
    Nodo* novo = new Nodo;
    novo->info = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    return pilha;
}

int pop(Pilha* pilha) {
    if (!vaziaPilha(pilha)) {
        Nodo* aux = pilha->topo;
        int valor = aux->info;
        pilha->topo = pilha->topo->prox;
        delete aux;
        return valor;
    } else {
        cout << "Pilha vazia!" << endl;
        return -1;
    }
}

int top(Pilha* pilha) {
    if (!vaziaPilha(pilha)) {
        return pilha->topo->info;
    } else {
        cout << "Pilha vazia!" << endl;
        return -1;
    }
}

void printPilha(Pilha* pilha) {
    if (!vaziaPilha(pilha)) {
        Pilha* aux = criaPilha();
        while (!vaziaPilha(pilha)) {
            int valor = top(pilha);
            cout << "(" << valor << ") -> ";
            push(aux, pop(pilha));
        }
        cout << "|X|" << endl;

        while (!vaziaPilha(aux)) {
            push(pilha, pop(aux));
        }
        delete aux;
    } else {
        cout << "Pilha vazia!" << endl;
    }
}

/* Buscar elemento */

bool buscaElemento(Pilha* pilha, int valor) {
    bool encontrado = false;
    Pilha* aux = criaPilha();

    while (!vaziaPilha(pilha)) {
        if (top(pilha) == valor) {
            encontrado = true;
        }
        push(aux, pop(pilha));
    }

    while (!vaziaPilha(aux)) {
        push(pilha, pop(aux));
    }

    delete aux;
    return encontrado;
}

/* Buscar e remover elemento */

bool buscaRemove(Pilha* pilha, int valor) {
    bool removido = false;
    Pilha* aux = criaPilha();

    while (!vaziaPilha(pilha)) {
        if (!removido && top(pilha) == valor) {
            pop(pilha); // remove o valor
            removido = true;
        } else {
            push(aux, pop(pilha));
        }
    }

    while (!vaziaPilha(aux)) {
        push(pilha, pop(aux));
    }

    delete aux;
    return removido;
}

/* remover numeros pares */

void removePares(Pilha* pilha) {
    Pilha* aux = criaPilha();

    while (!vaziaPilha(pilha)) {
        int v = top(pilha);
        if (v % 2 != 0) {
            push(aux, v);
        }
        pop(pilha);
    }

    while (!vaziaPilha(aux)) {
        push(pilha, pop(aux));
    }

    delete aux;
}

/* remover valores repetidos */

bool existeNaPilha(Pilha* pilha, int valor) {
    bool achou = false;
    Pilha* aux = criaPilha();

    while (!vaziaPilha(pilha)) {
        int v = top(pilha);
        if (v == valor) achou = true;
        push(aux, pop(pilha));
    }

    while (!vaziaPilha(aux)) {
        push(pilha, pop(aux));
    }

    delete aux;
    return achou;
}

void removeDuplicados(Pilha* pilha) {
    Pilha* nova = criaPilha(); // pilha sem duplicatas

    while (!vaziaPilha(pilha)) {
        int atual = pop(pilha);

        // Verifica se já existe em nova
        bool duplicado = false;
        Pilha* temp = criaPilha();

        while (!vaziaPilha(nova)) {
            int topoNova = pop(nova);
            if (topoNova == atual) {
                duplicado = true;
            }
            push(temp, topoNova);
        }

        // Restaura a pilha nova
        while (!vaziaPilha(temp)) {
            push(nova, pop(temp));
        }

        delete temp;

        if (!duplicado) {
            push(nova, atual);
        }
    }

    // Restaura para pilha original
    while (!vaziaPilha(nova)) {
        push(pilha, pop(nova));
    }

    delete nova;
}

