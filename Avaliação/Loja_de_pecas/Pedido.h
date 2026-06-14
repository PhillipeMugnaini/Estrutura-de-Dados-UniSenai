#ifndef PEDIDO_H
#define PEDIDO_H

#include <string>

using namespace std;


// Estrutura que representa um Pedido de Compra (Nó da Fila)
struct Pedido {
    int idPedido;
    string nomeCliente;
    string pecaComprada;
    float valorTotal;
    Pedido* proximo; // Ponteiro para o próximo pedido da fila
};

// Estrutura de controle da Fila Dinâmica (Possui ponteiro para o Início e para o Fim)
struct FilaPedidos {
    Pedido* inicio;
    Pedido* fim;
};

// Funções de gerenciamento da Fila (Baseado no slide 9 de Filas)
void inicializarFila(FilaPedidos& fila);
void enfileirarPedido(FilaPedidos& fila, int id, string cliente, string peca, float valor);
bool desenfileirarPedido(FilaPedidos& fila);
void exibirFila(FilaPedidos fila);
void liberarFila(FilaPedidos& fila);

#endif