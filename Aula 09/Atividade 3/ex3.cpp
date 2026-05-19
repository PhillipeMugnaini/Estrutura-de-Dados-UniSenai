#include <iostream>
using namespace std;

struct No {
    int valor;
    No* proximo;

    No(int v) {
        valor = v;
        proximo = nullptr;
    }
};

class FilaDinamica {
private:
    No* inicio;
    No* fim;

public:
    FilaDinamica() {
        inicio = nullptr;
        fim = nullptr;
    }

    ~FilaDinamica() {
        while (!estaVazia()) {
            dequeue();
        }
    }

    bool estaVazia() {
        return inicio == nullptr;
    }

    void enqueue(int valor) {
        No* novo = new No(valor);

        if (estaVazia()) {
            inicio = novo;
            fim = novo;
        } else {
            fim->proximo = novo;
            fim = novo;
        }

        cout << valor << " inserido na fila." << endl;
    }

    void dequeue() {
        if (estaVazia()) {
            cout << "Fila vazia!" << endl;
            return;
        }

        No* temp = inicio;
        int removido = inicio->valor;

        inicio = inicio->proximo;

        if (inicio == nullptr) {
            fim = nullptr;
        }

        delete temp;

        cout << removido << " removido da fila." << endl;
    }

    void peek() {
        if (estaVazia()) {
            cout << "Fila vazia!" << endl;
            return;
        }

        cout << "Primeiro elemento: " << inicio->valor << endl;
    }

    void exibir() {
        if (estaVazia()) {
            cout << "Fila vazia!" << endl;
            return;
        }

        No* atual = inicio;

        cout << "Fila: ";

        while (atual != nullptr) {
            cout << atual->valor << " ";
            atual = atual->proximo;
        }

        cout << endl;
    }
};

int main() {
    FilaDinamica fila;

    fila.enqueue(10);
    fila.enqueue(20);
    fila.enqueue(30);

    fila.exibir();

    fila.peek();

    fila.dequeue();

    fila.exibir();

    fila.peek();

    return 0;
}