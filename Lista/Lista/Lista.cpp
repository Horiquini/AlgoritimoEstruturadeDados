#include "lista.h"

Nodo* criaLista() {
    cout << "Lista criada!" << endl;
    return NULL;
}

int listaVazia(Nodo* lista) {
    return (lista == NULL);
}

Nodo* insereIni(Nodo* lista, int elem) {
    Nodo* novo = new Nodo;
    novo->info = elem;
    novo->prox = lista;
    return novo;
}

Nodo* insereFim(Nodo* lista, int elem) {
    Nodo* novo = new Nodo;
    novo->info = elem;
    novo->prox = NULL;

    if (listaVazia(lista)) {
        return novo;
    } else {
        Nodo* aux = lista;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
        return lista;
    }
}

Nodo* removeIni(Nodo* lista) {
    if (!listaVazia(lista)) {
        Nodo* aux = lista;
        lista = lista->prox;
        delete aux;
    } else {
        cout << "A lista já se encontra vazia!" << endl;
    }
    return lista;
}

Nodo* removeFim(Nodo* lista) {
    if (!listaVazia(lista)) {
        Nodo* ant = NULL;
        Nodo* aux = lista;

        while (aux->prox != NULL) {
            ant = aux;
            aux = aux->prox;
        }

        if (ant != NULL) {
            ant->prox = NULL;
        } else {
            lista = NULL;
        }

        delete aux;
    } else {
        cout << "A lista se encontra vazia!" << endl;
    }
    return lista;
}

Nodo* removeElem(Nodo* lista, int elem) {
    if (!listaVazia(lista)) {
        Nodo* aux = lista;
        Nodo* ant = NULL;

        while (aux && aux->info != elem) {
            ant = aux;
            aux = aux->prox;
        }

        if (aux) {
            if (aux != lista) {
                ant->prox = aux->prox;
            } else {
                lista = lista->prox;
            }
            delete aux;
        } else {
            cout << "O elemento buscado não se encontra na lista!" << endl;
        }
    } else {
        cout << "A lista se encontra vazia!" << endl;
    }

    return lista;
}

Nodo* buscaElem(Nodo* lista, int elem) {
    Nodo* aux = lista;
    while (aux && aux->info != elem) {
        aux = aux->prox;
    }
    return aux;
}

Nodo* editaElem(Nodo* pontElem, int edit) {
    if (pontElem) {
        pontElem->info = edit;
    }
    return pontElem;
}

int acessaElem(Nodo* pontElem) {
    if (pontElem)
        return pontElem->info;
    return -1;
}

void printLista(Nodo* lista) {
    if (!listaVazia(lista)) {
        Nodo* aux = lista;
        while (aux) {
            cout << "(" << aux->info << ") -> ";
            aux = aux->prox;
        }
        cout << "|x|" << endl;
    } else {
        cout << "Lista vazia!" << endl;
    }
}

int lenLista(Nodo* lista) {
    int count = 0;
    while (lista) {
        count++;
        lista = lista->prox;
    }
    return count;
}

int maxLista(Nodo* lista) {
    if (listaVazia(lista)) return -1;
    int max = lista->info;
    Nodo* aux = lista->prox;
    while (aux) {
        if (aux->info > max) max = aux->info;
        aux = aux->prox;
    }
    return max;
}

int minLista(Nodo* lista) {
    if (listaVazia(lista)) return -1;
    int min = lista->info;
    Nodo* aux = lista->prox;
    while (aux) {
        if (aux->info < min) min = aux->info;
        aux = aux->prox;
    }
    return min;
}

float mediaLista(Nodo* lista) {
    int soma = 0, cont = 0;
    while (lista) {
        soma += lista->info;
        cont++;
        lista = lista->prox;
    }
    return cont > 0 ? (double)soma / cont : 0.0;
}

Nodo* appendLista(Nodo* l1, Nodo* l2) {
    if (listaVazia(l1)) return l2;
    Nodo* aux = l1;
    while (aux->prox) {
        aux = aux->prox;
    }
    aux->prox = l2;
    return l1;
}

Nodo* reverseLista(Nodo* lista) {
    Nodo* ant = NULL;
    Nodo* atual = lista;
    Nodo* prox = NULL;

    while (atual) {
        prox = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = prox;
    }
    return ant;
}

bool isSubLista(Nodo* l1, Nodo* l2) {
    if (!l2) return 1;
    while (l1) {
        Nodo* a = l1;
        Nodo* b = l2;
        while (a && b && a->info == b->info) {
            a = a->prox;
            b = b->prox;
        }
        if (!b) return 1;
        l1 = l1->prox;
    }
    return 0;
}
