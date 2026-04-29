#include <iostream>

using namespace std;

struct No{

    int valor;
    No* prox;
    No* ant;
};

No* head = NULL;

void inserir(int valor){

    No* novo = new No();

    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;

    if(head == NULL){

        head = novo;

    }else{

        No* atual = head;

        while(atual->prox != NULL){
            atual = atual->prox;
        }

        atual->prox = novo;
        novo->ant = atual;
    }
}

void imprimir(){

    No* atual = head;

    while(atual != NULL){

        cout << atual->valor << " ";
        atual = atual->prox;
    }

    cout << endl;
}

void imprimirReverso(){

    if(head == NULL){
        return;
    }

    No* atual = head;

    // Vai até o último nó
    while(atual->prox != NULL){
        atual = atual->prox;
    }

    // Percorre do fim para o início
    while(atual != NULL){

        cout << atual->valor << " ";
        atual = atual->ant;
    }

    cout << endl;
}

void remover(int valor){

    No* atual = head;

    while(atual != NULL){

        if(atual->valor == valor){

            if(atual->ant != NULL){
                atual->ant->prox = atual->prox;
            }else{
                head = atual->prox;
            }

            if(atual->prox != NULL){
                atual->prox->ant = atual->ant;
            }

            delete atual;
            return;
        }

        atual = atual->prox;
    }
}

int main(){

    inserir(10);
    inserir(20);
    inserir(30);

    imprimir();

    remover(20);
    inserir(40);
    imprimirReverso();

    return 0;
}