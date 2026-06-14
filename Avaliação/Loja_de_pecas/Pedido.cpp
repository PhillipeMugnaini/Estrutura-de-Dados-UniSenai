#include "Pedido.h"
#include <iostream>

using namespace std;


// Inicializa a fila apontando início e fim para NULL
void inicializarFila(FilaPedidos& fila) {
    fila.inicio = nullptr;
    fila.fim = nullptr;
}

// Operação Enqueue: Insere no Fim da Fila
void enfileirarPedido(FilaPedidos& fila, int id, string cliente, string peca, float valor) {
    Pedido* novo = new Pedido();
    novo->idPedido = id;
    novo->nomeCliente = cliente;
    novo->pecaComprada = peca;
    novo->valorTotal = valor;
    novo->proximo = nullptr;

    if (fila.fim == nullptr) { // Fila estava vazia
        fila.inicio = novo;
        fila.fim = novo;
    } else {
        fila.fim->proximo = novo; // O antigo fim aponta para o novo
        fila.fim = novo;          // O fim da fila passa a ser o novo nó
    }
}

// Operação Dequeue: Remove do Início da Fila (Regra FIFO)
bool desenfileirarPedido(FilaPedidos& fila) {
    if (fila.inicio == nullptr) {
        return false; // Fila vazia
    }

    Pedido* aux = fila.inicio;
    fila.inicio = fila.inicio->proximo;

    if (fila.inicio == nullptr) { // Se a fila esvaziou por completo
        fila.fim = nullptr;
    }

    cout << endl << ">>> Pedido ID #" << aux->idPedido << " do cliente " << aux->nomeCliente 
              << " enviado com sucesso para a transportadora!" << endl;

    delete aux; // Desalocação de memória necessária
    return true;
}

// Exibe todos os pedidos aguardando envio na fila
void exibirFila(FilaPedidos fila) {
    if (fila.inicio == nullptr) {
        cout << "Nenhum pedido na fila de processamento/envio." << endl;
        return;
    }

    Pedido* aux = fila.inicio;
    cout << "--------- FILA DE PROCESSAMENTO DE PEDIDOS (DESPACHO) ---------" << endl;
    while (aux != nullptr) {
        cout << "Pedido #" << aux->idPedido << " | Cliente: " << aux->nomeCliente 
                  << " | Item: " << aux->pecaComprada << " | Total: R$" << aux->valorTotal << endl;
        aux = aux->proximo;
    }
    cout << "---------------------------------------------------------------" << endl;
}

// Limpa toda a fila da memória ao encerrar o sistema
void liberarFila(FilaPedidos& fila) {
    while (fila.inicio != nullptr) {
        Pedido* aux = fila.inicio;
        fila.inicio = fila.inicio->proximo;
        delete aux;
    }
    fila.fim = nullptr;
}