#include <iostream>
#include "fila.h"

using namespace std;

int main() {
    Fila* minhaFila = criaFila();

    // Inserindo elementos
    enqueue(minhaFila, 10);
    enqueue(minhaFila, 20);
    enqueue(minhaFila, 30);
    enqueue(minhaFila, 10); // duplicado
    enqueue(minhaFila, 40);
    enqueue(minhaFila, 2);  // par
    enqueue(minhaFila, 3);
    enqueue(minhaFila, 20); // duplicado
    enqueue(minhaFila, 5);  // impar
    enqueue(minhaFila, 6);  // par

    cout << "\nFila original:" << endl;
    printFila(minhaFila);

    // Buscar e editar
    cout << "\nEditando o primeiro '10' para '99'..." << endl;
    if (buscaEditaElemento(minhaFila, 10, 99))
        cout << "Elemento editado com sucesso." << endl;
    else
        cout << "Elemento não encontrado para edição." << endl;

    printFila(minhaFila);

    // Buscar e remover
    cout << "\nRemovendo o primeiro '20'..." << endl;
    if (buscaRemoveElemento(minhaFila, 20))
        cout << "Elemento removido com sucesso." << endl;
    else
        cout << "Elemento não encontrado para remoção." << endl;

    printFila(minhaFila);

    // Remover duplicados
    cout << "\nRemovendo elementos duplicados..." << endl;
    removeDuplicados(minhaFila);
    printFila(minhaFila);

    // Remover pares
    cout << "\nRemovendo todos os pares..." << endl;
    removePares(minhaFila);
    printFila(minhaFila);

    return 0;
}
