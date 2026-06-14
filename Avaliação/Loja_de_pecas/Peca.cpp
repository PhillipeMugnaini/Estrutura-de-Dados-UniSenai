#include "Peca.h"
#include <iostream>

using namespace std;


// Inicializa o ponteiro de início como NULL (Lista vazia)
void inicializarCatalogo(Peca*& inicio) {
    inicio = nullptr;
}

// Insere uma nova peça no final da lista encadeada (Alocação Dinâmica com new)
void inserirPeca(Peca*& inicio, int id, string nome, float preco, int estoque) {
    Peca* novo = new Peca();
    novo->id = id;
    novo->nome = nome;
    novo->preco = preco;
    novo->estoque = estoque;
    novo->proximo = nullptr;

    if (inicio == nullptr) {
        inicio = novo;
    } else {
        Peca* aux = inicio;
        while (aux->proximo != nullptr) {
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
}

// Remove uma peça do catálogo pelo ID e libera a memória (delete)
bool removerPeca(Peca*& inicio, int id) {
    if (inicio == nullptr) return false;

    Peca* atual = inicio;
    Peca* anterior = nullptr;

    while (atual != nullptr && atual->id != id) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == nullptr) return false; // Não achou

    if (anterior == nullptr) {
        inicio = atual->proximo; // Remove do início
    } else {
        anterior->proximo = atual->proximo; // Remove do meio/fim
    }

    delete atual; // Liberação de memória obrigatória para evitar Memory Leak!
    return true;
}

// Percorre a lista encadeada imprimindo os produtos
void exibirCatalogo(Peca* inicio) {
    if (inicio == nullptr) {
        cout << "O catalogo esta vazio" << endl;
        return;
    }
    Peca* aux = inicio;
    cout << "------------------ CATALOGO DE PECAS ------------------" << endl;
    while (aux != nullptr) {
        cout << "ID: " << aux->id << " | Nome: " << aux->nome 
             << " | Preco: R$" << aux->preco << " | Estoque: " << aux->estoque << endl;
        aux = aux->proximo;
    }
    cout << "-------------------------------------------------------" << endl;
}

// Libera toda a memória da lista ao fechar o programa
void liberarCatalogo(Peca*& inicio) {
    Peca* atual = inicio;
    while (atual != nullptr) {
        Peca* prox = atual->proximo;
        delete atual;
        atual = prox;
    }
    inicio = nullptr;
}

// Algoritmo Bubble Sort (Baseado no slide 10 e 11)
void ordenarPorBubbleSort(Peca* inicio) {
    // Contamos quantos elementos existem para criar o vetor dinâmico
    int n = 0;
    Peca* aux = inicio;
    while (aux != nullptr) { n++; aux = aux->proximo; }
    
    if (n == 0) return;

    // Criamos um vetor de ponteiros temporário para aplicar a ordenação tradicional de vetores
    Peca** vetor = new Peca*[n];
    aux = inicio;
    for(int i = 0; i < n; i++) {
        vetor[i] = aux;
        aux = aux->proximo;
    }

    // Aplicação do Bubble Sort (Complexidade O(n^2))
    int operacoes = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            operacoes++;
            if (vetor[j]->preco > vetor[j+1]->preco) {
                Peca* temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }

    cout << endl << "--- Catalogo Ordenado por Preco (Bubble Sort) ---" << endl;
    cout << "[Complexidade Pior Caso: O(n^2) | Operacoes realizadas: " << operacoes << "]" << endl;
    for(int i = 0; i < n; i++) {
        cout << "ID: " << vetor[i]->id << " | " << vetor[i]->nome << " | Preco: R$" << vetor[i]->preco << endl;
    }
    delete[] vetor;
}

// Algoritmo Insertion Sort (Baseado no slide 12)
void ordenarPorInsertionSort(Peca* inicio) {
    int n = 0;
    Peca* aux = inicio;
    while (aux != nullptr) { n++; aux = aux->proximo; }
    
    if (n == 0) return;

    Peca** vetor = new Peca*[n];
    aux = inicio;
    for(int i = 0; i < n; i++) {
        vetor[i] = aux;
        aux = aux->proximo;
    }

    // Aplicação do Insertion Sort (Complexidade O(n^2))
    int operacoes = 0;
    for (int i = 1; i < n; i++) {
        Peca* chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j]->preco > chave->preco) {
            operacoes++;
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }

    cout << endl << "--- Catalogo Ordenado por Preco (Insertion Sort) ---" << endl;
    cout << "[Complexidade Pior Caso: O(n^2) | Operacoes realizadas: " << operacoes << "]" << endl;
    for(int i = 0; i < n; i++) {
        cout << "ID: " << vetor[i]->id << " | " << vetor[i]->nome << " | Preco: R$" << vetor[i]->preco << endl;
    }
    delete[] vetor;
}

// Busca Linear / Sequencial (Baseado no slide 14) - O(n)
Peca* buscaLinear(Peca* inicio, int idProcurado) {
    Peca* aux = inicio;
    while (aux != nullptr) {
        if (aux->id == idProcurado) {
            return aux; // Encontrado
        }
        aux = aux->proximo;
    }
    return nullptr; // Não encontrado
}

// Busca Binária (Baseado no slide 14) - O(log n)
// Exige que os dados estejam ordenados. Vamos ordenar o vetor temporário por ID antes de buscar.
Peca* buscaBinaria(Peca* inicio, int idProcurado) {
    int n = 0;
    Peca* aux = inicio;
    while (aux != nullptr) { n++; aux = aux->proximo; }
    
    if (n == 0) return nullptr;

    Peca** vetor = new Peca*[n];
    aux = inicio;
    for(int i = 0; i < n; i++) { vetor[i] = aux; aux = aux->proximo; }

    // Ordenação rápida por ID (Bubble rápida) apenas para garantir pré-requisito da Busca Binária
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (vetor[j]->id > vetor[j+1]->id) {
                Peca* t = vetor[j]; vetor[j] = vetor[j+1]; vetor[j+1] = t;
            }
        }
    }

    // Execução da Busca Binária Real
    int esquerda = 0;
    int direita = n - 1;
    Peca* resultado = nullptr;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        if (vetor[meio]->id == idProcurado) {
            resultado = vetor[meio];
            break;
        }
        if (vetor[meio]->id < idProcurado) {
            esquerda = meio + 1; // Busca na metade direita
        } else {
            direita = meio - 1;  // Busca na metade esquerda
        }
    }

    delete[] vetor;
    return resultado;
}