#include <iostream>
using namespace std;

#define MAX 100
int pilha[MAX];
int topo = -1;

void push(int valor){
    if(topo < MAX -1){
        topo = topo+1;
        pilha[topo] = valor;
    }
}

int peak(){
    if(topo == -1){
        cout << "Pilha vazia" << endl;
        return -1; 
    }
    return pilha[topo];

}

int pop(){
    if(topo >=0){
        topo-- ;
    }
    return -1;
}

int main(){

    cout << peak() << endl;
    push(5);
    cout << peak() << endl;
    push(10);
    cout << peak() << endl;
    push(15);
    cout << peak() << endl;
    pop();
    cout << peak() << endl;
    push(20);
    cout << peak() << endl;
    push(25);
    cout << peak() << endl;
    return 0;
}
