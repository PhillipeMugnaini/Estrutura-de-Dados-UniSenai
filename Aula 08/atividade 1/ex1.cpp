#include <iostream>
using namespace std;

#define MAX 10
int pilha[MAX];
int topo = -1;

void push(int valor){
    if(topo < MAX - 1){
        topo++;
        pilha[topo] = valor;
    } else {
        cout << "Pilha cheia!" << endl;
    }
}

bool isEmpty(){
    return topo == -1;
}

int peek(){
    if(isEmpty()){
        cout << "Pilha vazia!" << endl;
        return -1;
    }
    return pilha[topo];
}

int pop(){
    if(isEmpty()){
        cout << "Pilha vazia!" << endl;
        return -1;
    }
    int valor = pilha[topo];
    topo--;
    return valor;
}

int main(){
    int opcao;

    while (true){
        cout << "\n1 - Push" << endl;
        cout << "2 - Pop" << endl;
        cout << "3 - Peek" << endl;
        cout << "4 - Sair" << endl;
        cin >> opcao;

        switch(opcao){
            case 1:{
                int valor;
                cout << "Digite o valor: ";
                cin >> valor;
                push(valor);
                break;
            }

            case 2:{
                int removido = pop();
                if(removido != -1)
                    cout << "Removido: " << removido << endl;
                break;
            }

            case 3:
                cout << "Topo: " << peek() << endl;
                break;

            case 4:
                return 0;

            default:
                cout << "Opção inválida!" << endl;
        }
    }
}