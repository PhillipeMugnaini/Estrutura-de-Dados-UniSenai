#include <iostream>
using namespace std;

const int TAM = 5;

int fila[TAM];
int inicio = 0;
int fim = 0;

bool filaVazia() {
    return inicio == fim;
}

bool filaCheia() {
    return fim == TAM;
}

void enqueue(int valor){
    if(filaCheia()){
        cout << "Fila cheia!" << endl;
        return;
    }

    fila[fim] = valor;
    fim++;

    cout << "Elemento inserido com sucesso!" << endl;
}

void daqueue(){
    if(filaVazia()){
        cout << "Fila vazia!" << endl;
        return;
    }

    cout << "Elemento removido: " << fila[inicio] << endl;
    inicio++;
}

void peek(){
    if(filaVazia()){
        cout << "Fila vazia!" << endl;
        return;
    }

    cout << "Elemento no início da fila: " << fila[inicio] << endl;
}

void exibirFila(){
    if(filaVazia()){
        cout << "Fila vazia!" << endl;
        return;
    }

    cout << "Fila: ";

    for(int i = inicio; i < fim; i++){
        cout << fila[i] << " ";
    }
    cout << endl;
}

int main(){

    int opcao, valor;

    do{
        cout << "\n=== Menu ===\n";
        cout << "1 - Enqueue\n";
        cout << "2 - Dequeue\n";
        cout << "3 - Peek\n";
        cout << "4 - Exibir Fila\n";
        cout << "5 - Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Digite o valor a ser inserido: ";
            cin >> valor;
            enqueue(valor);
            break;
        case 2:
            daqueue();
            break;
        case 3:
            peek();
            break;
        case 4:
            exibirFila();
            break;
        case 5:
            cout << "Saindo..." << endl;
            break;
        
        default:
            cout << "Opcao invalida!\n";
            break;
        }
    }while (opcao !=5);
    
    return 0;
}
