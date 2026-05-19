#include <iostream>

using namespace std;

class FilaCircular {
private:
    int *fila;
    int capacidade;
    int inicio;
    int fim;
    int quantidade;

public:
    FilaCircular(int tamanho) {
        capacidade = tamanho;
        fila = new int[capacidade];

        inicio = 0;
        fim = 0;
        quantidade = 0;
    }

    ~FilaCircular() {
        delete[] fila;
    }

    bool estaVazia() {
        return quantidade == 0;
    }

    bool estaCheia() {
        return quantidade == capacidade;
    }

    void enqueue(int valor) {
        if (estaCheia()) {
            cout << "Fila cheia!" << endl;
            return;
        }

        fila[fim] = valor;

        fim = (fim + 1) % capacidade;

        quantidade++;

        cout << valor << " inserido na fila." << endl;
    }

    void dequeue() {
        if (estaVazia()) {
            cout << "Fila vazia!" << endl;
            return;
        }

        int removido = fila[inicio];

        inicio = (inicio + 1) % capacidade;

        quantidade--;

        cout << removido << " removido da fila." << endl;
    }

    void exibir() {
        if (estaVazia()) {
            cout << "Fila vazia!" << endl;
            return;
        }

        cout << "Fila: ";

        for (int i = 0; i < quantidade; i++) {
            int indice = (inicio + i) % capacidade;
            cout << fila[indice] << " ";
        }

        cout << endl;
    }
};

int main() {
    FilaCircular fila(5);

    fila.enqueue(10);
    fila.enqueue(20);
    fila.enqueue(30);
    fila.enqueue(40);
    fila.enqueue(50);

    fila.exibir();

    fila.dequeue();
    fila.dequeue();

    fila.exibir();

    fila.enqueue(60);
    fila.enqueue(70);

    fila.exibir();

    return 0;
}