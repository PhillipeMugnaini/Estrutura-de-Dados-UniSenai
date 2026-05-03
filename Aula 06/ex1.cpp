#include <iostream>
using namespace std; 

struct No{
    int valor;
    No* proximo;
};

No* inicio = nullptr;

void inserirInicio(int valor){
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->valor = valor;
    novo->proximo = inicio;
    inicio = novo;
}

void exibirLista(){
    No* atual = inicio;
    cout << "Lista: ";
    while (atual != nullptr){
        cout << atual->valor << " ";
        atual = atual->proximo;
    }
}

void inserirFinal(int value){
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->valor = value;
    novo->proximo = nullptr;

    if (inicio == nullptr) {
        inicio = novo;
        return;
    } 

    No* atual = inicio;
    while (atual->proximo != nullptr){
        atual = atual->proximo;
    }
    atual->proximo = novo;

}

void inserirAposValor(int value, int apos){
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->valor = value;
    novo->proximo = nullptr;

    No* atual = inicio;
    while (atual != nullptr && atual->valor != apos){
        atual = atual->proximo;
    }

    if (atual == nullptr){
        No* novo = new No;
        novo->valor = value;
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }else{
        cout << "Valor " << apos << " não encontrado na lista." << endl;
    }

}

void removerValor(int value){
    No* atual = inicio;
    No* anterior = nullptr;

    while(atual != nullptr && atual->valor != value){
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == nullptr){
        cout << "Valor " << value << " não encontrado na lista." << endl;
        return;
    }

    if (anterior == nullptr){
        inicio = atual->proximo;
    }else{
        anterior->proximo = atual->proximo;
    }

    free(atual);

}




int main()
{
    int option, value, apos;

    do{
        cout << "\n--- MENU ---\n";
        cout << "1.Inserir no inicio" << endl;
        cout << "2.Inserir no final" << endl;
        cout << "3.Inserir após um valor" << endl;
        cout << "4.Remover um valor" << endl;
        cout << "5.Exibir a lista" << endl;
        cout << "0.Sair" << endl;
        cout << "\n------------\n";
        cin >> option;

        switch (option){
            case 1:
                cout << "Digite o valor a ser inserido: ";
                cin >> value;
                inserirInicio(value);
                break;
            case 2:
                cout << "Digite o valor a ser inserido: ";
                cin >> value;
                inserirFinal(value);
                break;
            case 3:
                cout << "Digite o valor após o qual deseja inserir: ";
                cin >> apos;
                cout << "Digite o valor a ser inserido: ";
                cin >> value;
                inserirAposValor(value, apos);
                break;
            case 4:
                removerValor();
                break;
            case 5:
                exibirLista();
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
            
            
    } while (option != 0);
    
    return 0;
}

