#include <iostream>
#include "pilha.h"
using namespace std;

int main() {
    Pilha* minhaPilha = criaPilha();

    cout << "Empilhando 10, 20, 30..." << endl;
    push(minhaPilha, 10);
    push(minhaPilha, 20);
    push(minhaPilha, 30);
    push(minhaPilha, 3);
    push(minhaPilha, 9);
    push(minhaPilha, 10);
    push(minhaPilha, 30);
    push(minhaPilha, 2);
    push(minhaPilha, 2);
    push(minhaPilha, 1);


    cout << "Conteudo da pilha: ";
    printPilha(minhaPilha);

    cout << "Topo da pilha: " << top(minhaPilha) << endl;

    cout << "Desempilhando um elemento..." << endl;
    pop(minhaPilha);
    cout << "Pilha apos pop: ";
    printPilha(minhaPilha);
    cout << "Desempilhando um elemento..." << endl;
    pop(minhaPilha);
    cout << "Pilha apos pop: ";
    printPilha(minhaPilha);
    cout << "Desempilhando um elemento..." << endl;
    pop(minhaPilha);
    cout << "Pilha apos pop: ";
    printPilha(minhaPilha);


    cout << "Buscando 20: " << (buscaElemento(minhaPilha, 20) ? "Encontrado" : "Não encontrado") << endl;
    cout << "Removendo 10: " << (buscaRemove(minhaPilha, 10) ? "Removido" : "Não encontrado") << endl;

    removePares(minhaPilha);
    cout << "Conteudo da pilha sem pares: ";
    printPilha(minhaPilha);

    removeDuplicados(minhaPilha);
    cout << "Conteudo da pilha sem duplicados: ";
    printPilha(minhaPilha);


    return 0;
}

