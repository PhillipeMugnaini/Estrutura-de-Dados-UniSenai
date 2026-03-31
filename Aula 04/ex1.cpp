#include <iostream>
#include <string>

using namespace std;

int main() {
    string nomes[5];
    string unidades[5];
    int quantidades[5];

    nomes[0] = "Arroz";
    unidades[0] = "kg";
    quantidades[0] = 10;

    cout << "--- LISTAGEM: ESTRUTURAS HOMOGÊNEAS (ARRAYS) ---" << endl;
    cout << "Produto: " << nomes[0] << " | Unidade: " << unidades[0] << " | Qtd: " << quantidades[0] << endl << endl;


    struct Produto {
        string nome;
        string unidade;
        int quantidade;
    };

    Produto listaProdutos[5];
    listaProdutos[0] = {"Feijão", "kg", 5}; 

    cout << "--- LISTAGEM: ESTRUTURA HETEROGÊNEA (STRUCT) ---" << endl;
    cout << "Produto: " << listaProdutos[0].nome 
         << " | Unidade: " << listaProdutos[0].unidade 
         << " | Qtd: " << listaProdutos[0].quantidade << endl;

    return 0;
}

//4. Tudo em um só lugar: Na struct, o nome, a unidade e a quantidade "andam juntos" como um único objeto. Nos arrays, as informações ficam soltas em gavetas separadas.