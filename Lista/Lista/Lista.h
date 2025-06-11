#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using namespace std;

struct nodo {
    int info;
    struct nodo* prox;
};

typedef struct nodo Nodo;

Nodo* criaLista();
int listaVazia(Nodo* lista);
Nodo* insereIni(Nodo* lista, int elem);
Nodo* insereFim(Nodo* lista, int elem);
Nodo* removeIni(Nodo* lista);
Nodo* removeFim(Nodo* lista);
Nodo* removeElem(Nodo* lista, int elem);
Nodo* buscaElem(Nodo* lista, int elem);
Nodo* editaElem(Nodo* pontElem, int edit);
int acessaElem(Nodo* pontElem);
void printLista(Nodo* lista);


int lenLista(Nodo* lista);
int maxLista(Nodo* lista);
int minLista(Nodo* lista);
float mediaLista(Nodo* lista);
Nodo* appendLista(Nodo* lista1, Nodo* lista2);
Nodo* reverseLista(Nodo* lista);
bool isSubLista(Nodo* lista, Nodo* sub);

#endif
