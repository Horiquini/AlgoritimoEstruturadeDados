#include <iostream>
#include "fila.h"

using namespace std;

Fila* criaFila() {
    Fila* fila = new Fila;
    fila->inicio = nullptr;
    fila->fim = nullptr;
    return fila;
}

int vaziaFila(Fila* fila) {
    return fila->inicio == nullptr;
}

void enqueue(Fila* fila, int valor) {
    Node* novo = new Node;
    novo->info = valor;
    novo->prox = nullptr;

    if (vaziaFila(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
}

int dequeue(Fila* fila) {
    if (vaziaFila(fila)) {
        cout << "Fila vazia!" << endl;
        return -1;
    }

    Node* aux = fila->inicio;
    int valor = aux->info;
    fila->inicio = aux->prox;

    if (fila->inicio == nullptr) {
        fila->fim = nullptr;
    }

    delete aux;
    return valor;
}

int first(Fila* fila) {
    if (!vaziaFila(fila)) {
        return fila->inicio->info;
    } else {
        cout << "Fila vazia!" << endl;
        return -1;
    }
}

/*imprimir fila*/

void printFila(Fila* fila) {
    if (vaziaFila(fila)) {
        cout << "Fila vazia!" << endl;
        return;
    }

    Fila* aux = criaFila();

    cout << "Fila: ";
    while (!vaziaFila(fila)) {
        int valor = dequeue(fila);
        cout << valor << " -> ";
        enqueue(aux, valor);
    }
    cout << "|X|" << endl;

    // Restaura fila original
    while (!vaziaFila(aux)) {
        enqueue(fila, dequeue(aux));
    }

    delete aux;
}

/*buscar e editar elemento*/

bool buscaEditaElemento(Fila* fila, int antigo, int novoValor) {
    bool editado = false;
    Fila* aux = criaFila();

    while (!vaziaFila(fila)) {
        int atual = dequeue(fila);
        if (atual == antigo && !editado) {
            atual = novoValor;
            editado = true;
        }
        enqueue(aux, atual);
    }

    while (!vaziaFila(aux)) {
        enqueue(fila, dequeue(aux));
    }

    delete aux;
    return editado;
}

/*buscar e remover elemento*/
bool buscaRemoveElemento(Fila* fila, int valor) {
    bool removido = false;
    Fila* aux = criaFila();

    while (!vaziaFila(fila)) {
        int atual = dequeue(fila);
        if (atual == valor && !removido) {
            removido = true; // remove apenas a primeira ocorrência
        } else {
            enqueue(aux, atual);
        }
    }

    while (!vaziaFila(aux)) {
        enqueue(fila, dequeue(aux));
    }

    delete aux;
    return removido;
}

/*remover repetições*/

void removeDuplicados(Fila* fila) {
    Fila* nova = criaFila();

    while (!vaziaFila(fila)) {
        int atual = dequeue(fila);
        bool duplicado = false;

        Fila* temp = criaFila();
        while (!vaziaFila(nova)) {
            int x = dequeue(nova);
            if (x == atual) {
                duplicado = true;
            }
            enqueue(temp, x);
        }

        while (!vaziaFila(temp)) {
            enqueue(nova, dequeue(temp));
        }
        delete temp;

        if (!duplicado) {
            enqueue(nova, atual);
        }
    }

    while (!vaziaFila(nova)) {
        enqueue(fila, dequeue(nova));
    }

    delete nova;
}

/*remover pares*/

void removePares(Fila* fila) {
    Fila* aux = criaFila();

    while (!vaziaFila(fila)) {
        int atual = dequeue(fila);
        if (atual % 2 != 0) {
            enqueue(aux, atual);
        }
    }

    while (!vaziaFila(aux)) {
        enqueue(fila, dequeue(aux));
    }

    delete aux;
}
