#include <iostream>

using namespace std;

struct Node {
    int valor;
    Node* prox;
};

Node* head = NULL;

// Inserção no final
void inserirFinal(int valor) {
    Node* novo = new Node();
    novo->valor = valor;

    // Se a lista estiver vazia
    if (head == NULL) {
        head = novo;
        novo->prox = head;
    } else {
        Node* atual = head;

        // Percorre até o último nó
        while (atual->prox != head) {
            atual = atual->prox;
        }

        atual->prox = novo;
        novo->prox = head;
    }
}

// Percurso completo da lista
void percorrer() {
    if (head == NULL) {
        cout << "Lista vazia!" << endl;
        return;
    }

    Node* atual = head;

    do {
        cout << atual->valor << " ";
        atual = atual->prox;
    } while (atual != head);

    cout << endl;
}

// Remoção por valor
void remover(int valor) {
    if (head == NULL) {
        cout << "Lista vazia!" << endl;
        return;
    }

    Node* atual = head;
    Node* anterior = NULL;

    // Caso especial: remover o primeiro nó
    if (head->valor == valor) {

        // Se houver apenas um nó
        if (head->prox == head) {
            delete head;
            head = NULL;
            return;
        }

        // Encontrar o último nó
        Node* ultimo = head;
        while (ultimo->prox != head) {
            ultimo = ultimo->prox;
        }

        Node* temp = head;
        head = head->prox;
        ultimo->prox = head;

        delete temp;
        return;
    }

    // Procurar o nó a ser removido
    do {
        anterior = atual;
        atual = atual->prox;

        if (atual->valor == valor) {
            anterior->prox = atual->prox;
            delete atual;
            cout << "Elemento removido!" << endl;
            return;
        }

    } while (atual != head);

    cout << "Elemento nao encontrado!" << endl;
}

int main() {

    inserirFinal(10);
    inserirFinal(20);
    inserirFinal(30);
    inserirFinal(40);

    cout << "Lista: ";
    percorrer();

    remover(20);

    cout << "Lista apos remover 20: ";
    percorrer();

    remover(10);

    cout << "Lista apos remover 10: ";
    percorrer();

    return 0;
}