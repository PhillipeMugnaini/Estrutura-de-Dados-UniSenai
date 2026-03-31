#include <iostream>
using namespace std;

#define MAX 10

struct Lista
{
    int elementos[MAX];
    int tamanho;
};

bool inserir(Lista &l, int valor){

    if(l.tamanho >= MAX){
        cout << "Lista cheia!" << endl;
        return false;
    }

    l.elementos[l.tamanho] = valor;
    l.tamanho++;
    return true;
}

void imprimir(Lista &l){
    if (l.tamanho == 0) {
        cout << "Lista vazia!" << endl;
        return;
    }
    cout << "Elementos da lista: ";
    for (int i = 0; i < l.tamanho; i++) {
        cout << l.elementos[i] << " ";
    }
    cout << endl;
}

int quantidadeElementos(Lista &l){
    return l.tamanho;
}

int main()
{
    Lista l;
    l.tamanho = 0;
    
    int opcao, valor;

    do{
        cout << "\n--- MENU ---\n";
        cout << "1 - Inserir elemento\n";
        cout << "2 - Imprimir lista\n";
        cout << "3 - Mostrar quantidade\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch(opcao){

            case 1:
                cout << "Digite um valor: ";
                cin >> valor;
                inserir(l, valor);
                break;
            case 2:
                imprimir(l);
                break;
            case 3:
                cout << "Quantidade de elementos: " << quantidadeElementos(l) << endl;
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
        }

    } while (opcao != 0);

    
    return 0;
}
