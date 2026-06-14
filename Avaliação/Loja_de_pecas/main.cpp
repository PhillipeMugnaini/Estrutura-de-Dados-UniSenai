#include <iostream>
#include <string>
#include "Peca.h"
#include "Pedido.h"

using namespace std;

int main() {
    Peca* catalogo;
    inicializarCatalogo(catalogo);

    FilaPedidos expedicao;
    inicializarFila(expedicao);

    // Massa de dados inicial para a loja não iniciar totalmente vazia
    inserirPeca(catalogo, 101, "Amortecedor Traseiro Pro-Link", 349.90, 15);
    inserirPeca(catalogo, 105, "Pastilha de Freio Brembo Carbon", 89.90, 40);
    inserirPeca(catalogo, 102, "Kit Relacao Transmissao (Corrente/Coroa/Pinhao)", 199.50, 20);
    inserirPeca(catalogo, 104, "Pneu Dianteiro Pirelli Diablo", 420.00, 8);

    int contadorPedidos = 1; // Controla o ID autoincrementável dos pedidos da fila
    int opcao = 0;

    do {
        cout << endl << "================ SIMULADOR DE E-COMMERCE (PECAS DE MOTO) ================" << endl;
        cout << "1. Listar Catálogo de Peças (Visualização Padrão)" << endl;
        cout << "2. Cadastrar Nova Peça no Catálogo" << endl;
        cout << "3. Remover Peça do Catálogo" << endl;
        cout << "4. Simular Compra de Peça (Adicionar à Fila de Envio)" << endl;
        cout << "5. Visualizar Fila de Despacho/Envio" << endl;
        cout << "6. Despachar Próximo Pedido da Fila (Processar Checkout)" << endl;
        cout << "7. Filtrar/Ordenar Peças por Preço (Bubble Sort vs Insertion Sort)" << endl;
        cout << "8. Buscar Peça por ID (Busca Linear vs Busca Binária)" << endl;
        cout << "9. Sair do Sistema" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                exibirCatalogo(catalogo);
                break;

            case 2: {
                int id, est; float prc; std::string nome;
                cout << "Digite o ID da peca: "; cin >> id;
                cin.ignore(); // Limpa o buffer do teclado antes de ler string
                cout << "Digite o Nome da peca: "; getline(cin, nome);
                cout << "Digite o Preco: R$ "; cin >> prc;
                cout << "Digite a quantidade em Estoque: "; cin >> est;
                inserirPeca(catalogo, id, nome, prc, est);
                cout << "Peca cadastrada com sucesso!" << endl;
                break;
            }

            case 3: {
                int id;
                cout << "Digite o ID da peca que deseja remover: ";
                cin >> id;
                if (removerPeca(catalogo, id)) {
                    cout << "Peca removida do catalogo com sucesso!" << endl;
                } else {
                    cout << "Erro: Peca nao encontrada." << endl;
                }
                break;
            }

            case 4: {
                int idBuscado; string nomeCliente;
                cout << "Digite o ID da peca que o cliente deseja comprar: ";
                cin >> idBuscado;
                
                Peca* pecaEncontrada = buscaLinear(catalogo, idBuscado);
                
                if (pecaEncontrada != nullptr) {
                    if (pecaEncontrada->estoque > 0) {
                        cin.ignore();
                        cout << "Digite o nome do Cliente: ";
                        getline(cin, nomeCliente);

                        // Enfileira o pedido na expedição
                        enfileirarPedido(expedicao, contadorPedidos++, nomeCliente, pecaEncontrada->nome, pecaEncontrada->preco);
                        pecaEncontrada->estoque--; // Deduz uma unidade do estoque da loja
                        cout << "Compra realizada! Pedido adicionado à fila de despacho." << endl;
                    } else {
                        cout << "Desculpe, produto temporariamente esgotado no estoque." << endl;
                    }
                } else {
                    cout << "Produto nao localizado no sistema." << endl;
                }
                break;
            }

            case 5:
                exibirFila(expedicao);
                break;

            case 6:
                if (!desenfileirarPedido(expedicao)) {
                    cout << "Nao ha pedidos pendentes para envio." << endl;
                }
                break;

            case 7:
                cout << endl << "--- EXECUTANDO ALGORITMOS DE ORDENACAO DE PRECOS ---";
                ordenarPorBubbleSort(catalogo);
                ordenarPorInsertionSort(catalogo);
                break;

            case 8: {
                int idProcurado;
                cout << "Digite o ID da peca que deseja buscar: ";
                cin >> idProcurado;

                cout << endl << "--- Executando Busca Linear (O(n)) ---";
                Peca* p1 = buscaLinear(catalogo, idProcurado);
                if(p1 != nullptr) cout << endl << "[Linear] Encontrado: " << p1->nome << " | Preco: R$" << p1->preco << endl;
                else cout << endl << "[Linear] Peca nao encontrada." << endl;

                cout << endl << "--- Executando Busca Binaria (O(log n)) ---";
                Peca* p2 = buscaBinaria(catalogo, idProcurado);
                if(p2 != nullptr) cout << endl << "[Binaria] Encontrado: " << p2->nome << " | Preco: R$" << p2->preco << endl;
                else cout << endl << "[Binaria] Peca nao encontrada." << endl;
                break;
            }

            case 9:
                cout << "Encerrando o simulador... Liberando memoria..." << endl;
                liberarCatalogo(catalogo);
                liberarFila(expedicao);
                cout << "Sistema desligado de forma segura!" << endl;
                break;

            default:
                cout << "Opcao invalida! Digite novamente." << endl;
                break;
        }
    } while (opcao != 9);

    return 0;
}