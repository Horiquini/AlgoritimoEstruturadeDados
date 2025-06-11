#include <iostream>
#include "lista.h" // Certifique-se de que contém todas as funções
using namespace std;

int main() {
    Nodo* minhaLista = criaLista();

    // Inserções no início
    minhaLista = insereIni(minhaLista, 10);
    minhaLista = insereIni(minhaLista, 20);
    minhaLista = insereIni(minhaLista, 30);
    cout << "Lista apos insercoes no início:" << endl;
    printLista(minhaLista);

    // Inserções no fim
    minhaLista = insereFim(minhaLista, 5);
    minhaLista = insereFim(minhaLista, 1);
    cout << "Lista apos insercoes no fim:" << endl;
    printLista(minhaLista);

    // Remover início
    minhaLista = removeIni(minhaLista);
    cout << "Lista apos remover início:" << endl;
    printLista(minhaLista);

    // Remover fim
    minhaLista = removeFim(minhaLista);
    cout << "Lista apos remover fim:" << endl;
    printLista(minhaLista);

    // Buscar elemento
    Nodo* buscado = buscaElem(minhaLista, 10);
    if (buscado) {
        cout << "Elemento 10 encontrado. Valor: " << acessaElem(buscado) << endl;
    } else {
        cout << "Elemento 10 não encontrado!" << endl;
    }

    // Editar elemento
    buscado = buscaElem(minhaLista, 10);
    if (buscado) {
        editaElem(buscado, 99);
        cout << "Elemento 10 editado para 99:" << endl;
        printLista(minhaLista);
    }

    // Remover elemento específico
    minhaLista = removeElem(minhaLista, 20);
    cout << "Lista apos remover elemento 20:" << endl;
    printLista(minhaLista);

    // Tentando remover elemento inexistente
    minhaLista = removeElem(minhaLista, 500);

    // Novos recursos
    cout << "\n=== Novos Recursos ===" << endl;
    cout << "Tamanho da lista: " << lenLista(minhaLista) << endl;
    cout << "Maior valor: " << maxLista(minhaLista) << endl;
    cout << "Menor valor: " << minLista(minhaLista) << endl;
    cout << "Média dos valores: " << mediaLista(minhaLista) << endl;

    // Criando nova lista para testar concatenação e sublista
    Nodo* outraLista = criaLista();
    outraLista = insereFim(outraLista, 5);
    outraLista = insereFim(outraLista, 1);

    // Concatenação
    minhaLista = appendLista(minhaLista, outraLista);
    cout << "Lista apos concatenacao:" << endl;
    printLista(minhaLista);

    // Inversão
    minhaLista = reverseLista(minhaLista);
    cout << "Lista apos inversao:" << endl;
    printLista(minhaLista);

    // Verificando se é sublista
    int sub = isSubLista(minhaLista, outraLista);
    cout << "A outra lista e sublista? " << (sub ? "Sim" : "Nao") << endl;

    return 0;
}


