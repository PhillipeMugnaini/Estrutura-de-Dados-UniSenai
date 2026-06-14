#ifndef PECA_H
#define PECA_H

using namespace std;


#include <string>

// Estrutura que representa uma Peça de Moto (Nó da Lista Encadeada)
struct Peca {
    int id;
    string nome;
    float preco;
    int estoque;
    Peca* proximo; // Ponteiro para o próximo nó da lista
};

// Funções de gerenciamento da Lista Encadeada do Catálogo
void inicializarCatalogo(Peca*& inicio);
void inserirPeca(Peca*& inicio, int id, string nome, float preco, int estoque);
bool removerPeca(Peca*& inicio, int id);
void exibirCatalogo(Peca* inicio);
void liberarCatalogo(Peca*& inicio);

// Funções exigidas de Ordenação (Bubble Sort e Insertion Sort)
// Nota: Como listas encadeadas são difíceis de ordenar diretamente para iniciantes,
// vamos copiar os dados para um vetor temporário, ordenar o vetor e exibir,
// exatamente como sugerido nas aulas de ordenação de vetores!
void ordenarPorBubbleSort(Peca* inicio);
void ordenarPorInsertionSort(Peca* inicio);

// Funções exigidas de Busca (Linear e Binária)
Peca* buscaLinear(Peca* inicio, int idProcurado);
Peca* buscaBinaria(Peca* inicio, int idProcurado);

#endif