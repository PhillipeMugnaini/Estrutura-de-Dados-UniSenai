/*
----------------------------------------------------
Nome: Phillipe Gabriel da Silva Littig Mugnaini
Matricula: 00757994
----------------------------------------------------
*/

#include <iostream>

using namespace std;

struct No {
    int valor;
    No* proximo;
};

void inserirFinal(No*& inicio, int valor) {

    No* novo = new No;

    novo->valor = valor;
    novo->proximo = nullptr;

    // Verifica se a lista está vazia
    if (inicio == nullptr) {
        inicio = novo;
    }
    else {

        No* aux = inicio;

        // Percorre até o último nó
        while (aux->proximo != nullptr) {
            aux = aux->proximo;
        }

        // Liga o último nó ao novo nó
        aux->proximo = novo;
    }
}

void exibirLista(No* inicio) {

    No* aux = inicio;

    cout << "\nSequencia de Fibonacci:" << endl;

    // Percorre a lista exibindo os valores
    while (aux != nullptr) {
        cout << aux->valor << " ";

        aux = aux->proximo;
    }

    cout << endl;
}

// Função para liberar a memória da lista
void liberarLista(No*& inicio) {

    No* aux = inicio;

    while (aux != nullptr) {

        No* temp = aux;

        aux = aux->proximo;

        delete temp;
    }

    inicio = nullptr;
}

int main() {

    No* inicio = nullptr;

    int quantidade;

    cout << "Digite a quantidade de termos da sequencia de Fibonacci: ";
    cin >> quantidade;

    // Verifica se a quantidade é válida
    if (quantidade <= 0) {
        cout << "Quantidade invalida!" << endl;
        return 1;
    }

    int a = 0;
    int b = 1;

    // Geração da sequência de Fibonacci
    for (int i = 0; i < quantidade; i++) {

        inserirFinal(inicio, a);

        int proximo = a + b;

        a = b;
        b = proximo;
    }

    exibirLista(inicio);

    liberarLista(inicio);

    return 0;
}