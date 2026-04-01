#include <iostream>
using namespace std; 

#define MAX 10

struct Lista{
    int elementos[MAX];
    int tamanho;
};

bool inserirNoFinal(Lista &l, int elemento){
    if(l.tamanho >= MAX){
        cout << "Lista cheia." << endl;
        return false;
    }

    l.elementos[l.tamanho] = elemento;
    l.tamanho++;
    return true;
}

bool inserirPosicao(Lista &l, int valor, int pos){
    if(l.tamanho >= MAX){
        cout << "Lista cheia." << endl;
        return false;
    }
    if (pos < 0 || pos > l.tamanho){
        cout << "Posição inválida." << endl;
        return false;
    }

     for (int i = l.tamanho; i > pos; i--){
        l.elementos[i] = l.elementos[i - 1];
     }
     l.elementos[pos] = valor;
     l.tamanho++;
     return true;
 
}

bool removerElemento(Lista &l, int valor){
    int pos = -1;

    for(int i = 0; i < l.tamanho; i++){
        if(l.elementos[i] == valor){
            pos = i;
            break;
        }
    }
    if (pos == -1){
        cout << "Elemento não encontrado." << endl;
        return false;
    }

    for (int i = pos; i < l.tamanho - 1; i++){
        l.elementos[i] = l.elementos[i + 1];
    }

    l.tamanho--;
    return true;
}

int buscarElemento(Lista &l, int valor){
    for (int i = 0; i < l.tamanho; i++){
        if(l.elementos[i] == valor){
            return i;
        }
    }
    return -1;
}

void imprimirLista(Lista &l){
    cout << "Elementos da lista: ";
    for (int i = 0; i < l.tamanho; i++){
        cout << l.elementos[i] << " ";
    }
    cout << endl;
}

int main()
{
    Lista l;
    l.tamanho = 0;

    int opcao, valor, pos;

    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1 - Inserir no final\n";
        cout << "2 - Inserir em posicao\n";
        cout << "3 - Remover elemento\n";
        cout << "4 - Buscar elemento\n";
        cout << "5 - Exibir lista\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao){
        case 1:
            cout << "Digite o valor a ser inserido: ";
            cin >> valor;
            inserirNoFinal(l, valor);
            break;  
        case 2:
            cout << "Digite o valor a ser inserido: ";
            cin >> valor;
            cout << "Digite a posição: ";
            cin >> pos;
            inserirPosicao(l, valor, pos);
            break;
        case 3:
            cout << "Digite o valor a ser removido: ";
            cin >> valor;
            removerElemento(l, valor);
            break;
        case 4:
            cout << "Digite o valor a ser buscado: ";
            cin >> valor;
            pos = buscarElemento(l, valor);
            if (pos != -1){
                cout << "Elemento encontrado na posição: " << pos << endl;
            } else {
                cout << "Elemento não encontrado." << endl;
            }
            break;
        case 5:
            imprimirLista(l);
            break;
        case 0:
            cout << "Saindo..." << endl;
            break;
        default:
            cout << "Opção inválida. Tente novamente." << endl;
        }
    

    } while (opcao != 0);
    
    
    return 0;
}
